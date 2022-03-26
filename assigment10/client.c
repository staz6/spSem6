

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fd = 0;
	char buff[1024];
	printf("input");
	memset(buff, '0',sizeof(buff));	

	fd = socket(AF_INET, SOCK_STREAM, 0);
    	if(fd<0)
	{
		perror("Connection not created");
		return 0;
	}
	
	struct sockaddr_in server; 
	memset(&server, '0', sizeof(server)); 

	server.sin_family = AF_INET;
	server.sin_port =  htons(atoi(argv[2]));

	int in = inet_pton(AF_INET, argv[1], &server.sin_addr);
	if(in<0)
	{
		perror("Ip not found");
		return 0;
	}

	in = connect(fd, (struct sockaddr *)&server, sizeof(server));
	if(in<0)
	{
		perror("Connection failed");
		return 0;
	}    	

	while(1)
	{
		printf("Please enter the message: ");
    		bzero(buff,256);
    		fgets(buff,255,stdin);
    		
		    printf("\nSending to SERVER: %s ",buff);
	
    		in = send(fd,buff,strlen(buff),0);
		    if (in < 0) 
		    {
			 perror("\nClient Error: Writing to Server");
		    	return 0;
		    }
		    
		    bzero(buff,256);
		    in = recv(fd,buff,255,0);
		    if (in < 0) 
		    {
			 perror("\nClient Error: Reading from Server");
			return 0;
		    }
		    printf("\nReceived FROM SERVER: %s ",buff);
	}
	close(fd);
	return 0;
}
