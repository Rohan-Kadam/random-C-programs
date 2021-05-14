#include <iostream>

using namespace std;

int main()
{
    try
    {
       throw 10;
    }
    catch (int param)
    {
        cout << "int exception\n";
    }
    catch (...)
    {
        cout << "default exception\n";
    }

    return 0;
}

