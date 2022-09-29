#ifndef _Stack_H_
#define _Stack_H_
#endif


#include <iostream>
using namespace std;
#define ElementType string

struct Stack
{
    ElementType el;
    Stack *next;
};

extern bool         isEmpty(Stack *s);
extern void         push(Stack *&s, ElementType el);
extern void         pop(Stack *&s, ElementType el);
extern void         print(Stack *s);
extern ElementType  head(Stack *&s);