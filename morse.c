#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "data.h"

FILE *OPENFILE(const char *fname, const char *mode)
/* Open specified file. Provides same functionality as fopen() and plus extra functionality:
  exit() on error and if the file has already existed then ask the users to overwrite or not. */
{
	FILE *fp;
	int check;

	if(!strcmp(mode,"w")){
		fp=fopen(fname,"r");

		if(fp==NULL){
			fclose(fp);
			goto here;
		}
		else{
			printf("WARNING: %s has already exist. Do you wish to overwrite? Yes(1)/No(0): ",fname);
			scanf("%d",&check);
			if(check==1) goto here;
			else exit(0);
		}
	}

	here:
	fp = fopen(fname, mode);
	if (fp == NULL) {
		printf("ERROR: Could not open file %s with mode %s\n",fname, mode);
		exit(0);
	}
	return fp;
}


int TYPE_OF_FILE(const char* fname)
/* 
Determinating type of input file is text file or morse file.
Morse file only contain: white space(" "), dash("-"), slash("/"), dot(".").
*/
{
    FILE *fp;
    char c;
    fp=fopen(fname,"r");
    if(fp == NULL){
        printf("ERROR: Could not open file %s with mode r.\n",fname);  
        exit(2);
    }      
    
    while((c = getc(fp)) != EOF ){
        if(c == '\n')
            continue;
        if((c!='-') && (c!='.') && (c!='/') && (c!=' ')){
            fclose(fp);
            return TEXT;
        }
    }

    fclose(fp);
    return MORSE;
}

void ERROR_MESSAGE(int num, int line_count, FILE *out)
/* This function send a message about error when convert Morse code to text.
 If the character is not in the Morse table, then replace them by character "*"   */
{
    // send a message about error
    printf("ERROR: Invalid Morse code ");
    while(num!=1){
        num%2 ? printf("-") : printf(".");
        num=num/2;
    }
    printf(" on line %d\n",line_count); 

    putc('*',out);    // replace a character that is not in the Morse code 
}

void CONVERT(int num, int k, int line_count, FILE *out)
/* Convert a Morse word to a ASCII character  */ 
{
    int flag=0;
    num=num+k*1;
    for(int i=0;i<ARRAY_SIZE+1;i++){
        if(num == table[i].binary){
            flag=1;
            putc(table[i].ascii,out);
            break;
            }
        }

    if(flag == 0 && num != 1)
        ERROR_MESSAGE(num,line_count,out);
}

void MORSE_TO_TEXT(const char *fin, const char *fout)
/* Convert morse file to text file */
{
    int  num=0,weight=1,flag=0;
    char c;
    int  line_count=1; // count number of line

    FILE *in,*out;
    in  = OPENFILE(fin,"r");
    out = OPENFILE(fout,"w");

    while((c = getc(in)) != EOF){
        if((c == ' ') || (c == '\n'))
            CONVERT(num,weight,line_count,out);   // convert morse code to coresponding word

        if(c == '\n') {
            line_count++;
            putc('\n',out);
        }
        if(c == '-'){
            num = num + weight*1;
            weight*=2;
            continue;
        }
        if(c == '.'){
            num = num + weight*0;
            weight*=2;
            continue;
        }

        if(c == '/'){
            putc(' ',out);
            continue;
        }

        // at the end of each loop, reset the original value of flag, num and weight
        flag=0;      //reset flag
        num=0;       // reset num
        weight=1;    // reset weight digit
    }

    // Print the last character
    CONVERT(num,weight,line_count,out);

    fclose(in);
    fclose(out);
    return;
}

void TEXT_TO_MORSE(const char *fin, const char *fout)
/* Convert text file to morse file  */
{
    char c;
    int  line_count=1;  // variable that use to count number of lines
    int  flag=0;        // using flag to check the character is undefined or not

    FILE *in, *out;
    in = OPENFILE(fin,"r");
    out= OPENFILE(fout,"w");

    while((c = getc(in)) != EOF){
        if(c >= 'a' && c<= 'z') c-=32;   // convert to uppercase 
        if(c == '\n'){
            putc('\n',out);
            line_count++;                // increase the number of line count by 1
            continue;
        }
        if(c == ' '){
            fputs("/ ",out);  // words in morse code are separated by " / "
            continue;
        }
        for(int i=0;i<ARRAY_SIZE;i++){
            if(c == table[i].ascii){
                fputs(table[i].morse,out);
                putc(' ',out);    // the characters in morse code are separated by a space " "
                flag=1;
                break;
            }
        }

        // if a ascii character is undefinded then send an error message
        if(flag==0)
            printf("ERROR: Unrecognised character %c on line %d\n",c,line_count);

        flag=0; //reset flag at the end of each loop
    }

    fclose(in);
    fclose(out);
    return;
}


int main(int argc, char *argv[])
/* Main function */
{    
    int type_check;

    if(argc != 3){
        printf("Usage: morse <inputfile> <outputfile>.");
        exit(1);
    }

    type_check = TYPE_OF_FILE(argv[1]);

    if(type_check == TEXT)
        TEXT_TO_MORSE(argv[1], argv[2]);
    if(type_check == MORSE)
        MORSE_TO_TEXT(argv[1],argv[2]);

    return 0;
}