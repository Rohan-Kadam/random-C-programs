//**********************************************************
//DEBUGFS: Kernel debugging infrastructure
//
//Author: Rohan Kadam
//Date: 15th November 2018
//
//**********************************************************
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/debugfs.h>
#include <asm/uaccess.h>

struct semaphore my_sem;
char kbuffer[] = "This is kernel data which can be modified";
struct dentry *my_dirent;

static ssize_t debugfs_read(struct file *file, char *buf, size_t lbuf, loff_t *ppos)
{
	int stat = -1;
	//SEMAPHORE related function call
	if(down_interruptible(&my_sem) == 0)
	{
		//Similar to copy_to_user used in char device read function,
		//Easier to use 
		//Here we will put data from kbuffer(kernel-space) to buf(user-space)
		stat = simple_read_from_buffer(buf, strlen(kbuffer), ppos, kbuffer, strlen(kbuffer));
	
		//SEMAPHORE related function call		
		up(&my_sem);
	}
	
	return stat;	
}	

static ssize_t debugfs_write(struct file *file, const char *buf, size_t lbuf, loff_t *ppos)
{
	int stat = -1;
	if(lbuf > strlen(kbuffer))
	{
		pr_info("write: returning EINVAL\n")	
		return -EINVAL;
	}

	//SEMAPHORE related function call		
	if(down_interruptible(&my_sem) == 0)
	{
		//Similar to copy_to_user used in char device read function,
		//Easier to use 
		//Here we will put data from buf(user-space) to kbuffer(kernel-space)
		stat = simple_write_to_buffer(kbuffer, strlen(buf), ppos, buf, lbuf);
		
		//If new string smaller than previous string held by kernel buffer,
		//old-string wont be overwritten fully.
		//Thus to avoid retaining data from previous string, we terminate new string.		
		kbuffer[lbuf] = '\0';

		//SEMAPHORE related function call		
		up(&my_sem);
	}

	return stat;
}	


//File operation mapped to our defined functions
static struct file_operations device_fops = {
	.read = debugfs_read,
	.write = debugfs_write,
};



static int __init init_debugfs(void)
{
	//SEMAPHORE related function call		
	sema_init(&my_sem, 1);
	
	//Creating debug directory, since 2nd param is NULL directory is created in std path
	//i.e. /sys/kernel/debug/RohanKadamDir
	my_dirent = debugfs_create_dir("RohanKadamDir",NULL);
	
	//Creating a file inside it, since file can be handled from userspace better than directory 
	//(For eg. storing data,reading it,.... many file operations available)
	//3rd param is buffer data to pass inside that file
	//4th param is file operation available
	debugfs_create_file("demo_file", 0666, my_dirent, (void *)kbuffer, &fops_debugfs);

	return 0;
}	

static void __exit exit_debugfs(void)
{
	pr_info("kernel buffer while exiting the module is <%s>\n",kbuffer);	
	debugfs_remove_recursive(my_dirent);
}

module_init(init_debugfs);
module_exit(exit_debugfs);

MODULE_AUTHOR("RohanKadam");
MODULE_DESCRIPTION("Demo for Debugfs");
MODULE_LICENSE("GPL");

/*End of code*/

