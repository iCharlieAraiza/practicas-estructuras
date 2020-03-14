#include <iostream>

using namespace std;

struct usuario{
    int id;
    char nombre[20];
    char passw[20];
    usuario *next;
};

int main()
{
   struct usuario *p =NULL, *q = NULL;
    char s;
    
    int id = 0;
    
    do{
        p = new usuario;
        
        p->id = id++;
        
        cout << "Agrega el nombre: ";
        cin >> p->nombre;

        cout << "Agrega la contraseña: " ;
        cin >> p->passw;
        
        p->next = p;

        if(q==NULL){
            q = p;
        }

        p->next = q->next;
        q->next = p;
        
        cout << endl << "¿Deseas agregar otro elemento?" <<endl;
        cin >> s;
    }while( s=='S' || s=='s');        

    for(int i = 0; i < id; i++){
        cout<< "ID: "<<p->id <<" Nombre de usuario: "<< p->nombre << " Contraseña: " << p->passw << endl;
        p = p->next;
    }

    while(p!=NULL){
        q = p->next;
        delete p;
        p=q;
    }

    return 0;
}
