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


int initBranchList(string dest, BranchList &branches, int amount)
{
    // инициализация
    ifstream file (dest);
    int i, node1, node2, weight;

    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        return 0;
    }
    else if (!file.eof())
    {

        file >> i;
        if (i == amount)
        {

            if(!file.eof())
            {

                for(i = 1; !file.eof(), i <= amount; i++)
                {
                    if (!file.eof()) file >> branches[i].node1;
                    if (!file.eof()) file >> branches[i].node2;
                    if (!file.eof()) file >> branches[i].weight;
                }
            }

            if (i-1 != amount)
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

void convertListToMatrix(BranchList &branches, AdjecencyMatrix &matrix, int countOfBranches)
{
    // обнуляем матрицу
    int i, j;
    for(i = 1; i <= Amount; i++)
        for(j = 1; j <= Amount; j++)
        {
            matrix[i][j] = 0;
        }
    // заполняем новыми значениями
    for (i = 1; i<= countOfBranches; i++)
    {
        matrix[branches[i].node1] [branches[i].node2] = branches[i].weight;
        matrix[branches[i].node2] [branches[i].node1] = branches[i].weight;
    }
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
    int countBranches = 12;

    initBranchList("in.txt", branches, countBranches);
    printBranchList(branches, countBranches);

    convertListToMatrix(branches, matrix, countBranches);
    cout << endl;
    return 0;
}