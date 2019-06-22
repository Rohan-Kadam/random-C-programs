#include <iostream>
#include <vector>

#define MAX_ID 10
#define ASSIGN_ID 20

using namespace std;

int assignId(vector<int> * unId)
{
	int ID;
	cout << "Assigning Id" << endl;
        cout << unId->at(unId->size()-1) << endl;
        ID = unId->at(unId->size()-1);
	unId->pop_back();

	return ID;
}

int main()
{
	vector<int> unusedId;
	
	//Make it a Init all ID Function
	for(int i = MAX_ID; i > 0; i--)	{
		unusedId.push_back(i);	
	}
	cout << "Ids filled" << endl << endl;
	
	//Make it a Display all available ID Function
	cout << "Displaying all unused Id's" << endl;
	for(int i = 0; i < unusedId.size(); i++) {
		cout << unusedId.at(i) << ",";
	}
	cout << endl << endl;

	//Make it assign ID Function with error handling inside it
	for(int i = 0; i < ASSIGN_ID; i++) {
		if(unusedId.size() != 0){		
			assignId(&unusedId);
		} else {
			cout << "All Id's exhausted" << endl;
		}
	}

	//Make it release ID Function with error handling for wrong id number
	unusedId.push_back(2);
	unusedId.push_back(5);

	cout << "Displaying all unused Id's" << endl;
	for(int i = 0; i < unusedId.size(); i++) {
		cout << unusedId.at(i) << ",";
	}
	cout << endl;

	return 0;

}
