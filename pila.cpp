#include <iostream>

using namespace std;

struct jugador_e{
    char nombre[25];
    int numero;
    int equipo;
    struct jugador_e *enlace;
};

struct jugador_e *p = NULL, *w;

bool nuevoElemento();
jugador_e *crearElemento();

void push(jugador_e*);
jugador_e *pop();
char *buscarEquipo(int);

int main()
{
    
    int op, equipo;
    
    do{
        push( crearElemento() );
    }while(nuevoElemento());
    
    w = p;
    
    cout << "\nElige una opción: (1) Buscar elemento (2) Quitar los elementos de una pila"<<endl;
    cin >> op;
    
    switch(op){
        case 1:
            cout << "Escribe el número de equipo: ";
            cin >> equipo;
            
            if(NULL!=buscarEquipo(equipo)){
                cout << "\nEl nombre es: " << buscarEquipo(equipo) << endl;
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

jugador_e *crearElemento(){
    jugador_e *q;
    q = new jugador_e;
    
    cout<<"Escribe el nombre: ";
    cin>> q->nombre;
    
    cout<<"Escribe el numero: ";
    cin>> q->numero;
    
    cout<<"Escribe el equipo: ";
    cin>> q->equipo;
    
    cout<<endl;
    
    return q;
}

void push(jugador_e *q){
    q->enlace = p;
    p = q;
}

jugador_e *pop(){
    jugador_e *q;
    q = p;
    if(p!=NULL){
        p = p->enlace;
    }
    return q;
}

char *buscarEquipo(int equipo){
    jugador_e *q;
    q=p;
    
    while(p!=NULL){
        if(p->equipo == equipo){
            return p->nombre;
        }
        q = p->enlace;
        p = q;
    }
    
    return NULL;
}
