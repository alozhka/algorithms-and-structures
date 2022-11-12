#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define Amount 10

struct Branch
{
    int node1, node2;
    int weight;
};
typedef int AdjecencyMatrix[Amount+1][Amount+1];
typedef Branch BranchList[(Amount+1) * (Amount+1)];


int initMatrix(string dest, AdjecencyMatrix &matrix)
{
    // инициализация
    ifstream file (dest);
    int ch, i, j;

    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        return 0;
    }
    else if (!file.eof())
    {

        file >> ch;
        if (ch == Amount)
        {

            if(!file.eof())
            {
                for(i = 1; !file.eof(), i <= Amount; i++)
                    for(j = 1; !file.eof(), j <= Amount; j++)
                    {
                        file >> ch;
                        matrix[i][j] = ch;
                    }
            }
            if (i-1 != Amount && j-1 != Amount)
            {
                cout << "Введены не все данные\n";
                return 0;
            }
            else return 1;

        }
        else
        {
            cout << "Размер матрицы некорректен";
            return 0;
        }
    }
}

int convertMatrixToList(AdjecencyMatrix matrix, BranchList &branches)
{
    // разделим граф пополам,
    // чтобы не записывать повторяющиеся пути
    int i, j, separator;
    int current = 1;
    for (i = 1, separator = 2; i<= Amount; i++, separator++)
        for(j = separator; j <= Amount; j++)
        {
            if (matrix[i][j] != 0)
            {
                branches[current].node1 = i;
                branches[current].node2 = j;
                branches[current].weight = matrix[i][j];
                current++;
            }
        }
    
    return current-1;
}

void printBranchList(BranchList branches, int amount)
{
    for (int j = 1; j<=amount; j++)
    {
        cout<< branches[j].node1 << " " << branches[j].node2 << " " << branches[j].weight << endl;
    }
}

int main() 
{
    AdjecencyMatrix matrix;
    BranchList branches;

    initMatrix("in.txt", matrix);
    int i = convertMatrixToList(matrix, branches);

    printBranchList(branches, i);
    cout << endl;
    return 0;
}