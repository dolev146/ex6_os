#ifndef MYQUEUE_H_
#define MYQUEUE_H_

struct node
{
    struct node *next;
    void *element;
};
typedef struct node node_t;
void enQ(void *element);
void* deQ();
void createQ();
void destroyQ();

#endif // MYQUEUE_H_