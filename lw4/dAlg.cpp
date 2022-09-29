#include <iostream>
#include <string.h>
#include "../lw3/Stack.h"
#include <map>

int main()
{
    Stack *stack = new Stack;
    stack == NULL;
    string s;
    map<string, int> cases;
    cases["/"] = 0;
    cases["*"] = 1;
    cases["-"] = 2;
    cases["+"] = 3;
    cases["("] = 4;
    cases[")"] = 5;
    bool noOpers;

    while (0 == 0)
    {
        if (!EOF) cin >> s;
        else break;
        noOpers = s == "*" | s == "/" | s == "+" | s == "-";
        switch(cases[s])
        {
            case 0: //mod
                if(noOpers | head(stack) == "(")
                    push(stack, s);
                break;
            default:
                push(stack, s);

        }
    }
}