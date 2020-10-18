//**********************************************************
//HELLO WORLD KERNEL MODULE
//
//Author: Rohan Kadam
//Date: 1st November 2018
//
//For compiling and running this module following steps were used
//>> make -C /usr/src/linux-headers-4.15.0-36-generic M=`pwd` modules (Makefile_old)
//Here,
//	-C is option in make to provide directory. make goes in that dir and runs Makefile. Specify the kernel for which module is written.
//	M=`pwd` is used to capture your current dir before moving to dir in -C. Get back to pwd and run make modules OR make modules_install 
//	make modules command will just compile the modules, leaving the compiled binaries in the build directory.
//	OR
//	make modules_install will make sure that there are compiled binaries and install the binaries into your kernel's modules directory.
//OR
//>> make 
//(here we used /lib/modules/(uname -r which gives *-36-generic)/build in Makefile,
//the build has a softlink to /usr/src/*-36-generic used in above make cmd
//We can check /boot for configuration version used by kernel )
//>> sudo insmod ./hello_world.ko
//>> dmesg (this is the ring buffer)
//>> dmesg -c (clear ring buffer, not recommended)
//>> lsmod | grep hello (this shows module and used by)
//>> sudo rmmod hellow_world (do not give extension)
//>> dmesg
//>> lsmod | grep hello
//
//
//**********************************************************

#include <linux/module.h> //All mandatory linux function for init/delete module

//make global variables static always
static int x;

//__init (NOT MANDATORY)
//modules which have some datastructures/varibles which are part of
//init, kernel once done with initialization of module may get away with
//those varibles
//
//static 
//To avoid namespace collision, but if this module is used by other modules
//remove static since we want it to be exported, but here we want to limit it
//only for this module.
static int __init insert_hello(void)
{
	x++;
	printk(KERN_INFO "Hello World %d\n",x); 
	//Here, printk is macro, hence no comma after KERN_INFO
	return 0;
}

//__exit (NOT MANDATORY)
//kernel can take off some of the variables as a part of cleanup
static void __exit remove_hello(void)
{
	printk(KERN_DEBUG "Hello World removed\n");
}


//Kernel macros to call init and exit functions
//comes from <linux/module.h>
module_init(insert_hello);
module_exit(remove_hello);

//Incase of wrong/no license linux kernel complains module tainted and it 
//might not load module at all.	
MODULE_LICENSE("GPL");	


