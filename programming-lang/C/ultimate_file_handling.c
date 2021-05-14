#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){

	if(argc != 2){
		printf("Invalid number of arguments\n");
		printf("USAGE: <executable> <file-operation-option>\n\n");
		printf("File operation options are as follows:\n");
		printf("\t(1) = RW txt file using putc/getc\n");
		printf("\t(2) = RW txt file using fprintf/fscanf/fgets\n");
		printf("\t(3) = RW txt file using fseek/ftell/rewind\n");
		printf("\t(4) = RW bin file using fread/fwrite\n");
		printf("\t(5) = Explore RW using fread/fwrite on txt file\n");		
		printf("\t(6) = Explore RW using putc/getc on bin file\n");
		printf("\t(7) = Explore RW using fprintf/fscanf/fgets on bin file\n");
		printf("\t(8) = Explore RW using fseek/ftell/rewind on bin file\n");
		printf("\t(9) = What is Purging and Flushing and when to use it\n");

		exit(0);
	}
	printf("Number of Args = %d \nExecutable name = %s\n",argc,argv[0]);

	
	//FILE *file-pointer* is defined in stdio.h, it uses _IO_FILE struct.
	FILE *fp;

	if(!strcmp(argv[1],"1"))
	{
		printf("\nOption 1 Selected\n");		
		printf("(1) = RW txt file using putc/getc\n");
		//Write Txt File using putc
		//---------------------------------------------------------
		char ch;
		fp = fopen("sample.txt", "w");
		printf("Enter data: \n");
		printf("Note: Press Ctrl+D twice to send EOF\n");
		while( (ch = getchar()) != EOF) {
			putc(ch,fp);
		}
		fclose(fp);


		//Read Txt File using getc
		//---------------------------------------------------------
		fp = fopen("sample.txt", "r");
		printf("\n\nPrinting file content: \n");
		ch = getc(fp);
		while( (ch != EOF)) {
			putc(ch, stdout);
			//or use printf instead of putc
			//printf("%c",ch);
			ch = getc(fp);
		}
		fclose(fp);
		//NOTE:
		//Using getc is okay.
		//But gets is dangerous, so instead use fgets as it protects us from buffer overflow attacks. 
		//fgets syntax:
		//char* fgets(char *string, int length, FILE * stream);
		//fgets is BEST READ METHOD to read stream(file,stdin,..) to string
	
		printf("\n\nOption 1 Complete\n");

	} else if(!strcmp(argv[1],"2")) {

		printf("\nOption 2 Selected\n");		
		printf("(2) = RW txt file using fprintf/fscanf/fgets\n");
		
		//Write Txt File using fprintf [BEST write for txt]
		//---------------------------------------------------------
		printf("Entering data:\nRohan <adding-2-spaces-inbetween> 123\n");
		fp = fopen("sample.txt", "w");
		//Using option a instead of w won't reset the file.
		//fp = fopen("sample.txt", "a");
		fprintf(fp,"%s <adding-2-spaces-inbetween> %d", "Rohan", 123);
		fclose(fp);


		//Read Txt File using fscanf
		//---------------------------------------------------------
		char name[10];
		int age;
		printf("\nPrinting file content: \n");
		fp = fopen("sample.txt", "r");
		printf("1-- Normal scanf\n");
		do
		{
			
			fscanf(fp,"%s", name);
			printf("%s",name);
		}
		while( !feof(fp) );
		fclose(fp);

		fp = fopen("sample.txt", "r");
		printf("\n\n2 -- Spl scanf with whitespace\n");
		printf("Note: Disabling this scanf will remove stack smashing detected (i.e. buffer overflow attack) warning at the end\n");
		do
		{
			//%[^\n]s is example of inverted scanset, 
			//so scanf keeps taking in values until it encounters a '\n'-- newline
			//So spaces get saved as well
			fscanf(fp,"%[^\n]s", name);
			printf("%s",name);
		}
		while( !feof(fp) );
		fclose(fp);

		fp = fopen("sample.txt", "r");
		printf("\n\n3 -- Spl scanf with whitespace and buffer overflow protection\n");
		do
		{
	
			fscanf(fp,"%10[^\n]s", name);
			printf("%s",name);
		}
		while( !feof(fp) );
		fclose(fp);

		//NOT RECOMMENDED
		//fgets is BEST READ METHOD to read stream(file,stdin,..) to string

		//Read Txt File using fgets [BEST read for txt]
		//---------------------------------------------------------
		printf("\n\n*** FGETS IS THE BEST ***\n");
		char buf[50];
		fp = fopen("sample.txt", "r");	
		fgets(buf, 50, fp); 
		printf("string is: %s\n", buf); 		
		fclose(fp);
		
		printf("\n\nOption 2 Complete\n");

	} else if(!strcmp(argv[1],"3")) {

		printf("\nOption 3 Selected\n");		
		printf("(3) = RW txt file using fseek/ftell/rewind\n");
		
		//ftell fseek rewind example
		//---------------------------------------------------------
		//NOTE:
		//
		//fseek() - It is used to move the reading control to different positions using fseek function.
		//ftell() - It tells the byte location of current position of cursor in file pointer.
		//rewind() - It moves the control to beginning of the file.
		//
		///. macro values for lseek(2) 
		//#define SEEK_SET    0   // set file offset to offset 
		//#define SEEK_CUR    1   // set file offset to current plus offset 
		//#define SEEK_END    2   // set file offset to EOF plus offset 
		
		char data[60];
		fp = fopen("sample.txt", "rw");
		printf("Entered data: Virtual Technotes is a programming tutorial website \n");
		fputs("Virtual Technotes is a programming tutorial website", fp);	

		printf("\n\nPrinting file content: \n");		
		fgets ( data, 60, fp );
		printf("Before fseek => %s\n\n", data);

		//To set file pointet to 21th byte/character in the file
		fseek(fp, 21, SEEK_SET);
		//fflush(data);
		fgets ( data, 60, fp );
		printf("After SEEK_SET to 21 => %s\n\n", data);

		// To find backward 10 bytes from current position
		fseek(fp, -10, SEEK_CUR);
		//fflush(data);
		fgets ( data, 60, fp );
		printf("After SEEK_CUR to -10 => %s\n\n", data);

		// To find 7th byte before the end of file
		fseek(fp, -7, SEEK_END);
		//fflush(data);
		fgets ( data, 60, fp );
		printf("After SEEK_END to -7 => %s\n\n", data);

		// To set file pointer to the beginning of the file
		fseek(fp, 0, SEEK_SET); // We can use rewind(fp); also

		// Moving pointer to end 
		fseek(fp, 0, SEEK_END); 
	      
		// Printing position of pointer 
		printf("Pointer position after SEEK_END = %ld", ftell(fp)); 

		printf("\n\nOption 3 Complete\n");
	
	} else if(!strcmp(argv[1],"4")) {

		printf("\nOption 4 Selected\n");		
		printf("(4) = RW bin file using fread/fwrite\n");

		//Write Bin File using fwrite
		//---------------------------------------------------------
		int num = 100;
		fp = fopen("sample.bin","wb");
		fwrite(&num, sizeof(num), 1, fp);		
		printf("Entered data: 100 \n");
		fclose(fp); 
		//NOTE:
		//fwrite syntax
		//fwrite(addressData, sizeData, numbersOfSuchTypeOfData, pointerToFile);


		//Read Bin File using fread
		//---------------------------------------------------------
		int n;
		fp = fopen("sample.bin","rb");
		printf("\n\nPrinting file content: \n");
		for(n = 1; n <= 1; ++n)
		{
			fread(&n, sizeof(n), 1, fp);
			printf("n = %d", n);
		}
		fclose(fp);
		//NOTE:
		//fread syntax
		//fread(addressData, sizeData, numbersOfSuchTypeOfData, pointerToFile);

		printf("\n\nOption 4 Complete\n");

	} else if(!strcmp(argv[1],"5")) {

		printf("\nOption 5 Selected\n");		
		printf("(5) = Explore RW using fread/fwrite on txt file\n");
		
		//Write Bin File using fwrite
		//---------------------------------------------------------
		int num = 100;
		fp = fopen("sample.txt","w");
		fwrite(&num, sizeof(num), 1, fp);		
		printf("Entered data: 100 \n");
		fclose(fp); 
		//NOTE:
		//fwrite syntax
		//fwrite(addressData, sizeData, numbersOfSuchTypeOfData, pointerToFile);


		//Read Bin File using fread
		//---------------------------------------------------------
		int n;
		fp = fopen("sample.txt","r");
		printf("\n\nPrinting file content: \n");
		for(n = 1; n <= 1; ++n)
		{
			fread(&n, sizeof(n), 1, fp);
			printf("n = %d", n);
		}
		fclose(fp);
		//NOTE:
		//fread syntax
		//fread(addressData, sizeData, numbersOfSuchTypeOfData, pointerToFile);

		printf("\n\nOption 5 Complete WORKS!!!\n");

	} else if(!strcmp(argv[1],"6"))	{
		printf("\nOption 6 Selected\n");		
		printf("(6) = Explore RW using putc/getc on bin file\n");
		//Write Txt File using putc
		//---------------------------------------------------------
		char ch;
		fp = fopen("sample.bin", "wb");
		printf("Enter data: \n");
		printf("Note: Press Ctrl+D twice to send EOF\n");
		while( (ch = getchar()) != EOF) {
			putc(ch,fp);
		}
		fclose(fp);


		//Read Txt File using getc
		//---------------------------------------------------------
		fp = fopen("sample.txt", "rb");
		printf("\n\nPrinting file content: \n");
		ch = getc(fp);
		while( (ch != EOF)) {
			putc(ch, stdout);
			//or use printf instead of putc
			//printf("%c",ch);
			ch = getc(fp);
		}
		fclose(fp);
		//NOTE:
		//Using getc is okay.
		//But gets is dangerous, so instead use fgets as it protects us from buffer overflow attacks. 
		//fgets syntax:
		//char* fgets(char *string, int length, FILE * stream);
		//fgets is BEST READ METHOD to read stream(file,stdin,..) to string
	
		printf("\n\nOption 6 Complete [X] DOESN'T WORKS [X]\n");

	} else if(!strcmp(argv[1],"7")) {
	
		printf("\nOption 7 Selected\n");
		printf("(7) = Explore RW using fprintf/fscanf/fgets on bin file\n");
		printf("\nfgets() is intended to be used to read lines from a text stream. It no longer works when character other than '\n' is used as the delimiter. Byte stream has no delimeter hence it can't be used in to read it\n");
		printf("fscanf might seem to work but here's the problem \nhttps://stackoverflow.com/questions/28506570/can-i-use-fscanf-with-binary-files-in-the-c-language\n");

		printf("\n\nOption 7 Complete [X] DOESN'T WORKS [X]\n");
	
	}else if(!strcmp(argv[1],"8")) {

		printf("\nOption 8 Selected\n");
		printf("(8) = Explore RW using fseek/ftell/rewind on bin file\n");
		printf("\nYou can move around with fseek(), but you can't 'insert' easily -- you can only overwrite, not insert or delete. Oh, and fseek(fp, -1L, SEEK_CUR); seeks back one character on civilized systems (meaning Unix-like systems). On systems where text and binary files are different (Windows), then there are a whole raft of issues related to the way CRLF line endings are managed and the constraint you quote is technically applicable (Standard C says so). I think POSIX partially or wholly lifts those restrictions (if only because it doesn't recognize text files as different from binary files).\n\n");

		printf("\nCheck out Option 3, with minor changes\n");
		printf("- Change file extension to bin\n");
		printf("- need to open/close file twice. First in wb mode then in rb mode. In current option 3 example for text file, file is opened in rw mode\n");
		
		printf("\n\nOption 8 Complete WORKS!!!\n");

	}else if(!strcmp(argv[1],"9")) {

		printf("\nOption 9 Selected\n");
		printf("(9) = What is Purging and Flushing and when to use it\n");
		
		printf("\nFor fflush(), the data is forced to be written to disk.\nFor fpurge(), data is discarded.\n\n");
		printf("NOTE:\n");
		printf("- fflush syntax is int fflush(FILE *ostream);\nIt shouldn't used for clearing stdin as behavior is undefined.\n");
		printf("- fpurge/__fpurge is not a C standard function and not portable across systems\n\n");
		printf("USE:\n");
		printf("- Use of fflush, to complete incomplete printf during loops/crashes/multhreading");
		printf("- Use of fpurge, to discard pending data for some reason......? \n\n");

		printf("EXAMPLE:\n");
		printf("Running an example. Check the code and the myfile content\n");
		char *bufflush="data will be written into file";
		char *bufpurge="data will be not written into file";
		FILE *fp=fopen("./myfile","a");
		if(NULL==fp){
			perror("failed to open file\n");
			exit(0);
		}
		fwrite(bufflush,strlen(bufflush),1,fp);
		fflush(fp);
		fwrite(bufpurge,strlen(bufpurge),1,fp);
		errno=0;
		__fpurge(fp);
		if(errno!=0)
			perror("call __fpurge() failed\n");
		fclose(fp); 
		printf("\n\nOption 9 Complete WORKS!!!\n");
	}

	return 0;
}

