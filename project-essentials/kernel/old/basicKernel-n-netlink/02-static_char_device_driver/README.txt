Here you will find all header files used by linux for its operations
Eg. 
fs.h //File Operation
i2c.h //I2C Operation
and many more

>>ls /usr/src/linux-headers-4.15.0-36-generic/include/linux/<Filename>.h

If we go in fs.h, we can see "struct file_operations" which define all the possible
operation we can perform on file from linux kernel module/driver.


MAJOR/MINOR number
MAJOR number: Char driver/Block driver
MINOR number: unique to devices using a particular MAJOR number (Char/Block driver)
>> cat /proc/devices


cat 	--> fopen()	--> open() --> sys_open() --> SYSCALL_DEFINE --> Interrupt --> kernel mode --> .write --> device_write() --> copy_from_user
echo 	--> fwrite	--> ...
...	--> getpid()	--> ...
Few syscalls do not have glibC wrappers (given in man page of gettid) as we have for fopen, to use in C program. Eg. SYS_gettid. 
So for calling it from C program we use syscall(SYS_gettid) similar to system()


In C programswhile calling function, error handling is not perform to keep code simple but its important, 
i.e. checking the return value at each step and if valid then only proceeding further.

Check udev infrastructure, allot major/minor number on a fly
