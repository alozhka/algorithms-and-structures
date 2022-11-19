#include <fstream>
#include <iostream>
#include <vector>
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

int main()
{
    BranchList list;
    AdjecencyMatrix adj;


    initBranchList("in.txt", list, 12);
    convertListToMatrix(list, adj, Amount+1);

    dfs(adj, Amount);
    cout << endl;
    return 0;
}