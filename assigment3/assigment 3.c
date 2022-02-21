#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convertToDecimal(unsigned int num);
unsigned int decimalToBinary(int decimalnum);

void main(){
	char str[50]="128.11.3.31";
  char str2[50]="128.11.3.31";
	unsigned int tmp;
	long result;
	int index =0;
	char * token = strtok(str, ".");
	while( token != NULL ) {
      tmp =decimalToBinary(atoi(token));
      printf("%d.",tmp);
      // int x = convertToDecimal(decimalToBinary(atoi(token)));

      // printf("%d.",x);
      token = strtok(NULL, ".");
   }
  printf("\n%s",str2);
}

unsigned int decimalToBinary(int decimalnum)
{
    int binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return (unsigned int)binarynum;
}

int convertToDecimal(unsigned int num) {
  int dec = 0, i = 0, rem,temp=1;

  while (num!=0) {
    rem = num % 10;
    num /= 10;
    dec = dec +rem*temp;
    temp=temp*2;
  }

  return dec;
}