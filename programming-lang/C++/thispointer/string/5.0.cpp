//
// Check if a String starts with an another given String
//

#include <iostream>
#include <string>
#include <algorithm>
/*
 * Case Sensitive Implementation of startsWith()
 * It checks if the string 'mainStr' starts with given string 'toMatch'
 */
bool startsWith(std::string mainStr, std::string toMatch)
{
    // std::string::find returns 0 if toMatch is found at starting
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}
/*
 * Case Insensitive Implementation of startsWith()
 * It checks if the string 'mainStr' starts with given string 'toMatch'
 */
bool startsWithCaseInsensitive(std::string mainStr, std::string toMatch)
{
    // Convert mainStr to lower case
    std::transform(mainStr.begin(), mainStr.end(), mainStr.begin(), ::tolower);
    // Convert toMatch to lower case
    std::transform(toMatch.begin(), toMatch.end(), toMatch.begin(), ::tolower);
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}
int main()
{
    std::string mainStr = "This is the sample string";
    std::string toMatch = "This";
    // Test case-sensitive implementation of startsWith function
    bool result = startsWith(mainStr , toMatch);
    std::cout<<result<<std::endl;
    // Test case-insensitive implementation of startsWith function
    result = startsWithCaseInsensitive(toMatch, "this");
    std::cout<<result<<std::endl;
}
