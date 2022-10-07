#include <iostream>
#include <map>
#include <stack>
using namespace std;
#define ElementType char



int main()
{
    // FILE *f = fopen("in.txt", "r");
    stack <ElementType> stack;
    ElementType el;
    map<ElementType, int> priority = 
    {
        {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2},
    };
    map<ElementType, int>:: iterator iter;
    
    if(cin.eof()) 
        cout << "Строка не введена!" << endl;
    while(!cin.eof())
    {
        cin >> el;

        if('0' <= el && el <= '9')
        {
            cout << el;
        }

        else if(el == '(')
        {
            stack.push(el);
        }

        else if(el == ')')
        {
            while(!stack.empty() && stack.top() != '(')
            {
                cout << stack.top();
                stack.pop();
            }
        }

        else
        {
            iter = priority.find(el);
            if(iter != priority.end())
            {
                while( ( !stack.empty() ) && priority[stack.top()] >= priority[el])
                {
                    cout <<stack.top();
                    stack.pop();
                }
                stack.pop();
            }
        }
    }
    
    while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
	cout << endl;
    return 0;
}