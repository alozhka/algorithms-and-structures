#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define Amount 10

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

void dfs(AdjecencyMatrix graphMatrix, int amountVert)
{
	bool visited[Amount+1];
	std::stack <int> stack;
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
/**
 * @brief Takes a breadth-first-out algorytm.
 * Gets maxtrix, beginning element and amount of nodes in matrix
*/
void bfs(AdjecencyMatrix adj, int cur, int amountNodes)
{
    queue<int> queue;
    bool visited[amountNodes];
    int i;

    for (i = 1; i <= amountNodes; i++)
	{
		visited[i] = false;
	}
    
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


int main()
{
    setlocale(LC_ALL, "rus");
    BranchList list;
    AdjecencyMatrix adj;


    initBranchList("in.txt", list, 12);
    convertListToMatrix(list, adj, Amount+1);

    bfs(adj, 1, Amount);
    cout << endl;
    return 0;
}