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

Tree* defineTree()
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

    tree->children->bro->bro->children->v = "fj"; // fj на 2 уровне
    tree->children->bro->bro->children->lvl = 2;
    tree->children->bro->bro->children->bro = NULL;
    tree->children->bro->bro->children->children = new Tree;
    tree->children->bro->bro->children->parent = tree->children->bro->bro;

    tree->children->bro->bro->children->children->v = "fj"; // fj на 3 уровне
    tree->children->bro->bro->children->children->lvl = 3;
    tree->children->bro->bro->children->children->children = NULL;
    tree->children->bro->bro->children->children->bro = NULL;
    tree->children->bro->bro->children->children->parent = tree->children->bro->bro->children;

    tree->children->bro->children->lvl = 2;
    tree->children->bro->children->v = "de";
    tree->children->bro->children->bro = new Tree;
    tree->children->bro->children->children = NULL;
    tree->children->bro->children->parent = tree->children->bro;

    tree->children->bro->children->bro->v = "de"; // правый de
    tree->children->bro->children->bro->lvl = 2;
    tree->children->bro->children->bro->bro = NULL;
    tree->children->bro->children->bro->children = NULL;
    tree->children->bro->children->bro->parent = tree->children->bro;

    return tree;
    /*
    Levels:

    0                           ab

    1       bc                  cd                  fj

    2                       de      de              fj
    */
}


void printTreeErrors(Tree *tr)
{
    if (tr != NULL)
    {
        printTreeErrors(tr->children);
        // если дети
        if (tr->parent != NULL && tr->v == tr->parent->v)
        {
            cout << tr->parent->v << tr->parent->lvl <<  " " << tr->v << tr->lvl << endl;
        }
        // если братья
        if (tr->bro != NULL && tr->v == tr->bro->v)
        {
            cout << tr->bro->v << tr->bro->lvl << " " << tr->v << tr->lvl << endl;
        }
        printTreeErrors(tr->bro);
    }
}


int main()
{
    Tree *tree = new Tree;

    tree = defineTree();

    printTreeErrors(tree);
    cout << endl;
}