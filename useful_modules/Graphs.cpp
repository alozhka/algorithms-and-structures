#include "Graphs.h"
#include <fstream>

int initBranchList(string dest, BranchList& branches, int amount)
{
    // инициализация
    ifstream file(dest);
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

            if (!file.eof())
            {

                for (i = 1; !file.eof(), i <= amount; i++)
                {
                    if (!file.eof()) file >> branches[i].node1;
                    if (!file.eof()) file >> branches[i].node2;
                    if (!file.eof()) file >> branches[i].weight;
                }
            }

            if (i - 1 != amount)
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
int initMatrix(string dest, AdjecencyMatrix& matrix)
{
    // инициализация
    ifstream file(dest);
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

            if (!file.eof())
            {
                for (i = 1; !file.eof(), i <= Amount; i++)
                    for (j = 1; !file.eof(), j <= Amount; j++)
                    {
                        file >> ch;
                        matrix[i][j] = ch;
                    }
            }
            if (i - 1 != Amount && j - 1 != Amount)
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

void convertListToMatrix(BranchList& branches, AdjecencyMatrix& matrix, int countOfBranches)
{
    // обнуляем матрицу
    int i, j;
    for (i = 1; i <= Amount; i++)
        for (j = 1; j <= Amount; j++)
        {
            matrix[i][j] = 0;
        }
    // заполняем новыми значениями
    for (i = 1; i <= countOfBranches; i++)
    {
        matrix[branches[i].node1][branches[i].node2] = branches[i].weight;
        matrix[branches[i].node2][branches[i].node1] = branches[i].weight;
    }
}
int convertMatrixToList(AdjecencyMatrix matrix, BranchList& branches)
{
    // разделим граф пополам,
    // чтобы не записывать повторяющиеся пути
    int i, j, separator;
    int current = 1;
    for (i = 1, separator = 2; i <= Amount; i++, separator++)
        for (j = separator; j <= Amount; j++)
        {
            if (matrix[i][j] != 0)
            {
                branches[current].node1 = i;
                branches[current].node2 = j;
                branches[current].weight = matrix[i][j];
                current++;
            }
        }

    return current - 1;
}

void printBranchList(BranchList branches, int amount)
{
    for (int j = 1; j <= amount; j++)
    {
        cout << branches[j].node1 << " " << branches[j].node2 << " " << branches[j].weight << endl;
    }
}