#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

constexpr auto Amount = 8;

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

void dfs(AdjecencyMatrix graphMatrix, int amountVert)
{
    bool visited[Amount + 1] = { false };
    stack <int> stack;
    int current, i;

    i = 1;
    stack.push(i);
    while (!stack.empty())
    {
        current = stack.top();
        stack.pop();
        if (visited[current] == false)
        {
            visited[current] = true;
            cout << current << " ";
        }
        for (i = amountVert; i >= 1; i--)
        {
            if (graphMatrix[current][i] > 0 && visited[i] == false)
            {
                stack.push(i);
            }
        }
    }
}
/**
 * @brief Takes a breath-first-out algorytm.
 * Gets maxtrix, beginning element and amount of nodes in matrix
*/
void bfs(AdjecencyMatrix adj, int cur, int amountNodes)
{
    queue<int> queue;
    bool visited[Amount + 1] = { false };
    int i;


    queue.push(cur);

    while (!queue.empty())
    {
        cur = queue.front();
        queue.pop();

        if (visited[cur] == false)
        {
            visited[cur] = true;
            cout << cur << " ";
        }
        for (i = 1; i <= amountNodes; i++)
        {
            if (adj[cur][i] > 0 && visited[i] == false)
            {
                queue.push(i);
            }
        }
    }
}

namespace test
{
    bool topologicalRecursive(AdjecencyMatrix& adj, int &amountNodes, int (&tin)[Amount + 1], int (&tout)[Amount + 1], int &time, int (&nodeState)[Amount + 1], int& node)
    {
        bool hasCycle;
        time++;
        tin[node] = time;
        if (nodeState[node] == 1)
        // попали в вершину, из которой не вышли => есть цикл
        {
            return true;
        }
        else
        {
            nodeState[node] = 1;
        }


        for (int i = 1; i <= amountNodes; i++)
        {
            if (adj[node][i] > 0)
            {
                hasCycle = test::topologicalRecursive(adj, amountNodes, tin, tout, time, nodeState, i);
                if (hasCycle)
                {
                    return true;
                }
            }
        }
        time++;
        tout[node] = time;
        nodeState[node] = 2;
        return false;
    }
    void topologicalSort(AdjecencyMatrix& adj, int amountNodes)
    {
        // для nodeState (проверка на отсутствие циклов)
        // 0 - не вошли в вершину
        // 1 - вошли внутрь вершины
        // 2 - вышли из вершины
        int nodeState[Amount + 1] = { 0 };
        int tin[Amount + 1] = { 0 }, tout[Amount + 1] = { 0 };
        int time = 0, cur = 1, i;
        bool hasCycle = false;
        
        tin[1] = 0;
        nodeState[1] = 1;
        for (i = 1; i <= amountNodes; i++)
        {
            if (adj[cur][i] > 0)
            {
                hasCycle = test::topologicalRecursive(adj, amountNodes, tin, tout, time, nodeState, i);
                if (hasCycle)
                {
                    cout << "Есть цикл, обход невозможен" << endl;
                    return;
                }
            }
        }
        tout[1] = time;
        nodeState[1] = 2;
        
        for (i = 1; i <= amountNodes; i++)
        {
            printf("in  %d:%2d;  ", i, tin[i]);
        }
        cout << endl;
        for (i = 1; i <= amountNodes; i++)
        {
            printf("out %d:%2d;  ", i, tout[i]);
        }
        cout << endl;
        for (i = 1; i <= amountNodes; i++)
        {
            printf("state %d:%2d;  ", i, nodeState[i]);
        }
        cout << endl;
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


void topologicalSort(AdjecencyMatrix& adj, int amountNodes)
{
    // 0 - не вошли в вершину
    // 1 - вошли внутрь вершины
    // 2 - вышли из вершины
    int nodeState[Amount + 1] = { 0 };
    int tin[Amount + 1] = { 0 }, tout[Amount + 1] = { 0 };

    stack <int> stack, route;
    int cur, i;
    string state = "in";

    stack.push(1);
    route.push(1);

    // обходим, ищем маршрут обратного выхода
    // для замены старых значений в будущем
    while (!stack.empty())
    {
        cur = stack.top();
        stack.pop();

        if (nodeState[cur] == 0 && state == "in")
        {
            nodeState[cur] = 1;
        }

        for (i = 1; i <= amountNodes; i++)
        {
            if (adj[cur][i] > 0)
            {
                stack.push(i);
                if (state == "in") route.push(i);
            }
        }

        if (stack.empty())
        {
            state = "out";
            while (!route.empty())
            {
                stack.push(route.top());
                route.pop();
            }
        }
    }

    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    BranchList list;
    AdjecencyMatrix adj;
    int amountBranches = 8;
    initBranchList("in.txt", list, amountBranches);
    convertListToOrientedMatrix(list, adj, amountBranches);

    test::topologicalSort(adj, Amount);
    cout << endl;

    //вариант с циклом
    amountBranches = 9;
    initBranchList("cyclic_graph.txt", list, amountBranches);
    convertListToOrientedMatrix(list, adj, amountBranches);


    test::topologicalSort(adj, Amount);
    cout << endl;
    return 0;
}