//**********************************************************
//CHAR DEVICE DRIVER DYNAMICALLY ALLOTTED MAJOR/MINOR NUMBER
//
//Author: Rohan Kadam
//Date: 1st November 2018
//
//For compiling and running this module following steps were used
//Used same Makefile
//sudo insmod ./char_driver_dynamic_demo.ko
//dmesg (Check major number)
//sudo rmmod char_driver_dynamic_demo
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
	
	/* CHANGED SECTION START */									//[COMMENTED == REMOVED]
	//===========================================================================
	//Here we are statically allotting the major/minor numbers	//[COMMENTED]
	//i.e. by checking /proc/devices which didnt had 100 unused	//[COMMENTED]
        //1st param = major/minor number				//[COMMENTED]	
        //2nd param = no. of nodes					//[COMMENTED]
        //if 3, we get (100,0) (100,1) (100,2)				//[COMMENTED]
        //3rd param = device name (can be any)				//[COMMENTED]

	//my_dev = MKDEV(100,0);	/* Major and Minor Number*/	//[COMMENTED]
	//register_chrdev_region(my_dev, 1, devname);			//[COMMENTED]
	
	//1st param = Passing empty my_dev address, it will be filled up
	//2nd param = Start from 0
	//3rd param = Total number of minor number
	//4th param = device name (can be any)
	alloc_chrdev_region(&my_dev, 0, 1, "rohankadam_dynamic_chardev");
	
	//===========================================================================
	/* CHANGED SECTION STOP */

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

        /* CHANGED SECTION START */
        //===========================================================================

	//macros provided by linux
	pr_info("Major number = %d and Minor number = %d\n",MAJOR(my_dev),MINOR(my_dev));

        //===========================================================================
        /* CHANGED SECTION STOP */

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

