//
// Find All Case IN-Sensitive Occurrences of a Sub String in a given String
//


#include <iostream>
#include <string>
#include <vector>
//RHK
// adds transform()
#include <algorithm>

// Case Insensitive version of std::string::find
size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
    // Syntax 
    // template <class InputIterator, class OutputIterator, class UnaryOperation>
    // OutputIterator transform (InputIterator first1, InputIterator last1,
    //                        OutputIterator result, UnaryOperation op);
    // template <class InputIterator1, class InputIterator2,
    // class OutputIterator, class BinaryOperation>
    // OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
    //                        InputIterator2 first2, OutputIterator result,
    //                        BinaryOperation binary_op);

    // Convert String to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    // Convert Sub String to lower case
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    
	//RHK
	//Code flow is still same, but before find we lower case the strings

	return data.find(toSearch, pos);
}
/*
 *Find all positions of the a Case Insensitive Sub String in given String
 */
void findAllOccurancesCaseInsensitive(std::vector<size_t> & vec, std::string data, std::string toSearch)
{
    // Find First Position
    size_t pos = findCaseInsensitive(data,toSearch);
    // Iterate till end
    while( pos != std::string::npos)
    {
        // Push position in vector
        vec.push_back(pos);
        // Search next position
        pos = findCaseInsensitive(data,toSearch, pos + toSearch.size());
    }
}
int main()
{
    std::string data = "Hi this is a Sample string, 'iS' is here 4 times";
    std::vector<size_t> vec;
    // Get All case insensitive occurrences of the 'is' in the vector 'vec'
    findAllOccurancesCaseInsensitive(vec, data , "IS");
    std::cout<<"All Index Position of 'is' in given string are,"<<std::endl;
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;
    return 0;
}
