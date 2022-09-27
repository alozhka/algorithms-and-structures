#include <iostream>
using namespace std;
#define ChildType int

struct Node
{
    ChildType element;
    Node *right;
};
struct Queue
{
    Node *head;
    Node *q;
    Node *tail;
};


bool isEmpty(Queue *q)
{
    if (q->q == NULL)
        return true;
    else
        return false;
}

ChildType QueueHead(Node *q)
{
    return q->element;
}

ChildType QueueTail(Node *q)
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


void NodeInsert(Queue *&q, Node *&node, ChildType el)
    {
        if(node == NULL)
        {
            node = new Node;
            node->element = el;
            node->right = NULL;
            q->tail = node;
        }
        else
            NodeInsert(q, node->right, el);
}

void QueueInsert(Queue *&q, ChildType el)
{

    if(q == NULL)
    {
        q = new Queue;
        q->q->element = el;
        q->q->right = NULL;
        q->head = q->q;
        q->tail = NULL;
    }
    else
        NodeInsert(q, q->q->right, el);
}


void NodePrint(Node *node)
{
    if(node != NULL)
    {
        cout << node->element << " ";
        NodePrint(node->right);
    }
}
void QueuePrint(Queue *q)
{
    if(q != NULL)
    {
        NodePrint(q->q);
    }
}

void QueueDelHead(Queue *&q)
{
    Node *temp = new Node;
    temp = q->q->right;
    delete(q->q);
    q->q = temp;
    q->head = q->q;
    delete(temp);
}

void QueueDelTail(Queue *&q)
{
    delete(q->tail);
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