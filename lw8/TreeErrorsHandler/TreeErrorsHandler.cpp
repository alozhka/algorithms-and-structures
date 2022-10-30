#include <iostream>

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

    tree->children->bro->bro->children->v = "fj"; // нижний
    tree->children->bro->bro->children->lvl = 2;
    tree->children->bro->bro->children->bro = NULL;
    tree->children->bro->bro->children->children = NULL;
    tree->children->bro->bro->children->parent = tree->children->bro->bro;

    tree->children->bro->children->lvl = 2;
    tree->children->bro->children->v = "de";
    tree->children->bro->children->bro = new Tree;
    tree->children->bro->children->children = NULL;
    tree->children->bro->children->parent = tree->children->bro;

    tree->children->bro->children->bro->v = "de"; // правый
    tree->children->bro->children->bro->lvl = 2;
    tree->children->bro->children->bro->bro = NULL;
    tree->children->bro->children->bro->children = NULL;
    tree->children->bro->children->bro->parent = tree->children->bro;

    return tree;
    /*
    0                           ab

    1       bc                  cd                  fj

    2                       de      de              fj
    */
}


void printTreeErrors(Tree *tr)
{
    if (tr == NULL)
    {
        return NULL;
    } // != NULL
    else if (tr->bro != NULL)
    {
        Tree *temp = new Tree;
        temp = tr;

    }
    else if (tr->children != NULL)
    {
        Tree *temp = new Tree;
        temp = tr;
        while (tr->l != NULL)
        {
            tr = tr->l;
        }
        return tr;
    }
    return NULL
}


int main()
{
    Tree *tree = new Tree;

    tree = defineTree();

}