#include <iostream>

using namespace std;


float AgregarAumento(float);


struct caja{
    int id;
    char nombre[30]; 
    int cantidad; 
    float precio;
    caja *link;
};

int main()
{
    struct caja *ini=NULL, *aux=NULL;
    int s=1, id= 0;
    
    
    while(s!=0){
        do{
            cout << "\nDeseas agregar una caja? (1) Sí (0) No" << endl;
            cin >> s;
            
        }while(s!=0&&s!=1);
        
        if(s==1){
            ini = new caja;
            ini->id = id++;
            cout << "\nAgrega el nombre: ";
            cin >> ini->nombre;
    
            cout << "Agrega la cantidad: " ;
            cin >> ini->cantidad;
    
            cout << "Agrega el precio: " ;
            cin >> ini->precio;
    
            ini->link = aux;
            aux = ini;

        }
        
    }
    
        while(aux!=NULL){
            aux->precio = AgregarAumento(aux->precio);
            aux= aux->link;
        }
        
        while(ini!=NULL){
            cout<<"ID: "<<ini->id<<endl;
            cout<<"Nombre: "<<ini->nombre<<endl;
            cout<<"Cantidad: "<<ini->cantidad<<endl;
            cout<<"Precio: "<<ini->precio<<endl;
            
            aux = ini->link;
            
            delete ini;
            ini = aux;
        }
        


    return 0;
}

float AgregarAumento(float precio){
    return precio*1.25;
}
