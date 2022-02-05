// C program to show input and output

#include <stdio.h>
#include <string.h>
int main()
{

	// Declare string variable
	// as character array
	char str[50]="Hello -world -s";
	printf("\n\nEnter command: ");
	// scanf("%[^\n]\ns", str);

	printf("\nEntered command is: %s\n", str);

	char * token = strtok(str, "-");
	while( token != NULL ) {
      printf( " %s\n", token ); //printing each token
      token = strtok(NULL, " ");
   }


	return 0;
}
