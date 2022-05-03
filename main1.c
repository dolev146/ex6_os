#include "blockqueue.h"
#include "Pipeline.h"
#include "myActiveObject.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// #include <stdlib.h>
// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>

// questions 1,2,3

// 1. implement queue in c with thread-safe using cond()
// first function createQ , create the new queue
// second function destroyQ , destroy the queue
// third function enQ , enqueue the element
// thorth function deQ , dequeue the element
// forth function getQ , get the queue size
// fifth function getQfront , get the front element
// sixth function getQback , get the back element
// you can use pthread_cond_t and pthread_mutex_t
// you may use c++ ... we chose to use c
// so there is no equivalent to new and delete https://stackoverflow.com/questions/2839551/whats-the-equivalent-of-new-delete-of-c-in-c

// int main()
// {
//     int x = 10;
//     void *p = &x;
//     createQ();
//     pthread_t th[12];
//     for (int i = 0; i < 12; i++)
//     {
//         if (i < 2)
//         {
//             if (pthread_create(&th[i], NULL, &deQ, NULL) != 0)
//             {
//                 printf("Error creating thread\n");
//                 exit(1);
//             }
//         }
//         else
//         {
//             if (pthread_create(&th[i], NULL, &enQ, p) != 0)
//             {
//                 printf("Error creating thread\n");
//                 exit(1);
//             }
//             // printf("enQ out side : %d\n", x);
//             x = x + 10;
//             p = &x;
//         }
//     }

//     for (int i = 0; i < 12; i++)
//     {
//         if (pthread_join(th[i], NULL) != 0)
//         {
//             printf("Error joining thread\n");
//             exit(1);
//         }
//     }

//     return 0;
// }

//***********************************************************************************************************
// // gcc -o main main.c -lpthread
// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <sys/mman.h>
// #include <string.h>
// #include <errno.h>
// #include <sys/time.h>
// #include <sys/resource.h>
// #include <sys/wait.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <sys/sem.h>
// #include <sys/msg.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <netdb.h>
// #include <signal.h>
// #include <sys/ioctl.h>
// #include <sys/uio.h>
// #include <sys/poll.h>
// #include <sys/file.h>
// #include <sys/sysinfo.h>
// #include <sys/utsname.h>
// #include <sys/ptrace.h>
// #include <sys/user.h>
// #include <sys/syscall.h>
// #include <sys/mount.h>

// #include <stdio.h>
// // #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <stdbool.h>
// #include <limits.h>
// #include <pthread.h>
// #include "myqueue.h"
// #include <signal.h>
// #define MAX_LIMIT 1024

// #define SERVERPORT 5008
// #define BUFSIZE 1024
// #define SOCKETERROR (-1)
// #define SERVER_BACKLOG 100
// #define THREAD_POOL_SIZE 20

// int counter = 4000;

// pthread_t thread_pool[THREAD_POOL_SIZE];

// typedef struct sockaddr_in SA_IN;
// typedef struct sockaddr SA;

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t stack_mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

// char size_message[1024];
// int server_socket;
// void *handle_connection(void *p_client_socket);
// int check(int exp, const char *msg);
// void *thread_function(void *arg);

// void ctrlc_handler(int num)
// {

//     close(server_socket);
//     printf("server socket finish  %d", server_socket);
// }

// int main(int argc, char **argv)
// {
//     signal(SIGINT, ctrlc_handler);

//     int client_socket, addr_size;
//     SA_IN server_addr, client_addr;

//     // first off we create a bunch of threads
//     for (int i = 0; i < THREAD_POOL_SIZE; i++)
//     {
//         pthread_create(&thread_pool[i], NULL, thread_function, NULL);
//     }

//     check((server_socket = socket(AF_INET, SOCK_STREAM, 0)), "Failed to craete socket");

//     // initialize the adress struct
//     server_addr.sin_family = AF_INET;
//     server_addr.sin_addr.s_addr = INADDR_ANY;
//     server_addr.sin_port = htons(SERVERPORT);

//     check(bind(server_socket, (SA *)&server_addr, sizeof(server_addr)), "Bind Failed!");
//     check(listen(server_socket, SERVER_BACKLOG), "Listen Failed!");

//     while (true)
//     {
//         printf("Waiting for connections... \n");
//         // wait for and eventually accept an incomming connection

