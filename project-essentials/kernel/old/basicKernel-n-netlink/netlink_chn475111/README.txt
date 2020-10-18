# netlink
user space and kernel space communicate with netlink

Added by Rohan Kadam
2nd November 2018
=======================================
This example establishes unicast communication between user and kernel using netlink (not generic)

Goto kernel folder

Changes done in kernel code named test.c
-- Added linux/module.h
-- Added new structure and updated old function call to match latest syntax.

struct netlink_kernel_cfg cfg = {
    .input = <Handler Name>,
};

nl_sk = netlink_kernel_create(&init_net, NETLINK_TEST, &cfg);

For latest version of linux, netlink_kernel_create( ) API has changed. Check "/usr/src/linux-headers-4.15.0-36-generic/include/linux/netlink.h", in header file search "netlink_kernel_create(" and new 3rd param named "struct netlink_kernel_cfg". 


>> make (kernel code)
>> sudo insmod test.ko
>> lsmod | grep test

Goto user folder

>> make (user code)
>> ./test
