//
// Find All Case Sensitive Occurrences of a Sub String in a given String
//

#include <iostream>
#include <string>
#include <vector>
/*
 *Find all positions of the a SubString in given String
 */
void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Add position to the vector
        vec.push_back(pos);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + toSearch.size());
    }
}
int main()
{
    std::string data = "Hi this is a Sample string, 'iS' is here 3 times";
    std::vector<size_t> vec;
    // Get All occurrences of the 'is' in the vector 'vec'
    findAllOccurances(vec, data , "is");
    std::cout<<"All Index Position of 'is' in given string are,"<<std::endl;
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;
    return 0;
}
