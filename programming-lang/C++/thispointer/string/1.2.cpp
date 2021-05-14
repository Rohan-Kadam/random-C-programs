//
// Find & Replace all sub strings – using STL
//
// RHK
// SAME AS 1.c, here we change flow from find->while->replace->find to while->find->replace. 
// To check why first find should be outside
//
// Answer: In last iteration .find will reach end of string, and fill pos with npos. This npos is passed to .replace which breaks 
// as shown below.
// Output is
// Before: Hello World
// terminate called after throwing an instance of 'std::out_of_range'
// what():  basic_string::replace: __pos (which is 18446744073709551615) > this->size() (which is 11)
// Aborted (core dumped)


#include <iostream>
#include <string>

using namespace std;

//RHK
//Func flow is
//First find --> WHILE npos --> replace --> find from pos --> WHILE END
void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	
	size_t pos;

	// Repeat till end is reached
    while( pos != string::npos)
    {

		// Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
	    
		// Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        
    }
}

int main(){

	string data = "Hello World";
	cout << "Before: " << data << endl;
	//Passing full string, sub string to remove, sub string to add
	findAndReplaceAll(data,"Wor","XXX");
	cout << "After: " << data << endl;

	return 0;
}
