#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
//#include <unistd.h>
#include <chrono>
#include <thread>
#include <string>

#define PORT    8080 
#define MAXLINE 1024

#define MSG_CONFIRM 0


int main(int argc, char* argv[]) { 
    int sockfd; 
    char buffer[MAXLINE];
    const char *msg = "Hello from client";
    struct sockaddr_in     servaddr; 
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET;  // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT); 


    ssize_t n;
    socklen_t len;
    //unsigned int microseconds;
    unsigned long milliseconds = 200;
    unsigned long seq = 0;
    int n_zero = 8;
    for (int i=0; i<40; ++i)
    {
        seq++;
        char sseq[100];
        sprintf(sseq, "%016lX", seq);
        
        sendto(sockfd, (const char *)sseq, strlen(sseq), MSG_CONFIRM,
            (const struct sockaddr *) &servaddr, sizeof(servaddr));
        printf("Message sent: %s\n", sseq);
        /*std::string sseq = std::to_string(seq);
        sseq = std::string(n_zero - sseq.length(), '0') + sseq;*/
        /*sendto(sockfd, (const char *)sseq.c_str(), sseq.length(), MSG_CONFIRM,
            (const struct sockaddr *) &servaddr, sizeof(servaddr));*/
        /*sendto(sockfd, (const char *)msg, strlen(msg), MSG_CONFIRM,
            (const struct sockaddr *) &servaddr, sizeof(servaddr));*/
        //printf("Message sent: %s\n", sseq.c_str());
        //usleep(microseconds);
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
    /*n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr *) &servaddr, &len); 
    buffer[n] = '\0'; 
    printf("Server : %s\n", buffer);*/
  
    close(sockfd);
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