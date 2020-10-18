
// new & delete operator
// new : 1 - Alloc memory from heap = sizeof(datatype/class) and return ptr
//		 2 - Initialize var or call constructor in case of class
//
// delete: 1 - destructor
//		   2 - dealloc

#include <iostream>
class Sample
{
public:
    Sample()
    {
        std::cout<<"Sample::Constructor\n";
    }
    ~Sample()
    {
        std::cout<<"Sample::Destructor\n";
    }
};
int main()
{
    Sample * ptr = new Sample();
    delete ptr;
    return 0;
}
