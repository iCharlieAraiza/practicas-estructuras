#include <iostream>

using namespace std;

struct s_jugador {
    int numero;
    float puntaje;
    char nombre[25];
    s_jugador *siguiente;
};

struct s_jugador *p = NULL, *w;

bool nuevoElemento();
s_jugador *crearElemento();

void push(s_jugador*);
s_jugador *pop();
char *buscarNumero(int);

int main()
{
    
    int op, numero;
    
    do{
        push( crearElemento() );
    }while(nuevoElemento());
    
    w = p;

    cout << "\nElige una opción: (1) Buscar elemento (2) Quitar los elementos de una pila"<<endl;
    cin >> op;

    switch(op){
        case 1:
            cout << "Escribe el número del jugador: ";
            cin >> numero;

            if(NULL!=buscarNumero(numero)){
                cout << "\nEl nombre es: " << buscarNumero(numero) << endl;
            }else{
                cout << "\nNo se encontraron resultados para la búsqueda" << endl;
            }
            break;

        case 2:
            while(NULL != ( w=pop() ) ){
                cout << "Se ha quitado de la pila a " << w->nombre <<endl;
                delete w;
            }
            break;

        default:
            cout << "¡Ups! has elegido una opción inválida" << endl;
    }

    return 0;
}

bool nuevoElemento(){
    char c;
    cout<< "¿Deseas agregar otro elemento? (presiona 's' o 'S'): ";
    cin>> c;
    return c == 's' || c == 'S';
}

s_jugador *crearElemento(){
    s_jugador *q;
    q = new s_jugador;
    
    cout<<"Escribe el numero: ";
    cin>> q->numero;
    
    cout<<"Escribe el puntaje: ";
    cin>> q->puntaje;
    
    cout<<"Escribe el nombre: ";
    cin>> q->nombre;
    
    cout<<endl;
    
    return q;
}

void push(s_jugador *q){
    q->siguiente = p;
    p = q;
}

s_jugador *pop(){
    s_jugador *q;
    q = p;
    if(p!=NULL){
        p = p->siguiente;
    }
    return q;
}

char *buscarNumero(int numero){
    s_jugador *q;
    q=p;

    while(p!=NULL){
        if(p->numero == numero){
            return p->nombre;
        }
        q = p->siguiente;
        p = q;
    }

    return NULL;
}
