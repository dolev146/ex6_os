#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H
#include "myqueue.h"

struct parameters
{
    pmyqueue_t queue;
    void *element;
};

void *enQ(void *arguments);
void *deQ(void *arguments);
pmyqueue_t createQ();
void destroyQ(pmyqueue_t);

#endif // BLOCKQUEUE_H