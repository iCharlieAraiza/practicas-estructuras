#include <iostream>

using namespace std;

struct Nodo{
    int key;
    Nodo *left;
    Nodo *right;
};

void imprimirArbolPre(Nodo *);
void imprimirArbolPost(Nodo *);
void imprimirArbolEntre(Nodo *);

void deleteElement(Nodo *tree){
    if(tree == NULL)
        return;
    Nodo *p = tree;

    delete tree;
    deleteElement(p->left);
    deleteElement(p->right);
}


int getNivel(Nodo *p){
    if(p==NULL)
        return 0;
    return 1 + max( getNivel(p->left), getNivel(p->right) );
}

int main()
{


    struct Nodo *tree = new Nodo;
    tree->key = 19;

    tree->left = new Nodo;
    tree->left->key = 13;
    tree->left->left = new Nodo;
    tree->left->left->key = 9;
    tree->left->right = new Nodo;
    tree->left->right->key = 16;
    tree->left->right->left = new Nodo;
    tree->left->right->left->key = 145;

    tree->right = new Nodo;
    tree->right->key = 30;
    tree->right->left = new Nodo;
    tree->right->right = new Nodo;
    tree->right->left->key = 25;
    tree->right->right->key = 35;
    tree->right->left->right = new Nodo;
    tree->right->left->right->key = 29;

    cout << "En preorden: " << endl;
    imprimirArbolPre(tree);

    cout << endl << "En postorden: " << endl;
    imprimirArbolPost(tree);

    cout << endl << "En entreorden: " << endl;
    imprimirArbolEntre(tree);

    //deleteElement(tree);

    return 0;
}

void imprimirArbolPre(Nodo *nodo){
    if(nodo==NULL)
        return;

    cout << nodo->key<< " ";

    imprimirArbolPre(nodo->left);
    imprimirArbolPre(nodo->right);
}

void imprimirArbolPost(Nodo *nodo){
    if(nodo==NULL)
        return;

    imprimirArbolPost(nodo->left);
    imprimirArbolPost(nodo->right);

    cout << nodo->key<< " ";
}

void imprimirArbolEntre(Nodo *nodo){
    if(nodo==NULL)
        return;

    imprimirArbolEntre(nodo->left);

    cout << nodo->key<<" ";

    imprimirArbolEntre(nodo->right);

}

