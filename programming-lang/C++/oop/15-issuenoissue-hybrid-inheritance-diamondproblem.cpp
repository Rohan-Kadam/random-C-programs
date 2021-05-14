
#include<iostream>
using namespace std;
class Person {
// Data members of person
public:
	Person() { cout << "Customized default constructor with this cout" << endl; }
};

class Faculty : public Person {
// data members of Faculty
public:
	Faculty(int x) {
	cout<<"Faculty::Faculty(int ) called"<< endl;
	}
};

class Student : public Person {
// data members of Student
public:
	Student(int x) {
		cout<<"Student::Student(int ) called"<< endl;
	}
};

class TA : public Faculty, public Student {
public:
	TA(int x):Student(x), Faculty(x) {
		cout<<"TA::TA(int ) called"<< endl;
	}
};

int main() {
	TA ta1(30);
	cout<<"X --> A --> Y"<<endl;
	cout<<"X --> B --> Y"<<endl;
	cout<<"Here looks like the problem doesn't arise since we are not calling the parameterized constructor of the\n\
	    	grandparent class. BUT problem exist its just invisible since we are calling default constructor twice.\n\
		If you print something in default constructor, problem will be visible."<<endl;
}

