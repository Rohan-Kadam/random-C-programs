//
// Generic Find All Implementation
//

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
typedef size_t (* FINDFUNCTOR)(std::string data, std::string toSearch, size_t pos);
void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch, FINDFUNCTOR finder)
{
    // Find first occurrence
    size_t pos = finder(data, toSearch, 0);
    // Iterate till last
    while( pos != std::string::npos)
    {
        vec.push_back(pos);
        // Find next occurrence
        pos =finder(data, toSearch, pos + toSearch.size());
    }
}
int main()
{
    std::string data = "Hi this is a Sample string, iS is 3 times here";
    std::vector<size_t> vec;
    std::cout<<"All Index Position of Case InSensitive 'is' in given string are,"<<std::endl;
    // Find All case insensitive occurrences of the 'is' in the vector 'vec'
    findAllOccurances(vec, data , "iS", &findCaseInsensitive);
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;
    vec.clear();
    std::cout<<"All Index Position of Case Sensitive 'is' in given string are,"<<std::endl;
    // Get All Case Sensitive occurrences of the 'is' in the vector 'vec'
    findAllOccurances(vec, data , "iS", [](std::string data, std::string toSearch, size_t pos){
        return data.find(toSearch, pos);
    });
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;
    return 0;
}
