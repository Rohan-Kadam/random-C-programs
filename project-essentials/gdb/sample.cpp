#include <iostream>

using namespace std;

void t();

void func(int sum){
	cout<< "In func"<< endl;
}

int main(){

	int a=2,b=4;
	static int sum;
	sum = a + b;
	func(sum);
	t();
	func(a);
	cout<< "Sum = "<< sum<< endl;

	return 0;
}
