// Tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;
#define ChildType int

struct Tree
{
    ChildType value;
    Tree* l;
    Tree* r;
};


void init(Tree *&tree)
{
    tree = NULL;
}

void insert(Tree *&tr, ChildType el)
{
    if (tr == NULL)
    {
        tr = new Tree;
        tr->l = NULL;
        tr->r = NULL;
        tr->value = el;
    }
    else if (el < tr->value)
    {
        insert(tr->l, el);
    }
    else if (el >= tr->value)
    {
        insert(tr->r, el);
    }
}


void infix_bypass(Tree* tr)
{
    if (tr != NULL)
    {
        infix_bypass(tr->l);
        cout << tr->value << " ";
        infix_bypass(tr->r);
    }
}
void prefix_bypass(Tree* tr)
{
    if (tr != NULL)
    {
        cout << tr->value << " ";
        prefix_bypass(tr->l);
        prefix_bypass(tr->r);
    }
}
void postfix_bypass(Tree* tr)
{
    if (tr != NULL)
    {
        postfix_bypass(tr->l);
        postfix_bypass(tr->r);
        cout << tr->value << " ";
    }
}


Tree* findMostLeft(Tree* tr)
{
    if (tr == NULL)
    {
        return NULL;
    }
    else
    {
        while (tr->l != NULL)
        {
            tr = tr->l;
        }
        return tr;
    }
};
void deleteNode(Tree* &tr, ChildType el)
{
    if (tr->value == el)
    {
        // если нашли
        if (tr->l == NULL && tr->r == NULL)
        {
            delete tr;
            tr = NULL;
        } 
        else if (tr->l != NULL && tr->r == NULL)
        {
            Tree* temp = new Tree;
            temp = tr;
            tr = temp->l;
            delete temp;
            
        }
        else if (tr->l == NULL && tr->r != NULL)
        {
            Tree* temp = new Tree;
            temp = tr;
            tr = temp->r;
            delete temp;
        }
        else // оба не NULL
        {
            Tree* temp = new Tree;
            temp = tr;
            tr = temp->r;
            delete temp;
            tr->l = findMostLeft(tr);

        }
    }

    // ищем нужный элемент дальше
    else if (el < tr->value)
    {
        if (tr->l != NULL)
            deleteNode(tr->l, el);
    }
    else // >=
    {
        if (tr->l != NULL)
            deleteNode(tr->r, el);
    }
}
void deleteTree(Tree *tr)
{
    if (tr != NULL)
    {
        deleteTree(tr->l);
        deleteTree(tr->r);
        delete tr;
        tr = NULL;
    }
}



int main()
{
    Tree *tree;
    ifstream file("in.txt");
    ChildType i;
    init(tree);

    setlocale(LC_ALL, "rus");
    if (!file.is_open())
    {
        cout << "Ошибк апри открытии файла\n";
        return 1;
    }
    else if (!file.eof())
    {
        do
        {
            file >> i;
            insert(tree, i);
        } 
        while (!file.eof());
    }
    file.close();

    infix_bypass(tree);
    puts("");
    deleteNode(tree, 48);
    infix_bypass(tree);
    puts("");
    prefix_bypass(tree);
    puts("");
    postfix_bypass(tree);
    cout << endl;

    deleteTree(tree);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
