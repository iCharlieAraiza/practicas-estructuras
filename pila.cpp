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
    
    do{
        push( rearElemento() );
    }while(nuevoElemento());
    
    w = p;
    
    /*
    for(int i=0; i<2; i++){
        cout<< i+1<< ".- Nombre: "<< p->nombre <<endl;
        w = p->enlace;
        p = w;
    }
    */
    
    cout<< "El nombre es: "<< buscarEquipo(3);
    
    int i=0;
    /*
    while(NULL != ( w=pop() ) ){
        cout << i+1 <<".- Nombre: "<< w->nombre <<endl;
        delete w;
        i++;
    }
    */
    return 0;
}

bool nuevoElemento(){
    char c;
    cout<< "\n Otra caja? ";
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
