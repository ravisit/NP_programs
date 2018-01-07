#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#include<sys/socket.h> 
#include<sys/types.h> 
#include<netinet/in.h> 
#include<arpa/inet.h> 

main() 
{ 
	int std,  len, choice, i,j,status,sendsize,port,recvsize,temp1; 
	char str[20], frame[20], temp[20], ack[20],sendwin[20]; 
	char *msg="network programming";
	struct sockaddr_in saddr, caddr; 
	port=5000;
	std = socket(AF_INET, SOCK_STREAM, 0); 
	
	if(std<0) perror("Error");
	
	bzero(&saddr, sizeof(saddr)); 
	saddr.sin_family = AF_INET; 
	saddr.sin_addr.s_addr=inet_addr("226.1.1.1"); 
	saddr.sin_port = htons(port); 
	connect(std, (struct sockaddr *)&saddr, sizeof(saddr)); 
	printf("\n msg= %s ",msg);
	printf("\n len = %d ",strlen(msg));
	i = 0;
	sendsize=5; 
	while(i<strlen(msg)) 
	{ 
        //sender
        memset(frame, 0, 20); 
        strncpy(frame, msg+i, sendsize); 
        printf("\n\nSending frame = %s , Sending WINDOW: start seqno= %d -  end seqno= %d  ",frame ,i , i+sendsize-1 );
        send(std, frame, strlen(frame), 0) ;
        i=i+sendsize;
  	
	} /*END OF WHILE*/
	write(std, "Exit", sizeof("Exit")); 
	printf("\nExitting!\n"); 
	close(std); 
}
