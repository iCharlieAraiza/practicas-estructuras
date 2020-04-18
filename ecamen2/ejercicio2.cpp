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
char *buscarEquipo(int);

int main()
{
    
    int op, equipo;
    
    do{
        push( crearElemento() );
    }while(nuevoElemento());
    
    w = p;

    while(NULL != ( w=pop() ) ){
        cout << "Se ha quitado de la pila a " << w->nombre <<endl;
        delete w;
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
