#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//2:10

static int number;

int rect(int *arr,int n,int count){
    
int start = count;
    for(int i=start; i<((2*n)-1)+count ; i++){
        for(int j=start; j<((2*n)-1)+count ; j++){
    
            if(i==j && i==(n-1) && j==number){
                *(arr+(i*2000)+j) = 1;
            
            } else if(i==start || i==(2*n-2)+count){
                *(arr+(i*2000)+j) = n;
            
            } else if(j==start || j==(2*n-2)+count){
                *(arr+(i*2000)+j) = n;
            
            } else {
                //*(arr+(i*1000)+j) = n;
            }
        }
    }

    ++count;
    if(number%2 == 1 && count==number){
        return 0;

    }else if(number%2 == 0 && count==number){
        return 0;

    }else{    
        rect(arr,n-1,count);
        return 0;
    }
    
}

int main() 
{

    int n;
    scanf("%d", &n);
      // Complete the code to print the pattern.
    int arr[2000][2000];
    number = n;

    if(number > 1000){
        return 0;
    }

    rect(arr,n,0);

    for(int i=0; i<((2*n)-1) ; i++){
        for(int j=0; j<((2*n)-1) ; j++){
 
 
            if(j == ((2*n)-2)){
                printf("%d ",arr[i][j]);
                printf("\n");
            } else{
                printf("%d ",arr[i][j]);
            }
        }
    }
    return 0;
}