//         addr_size = sizeof(SA_IN);
//         check(client_socket = accept(server_socket, (SA *)&client_addr, (socklen_t *)&addr_size), "accept failed");
//         printf("connected! on socket %d \n", client_socket);

//         // do whatever we do with connections.
//         int *pclient = (int *)malloc(sizeof(int));
//         *pclient = client_socket;
//         pthread_mutex_lock(&mutex);
//         enqueue(pclient);
//         pthread_cond_signal(&condition_var);
//         pthread_mutex_unlock(&mutex);
//     }
//     close(server_socket);
//     printf("server socket finish  %d", server_socket);
// }

// void *thread_function(void *arg)
// {
//     while (true)
//     {
//         // mutex and cond are designed to work with each other so it is writen like that so that a mutex will not block
//         // if contition doesnt met
//         int *pclient;
//         pthread_mutex_lock(&mutex);
//         if ((pclient = dequeue()) == NULL)
//         {
//             pthread_cond_wait(&condition_var, &mutex);
//             // try again
//             pclient = dequeue();
//         }
//         pthread_mutex_unlock(&mutex);
//         if (pclient != NULL)
//         {
//             // we have a connection

//             handle_connection(pclient);
//         }
//     }
// }

// int check(int exp, const char *msg)
// {
//     if (exp == SOCKETERROR)
//     {
//         perror(msg);
//         return 1;
//     }
//     return exp;
// }

// void *handle_connection(void *p_client_socket)
// {
//     int client_socket = *((int *)p_client_socket);
//     free(p_client_socket);
//     char client_message[1024];

//     while (true)
//     {

//         bzero(client_message, sizeof(client_message));
//         recv(client_socket, client_message, sizeof(client_message), 0);
//         pthread_mutex_lock(&stack_mutex);

//         if (strncmp(client_message, "PUSH", 4) == 0)
//         {
//             // printf("DEBUG:from client : %s\n", client_message);
//             memcpy(client_message, client_message + 5, MAX_LIMIT - 5);
//             push(client_message);
//             // printf("DEBUG: push good! socket %d\n", client_socket);
//         }
//         else if (strncmp(client_message, "POP", 3) == 0)
//         {

//             // printf("DEBUG: from client : %s \n", client_message);
//             pop();
//             // printf("DEBUG: pop good!\n");
//         }
//         else if (strncmp(client_message, "TOP", 3) == 0)
//         {
//             // printf("DEBUG: from client : %s \n", client_message);
//             char *msg = top();
//             send(client_socket, msg, sizeof(msg), 0);
//             free(msg);
//         }
//         else if (strncmp(client_message, "size", 4) == 0)
//         {
//             // printf("DEBUG: IN SIZE: %s \n", client_message);
//             printf("DEBUG: size call \n");
//             int output = get_size();
//             bzero(client_message, sizeof(client_message));
//             strcat(client_message, "DEBUG:");
//             sprintf(size_message, "%d", output);
//             strncat(client_message, size_message, sizeof(size_message));
//             send(client_socket, client_message, sizeof(client_message), 0);
//         }
//         else if (strncmp(client_message, "exit", 4) == 0)
//         {
//             pthread_mutex_unlock(&stack_mutex);
//             return NULL;
//         }

//         if (strncmp(client_message, "hello from ruby \n", 17) == 0) /* hello from ruby \n */
//         {
//             char buffer_ruby_test[BUFSIZE] = "hi from server ";
//             printf("%s", client_message);
//             send(client_socket, buffer_ruby_test, 1024, 0);
//             bzero(buffer_ruby_test, sizeof(buffer_ruby_test));
//             close(client_socket);
//             pthread_mutex_unlock(&stack_mutex);
//             return NULL;
//         }
//         pthread_mutex_unlock(&stack_mutex);
//     }
//     return NULL;
// }
// *************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>
#define SERVERPORT 5008
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100
#define THREAD_POOL_SIZE 20
#define SHIFT 1

struct sendmsgwithao
{
    char *message;
    int socket;
};

// ceaser cipher
void *ceaser_cipher(void *param)
{
    char *msg = (char *)param;
    int i;
    for (i = 0; i < strlen(msg); i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = msg[i] + SHIFT;
            if (msg[i] > 'z')
            {
                msg[i] = msg[i] - 26;
            }
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = msg[i] + SHIFT;
            if (msg[i] > 'Z')
            {
                msg[i] = msg[i] - 26;
            }
        }
    }
    return NULL;
}

