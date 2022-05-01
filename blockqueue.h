#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

void *enQ(void *args);
void *deQ(void *args);
pmyqueue_t createQ();
void destroyQ(pmyqueue_t);

#endif // BLOCKQUEUE_H