#include <iostream>
using namespace std;
#define ElementType string

struct Stack
{
    ElementType el;
    Stack *next;
};


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
        cout << s->el <<endl;
        print(s->next);
    }
    
}


int main()
{
    Stack *stack;
    stack = NULL;

    cout << isEmpty(stack) << endl;
    push(stack, "abcdef");
    push(stack, "4321");
    print(stack);

    return 0;
}