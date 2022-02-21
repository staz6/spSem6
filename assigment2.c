#include <stdio.h>
#include <stdlib.h>
void main(){
	int a=10;
	int b=20;
	int tmp=0;
	printf("a = %d, b = %d\n", a,b);
	// Normal swap implementation
	tmp =a;
	a=b;
	b = tmp;
	printf("Values after normal swap, a = %d, b = %d\n", a,b);

	// Pointer swap
	int *x=&a;
	int *y=&b;
	
	tmp = *x;
   *x = *y;
   *y = tmp;

   printf("Values after pointer swap, a = %d, b = %d\n", a,b);

   

   printf("No reference type in C\n");

   printf("\nMalloc !!!!\n");
   printf("Assign 100 int variable size memory to malloc pointer ptr\n");
   int *ptr = (int*) malloc(100 * sizeof(int));
   int n = 100;
   if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        printf("Memory successfully allocated using malloc.\n");
 		printf("Allocate 1-100 to ptr");
        for (int i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
    printf("\n");

    printf("Calloc !!!!!!!");
    int *callocPtr=(int*)calloc(n, sizeof(int));
    printf("Allocate 100 blocks of int size using calloc\n");

    int i;
        if (callocPtr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            callocPtr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", callocPtr[i]);
        }
    }

    printf("\nusing realloc to reallocate space for 25 float variable in malloc pointer \n");
    ptr = realloc(ptr, 25 * sizeof(float));
    printf("\nUsing free to reallocat memory from malloc and calloc pointer\n");

    free(ptr);
    free(callocPtr);

    printf("\nOne dimensional array implementaion using malloc\n");
    int *mallocPtr = (int*) malloc(100 * sizeof(int));
   n = 100;
   if (mallocPtr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        printf("Memory successfully allocated using malloc.\n");
 		printf("Allocate 1-100 to mallocPtr");
        for (int i = 0; i < n; ++i) {
            mallocPtr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) {
            printf("%d, ", mallocPtr[i]);
        }
    }
    free(mallocPtr);
    
    printf("\nMultidimension array implementaion using malloc\n");
    int r = 3, c = 4;
 
    int* multiArray = malloc((r * c) * sizeof(int));
 
    for (int i = 0; i < r * c; i++)
        multiArray[i] = i + 1;
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", multiArray[i * c + j]);
        printf("\n");
    }
}