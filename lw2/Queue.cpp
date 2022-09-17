#include <iostream>
using namespace std;
#define ChildType int

struct Queue
{
    ChildType element;
    Queue *right;
};


bool isEmpty(Queue *q)
{
    if (q == NULL)
        return true;
    else
        return false;
}

ChildType QueueHead(Queue *q)
{
    return q->element;
}

ChildType QueueTail(Queue *q)
{
    if (q->right == NULL)
    {
        return q->element;
    }
    else
    {
        QueueTail(q->right);
    }
}

void QueueInsert(Queue *&q, ChildType el)
{
    if(q == NULL)
    {
        q = new Queue;
        q->element = el;
        q->right = NULL;
    }
    else
        QueueInsert(q->right, el);
}

void QueuePrint(Queue *q)
{
    if(q != NULL)
    {
        cout << q->element << " ";
        QueuePrint(q->right);
    }
}

void QueueDelHead(Queue *&q)
{
    Queue *temp = new Queue;
    temp = q->right;
    delete(q);
    q = temp;
}

void QueueDelTail(Queue *&q)
{
    if(q->right == NULL)
    {
        free(q);
        q = NULL;
    }
    else
        QueueDelTail(q->right);
}

int main()
{
    Queue *queue;
    queue = NULL;
    
    cout << isEmpty(queue) << endl;

    QueueInsert(queue, 12);
    QueueInsert(queue, 8743);

    cout << isEmpty(queue) << endl;

    QueuePrint(queue);
    cout << endl;

    QueueDelHead(queue);
    QueuePrint(queue);
    cout << endl;
    
    QueueInsert(queue, 627362);
    QueueInsert(queue, 24);
    QueuePrint(queue);
    cout << endl;
    QueueDelTail(queue);
    QueuePrint(queue);
    cout << endl;

    QueueDelTail(queue);
    QueuePrint(queue);
    cout << endl;

    return 0;
}