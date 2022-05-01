#ifndef MYQUEUE_H_
#define MYQUEUE_H_

struct node
{
    struct node *next;
    void *element;
};

typedef struct node node_t;
void NenQ(void *element);
void* NdeQ();
void NcreateQ();
void NdestroyQ();

#endif // MYQUEUE_H_