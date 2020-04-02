#include <iostream>

using namespace std;


struct books{
    int clave_libro;
    char titulo[50];
    char autor[50];
    char categoria[100];
    books *next;
};

void imprimirLista(books*);

int main()
{
    books *p=NULL, *q=NULL;
    int cont;
    char el;
    bool s = true;
    
    do{
        cont++;
        p = new books;
        
        cout << endl;
        cout << cont <<".- Clave del libro: "<<endl;
        cin >> p->clave_libro;
        cout << cont <<".- Título: "<<endl;
        cin >> p->titulo;
        cout << cont <<".- Autor: "<<endl;
        cin >> p->autor;
        cout << cont <<".- Categoría: "<<endl;
        cin >> p->categoria;
        
        p->next = q;
        q = p;
        
        if(cont >= 5){
            cout << "¿Deseas agregar otro libro? Escribe 'S' o 's' para confirmar "<<endl;
            cin >> el;
            s = (el == 'S' || el == 's') ? true : false;
        }
        
    }while(s);

    q = p;
    
    imprimirLista(p);
    
    //Eliminar
    
    while(q!=NULL){
        q = p->next;
        delete p;
        p = q;
    }
    
    return 0;
}

void imprimirLista(books *p){
    while(p!=NULL){
        cout << "Clave: " << p->clave_libro << endl;
        cout << "Título: " << p->titulo << endl;
        cout << "Autor: " << p->autor << endl;
        cout << "Categoria: " << p->categoria << endl << endl;
        p = p->next;
    }
}
