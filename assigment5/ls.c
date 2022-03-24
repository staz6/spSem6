#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
void _ls(const char *dir,int op_a,int op_l,int op_r)
{
	printf("%s",dir);
	//Creating dirent object,
	// The opendir() function opens a directory stream corresponding to the directory named by the dirname argument.
	 // The directory stream is positioned at the first entry. If the type DIR, is implemented using a file descriptor, applications will only be able to open up to a total of {OPEN_MAX} files and directories.
	 // A successful call to any of the exec functions will close any directory streams that are open in the calling process.
	struct dirent *d;
	DIR *dh = opendir(dir);
	// Error handling
	if (!dh)
	{
		if (errno = ENOENT)
		{
			perror("Directory doesn't exist");
		}
		else
		{
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	struct stat sbuf;
	// disk cache
	char *tmp[50];
	int index =0;
	char tmpr[128];

	// Print directory
	while ((d = readdir(dh)) != NULL)
	{
		
		//check for hidden files
		if (!op_a && d->d_name[0] == '.')
			continue;
		tmp[index]=d->d_name;
		index++;
		if(op_r){

			 strcpy(tmpr,dir);
			 strcat(tmpr,"/");
			 strcat(tmpr,d->d_name);
			 printf("%s\n",tmpr);
			 stat(tmpr, &sbuf); 
			 if(sbuf.st_mode && S_ISDIR(sbuf.st_mode)) {
            	 
       		 } 
			// _ls(tmpr,0,0,0);

			
		}
		if(!op_r){
			printf("%s ", d->d_name);
			
		// check for -l
		if(op_l){
			stat(d->d_name, &sbuf);
			printf(" %d ", (int)sbuf.st_nlink);
			printf("%d ",(int)sbuf.st_mode); 
			printf(" %d", sbuf.st_uid);
			printf(" %d", sbuf.st_gid); 
			printf(" %5d", (int)sbuf.st_size);
			printf("\n");
		} 
		}
	}
	if(op_r){
		for(int i=index-1;i>=0;i--){
		printf("%s\n",tmp[i]);
	}
	}
	printf("\n");
}
void find(char* arg){
	// printf("%s",arg);
	int result =  strcmp(arg,"hola");
	// printf("%d",result);
}
void ls_r(char path[]) { 
    DIR * dir; struct dirent * file; struct stat sbuf; 
    char tmp[128]; 
    dir = opendir(path); 
    while(file=readdir(dir)) { 
        if(file->d_name[0] == '.') continue; 
        strcpy(tmp, path); 
        strcat(tmp, "/"); 
        strcat(tmp, file->d_name); 
        //printf("%s\n", tmp); 
        stat(tmp, &sbuf); 
        if(sbuf.st_mode && S_ISDIR(sbuf.st_mode)) {
        	printf("child directory ->"); 
            printf("%s/\n", tmp); 
            ls_r(tmp); 
        } else  
            printf("%s\n", file->d_name); 
    } 
}
int main(int argc, const char *argv[])
{

	if (argc == 1)
	{
		// If no args are giving
		_ls(".",0,0,0);

	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			//Checking if option is passed
			//Options supporting: a, l
			int op_a = 0, op_l = 0, op_r =0;
			char *p = (char*)(argv[1] + 1);
			// printf("%s",p);
			while(*p){
				if(*p == 'a') op_a = 1;
				else if(*p == 'l') op_l = 1;
				else if (*p == 'r') op_r = 1;
				else{
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			if(op_r){
				ls_r(".");
			}
			else{
				_ls(".",op_a,op_l,op_r);
			}
		}
	}
	return 0;
}
