#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc , char *argv[])
{
    //create a socket
    char inputBuffer[4096] = {};
    char message[] = {"Hi,this is server.\n"};
    int sockfd = 0;
    int forClientSockfd = 0;
    // TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1){
        printf("Fail to create a socket.\n");
    }

    //server configuration
    struct sockaddr_in serverInfo;
    struct sockaddr_in clientInfo;
    socklen_t addrlen = sizeof(clientInfo);
    memset(&serverInfo, 0, sizeof(serverInfo));
    /* non-standard function
    * bzero(&serverInfo, sizeof(serverInfo));
    */
    
    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr.s_addr = INADDR_ANY;
    //e.g., port 8700
    serverInfo.sin_port = htons(8700);
    //bind the address and the port to socket
    bind(sockfd, (struct sockaddr *)&serverInfo, sizeof(serverInfo));
    //listen clients 
    listen(sockfd, 5);
    int err_num;
    while(1){
        forClientSockfd = accept(sockfd, (struct sockaddr*) &clientInfo, &addrlen);
        send(forClientSockfd, message, sizeof(message), 0);
        err_num = recv(forClientSockfd, inputBuffer, sizeof(inputBuffer), 0);    
        if (err_num == -1) {
            fprintf(stderr, "Value of errno: %d\n", errno);
            fprintf(stderr, "Error: %s\n", strerror(errno));
        }

        printf("Get:%s\n", inputBuffer);
    }
    return 0;
}