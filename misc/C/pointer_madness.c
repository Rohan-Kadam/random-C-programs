#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

        if(argc != 2){
                printf("Invalid number of arguments\n");
                printf("USAGE: <executable> <file-operation-option>\n\n");
                printf("File operation options are as follows:\n");
		printf("\t(0) Basic Ptr understanding\n");
		printf("\t(1) Ptr to Ptr to Ptr to Int\n");
		printf("\t(2) Ptr to Ptr to Ptr to Int-Array\n");
		printf("\t(3) Array-of-Ptr to Int-Array,Int-Array,Int\n");
		printf("\t(4) Array-of-Ptr to Int-Array-all-elements\n");
		printf("\t(5) Ptr to Array-of-Ptr to Int-Array,Int-Array,Int\n");
		printf("\t(6) Array-of-Ptr to Array-of-Ptr to Int-Array,Int-Array,Int\n");
		printf("\t(7) Ptr-to-Array(Array Pointer) vs Simple-Ptr-to-Array\n");
		printf("\t(8) Pointer to Constant [VALUE CONSTANT]\n");
		printf("\t(9) Constant Pointer [ADDRESS CONSTANT]\n");

                exit(0);
        }
        printf("Number of Args = %d \nExecutable name = %s\n",argc,argv[0]);

	
	int p0 = 10;
	int p0arr[3] = {1,2,3};
	int *p1 = NULL;
	int **p2 = NULL;
	int ***p3 = NULL;

	int p0arr12[3] = {4,5,6};
	int p0arr22[3] = {7,8,9};
	int p02 = 10;
	int *p12arr[3] = {0};
	int **p22 = NULL;
	int **p22arr[3] = {0};

	printf("Address of P0=%p, P1=%p, P2=%p, P3=%p\n\n",&p0,&p1,&p2,&p3);

	if(!strcmp(argv[1],"0"))
        {

		/*
		 * Variables used
		 * int p0 = 10;
		 * int p0arr[3] = {1,2,3};
		 * int *p1 = NULL;
		 * int **p2 = NULL;
		 * int ***p3 = NULL;
		 */

                printf("\nOption 0 Selected\n");
		printf("\n\n0. Basic ptr understanding\n");
                printf("------------------------------------------\n\n");
		printf("Observe &P1, P1, *P1 values carefully, turning 4th arg in below printf to *p1 will seg fault coz no mem allocated\n");

		printf("Address of P0=%p, &P1=%p P1=%p *P1=%p, P2=%p, P3=%p\n\n",&p0,&p1,p1,p1,&p2,&p3);
	
		printf("\n\nOption 0 Complete\n");

       	} else if(!strcmp(argv[1],"1")) {

		/*
		 * Variables used
		 * int p0 = 10;
		 * int p0arr[3] = {1,2,3};
		 * int *p1 = NULL;
		 * int **p2 = NULL;
		 * int ***p3 = NULL;
		 */

		printf("\nOption 1 Selected\n");
		printf("\n\n1. Ptr to Ptr to Ptr to Int\n");
		printf("------------------------------------------\n\n");
		p1 = &p0;
		printf("Pointed P1 to P0 and single deref value = %d %d (p0 value)\n\n",*p1,p1[0]);
		
		p2 = &p1;	
		printf("Pointed P2 to P1 and single deref value = %p %p (p1 value, p1 has address of p0 stored)\n",*p2,p2[0]);
		printf("Pointed P2 to P1 and double deref value = %d %d (p0 value)\n\n",**p2,p2[0][0]);
		
		p3 = &p2;	
		printf("Pointed P3 to P2 and single deref value = %p %p (p2 value, p2 has address of p1 stored)\n",*p3,p3[0]);
		printf("Pointed P3 to P2 and double deref value = %p %p (p1 value, p1 has address of p0 stored)\n",**p3,p3[0][0]);
		printf("Pointed P3 to P2 and triple deref value = %d %d (p0 value)\n\n",***p3,p3[0][0][0]);

       
		printf("\n\nOption 1 Complete\n");

        } else if(!strcmp(argv[1],"2")) {

		/*
		 * Variables used
		 * int p0arr12[3] = {4,5,6};
		 * int p0arr22[3] = {7,8,9};
		 * int p02 = 10;
		 * int *p12arr[3] = {0};
		 * int **p22 = NULL;
		 * int **p22arr[3] = {0};
		 */

		printf("\nOption 2 Selected\n");	
		printf("\n\n2. Ptr to Ptr to Ptr to Int-Array\n");
		printf("------------------------------------------\n\n");
		p1 = &p0arr;
		for(int i=0; i<3; i++){	
			printf("%d. Pointed P1 to P0arr and single deref value = %d %d (p0arr value)\n",
					i+1,*(p1+i),p1[i]);
		}
		printf("\n");
		
		p2 = &p1;
		for(int i=0; i<3; i++){	
			printf("%d. Pointed P2 to P1 and double deref value = %d %d (p0 value)\n",
					i+1,*((*p2)+i),p2[0][i]);
		}
		printf("\n");

		p3 = &p2;
		for(int i=0; i<3; i++){	
			printf("%d. Pointed P3 to P2 and triple deref value = %d %d (p0 value)\n",
					i+1,*((**p3)+i),p3[0][0][i]);
		}
		printf("\n");

                printf("\n\nOption 2 Complete\n");

        } else if(!strcmp(argv[1],"3")) {

		/*
		 * Variables used
		 * int p0arr12[3] = {4,5,6};
		 * int p0arr22[3] = {7,8,9};
		 * int p02 = 10;
		 * int *p12arr[3] = {0};
		 * int **p22 = NULL;
		 * int **p22arr[3] = {0};
		 */

                printf("\nOption 3 Selected\n");

		//Array of pointers
		printf("\n\n3. Array-of-Ptr to Int-Array,Int-Array,Int\n");
		printf("------------------------------------------\n\n");
				p12arr[0] = p0arr12;
		p12arr[1] = p0arr22;
		p12arr[2] = &p02;

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d.%d Pointed P1[0,1,2] to P0arr1,P0arr2,P02 and deref value = %d %d (p0arr value) ",
						i+1,j+1,*((*(p12arr+i))+j),p12arr[i][j]);
				if(i==2 && j>0){
					printf("GARBAGE VALUE\n");
				} else {
					printf("\n");
				}
			}
		}

		printf("We use *((*(p12+i))+j) OR p12[i][j] to get value\
				\n--> p12+i moves in Array of ptr, \
				\n--> * goto address stored in Array of ptr i.e. Array, \
				\n--> +j moves in pointed Array,\
				\n--> * gets value stored in Array\n\n");

		printf("\n");

                printf("\n\nOption 3 Complete\n");

        } else if(!strcmp(argv[1],"4")) {

		/*
		 * Variables used
		 * int p0arr12[3] = {4,5,6};
		 * int p0arr22[3] = {7,8,9};
		 * int p02 = 10;
		 * int *p12arr[3] = {0};
		 * int **p22 = NULL;
		 * int **p22arr[3] = {0};
		 */

                printf("\nOption 4 Selected\n");

		printf("\n\n4. Array-of-Ptr to Int-Array-all-elements\n");
		printf("------------------------------------------\n\n");
		
		p12arr[0] = &p0arr12[0];
		p12arr[1] = &p0arr12[1];
		p12arr[2] = &p0arr12[2];

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d.%d. Pointed P1[0,1,2] to P0arr1's element 0 1 2 and deref value = %d %d (p0arr value) ",
						i+1,j+1,*((*(p12arr+i))+j),p12arr[i][j]);
				if(j==1 || j==2){
					printf("GARBAGE VALUE\n");
				} else {
					printf("\n");
				}
			}
		}
		printf("\n");

                printf("\n\nOption 4 Complete\n");

        } else if(!strcmp(argv[1],"5")) {

		/*
		 * Variables used
		 * int p0arr12[3] = {4,5,6};
		 * int p0arr22[3] = {7,8,9};
		 * int p02 = 10;
		 * int *p12arr[3] = {0};
		 * int **p22 = NULL;
		 * int **p22arr[3] = {0};
		 */

                printf("\nOption 5 Selected\n");

		printf("\n\n5. Ptr to Array-of-Ptr to Int-Array,Int-Array,Int\n");
		printf("------------------------------------------\n\n");
		
		p12arr[0] = p0arr12;
		p12arr[1] = p0arr22;
		p12arr[2] = &p02;
		p22 = &p12arr;
		//Do not do p22 = p12
		//In that case p22 will directly point to whatever p12 is pointing
		//p12->x<-p22 instead of p22->p12->x

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){	
				printf("%d.%d. Pointed P1[0,1,2] to P0arr1,P0arr2,P02 and Pointed P2 to P1 and deref value = %d %d ",
						i+1,j+1,(*((*(p22+i))+j)),p22[i][j]);
				if(i==2 && j>0){
					printf("GARBAGE VALUE\n");
				} else {
					printf("\n");
				}
			}
		}
		printf("\n");

                printf("\n\nOption 5 Complete\n");

        } else if(!strcmp(argv[1],"6")) {
		
		/*
		 * Variables used
		 * int p0arr12[3] = {4,5,6};
		 * int p0arr22[3] = {7,8,9};
		 * int p02 = 10;
		 * int *p12arr[3] = {0};
		 * int **p22 = NULL;
		 * int **p22arr[3] = {0};
		 */


                printf("\nOption 6 Selected\n");

		printf("\n\n6. Array-of-Ptr to Array-of-Ptr to Int-Array,Int-Array,Int\n");
		printf("---------------------------------------------------------\n\n");
		
		p12arr[0] = p0arr12;
		p12arr[1] = p0arr22;
		p12arr[2] = &p02;
		p22arr[0] = p12arr;

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				for(int k=0; k<3; k++){

					if(i==0)
					{
						printf("%d.%d.%d. Pointed P1[0,1,2] to P0arr1,P0arr2,P02 and Pointed P2[0] to P1 and deref value = %d %d ",
							i+1,j+1,k+1,(*((*((*(p22arr+i))+j))+k)),p22arr[i][j][k]);

						if(j==2 && k>0){
							printf("GARBAGE VALUE\n");
						} else {
							printf("\n");
						}

					}

				}
			}
		}


		printf("\nWe use (*((*((*(p22arr+i))+j))+k)) OR p22arr[i][j][k] to get value\
				\n--> p22arr+i moves in 2nd order Array of ptr, \
				\n--> * goto address stored in 2nd order Array of ptr i.e. 1st order Array of ptr, \
				\n--> +j moves in 1st order Array of ptr,\
				\n--> * goto address stored in 1st order Array of ptr i.e. Array, \
				\n--> +k moves in Array,\
				\n--> * gets value stored in Array\n\n");

		printf("\n");


                printf("\n\nOption 6 Complete\n");

        } else if(!strcmp(argv[1],"7")) {

                printf("\nOption 7 Selected\n");		
		
		printf("\n\n7. Ptr-to-Array(Array Pointer) vs Simple-Ptr-to-Array\n");
		printf("---------------------------------------------------------\n\n");
			
		//Pointer to array
		int (*p13)[3] = NULL;
		int *ptr;
		int arr[3] = {11,22,33};
		ptr = arr;
		p13 = arr;

		printf("Pointed P13(Array Pointer/Ptr to Array) to whole Arr and double deref value = %d %d (arr0 value) %d %d (arr1 value) %d %d (arr2 value)\n\n",
				**p13,p13[0][0],*((*p13)+1),p13[0][1],*((*p13)+2),p13[0][2]);
	
		printf("Pointed ptr(Simple Pointer) to Arr's 1st element and single deref value = %d %d (arr2 value) %d %d (arr1 value) %d %d (arr0 value)\n\n",
				*(ptr+2),ptr[2],*(ptr+1),(ptr)[1],*ptr,ptr[0]);
		//NOTE: printing it in reverse order since printf starts executing from end
		//So adding ptr+2 at end increments ptr address before printing ptr and ptr+1
		
                printf("\n\nOption 7 Complete\n");

        } else if(!strcmp(argv[1],"8")) {

                printf("\nOption 8 Selected\n");
			
		printf("\n\n8. Pointer to Constant [VALUE CONSTANT]\n");
		printf("---------------------------------------------------------\n\n");
		
		//Constant pointer
		char a ='A', b ='B'; 
		const char *ptr = &a;

		printf("*ptr(pointed value) cannot be changed\n");
		printf("Commented below line\n*ptr = b;\nillegal statement (assignment of read-only location *ptr\n\n");

		printf("ptr(pointed address) can be changed\n");
		printf( "value pointed to by ptr: %c\n", *ptr);
		ptr = &b;
		printf( "value pointed to by ptr: %c\n", *ptr);

                printf("\n\nOption 8 Complete\n");

        } else if(!strcmp(argv[1],"9")) {

                printf("\nOption 9 Selected\n");
	
		printf("\n\n9. Constant Pointer [ADDRESS CONSTANT]\n");
		printf("---------------------------------------------------------\n\n");

		//Pointer to a constant
		char a ='A', b ='B';
		char *const ptr = &a;

		printf( "Value pointed to by ptr: %c\n", *ptr);
		printf( "Address ptr is pointing to: %d\n\n", ptr);


		printf("ptr(pointed address) cannot be changed\n");
		printf("Commented below line\nptr = &b;\nillegal statement (assignment of read-only variable ptr)\n\n");

		printf("*ptr(pointed value) can be changed\n");
		// changing the value at the address ptr is pointing to
		*ptr = b;
		printf( "Value pointed to by ptr: %c\n", *ptr);
		printf( "Address ptr is pointing to: %d\n", ptr); 
		
                printf("\n\nOption 9 Complete\n");

        } else if(!strcmp(argv[1],"A")) {

                printf("\nOption A Selected\n");
		//Function Pointer

                printf("\n\nOption A Complete\n");
	}

	return 0;
}
