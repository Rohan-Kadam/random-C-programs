//
// Find & Replace all sub strings – using STL
//

#include <iostream>
#include <string>

using namespace std;

//RHK
//Func flow is
//First find --> WHILE npos --> replace --> find from pos --> WHILE END
void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{

	//RHK
	//.find gives position of sub string
    //
	// About size_t
	// Alias of one of the fundamental unsigned integer types (uint_t or unsigned int).
	//
	// Get the first occurrence 
    size_t pos = data.find(toSearch);

    //RHK
	//if line 37 .find returns npos, while loop exits
	//
	//About .find return value
	//The position of the first character of the first match.
	//If no matches were found, the function returns string::npos.
	//
	//About npos:
    //npos is a static member constant value with the greatest possible value for an element of type size_t.
    //This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
    //As a return value, it is usually used to indicate no matches.
    //
    // Repeat till end is reached
    while( pos != string::npos)
    {

		//RHK
		//.size is used for len and .replace is used on main string
		//
		//About .replace syntax:
		//string& replace (size_t pos,        size_t len,        const string& str);
		//
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        
		//RHK
		//this is different syntax for .find, then the one used before. We provide pos to start search from
		//
		// Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
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
