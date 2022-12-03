#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

#define Amount 10
struct Branch
{
    int node1, node2;
    int weight;
};
typedef int AdjecencyMatrix[Amount + 1][Amount + 1];
typedef Branch BranchList[(Amount + 1) * (Amount + 1)];

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
    return 0;
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

bool isFilled(int list[Amount])
{
    for (int i = 1; i <= Amount; i++)
	{
		if(list[i] == 0) return false;
	}
    return true;
}

void ConnectivitySearch(AdjecencyMatrix &adj, int amountNodes)
{
    
    int nodeGroup[amountNodes];
    int i, j, cur, amountGroups;
    stack<int> stack;

    for (i = 1; i <= amountNodes; i++)
	{
		nodeGroup[i] = 0;
	}

    for (nodeGroup, j = 1, amountGroups = 1; nodeGroup[j] == 0, !isFilled(nodeGroup); amountGroups++, j++)
    {
        stack.push(j);
        while (!stack.empty())
	    {
		    cur = stack.top();
		    stack.pop();
            if(nodeGroup[cur] == 0)
            {
                nodeGroup[cur] = amountGroups;
            }
		    for (i = 1; i <= amountNodes; i++)
		    {
			    if (adj[cur][i] > 0 && nodeGroup[cur] != 0)
			    {
				    stack.push(i);
			    }
		    }
        }
    }

    for (i = 1; i <= amountNodes; i++)
    {
        cout << i;
    }
    cout << endl;
    for (i = 1; i <= amountNodes; i++)
    {
        cout << nodeGroup[i];
    }
	cout << endl;
}

int main()
{
    BranchList list;
    AdjecencyMatrix adj;
    int countOfBranches = 10;

    initBranchList("in.txt", list, countOfBranches);
    convertListToMatrix(list, adj, countOfBranches);


}