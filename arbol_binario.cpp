#include <iostream>
#include <stdlib.h> 

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};


bool addNewChild(int n){
    char s;
    string res = (n == 1) ? "left" : "right";
    
    cout << "Preciona 's' si deseas agregar el hijo "<< res << " ";
    cin >> s;
    
    return s=='s';
}


Node *createNode(){
    
    Node *node = new Node;
    
    cout<< "Add a new value: ";
    cin >> node->key;
    
    node->left = NULL;
    node->right = NULL;
    if( addNewChild(1) )
        node->left = createNode();
    if( addNewChild(2) )
        node->right = createNode();
    return node;
}

void printTree(Node *tree){
    if(tree==NULL)
        return;
    cout << tree->key<<endl;
    
    printTree(tree->left);
    printTree(tree->right);
}

void deleteElement(Node *tree){
    if(tree == NULL)
        return;
    Node *p = tree;
    
    delete tree;
    deleteElement(p->left);
    deleteElement(p->right);
}


int getNivel(Node *p){
    if(p==NULL)
        return 0;
    return 1 + max( getNivel(p->left), getNivel(p->right) );
}

int main()
{

    
    struct Node *tree = createNode();
    /*
    cout << "The value of the node is " << tree->key << endl;
    cout << "The value of the left son is " << tree->left->key << endl;
    */
    
    printTree(tree);
    
    cout << "El nivel es: " << getNivel(tree)-1;
    
    deleteElement(tree);
    
    return 0;
}
