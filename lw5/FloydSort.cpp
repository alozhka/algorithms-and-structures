#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
#define ElementType int

typedef vector <ElementType> vectorEl;



int floydSort(vectorEl v)
{
    if(v.size() <= 1)
    {
        return 1;
    }
    else
    {

        int size = v.size()-1;                // соответствие индексам
        int i, j, min, minIndex;

        while(size > 1)                       // когда остался не только один ноль + верхушка дерева
        {
            min = INT32_MAX;                  // для поиска минимума
            for(j = size; j >= 2; j--)
            {
                i = floor(j / 2);
                if(v[i] < v[j])
                {
                    swap(v[i], v[j]);
                }
                if(v[j] <= min)               // сделал, чтобы индекс элемента был иницализирован
                {                             // в любом случае, даже если все элементы равны
                    minIndex = i;
                    min = v[i];
                }

            }


            cout << v[1] << " ";
            swap(v[1], v[minIndex]);
            v.erase(v.begin() + minIndex);
            size--;
        }
        cout << v[1];
        return 0;
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
        if(!file.eof())
            do
            {
                file >> el;
                inputElements.push_back(el);
            } while (!file.eof());
    }

    floydSort(inputElements);

    cout << endl;
    return 0;
}