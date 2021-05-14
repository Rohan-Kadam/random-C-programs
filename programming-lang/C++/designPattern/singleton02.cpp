#include <iostream>

class Singleton
{
public:
	static Singleton& getInstance(); 

private:

	Singleton() {std::cout << "Ctor\n";};
	~Singleton() {std::cout << "Dtor\n";};
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);
};

Singleton& Singleton::getInstance() 
{
	static Singleton instance;
	return instance;
}

int main()
{
	Singleton &s1 = Singleton::getInstance();
	Singleton &s2 = Singleton::getInstance();
	return 0;
}
