#include <stdio.h>
#include <math.h>   // ceil()
#include <stdlib.h> // exit()
#include <sys/stat.h>
#include<pthread.h>
void *print()
{
   printf("\nThread Created");
}
int main(int argc, char *argv[]) {
	pthread_t *t;

	struct stat st;
	char part_filename[]="dump.txt";
	FILE *ptr_source, *ptr_part;
	size_t parts, i;
	unsigned long int part_size, written_bytes;
	int byte;
	// ptr_source = fopen("x1.txt", "rb");
	
	if (argc != 3) {
		printf("Usage: %s <Number of threads> <file to split>\n", argv[0]);
		exit(1);
	}

	if ((ptr_source = fopen(argv[2], "rb")) == NULL) {
		perror("Could not open file to split");
		exit(1);
	}
	t=(pthread_t *)malloc(atol(argv[1]+1) * sizeof(pthread_t ));
	stat(argv[2], &st);
	int size = st.st_size;
	printf("size is%d\n",size);
	fseek(ptr_source, 0, SEEK_END);
	part_size = size/atol(argv[1]);
	printf("%ld\n",part_size);
	if (part_size == 0) {
		printf("Invalid part size: %ld\n", part_size);
		exit(1);
	}
	parts = (size_t) ceil((double) ftell(ptr_source) / part_size);
	rewind(ptr_source);

	printf("File will be split into %lu parts.\n", parts);

	for (i = 0; i < parts; i++) {
		printf("\nWriting part%02ld... ", i);
		// sprintf(part_filename, "%s.part%02ld", argv[2], i);
		
		if ((ptr_part = fopen(part_filename, "wb")) == NULL) {
			perror("Could not open part for writing");
			exit(1);
		}
		pthread_create(&t[i],NULL,print,NULL);
		for (written_bytes = 0; written_bytes < part_size &&
		    (byte = fgetc(ptr_source)) != EOF; written_bytes++)
		{
			
			fputc(byte, ptr_part);
			
		}
		pthread_join(t[i],NULL);
		printf("(%lu bytes)", written_bytes);
		fclose(ptr_part);
	}

	printf("\n\nDone!\n");
	fclose(ptr_source);

	return 0;
}