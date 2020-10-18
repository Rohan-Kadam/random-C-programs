//**********************************************************
//CHAR DEVICE DRIVER STATICALLY ALLOTTED MAJOR/MINOR NUMBER
//
//Author: Rohan Kadam
//Date: 1st November 2018
//
//For compiling and running this module following steps were used
//Used same makefile, changed filenames
//>> insmod ./char_device_driver.ko (reflects in /lsmod)
//>> lsmod | grep -i char (displays all char device) ==> char_device_driver.ko (Name of insmod-ed ko file) MODULE NAME
//>> sudo mknod /dev/rohan_node c 100 0 
//(create file/node in /dev,creates special file which kernel knows about its existances)
//>> ls -l  /dev/ | grep rohan (reflects in /dev) ==> rohan_node (Name give through mknod command) NODE NAME
//>> cat /proc/devices (reflects in /proc/devices) ==> rohankadam_char_devices (Name given in code) DEVICE NAME
//Performed echo and cat operations on device node in /dev
//sudo su
//echo "hello" > /dev/rohan_node
//cat /dev/rohan_node
//dmesg
//Created one more node with same major minor number, kernel treats it as same device (Avoid it)
//>> sudo rmmod char_driver_demo
//>> rm /dev/rohan_node
//>> sudo mknod /dev/rohan_node c 100 0
//>> cat /dev/rohan_node 
//gives /dev/rohan_node: No such device or address 
//**********************************************************
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/slab.h>

static char buffer[PAGE_SIZE];
struct cdev *my_cdev;
dev_t my_dev;
char devname[] = "rohankadam_char_device";

static int device_open(struct inode *inode, struct file *file)
{
	/* This can be used to synchroniztion purpose (eg.locking of buffer to avoid overwrites)
	 * to say if the device is already in use
	 */
	
	return 0;
}


//ARGS are as follows file, buffer to write, size of buffer and position of buffer
//Will be called when we call fwrite/write from userspace
static ssize_t device_write(struct file *file, const char *buf, size_t lbuf, loff_t *ppos)
{
	//copies userspace buffer "buf" to kernelspace buffer "buffer". 
	//Added buffer offset to avoid overwrites
	int nbytes = lbuf - copy_from_user(buffer + *ppos, buf, lbuf);
	//increment buffer pointer
	*ppos += nbytes;
	pr_info("Received data from app %s, nbytes=%d\n",buffer,nbytes);

	return nbytes;
}	

//Will be called when we call fread/read from userspace
static ssize_t device_read(struct file *file, char *buf, size_t lbuf, loff_t *ppos)
{
	int nbytes;
	int maxbytes;
	int bytes_to_do;

	maxbytes = PAGE_SIZE - *ppos;
	if(maxbytes > lbuf)
		bytes_to_do = lbuf;
	else
		bytes_to_do = maxbytes;

	//reverse of copy_from_user (i.e. copy_to_user does kernel --> userspace)
	nbytes = bytes_to_do - copy_to_user(buf, buffer + *ppos, bytes_to_do);
	*ppos += nbytes;
	pr_info("Data send to app %s, nbytes=%d\n",buffer,nbytes);

	return nbytes;
}	

//File operation mapped to our defined functions
static struct file_operations device_fops = {
	.owner = THIS_MODULE,
	.write = device_write,
	.open = device_open,
	.read = device_read,
};



static int __init my_driver_init(void)
{
	int status;
	
	//Here we are statically allotting the major/minor numbers
	//i.e. by checking /proc/devices which didnt had 100 unused
        //1st param = major/minor number
        //2nd param = no. of nodes
        //if 3, we get (100,0) (100,1) (100,2)
        //3rd param = device name (can be any)

	my_dev = MKDEV(100,0);	/* Major and Minor Number*/
	register_chrdev_region(my_dev, 1, devname);
	
	//Allocate device
	my_cdev = cdev_alloc();
	//Map device and operations it will support
	cdev_init(my_cdev,&device_fops);

	//Map my_cdev(Char dev allotted and mapped to fops) to my_dev(Char dev with major/minor number and my name)
	//defined above as
	//struct cdev *my_cdev;
	//dev_t my_dev;
	//SO HERE WE, 
	//my_cdev + my_dev = dev allotted + fops + devname + major/minor number
	status = cdev_add(my_cdev, my_dev, 1);

	if(status < 0)
	{
		pr_info("Driver init failed\n");
		return status;
	}
	
	//Init kernel buffer with zeros
	memset(buffer,'\0',PAGE_SIZE);	

	return 0;
}	

static void __exit my_driver_exit(void)
{
	//RM my_cdev
	cdev_del(my_cdev);
	//RM my_dev 
	unregister_chrdev_region(my_dev,1);
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_AUTHOR("RohanKadam");
MODULE_DESCRIPTION("Device to demonstrate read/write calls of char driver");
MODULE_LICENSE("GPLV3");

/*End of code*/

