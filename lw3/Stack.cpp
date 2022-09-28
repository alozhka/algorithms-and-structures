#include "Stack.h"


bool isEmpty(Stack *s)
{
    return s == NULL;
}

void push(Stack *&s, ElementType el)
{
    Stack *temp = new Stack;
    temp->el = el;
    temp->next = s;
    s = temp;
}


void pop(Stack *&s, ElementType el)
{
    el = s->el;
    Stack *temp = new Stack;
    temp = s->next;
    delete(s);
    s = temp;
}


void print(Stack *s)
{
    if(s != NULL)
    {
        cout << s->el << endl;
        print(s->next);
    }
    
}

ElementType seeHead(Stack *&s)
{
    return s->el;
}