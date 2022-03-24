#include<stdio.h>
int main()
{
  struct simp 
  {
    char a,b;
    double c;
    double k;
    char d,y,z;
    int *ptr;t
    struct simp *next;
  };
  struct simp p1;
  printf("%ld\n",sizeof(p1) );
  printf("%ld\n",sizeof(p1.next) );
  return 0;
}