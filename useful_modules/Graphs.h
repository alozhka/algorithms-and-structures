#pragma once
#ifndef _Graph_H_
#define _Graph_H_
#endif

#include <iostream>

using namespace std;
#define Amount 10

struct Branch
{
    int node1, node2;
    int weight;
};
typedef int AdjecencyMatrix[Amount + 1][Amount + 1];
typedef Branch BranchList[(Amount + 1) * (Amount + 1)];

int initBranchList(string dest, BranchList& branches, int amount);
int initMatrix(string dest, AdjecencyMatrix& matrix);

void convertListToMatrix(BranchList& branches, AdjecencyMatrix& matrix, int countOfBranches);
int convertMatrixToList(AdjecencyMatrix matrix, BranchList& branches);

void printBranchList(BranchList branches, int amount);