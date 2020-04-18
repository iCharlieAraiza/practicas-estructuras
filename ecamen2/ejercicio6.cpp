#include <iostream>

using namespace std;

struct Nodo{
    int valor;
    Nodo *left;
    Nodo *right;
};


bool nuevoElemento(int i);
Nodo *crearNodo();
void imprimirArbolPre(Nodo *nodo);
void imprimirArbolPost(Nodo *nodo);
void imprimirArbolEntre(Nodo *nodo);
int getNivel(Nodo *p);
void borrar(Nodo *nodo);


int main()
{

    Nodo *arbol = crearNodo();
    int op;

    do{
        cout << "\nElige una opción: (1) imprimir en recorrido preorden (2) ídem en postorden (3) ídem en entre orden (4) Mostrar el nivel del árbol (5) Salir" << endl;
        cin >> op;
        cout << endl;

        switch(op){
            case 1:
                imprimirArbolPre(arbol);
                break;
            case 2:
                imprimirArbolPost(arbol);
                break;
            case 3:
                imprimirArbolEntre(arbol);
                break;
            case 4:
                cout << "El nivel del árbol es: " << getNivel(arbol)-1<<endl;
                break;
            case 5:
                borrar(arbol);
                break;
            default:
                cout << "¡Ups! Has agregado un valor no válido" <<endl;
        }

    }while(op!=5);



    return 0;
}


bool nuevoElemento(int i){
    string el = i == 1 ? "izquierda" : "derecha";
    char c;

    cout<< "Escribe 's' si deseas agregar un nodo a la "<< el<<": ";
    cin >> c;
    return c == 's' ? true : false;
}


Nodo *crearNodo(){
    Nodo *nodo = new Nodo;
    cout << "Agrega un valor: ";
    cin >> nodo->valor;

    nodo->left = NULL;
    nodo->right = NULL;

    if( nuevoElemento(1) )
        nodo->left = crearNodo();
    if( nuevoElemento(2) )
        nodo->right = crearNodo();

    return nodo;
}

void imprimirArbolPre(Nodo *nodo){
    if(nodo==NULL)
        return;

    cout << nodo->valor<<endl;

    imprimirArbolPre(nodo->left);
    imprimirArbolPre(nodo->right);
}

void imprimirArbolPost(Nodo *nodo){
    if(nodo==NULL)
        return;

    imprimirArbolPost(nodo->left);
    imprimirArbolPost(nodo->right);

    cout << nodo->valor<<endl;
}

void imprimirArbolEntre(Nodo *nodo){
    if(nodo==NULL)
        return;

    imprimirArbolEntre(nodo->left);

    cout << nodo->valor<<endl;

    imprimirArbolEntre(nodo->right);

}

int getNivel(Nodo *p){
    if(p==NULL)
        return 0;
    return 1 + max( getNivel(p->left), getNivel(p->right) );
}

void borrar(Nodo *nodo){
    if(nodo==NULL)
        return;

    Nodo *p = nodo;

    delete nodo;

    borrar(p->left);
    borrar(p->right);

}
