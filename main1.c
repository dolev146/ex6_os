#include "blockqueue.h"
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

// gcc -o main main.c -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <sys/poll.h>
#include <sys/file.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/wait.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

// gcc -o main main.c -lpthread

int main()
{

    int x = 1;
    void *p = &x;

    pthread_t th[6];
    for (int i = 0; i < 6; i++)
    {
        if (i < 4)
        {
            if (pthread_create(&th[i], NULL, &deQ, NULL) != 0)
            {
                printf("Error creating thread\n");
                exit(1);
            }
        }
        else
        {

            if (pthread_create(&th[i], NULL, &enQ, p) != 0)
            {
                printf("Error creating thread\n");
                exit(1);
            }
            p = &i;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            printf("Error joining thread\n");
            exit(1);
        }
    }

    return 0;
}