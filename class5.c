#include <stdio.h>
int main(){

	
	int i = 256;
	char c = 'A';
	char *cp = (char *) &i-4;
	printf("i : %d at %u\n",i,&i);
	printf("c : %d at %u\n",c,&c);

	for(int d=0;d<8;d++){
		printf("%d at %u\n",*cp,cp);
		cp++;
	}
}