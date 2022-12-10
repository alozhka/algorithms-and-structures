#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define Amount 6

struct Branch
{
    int node1, node2, weight;
};
typedef Branch BranchList[(Amount+1) * (Amount+1)];
typedef int AdjecencyMatrix[Amount+1][Amount+1];



int initBranchList(string dest, BranchList &branches, int amountBranches)
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
        if (i == amountBranches)
        {

            if(!file.eof())
            {

                for(i = 1; !file.eof(), i <= amountBranches; i++)
                {
                    if (!file.eof()) file >> branches[i].node1;
                    if (!file.eof()) file >> branches[i].node2;
                    if (!file.eof()) file >> branches[i].weight;
                }
            }

            if (i-1 != amountBranches)
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

void dfs(AdjecencyMatrix graphMatrix, int amountVert)
{
	bool visited[Amount+1];
	stack <int> stack;
	int current;
	int i;

	for (i = 1; i <= amountVert; i++)
	{
		visited[i] = false;
	}

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
		for (i = 1; i <= amountVert; i++)
		{
			if (graphMatrix[current][i] > 0 && visited[i] == false)
			{
				stack.push(i);
			}
		}
    }
}


void topologicalSort(AdjecencyMatrix &adj, int amountNodes)
{
    bool visited[Amount + 1],hasEnteredNodes, hasCycle = false, in_porgess[Amount + 1];
    int enter[Amount + 1], exit[Amount + 1];
	stack <int> stack;
    vector <int> route;
	int cur, i, time = 1;
    string result = "";

	for (i = 1; i <= amountNodes; i++)
	{
		visited[i] = false;
        enter[i] = 0;
        exit[i] = 0;
        in_porgess[i] = false;
	}

	stack.push(1);
	route.push_back(1);
	while (!stack.empty())
	{
        hasEnteredNodes = false;
        
		cur = stack.top();
		stack.pop();

		if (visited[cur] == false)
		{
			visited[cur] = true;
		}

        if (exit[cur] == 0 && enter[cur] != 0)
        {
            exit[cur] = time;
            in_porgess[cur] = false;
        }
        if (enter[cur] == 0)
        {
            enter[cur] = time;
            in_porgess[cur] = true;
        }
    }
    // Если есть цикл
    if (hasCycle)
    {
        cout << "Есть цикл, обход невозможен" << endl;
    }
    else 
    {
        cout << result << endl;
    }
}

int main()
{
    BranchList list;
    AdjecencyMatrix adj;
    int amountBranches = 5;
    initBranchList("int.txt", list, amountBranches);
    convertListToOrientedMatrix(list, adj,  Amount);

    topologicalSort(adj, Amount);
    cout << endl;
    return 0;
}