// upper to lower and lower to upper
void *uppertolowerandlowertoupper(void *param)
{
    char *msg = (char *)param;
    int i;
    for (i = 0; i < strlen(msg); i++)
    {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = msg[i] + 32;
        }
        else if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = msg[i] - 32;
        }
    }
    return NULL;
}

void *send_message(void *param)
{
    struct sendmsgwithao *strc = (struct sendmsgwithao *)param;
    char *msg = strc->message;
    int client_socket = strc->socket;
    send(client_socket, msg, strlen(msg), 0);
    free(strc);
    return NULL;
}

pthread_t thread_pool[THREAD_POOL_SIZE];

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

pthread_mutex_t server_mutex = PTHREAD_MUTEX_INITIALIZER;
char client_message[1024];

struct pipeline *pointer_pipeline;
struct activeobject *ao1;
struct activeobject *ao2;
struct activeobject *ao3;

void *handle_connection(void *p_client_socket);
int check(int exp, const char *msg);
void *thread_function_deq(void *arg);

int main(int argc, char **argv)
{
    //
    pthread_mutex_init(&server_mutex, NULL);

    // create a blocked queue
    pmyqueue_t queue1 = createQ();
    // malloc pointer_pipeline
    pointer_pipeline = (struct pipeline *)malloc(sizeof(struct pipeline));
    // malloc ao1
    ao1 = (struct activeobject *)malloc(sizeof(struct activeobject));
    ao1->firstfunc = &ceaser_cipher;
    // malloc ao2
    ao2 = (struct activeobject *)malloc(sizeof(struct activeobject));
    ao2->firstfunc = &uppertolowerandlowertoupper;
    // malloc ao3
    ao3 = (struct activeobject *)malloc(sizeof(struct activeobject));
    ao3->firstfunc = &send_message;
    // set active object to pipeline
    pointer_pipeline->first = ao1;
    pointer_pipeline->second = ao2;
    pointer_pipeline->third = ao3;

    struct parameters *param1 = (struct parameters *)malloc(sizeof(struct parameters));
    param1->queue = queue1;
    param1->element = NULL;

    // deQ(param1);
    // first off we create a bunch of threads
    for (int i = 0; i < THREAD_POOL_SIZE; i++)
    {
        pthread_create(&thread_pool[i], NULL, &thread_function_deq, (void *)param1);
    }
    
    //
    int server_socket, client_socket, addr_size;
    SA_IN server_addr, client_addr;

    check((server_socket = socket(AF_INET, SOCK_STREAM, 0)), "Failed to craete socket");

    // initialize the adress struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVERPORT);

    check(bind(server_socket, (SA *)&server_addr, sizeof(server_addr)), "Bind Failed!");
    check(listen(server_socket, SERVER_BACKLOG), "Listen Failed!");

    while (true)
    {
        printf("Waiting for connections... \n");
        // wait for and eventually accept an incomming connection

        addr_size = sizeof(SA_IN);
        check(client_socket = accept(server_socket, (SA *)&client_addr, (socklen_t *)&addr_size), "accept failed");
        printf("connected! on socket %d \n", client_socket);

        // do whatever we do with connections.
        // handle_connection(client_socket);
        pthread_t t;
        int *pclient = (int *)malloc(sizeof(int));
        *pclient = client_socket;
        struct parameters *enq_args1 = (struct parameters *)malloc(sizeof(struct parameters));
        enq_args1->queue = queue1;
        enq_args1->element = (void *)pclient;
        enQ(enq_args1);
    }

    close(server_socket);
    printf("server socket finish  %d", server_socket);
    pthread_mutex_destroy(&server_mutex);
    return 0;
}

void *thread_function_deq(void *arg)
{
    while (true)
    {
        void *element = deQ(arg);
        handle_connection(element);
    }
}

int check(int exp, const char *msg)
{
    if (exp == SOCKETERROR)
    {
        perror(msg);
        exit(1);
    }
    return exp;
}

