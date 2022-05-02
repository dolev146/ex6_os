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
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/syscall.h>
#include <sys/mount.h>

// gcc -o main main.c -lpthread

int main()
{

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
    return 0;
}