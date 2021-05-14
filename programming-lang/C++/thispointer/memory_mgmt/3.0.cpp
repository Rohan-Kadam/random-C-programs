
// delete vs delete[]
// To delete the memory allocated by new[] operator , we should not use delete operator because delete operator internally calls operator delete  to deallocate the memory and calling only 1 object’s destructor. Remaining 4 object’s destructor will not be called in this case, although memory will be deallocated. This can give rise to the problems of memory leaks
// new --> delete
// new[] --> delete[] 
// DO NOT MIX new[] with delete, it shall give rise to memory leak

#include <iostream>
class Sample
{
    int * m_ptr;
public:
    Sample()
    {
        std::cout<<"Sample::Constructor\n";
        m_ptr = new int();
    }
    ~Sample()
    {
        std::cout<<"Sample::Destructor\n";
        delete m_ptr;
        m_ptr = NULL;
    }
};
int main()
{
    Sample * ptrArr = new Sample[5];
    // Calling delete on pointer that contains
    // memory allocated by new[] will cause only
    // one destructor, remaining 4 destructors
    // will not be called, hence memory leak.
    delete ptrArr;
	//Use delete [] ptrArr;
	
    return 0;
}
