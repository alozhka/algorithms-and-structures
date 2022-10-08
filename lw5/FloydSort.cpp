#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define ElementType int

typedef vector <ElementType> vectorEl;
int floydSort(vectorEl v)
{
    if(v.empty())
        return 1;
    else
    {
        int size = v.size() - 1; // тк первый элемент 0
        ElementType temp;        // для хранения значения во время замены

        
    }
}


int main()
{
    ifstream file ("in.txt");
    ElementType el;
    vectorEl inputElements;
    inputElements.push_back(0);

    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return 1;
    }
    else
    {
        for(file >> el; !file.eof(); file >> el)
            inputElements.push_back(el);
    }

    // while(!inputElements.empty())
    // {
    //     cout << inputElements.front();
    //     inputElements.erase(inputElements.begin());
    // }

    cout << endl;
    return 0;
}