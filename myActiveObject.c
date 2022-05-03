#include "myActiveObject.h"

// void newAO() will get 3 parameters:
// 1. a pointer to a pmyqueue_t
// 2. a pointer to a function to deal with the queue element
// 3. a pointer to a function to cleanup after the queue element
/*
 * create a threadpool that will dequeue the queue
 * and will call the function to deal with the queue element
 * after the function is done, it will call the function to cleanup
 */
struct activeobject *newAO(pmyqueue_t *queueparam, void *(*firstfunc)(void *), void *(*secondfunc)(void *))
{
    struct activeobject *ao = (struct activeobject *)malloc(sizeof(struct activeobject));
    ao->queue = *queueparam;
    ao->firstfunc = firstfunc;
    ao->secondfunc = secondfunc;
    return ao;
}

/*
 *destroyAO() will get a pointer to a blockqueue
 *and will destroy the blockqueue
 * with a call to pthread_cancel()
 * and will release the memory allocated for the blockqueue
 *
 */

void destroyAO(struct activeobject *ao_param){
    // pthread_cancel(ao_param->thread);
    // NdestroyQ(ao_param->queue);
    // free(ao_param);



    // TODO
    return;
    
}