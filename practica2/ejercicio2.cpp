#include <iostream>

using namespace std;

struct address{
    char name[50];
    char street[100];
    char city[50];
    char state[20];
    int pin;
    address *next;
    address *prev;
};

//Lista para agregar otro elemento
bool agregarOtroElemento();

//Imprimirt Lista
void imprimirLista(address*);


int main()
{
    int s = true, cont;
    struct address *p, *q=NULL;
    
    do{
        cont++;
        
        p = new address;
        
        cout << endl << cont << ".- Agrega el nombre: ";
        cin >> p->name;
        cout << cont << ".- Agrega la calle: ";
        cin >> p->street;
        cout << cont << ".- Agrega la ciudad: ";
        cin >> p->city;
        cout <<  cont << ".- Agrega el estado: ";
        cin >> p->state;
        cout << cont << ".- Agrega el PIN: ";
        cin >> p->pin;
        
        p->next = q;
        p->prev = NULL;
        
        if(q!=NULL)
            q->prev = p;
            
        q = p;
        
        if(cont>=5)
            s = agregarOtroElemento();
    }while(s);

    imprimirLista(p);
    
    while(p!=NULL){
        q = p->next;
        delete p;
        p = q;
    }
    
    return 0;
}


bool agregarOtroElemento(){
    char s;
    cout << endl <<"¿Deseas agregar otro elemento?" << endl;
    cin >> s;
    return s == 'S' || s == 's';
}

void imprimirLista(address *p){
    while(p!=NULL){
        cout << endl << "Nombre: " << p->name<<endl;
        cout << "Calle: " << p->street<<endl;
        cout << "Ciudad: " << p->city<<endl;
        cout << "Estado: " << p->state<<endl;
        cout << "PIN: " << p->pin<<endl;
        p = p->next;
    }
}
