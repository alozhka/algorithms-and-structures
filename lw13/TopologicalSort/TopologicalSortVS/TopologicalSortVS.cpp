#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

constexpr auto Amount = 9;

struct Branch
{
    int node1, node2, weight;
};
typedef Branch BranchList[(Amount + 1) * (Amount + 1)];
typedef int AdjecencyMatrix[Amount + 1][Amount + 1];


int initBranchList(string dest, BranchList& branches, int amountBranches)
{
    // инициализация
    ifstream file(dest);
    int i;

    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        return 0;
    }
    else if (!file.eof())
    {

        file >> i;
        if (i == amountBranches)
        {

            if (!file.eof())
            {
                for (i = 1; !file.eof(), i <= amountBranches; i++)
                {
                    if (!file.eof()) file >> branches[i].node1;
                    if (!file.eof()) file >> branches[i].node2;
                    if (!file.eof()) file >> branches[i].weight;
                }
            }
            if (i - 1 != amountBranches)
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
    else
    {
        return 0;
    }
}
void convertListToOrientedMatrix(BranchList& branches, AdjecencyMatrix& matrix, int countOfBranches)
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
    }
}

namespace topologic
{
    bool topologicalRecursive(AdjecencyMatrix& adj, int &amountNodes, int (&tin)[Amount + 1], int (&tout)[Amount + 1], int &time, int& node)
    {
        bool hasCycle;
        if (tin[time] != 0 && tout[time] == 0)
        {
            // попали в вершину, из которой не вышли => есть цикл
            // возвратим истину, что есть цикл, и таким образом выйдем из рекурсии
            return true;
        }
        time++;
        tin[node] = time;
        

        for (int i = 1; i <= amountNodes; i++)
        {
            if (adj[node][i] > 0)
            {
                hasCycle = topologic::topologicalRecursive(adj, amountNodes, tin, tout, time, i);
                if (hasCycle)
                {
                    return true;
                }
            }
        }
        time++;
        tout[node] = time;
        return false;
    }
    void topologicalSort(AdjecencyMatrix& adj, int amountNodes)
    {
        int tin[Amount + 1] = { 0 }, tout[Amount + 1] = { 0 };
        int time = 0, cur = 1, i;
        bool hasCycle = false;
        
        tin[1] = 0;
        for (i = 1; i <= amountNodes; i++)
        {
            if (adj[cur][i] > 0)
            {
                hasCycle = topologic::topologicalRecursive(adj, amountNodes, tin, tout, time, i);
                if (hasCycle)
                {
                    cout << "Есть цикл, обход невозможен" << endl;
                    return;
                }
            }
        }
        tout[1] = time;
        
        // печать
        for (cur = 0, time = 0; cur < amountNodes; time++)
        {
            for (i = 1; i <= amountNodes; i++)
            {
                if (tin[i] == time)
                {
                    cout << i;
                    cur++;
                    break;
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    BranchList list;
    AdjecencyMatrix adj;
    //вариант без цикла
    int amountBranches = 9;
    initBranchList("in.txt", list, amountBranches);
    convertListToOrientedMatrix(list, adj, amountBranches);

    topologic::topologicalSort(adj, Amount);
    cout << endl;

    //вариант с циклом
    amountBranches = 10;
    initBranchList("cyclic_graph.txt", list, amountBranches);
    convertListToOrientedMatrix(list, adj, amountBranches);


    topologic::topologicalSort(adj, Amount);
    cout << endl;
    return 0;
}