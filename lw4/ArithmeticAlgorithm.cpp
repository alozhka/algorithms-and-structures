#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#define ElementType char
using namespace std;


int ArithmecitExchange(string dest)
{
    stack <ElementType> stack;
    ElementType el;
    map<ElementType, int> priority = 
    {
        {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2},
    };
    map<ElementType, int>:: iterator iter;

    fstream file;
    file.open(dest);


    if(!file.is_open()) 
    {
        cout << "Строка не введена!" << endl;
        file.close();
        return 1;
    }
    for(file >> el; !file.eof(); file >> el)
    {
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
            stack.pop();
        }

        else
        {
            iter = priority.find(el);
            if(iter != priority.end())
            {
                while( (!stack.empty()) && priority[stack.top()] >= priority[el])
                {
                    cout << stack.top();
                    stack.pop();
                }
                stack.push(el);
            }
        }
    }
    
    while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
	cout << endl;


    file.close();
    return 0;

}


int main()
{
    ArithmecitExchange("in.txt");
    return 0;
}