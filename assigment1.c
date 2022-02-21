// C program to show input and output

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool compare(char *str1,char *str2);
int main()
{
	// input code for production, commenting it otherwise development take too much time
	char str[50];
	printf("\n\nEnter command: ");
	scanf("%[^\n]\ns", str);
	
	// Development code
	// char str[50]="ls-l-a";
	
	int index=0;
	char *array[2];


	printf("\nEntered command is: %s\n", str);
	char * token = strtok(str, "-");
	while( token != NULL ) {
      // printf( " %s\n", token );
		if(strcmp(token,"ls")==0){
    printf("RETURNS ALL FILES IN THE DIRECTORY");
    printf("\n");
}
else if(strcmp(token,"cp")==0){
    printf("COPY A FILE");
    printf("\n");
}else  if(strcmp(token,"rm")==0){
    printf("REMOVE FILES IN A DIRECTORY");
    printf("\n");
}else if(strcmp(token,"mkdir")==0){
    printf("CREATES FOLDAER OR DIRECTORY");
    printf("\n");
}else if(strcmp(token,"rmdir")==0){
    printf("DELETES AN EMPTY DIRECTORY");
    printf("\n");
}else if(strcmp(token,"pwd")==0){
    printf("RETURNS THE USER DIRECTORY");
    printf("\n");
}else if(strcmp(token,"cd")==0){
    printf("GO TO A PARTICULAR DIRECTORY");
    printf("\n");
}else  if(strcmp(token,"mv")==0){
    printf("MOVE A FILE");
    printf("\n");
}else  if(strcmp(token,"man")==0){
    printf("USED TO DISPLAY THE USER MANUAL OF ANY COMMAND");
    printf("\n");
}else  if(strcmp(token,"help")==0){
    printf("GIVE COMPELTE USAGE OF A PARTICULAR COMMAND");
    printf("\n");
}else if (strcmp(token,"a")==0){
    printf("RETURNS ALL THE HIDDEN FILES IN THE DIRECTORY");
    printf("\n");
}else if(strcmp(token,"l")==0){
    printf("SHOWS DETAILED DESCRIPTION OF FILE ");
    printf("\n");
}else  if(strcmp(token,"r")==0){
    printf("RECURSIVELLY LIST ALL SUBDIRECTORIES AND THEIR FILE");
    printf("\n");
}
else printf("wrong command\n");

      token = strtok(NULL, "-");

   }


	return 0;
}
