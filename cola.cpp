#include <iostream>

using namespace std;

struct jugador_e{
    char nombre[25];
    int numero;
    int equipo;
    struct jugador_e *enlace;
};

struct jugador_e *inicial = NULL, *final = NULL, *nuevo = NULL;

bool nuevoElemento();
jugador_e *crearElemento();
void enqueue(jugador_e*);
jugador_e *dequeue();
char *buscarNumero(int);

int main()
{
    jugador_e *w;
    int op, n;
    
    do{
        enqueue(crearElemento());
    }while( nuevoElemento() );
    
    
    cout << "\nElige una opción: (1) Buscar elemento (2) Quitar los elementos de la cola"<<endl;
    cin >> op;
    
    switch(op){
        case 1:
            cout << "Escribe el número: ";
            cin >> n;
            
            if(NULL!=buscarNumero(n)){
                cout << "\nEl nombre es: " << buscarNumero(n) << endl;
            }else{
                cout << "\nNo se encontraron resultados para la búsqueda" << endl;
            }
            break;
        
        case 2:
            while( NULL!=(w = dequeue()) ){
                cout<<"Se ha sacado de la cola "<< w->nombre<<endl;
                delete w;
            }
            break;
        
        default:
            cout << "¡Ups! has agregado una opción incorrecta";
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
    jugador_e *q = new jugador_e;
    
    cout << "Escribe el nombre: ";
    cin >> q->nombre;
    cout << "Escribe el numero: ";
    cin >> q->numero;
    cout << "Escribe el numero de equipo: ";
    cin >> q->equipo;
    cout << endl;
    
    return q;
} 

void enqueue(jugador_e *q){
    nuevo = q;
    nuevo->enlace = NULL;
    
    if(final == NULL){
        inicial = nuevo;    
    }else{
        final->enlace = nuevo;
    }
    
    final = nuevo;
}

jugador_e *dequeue(){
    if(inicial==NULL){
        return NULL;
    }
    jugador_e *q = inicial;
    inicial = inicial->enlace;
    q->enlace =  NULL;
    
    if(inicial == NULL)
        inicial = NULL;
        
    return q;
}

char *buscarNumero(int numero){
    jugador_e *q = inicial;
    
    while(q!=NULL){
        if(q->numero == numero)
            return q->nombre;
    
        q = q->enlace;        
    }
    return NULL;
}
