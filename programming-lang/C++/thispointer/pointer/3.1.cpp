
// 3d array
#include <iostream>

using namespace std;

int *** allocateThreeDimenArrayOnHeapUsingNew(int row, int col, int z)
{
	int *** ptr = new int**[row];

	for(int i = 0; i < row; i++)
	{
		ptr[i] = new int*[col];
		for(int j = 0; j < col; j++)
		{
			ptr[i][j] = new int[z];
		}
	}

	ptr[0][0][0] = 1;
	ptr[0][0][1] = 2;
	ptr[0][1][0] = 3;
	ptr[0][1][1] = 4;
	ptr[0][2][0] = 5;
	ptr[0][2][1] = 6;

	ptr[1][0][0] = 11;
	ptr[1][0][1] = 12;
	ptr[1][1][0] = 13;
	ptr[1][1][1] = 14;
	ptr[1][2][0] = 15;
	ptr[1][2][1] = 16;

	return ptr;
}

int main()
{

int *** ptr = allocateThreeDimenArrayOnHeapUsingNew(2,3,2);

for(int i = 0; i < 2; i++)
{
	for(int j = 0; j < 3; j++)
	{
		std::cout<<"(";
		for(int k = 0; k < 2; k++)
		{
			std::cout<<ptr[i][j][k]<<",";
		}
		std::cout<<"),";
	}
	std::cout<<std::endl;
}

return 0;
}

