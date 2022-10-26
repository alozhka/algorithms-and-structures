#include <iostream>
using namespace std;
#define ElType string

struct Tree
{
    ElType v;           // value
    int lvl;            // level
    Tree* children;
    Tree* bro;
    Tree* parent;
};


void printLeaves(Tree* tr)
{
    if (tr != NULL)
    {
        printLeaves(tr->children);

        if (tr->children == NULL)
            cout << tr->v << " ";

        printLeaves(tr->bro);
    }
}

void printKnots(Tree* tr)
{
    if (tr != NULL)
    {
        printKnots(tr->children);

        if (tr->children != NULL)
            cout << tr->v << " ";

        printKnots(tr->bro);
    }
}


void printParent(Tree* tr, ElType el)
{
    if (tr != NULL)
    {
        printParent(tr->children, el);

        if(tr->v == el)
        {
            cout << tr->parent->v;
            return ;
        }

        printParent(tr->bro, el);
    }    
}

void printTreeOnLevel(Tree* tr, int level)
{
    if (tr != NULL)
    {
        printTreeOnLevel(tr->children, level);

        if (tr->lvl == level)
            cout << tr->v << " ";
        
        printTreeOnLevel(tr->bro, level);
    }
}

int main()
{
    Tree *tree = new Tree;

    tree->v = "ab";
    tree->lvl = 0;
    tree->children = new Tree;
    tree->bro = NULL;
    tree->parent = NULL;

    tree->children->lvl = 1;
    tree->children->v = "bc";
    tree->children->bro = new Tree;
    tree->children->children = NULL;
    tree->children->parent = tree;

    tree->children->bro->lvl = 1;
    tree->children->bro->v = "cd";
    tree->children->bro->bro = new Tree;
    tree->children->bro->children = new Tree;
    tree->children->bro->parent = tree;

    tree->children->bro->bro->v = "fj";
    tree->children->bro->bro->lvl = 1;
    tree->children->bro->bro->bro = NULL;
    tree->children->bro->bro->children = new Tree;
    tree->children->bro->bro->parent = tree;

    tree->children->bro->bro->children->v = "kl";
    tree->children->bro->bro->children->lvl = 2;
    tree->children->bro->bro->children->bro = NULL;
    tree->children->bro->bro->children->children = NULL;
    tree->children->bro->bro->children->parent = tree->children->bro->bro;

    tree->children->bro->children->lvl = 2;
    tree->children->bro->children->v = "de";
    tree->children->bro->children->bro = new Tree;
    tree->children->bro->children->children = NULL;
    tree->children->bro->children->parent = tree->children->bro;

    tree->children->bro->children->bro->v = "ef";
    tree->children->bro->children->bro->lvl = 2;
    tree->children->bro->children->bro->bro = NULL;
    tree->children->bro->children->bro->children = NULL;
    tree->children->bro->children->bro->parent = tree->children->bro;
    /*
    0                           ab

    1       bc                  cd                  fj

    2                       de      ef              kl
    */
    
    cout << "Leaves are: ";
    printLeaves(tree);
    cout << "\nKnots are: ";
    printKnots(tree);
    cout << "\nParent of ef is: ";
    printParent(tree, "ef");
    cout << "\nParent of cd is: ";
    printParent(tree, "cd");
    cout << "\nParent of fj is: ";
    printParent(tree, "fj");
    cout << "\nNodes of 2 level are: ";
    printTreeOnLevel(tree, 2);
    cout << endl;


    return 0;
}
