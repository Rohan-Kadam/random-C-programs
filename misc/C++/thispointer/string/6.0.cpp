//
// How to check if a String Ends With an another given String
//

#include <iostream>
#include <string>
#include <algorithm>
/*
 * Case Sensitive Implementation of endsWith()
 * It checks if the string 'mainStr' ends with given string 'toMatch'
 */
bool endsWith(const std::string &mainStr, const std::string &toMatch)
{
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
    auto it = toMatch.begin();
        return mainStr.size() >= toMatch.size() &&
                std::all_of(std::next(mainStr.begin(),mainStr.size() - toMatch.size()), mainStr.end(), [&it](const char & c){
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
