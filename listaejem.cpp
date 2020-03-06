#include <stdio.h>
#include <iostream>

using namespace std;


struct jugador{
    char nombre[20];
    int numero;
};

struct equipo{
    char nombre[40];
    jugador jug[10];
    equipo *next;
};

int main()
{
    struct equipo *p = NULL, *q = NULL;
    int n;
    char s;
    
    do{
        p = new equipo;
        cout << "Escribe el nombre del equipo: " << endl;
        cin >> p->nombre;
        cout << "Escribe el número de jugadores que vas a agregar:" << endl;
        cin >> n;
        
        for(int i = 0; i < n; i ++ ){
            cout << endl << i + 1 << ".- Escribe el nombre del jugador" << endl;  
            cin >> p->jug[i].nombre;
            cout << i + 1 << ".- Escribe el número del jugador" << endl;  
            cin >> p->jug[i].numero;
        }
        
        p->jug[n].nombre[0] = '-'; 
        
        p->next = q;
        q = p;
        
        cout << endl << "¿Deseas agregar otro elemento?" <<endl;
        cin >> s;
        
    }while( s=='S' || s=='s' );
    
    while(p!=NULL){
        int i = 0;
        cout << "Equipo " << p->nombre << endl;
        
        while(p->jug[i].nombre[0]!= '-'){
            cout <<  p->jug[i].numero << " " << p->jug[i].nombre << endl;
            i++;
        }
        
        q = p->next;
        p = q;
    
    }
    
    while(p!=NULL){
        q = p->next;
        delete p;
        p = q;
    }

    return 0;
}
