#include <iostream>

using namespace std;


struct jugador_e{
	char nombre[25];
	int numero;
	int equipo;
	struct jugador_e *enlace;
};
struct jugador_e *q=NULL; 

jugador_e *hacerJugador();
void push(jugador_e*);
jugador_e *pop();

int main()
{
    struct jugador_e *p=NULL; 
    
    for(int i = 0; i < 2; i++){
        push( hacerJugador());
    }
    
    
    for(int i = 0; i < 2; i++){
        q = pop();
        cout<<p->nombre<<endl;
    }

    return 0;
}

jugador_e *hacerJugador(){
    struct jugador_e *p;
    p = new jugador_e;
    
    cout << "Escribe el nombre" << endl;
    cin >> p->nombre;
    
    cout << "Escribe el número" << endl;
    cin >> p->numero;
    
    cout << "Escribe el equipo" << endl;
    cin >> p->equipo;
    
    return p==NULL ? NULL : p;
}

void push(jugador_e *p){
    p->enlace = q;
    q = p;
}

jugador_e *pop(){
    jugador_e *p;
    p = q;
    if(p != NULL){
        p = p->enlace;
    }
        
    return p;
}
