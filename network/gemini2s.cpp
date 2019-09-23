#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT    8080 
#define MAXLINE 1024 
  
#define MSG_CONFIRM 0


int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    struct sockaddr_in servaddr, cliaddr; 
    
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    // Filling server information 
    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY;
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT); 
    
    // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    in_addr_t addr = servaddr.sin_addr.s_addr;
    unsigned short port = ntohs(servaddr.sin_port);
    printf("Server Running  %lu : %u\n", (unsigned long)addr, (unsigned int)port);
    

    socklen_t len;
    ssize_t n;
    while (true)
    {
        n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                    MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
        buffer[n] = '\0'; 
        printf("Client : %s\n", buffer); 

        /*sendto(sockfd, (const char *)hello, strlen(hello),  
            MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len); 
        printf("Hello message sent.\n");*/
    }
    
    return 0; 
} 




/*
Stream multiplexer 

Write a program that reads input from multiple UDP streams and publishes it out to a
single UDP stream. The incoming and outgoing UDP endpoints must be read as program
input (either from the command line or configuration). The messages must be published
in the order in which they are received. Each input stream sends sequenced messages.
Your program must assign every message with another sequence number that gets incremented
while also keeping the sequence number of the incoming message.

While writing code, prefer performance over cross platform compatibility.
Use Google protobuf when possible and define your own messages.

Your program should log to a file or stdout.

Please make sure your program compiles with GCC (on Linux).

Feel free to use STL as supported by your GCC compiler, however using third party libraries
(like boost, Qt, etc.) is prohibited.

Please include the source code and instructions for compiling and running the program.

For example:

Incoming UDP streams: 192.168.9.10:37865,192.168.9.11:37654, 192.168.10.15:28976 Outgoing stream: 192.168.11.155:48763

*/