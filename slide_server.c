
#include<string.h>
#include<sys/types.h> 
#include<netinet/in.h> 
#include<arpa/inet.h> 
#include <time.h>
#define RECVBUF 20
main() 
{ 
	int sockfd, lfd, len, port, i, j, status, choice; 
	char str[20], str1[20], err[20], ack_str[20];
	int ack,sendsize=5; 
	char frame[20],frame1[20];
	char *recv_str;
	recv_str=malloc(50);
	memset(recv_str, 0, 20);
	
	struct sockaddr_in saddr, caddr;
	//srand(time(NULL));
	port=5000;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int yes=1;
	//if(sockfd<0) perror("Error");
	
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,sizeof(int)); 
	
	 
	bzero(&saddr, sizeof(saddr)); 
	saddr.sin_family = AF_INET; 
	saddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	saddr.sin_port = htons(port);
	 
	 bind(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)); 

	
	listen(sockfd, 5); 

	len = sizeof(&caddr); 
	lfd = accept(sockfd, (struct sockaddr *)&caddr, &len); 
		while(1) 
		{ 
			//media
			memset(frame, 0, 20); 
			recv(lfd, frame, 5, 0) ;
			
			if(strcmp(frame, "Exit") == 0) break;
			
			printf("\n\nReceving frame (SUCCESS ) = %s   ,Receiving WINDOW: start seqno= %d -  end seqno= %d   ",frame, i, i+ sendsize-1);
			recv_str=(char*) strcat(recv_str,frame);
			i=i+ sendsize;

			if(i==20) break;
		} /*END OF FOR*/
	printf("\nReceived Final str at Destination = %s \n ", recv_str);
	close(sockfd);
} 
