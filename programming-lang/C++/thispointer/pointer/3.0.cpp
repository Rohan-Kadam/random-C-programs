
//Allocating and deallocating 2D arrays dynamically in C and C++

#include <iostream>

using namespace std;

int ** make2d(int row, int col){
	
	//malloc statement: int **p = (int **)malloc(row * sizeof(int))
	int **p = new int*[row];
	for(int i=0; i<row; i++){
		//malloc statement: p[i] = (int *)malloc(col * sizeof(int)) 
		//using same p, one level up
		p[i] = new int[col];
	}
	return p;

}

//pass using **, not using & or &&
void print2d(int **p, int row, int col){
	cout<<"Printing 2d array "<< endl;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			//use i and j 
			cout<<p[i][j]<<" "<<endl;
		}
		cout<<endl;
	}
}

void del2d(int **p, int row, int col){
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			//free statement: free(p[i])
			delete [] p[i];
		}
		//free statement: free(p)
		delete [] p;
	}
}

int main(){
	int row = 2;
	int col = 2;
	int **ptr = make2d(row,col);
	ptr[0][0]=1;
	ptr[0][1]=1;
	ptr[1][0]=1;
	ptr[1][1]=1;

	print2d(ptr,row,col);
	del2d(ptr,row,col);

	return 0;
}
