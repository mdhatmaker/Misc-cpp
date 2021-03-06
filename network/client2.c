#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>

#define MAX 80 
#define PORT 8888 
#define SA struct sockaddr

void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
} 

void process_file(char *filename)
{
    FILE *fptr;
    char txt1[256], txt2[256];
    char ch;
 
    /*  open the file for reading */
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    fscanf(fptr, "%s %s", txt1, txt2);
    printf("%s %s\n", txt1, txt2);
    int res = fscanf(fptr, "%s", txt1);
    while (res != EOF)
    {
        unsigned long timestamp = atol(txt1);
        printf("%lu %s %lu\n", strlen(txt1), txt1, timestamp);
        // check timestamp here
        res = fscanf(fptr, "%s", txt1);
    }
    /*ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }*/
    fclose(fptr);
}

int main() 
{ 
    process_file("./data/samplein1.txt");
    exit(1);

    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;

    char buff[MAX];

    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
    {
        printf("connected to the server..\n"); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
    }

    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 