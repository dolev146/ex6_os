#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
// #include <stdlib.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close
#include <pthread.h>
#include <assert.h>

void *cientThread(void *arg)
{
    printf("In thread\n");
    char message[1024];

    char buffer[1024];
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Create the socket.
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure settings of the server address
    // Address family is Internet
    serverAddr.sin_family = AF_INET;

    // Set port number, using htons function
    serverAddr.sin_port = htons(5009);

    // Set IP address to localhost
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Connect the socket to the server using the address
    addr_size = sizeof serverAddr;
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, addr_size))
    {
        perror("connect\n");
        return NULL;
    }
    strcpy(message, "HAL");

    // for (int i = 0; i < 1000; i++)
    // {
    send(clientSocket, message, strlen(message), 0);

    // }
    // printf("finished pushing 100 \n");

    bzero(message, sizeof(message));

    if (recv(clientSocket, message, 1024, 0) < 0)
    {
        printf("Recv failed\n");
    }
    printf("message recieved  %s\n", message);
    // printf("%s\n", message);

    close(clientSocket);
    pthread_exit(NULL);
}

int main()
{
    int i = 0;
    pthread_t tid[5];
    while (i < 4)
    {
        if (pthread_create(&tid[i], NULL, cientThread, NULL) != 0)
            printf("Failed to create thread\n");
        usleep(5000);
        i++;
    }
    sleep(3);
    i = 0;
    while (i < 4)
    {
        pthread_join(tid[i++], NULL);
        printf("thread end number %d:\n", i);
    }

    return 0;
}