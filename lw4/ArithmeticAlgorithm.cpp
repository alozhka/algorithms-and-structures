#include <iostream>
#include <map>
#include <stack>
using namespace std;
#define ElementType string



int main()
{
    FILE *f = fopen("in.txt", "r");
    stack <ElementType> stack;
    ElementType s;
    map<string, int> cases =
    {
        {"/", 0}, {"*", 0}, {"-", 0}, {"+", 0},
        {"(", 1},
        {")", 2},
    };
    
    while(!EOF)
    {
        cin >> s;
        switch (cases[s])
        {
            case 0:

                break;
            case 1:  // (
                stack.push(s);
                break;
        
            default: // всё остальное
                stack.push(s);
                break;
        }
    }

    

}