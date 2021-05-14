//
// Generic Find All Implementation
// RHK
// In main we pass function pointer. Code flow is firstfind --> while --> push_back --> func ptr 
// func ptr 1 = transform all to lowercase and find in callback
// func ptr 2 = lambda func which calls find and returns find's result 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
// Case Insensitive version of std::string::find
size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
    // Convert String to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    // Convert String to lower case
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    return data.find(toSearch, pos);
}

//RHK
// This looks like a normal function pointer. Compare with functor later
typedef size_t (* FINDFUNCTOR)(std::string data, std::string toSearch, size_t pos);

void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch, FINDFUNCTOR finder)
{
    // Find first occurrence
    size_t pos = finder(data, toSearch, 0);
    // Iterate till last
    while( pos != std::string::npos)
    {
        vec.push_back(pos);

		//RHK
		// Call to func ptr's func (func pointed by func ptr)
        // Find next occurrence
        pos =finder(data, toSearch, pos + toSearch.size());
    }
}

int main()
{
    std::string data = "Hi this is a Sample string, iS is 3 times here";
    std::vector<size_t> vec;
    std::cout<<"All Index Position of Case InSensitive 'is' in given string are,"<<std::endl;
    //RHK
	// vector is tranversed using range based for loop introduced in c++11
	// range based for loop can be used for str,arr,any other container
	//
	// Find All case IN-sensitive occurrences of the 'is' in the vector 'vec'
    findAllOccurances(vec, data , "iS", &findCaseInsensitive);
    for(size_t pos : vec)
        std::cout<<pos <<  std::endl;
    vec.clear();
    std::cout<<"All Index Position of Case Sensitive 'is' in given string are,"<<std::endl;
    
	//RHK
	// Here we have a lambda function. Looks similar to inline function? 
	// Instead of func name we have [](return arg?,args){func body} as 3rd arg, compare to line 50
	// Need to understand lambda function in detail
	//
	// Get All Case Sensitive occurrences of the 'is' in the vector 'vec'
    findAllOccurances(vec, data , "iS", [](std::string data, std::string toSearch, size_t pos){return data.find(toSearch, pos);});
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;

    return 0;
}
