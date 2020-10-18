//
// How to check if a String Ends With an another given String
// Not using next in secApproach - wont compile as all_of need iterator as arg

#include <iostream>
#include <string>
#include <algorithm>
/*
 * Case Sensitive Implementation of endsWith()
 * It checks if the string 'mainStr' ends with given string 'toMatch'
 */
bool endsWith(const std::string &mainStr, const std::string &toMatch)
{
	//RHK
	// Check size, then use .compare to check last chars of string
	// 
	// About .compare
	// Syntax used: int compare (size_t pos, size_t len, const string& str) const; 
	// const at the end meaning "A const member function never modifies data members in an object."
	// TODO: const noexcept?
	//
    if(mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        else
            return false;
}
/*
 * Case Sensitive Implementation of endsWith()
 * It checks if the string 'mainStr' ends with given string 'toMatch'
 */
bool endsWith_secApproach(const std::string &mainStr, const std::string &toMatch)
{
	//RHK
	// TODO: auto,begin,all_of,next,lambda function
	//
    // all_of:
    // template <class InputIterator, class UnaryPredicate>
    // bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred);
    // Returns true if pred returns true for all the elements in the 
    // range [first,last) or if the range is empty, and false otherwise.
    // 
    // next:
    // template <class ForwardIterator>
    // ForwardIterator next (ForwardIterator it,
    // typename iterator_traits<ForwardIterator>::difference_type n = 1);
    // Returns an iterator pointing to the element that it would be pointing to 
    // if advanced n positions.


    auto it = toMatch.begin();
    return mainStr.size() >= toMatch.size() &&
    	std::all_of(mainStr.size() - toMatch.size(), mainStr.end(), [&it](const char & c){
                    return c == *(it++)  ;
        } );
}
/*
 * Case Insensitive Implementation of endsWith()
 * It checks if the string 'mainStr' ends with given string 'toMatch'
 */
bool endsWithCaseInsensitive(std::string mainStr, std::string toMatch)
{
    auto it = toMatch.begin();
    return mainStr.size() >= toMatch.size() &&
            std::all_of(std::next(mainStr.begin(),mainStr.size() - toMatch.size()), mainStr.end(), [&it](const char & c){
                return ::tolower(c) == ::tolower(*(it++))  ;
    } );
}
int main()
{
    std::string mainStr = "This is the sample STRing";
    std::string toMatch = "STRing";
    // Test case-sensitive implementation of endsWith() function
    bool result = endsWith(mainStr , toMatch);
    std::cout<<result<<std::endl;
    // Test case-sensitive implementation of endsWith_secApproach() function
    result = endsWith_secApproach(mainStr , toMatch);
    std::cout<<result<<std::endl;
    // Test case-insensitive implementation of endsWith function
    result = endsWithCaseInsensitive(toMatch, "String");
    std::cout<<result<<std::endl;
}
