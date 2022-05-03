#ifndef ActiveObject
#define ActiveObject
#include "blockqueue.h"

struct activeobject
{
    pmyqueue_t queue;
    void *(*firstfunc)(void *);
    void *(*secondfunc)(void *);
};

// void newAO() will get 3 parameters:
// 1. a pointer to a blockqueue
// 2. a pointer to a function to deal with the queue element
// 3. a pointer to a function to cleanup after the queue element

struct activeobject *newAO(pmyqueue_t *, void *(*)(void *), void *(*)(void *));

/*
 *destroyAO() will get a pointer to a blockqueue
 *and will destroy the blockqueue
 * with a call to pthread_cancel()
 * and will release the memory allocated for the blockqueue
 *
 */

void destroyAO(struct activeobject *);

// struct parameters
// {
//     pmyqueue_t queue;
//     void *element;
// };

// void *enQ(void *arguments);
// void *deQ(void *arguments);
// pmyqueue_t createQ();
// void destroyQ(pmyqueue_t);1

#endif // ActiveObject