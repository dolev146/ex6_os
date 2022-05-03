#ifndef PIPLINE_H
#define PIPLINE_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include "myqueue.h"

// make a struct to store the information of the pipeline
// the pipeline will contain three active objects
// the first one will get the data from the socket
// and then it will provoke its functions to use Keisar encrypter
// the second one will get the data from the Keisar encrypter , and then it will
// tranfrom upper case to lower case and lower case to upper case
// the third one will get the data and will send it to the socket that send the data

struct pipeline
{
    pmyqueue_t *queue;
    struct activeobject *first;
    struct activeobject *second;
    struct activeobject *third;
};

#endif // PIPLINE_H