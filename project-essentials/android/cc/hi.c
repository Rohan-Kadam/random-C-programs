
// Compile using "arm-linux-gnueabi-gcc -static -march=armv5 hi.c -o hi"
// Check detect the target architecture and operating system for a given binary using "file hi"
// Push to phone using "adb push hello /data/local/tmp"
// Run using "adb shell", "chmod 755 /data/local/tmp/hello", "/data/local/tmp/hello"
#include <stdio.h>

int main(int argc, char** argv) {
   printf("hello world\n");
   return 0;
}