void *handle_connection(void *p_client_socket)
{
    int client_socket = *((int *)p_client_socket);
    free(p_client_socket);
    recv(client_socket, client_message, 1024, 0);
    pthread_mutex_lock(&server_mutex);
    // now we will pass the client_message in a pipeline of all three active objects
    // first we will pass it to ceaser cipher
    pthread_t t1;
    struct activeobject *first_ao1 = (struct activeobject *)pointer_pipeline->first;
    pthread_create(&t1, NULL, first_ao1->firstfunc, (void *)client_message);
    pthread_join(t1, NULL);
    pthread_t t2;
    struct activeobject *first_ao2 = (struct activeobject *)pointer_pipeline->second;
    pthread_create(&t2, NULL, first_ao2->firstfunc, (void *)client_message);
    pthread_join(t2, NULL);
    pthread_t t3;
    struct activeobject *first_ao3 = (struct activeobject *)pointer_pipeline->third;
    struct sendmsgwithao *strc = (struct sendmsgwithao *)malloc(sizeof(struct sendmsgwithao));
    strc->message = client_message;
    strc->socket = client_socket;
    pthread_create(&t3, NULL, first_ao3->firstfunc, (void *)strc);
    pthread_join(t3, NULL);
    close(client_socket);
    pthread_mutex_unlock(&server_mutex);
    return NULL;
}
// then we will pass it to upper to lower and lower to upper

// pointer_pipeline->first->firstfunc(client_message);

// pointer_pipeline->first    ->firstfunc(client_message);
// then we will pass it to upper to lower and lower to upper
// ao2->firstfunc(client_message);

// char buffer[BUFSIZE] = "hi from server ";
// printf("%s", client_message);
// send(client_socket, buffer, 1024, 0);
// close(client_socket);
// pthread_mutex_unlock(&server_mutex);
// return NULL;
// }

// gcc -o main main.c -lpthread

// int main()
// {

//*********** run this to see them work  in parallel**************
// https://stackoverflow.com/questions/2353371/how-to-do-an-atomic-increment-and-fetch-in-c
// int index = 0;
// pmyqueue_t queue1 = createQ();
// pmyqueue_t queue2 = createQ();
// struct parameters *enq_args1 = (struct parameters *)malloc(sizeof(struct parameters));
// enq_args1->queue = queue1;
// int a = 1;
// enq_args1->element = &a;
// struct parameters *enq_args2 = (struct parameters *)malloc(sizeof(struct parameters));
// enq_args2->queue = queue2;
// int b = 1;
// enq_args2->element = &b;

// pthread_t th[50];

// for (int i = 0; i < 10; i++)
// {
//     if ((i % 2) == 0)
//     {
//         if (pthread_create(&th[i], NULL, &deQ, enq_args1) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//     }
//     else
//     {
//         if (pthread_create(&th[i], NULL, &deQ, enq_args2) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//     }
// }

// for (int i = 10; i < 50; i++)
// {
//     if ((i % 2) == 0)
//     {
//         if (pthread_create(&th[i], NULL, &enQ, enq_args1) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//         enq_args1->element = &index;
//         __atomic_fetch_add(&index, 1, __ATOMIC_SEQ_CST);
//     }
//     else
//     {
//         if (pthread_create(&th[i], NULL, &enQ, enq_args2) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//         enq_args2->element = &index;
//         __atomic_fetch_add(&index, 1, __ATOMIC_SEQ_CST);
//     }
// }

//*********** run this to see them work not in parallel**************
// for (int i = 0; i < 25; i++)
// {
//     if (i<5)
//     {
//         if (pthread_create(&th[i], NULL, &deQ, enq_args1) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//     }
//     else
//     {
//         if (pthread_create(&th[i], NULL, &enQ, enq_args1) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//     }
// }

// for (int i = 25; i < 50; i++)
// {
//     if (i < 30)
//     {
//         if (pthread_create(&th[i], NULL, &deQ, enq_args2) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }
//     }
//     else
//     {

//         if (pthread_create(&th[i], NULL, &enQ, enq_args2) != 0)
//         {
//             printf("Error creating thread\n");
//             exit(1);
//         }

//     }
// }

// for (int i = 0; i < 50; i++)
// {
//     if (pthread_join(th[i], NULL) != 0)
//     {
//         printf("Error joining thread\n");
//         exit(1);
//     }
// }
// destroyQ(queue1);
// destroyQ(queue2);

//     return 0;
// }