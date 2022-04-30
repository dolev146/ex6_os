#include "blockqueue.h"
#include "myqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enQ(void *element)
{
    pthread_mutex_lock(&mutex);
    NcreateQ();
    pthread_mutex_unlock(&mutex);
}
void *deQ()
{
    pthread_mutex_lock(&mutex);
    NdeQ();
    pthread_mutex_unlock(&mutex);
}
void createQ()
{
    pthread_mutex_lock(&mutex);
    NcreateQ();
    pthread_mutex_unlock(&mutex);
}
void destroyQ()
{
    pthread_mutex_lock(&mutex);
    NdestroyQ();
    pthread_mutex_unlock(&mutex);
}