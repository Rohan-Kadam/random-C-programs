/*
 * Polymorphism is a feature of OOPs that allows the object to behave differently in different conditions
 *
 * Type 1
 * Compile Time Polymorphism = Static binding = Early binding = Function overloading = Operator overloading
 *
 * Return type doesn't matter in overloading, only func arguments matter (number of args, type of args, seq of args)
 */


#include <iostream>
using namespace std;
class Addition {
public:
    int sum(int num1,int num2) {
        cout<<"f1"<<endl;
	return num1+num2;
    }
    int sum(int num1,int num2, int num3) {
	cout<<"f2"<<endl;
       	return num1+num2+num3;
    }
    int sum(double num1,int num2, int num3) {
	cout<<"f3"<<endl;
       	return num1+num2+num3;
    }
    int sum(float num1,int num2, int num3) {
	cout<<"f4"<<endl;
       	return num1+num2+num3;
    }
};
int main(void) {
    Addition obj;
    cout<<obj.sum(20, 15)<<endl;
    cout<<obj.sum(81, 100, 10)<<endl;
    cout<<obj.sum(81.5, 100, 10)<<endl;
    cout<<obj.sum(81.5f, 100, 10)<<endl;
    return 0;
}
