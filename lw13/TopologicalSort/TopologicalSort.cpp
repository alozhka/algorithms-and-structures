#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

#define Amount 5

struct Branch
{
    int node1, node2, weight;
};
typedef Branch BranchList[(Amount+1) * (Amount+1)];
typedef int AdjecencyMatrix[Amount+1][Amount+1];



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


void convertListToOrientedMatrix(BranchList &branches, AdjecencyMatrix &matrix, int countOfBranches)
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
    }
}

void topologicalSort(AdjecencyMatrix &adj, int amountNodes)
{
    bool visited[Amount+1], noEnteringNodes;
	stack <int> stack, backRoute;
	int cur, i;

	for (i = 1; i <= amountNodes; i++)
	{
		visited[i] = false;
	}

	i = 1;
	stack.push(i);
    // обходим, ищем маршрут обратного выхода
    // для замены старых значений в будущем
	while (!stack.empty())
	{
        noEnteringNodes = true;
		cur = stack.top();
		stack.pop();
		if (visited[cur] == false)
		{
			visited[cur] = true;
		} 
		for (i = 1; i <= amountVert; i++)
		{
			if (adj[cur][i] > 0 && visited[i] == false)
			{
                noEnteringNodes = false;
				stack.push(i);
			}
		}
        if (noEnteringNodes)
        {
            backRoute.push(cur);
        }
    }
    // замена старых значений новыми
}

int main()
{
    BranchList list;
    AdjecencyMatrix adj;
    int amountBranches = 5;
    initBranchList("int.txt", list, amountBranches);
    convertListToOrientedMatrix(list, adj,  amountBranches);

    
    return 0;
}