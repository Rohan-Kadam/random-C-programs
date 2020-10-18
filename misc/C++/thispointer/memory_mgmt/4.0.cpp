
// Handling Out-of-memory
// new_handler and catch exception
// new_handler will try to:
//	- Make memory available again by deleting some of the memory from heap.
//	- Do some application specific logging.
//	- Start another instance of the application as a seperate process, so that services it provides can be continous.
//
//On 64 bit machine, to crash code quickly compile using "g++ -m32 main.cpp"
//This will give application a memory of 2^32(4GB). Else 2^64 will take lot of time to reach
//For -m32 install "sudo apt-get install gcc-multilib g++-multilib"
//Else it throws  
//#include <bits/c++config.h>
//          ^~~~~~~~~~~~~~~~~~
//compilation terminated.


#include <cstdlib>
#include <iostream>
#include <new>
 
void handler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
}
 
int main()
{
    std::set_new_handler(handler);
    //try {
        while (true) {
            new int[100000000ul];
        }
    //} catch (const std::bad_alloc& e) {
    //    std::cout << e.what() << '\n';
    //}
	//
	//WITH TRY-CATCH
	//ERROR: ld.so: object 'libgtk3-nocsd.so.0' from LD_PRELOAD cannot be preloaded (cannot open shared object file): ignored.
	//Memory allocation failed, terminating
	//std::bad_alloc
	//
	//WITHOUT TRY-CATCH
	//ERROR: ld.so: object 'libgtk3-nocsd.so.0' from LD_PRELOAD cannot be preloaded (cannot open shared object file): ignored.
	//Memory allocation failed, terminating
	//terminate called after throwing an instance of 'std::bad_alloc'
	//  what():  std::bad_alloc
	//Aborted (core dumped)



}
