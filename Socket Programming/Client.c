#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc , char *argv[])
{

    //socket 的建立
    int sockfd = 0;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1){
        printf("Fail to create a socket.");
    }

    //socket connecting to server
    struct sockaddr_in info;
    memset(&info, 0, sizeof(info));
    /* non-standard function
    * bzero(&info, sizeof(info));
    */
    info.sin_family = PF_INET;
    //localhost test
    inet_pton(AF_INET, "127.0.0.1", &info.sin_addr);
    //info.sin_addr.s_addr = inet_addr("127.0.0.1");
    //e.g., port 8700
    info.sin_port = htons(8700);
    int err = connect(sockfd, (struct sockaddr *)&info, sizeof(info));
    if(err == -1){
        printf("Connection error\n");
    }


    //Send a message to server
    char message[] = {"Hi there"};
    char receiveMessage[4096] = {};
    send(sockfd, message, sizeof(message), 0);
    int err_num = recv(sockfd, receiveMessage, sizeof(receiveMessage), 0);
    if (err_num == -1) {
        fprintf(stderr, "Value of errno: %d\n", errno);
        fprintf(stderr, "Error: %s\n", strerror(errno));
    }
    printf("%s", receiveMessage);
    printf("close Socket\n");
    close(sockfd);
    return 0;
}