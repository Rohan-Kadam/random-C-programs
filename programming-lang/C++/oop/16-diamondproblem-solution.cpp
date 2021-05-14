/*
 *
 * The solution to Diamond problem is ‘virtual’ keyword. 
 * We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class.
 *
 * In the below program, constructor of ‘Person’ is called once. One important thing to note in the above output is, the default constructor 
 * of ‘Person’ is called. When we use ‘virtual’ keyword, the default constructor of grandparent class is called by default even if the parent
 * classes explicitly call parameterized constructor. 
 *
 */

#include<iostream>
using namespace std;
class Person {
public:
	Person(int x) { cout << "Person::Person(int ) called" << endl; }
	Person()	 { cout << "Person::Person() called" << endl; }
	~Person()  { cout << "INSIDE destructor" << endl; }

};

class Faculty : virtual public Person {
public:
	Faculty(int x):Person(x) {
	cout<<"Faculty::Faculty(int ) called"<< endl;
	}
	~Faculty() {
		cout<<"INSIDE faculty"<<endl;
	}


};
/*
class Student : virtual public Person {
public:
	Student(int x):Person(x) {
		cout<<"Student::Student(int ) called"<< endl;
	}
	~Student() {
		cout<<"INSIDE student"<<endl;
	}


};
*/
class TA : public Faculty {
public:
	TA(int x): Faculty(x) {
		cout<<"TA::TA(int ) called"<< endl;
	}
};

int main() {
	TA ta1(30);
	delete &ta1;
}

