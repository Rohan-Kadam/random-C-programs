DEBUGFS
Debugging kernel problems
https://opensourceforu.com/2010/10/debugging-linux-kernel-with-debugfs/

In kernel we have multiple filesystems procfs,sysfs. So sysfs has debugfs. But this debugfs is different. ???SURE
https://johnsofteng.wordpress.com/2013/11/20/sysfs-procfs-sysctl-debugfs-and-other-similar-kernel-interfaces/

Check if debugfs was enabled in kernel config
>> mount | grep debugfs

If not enabled...
Try mounting it manually
>> mount -t debugfs none /sys/kernel/debug
OR Recompile kernel if mounting also fails
>> cd /usr/src/kernels/linux
>> vi .config file
Enable CONFIG_DEBUG_FS = y, recompile and load it.
