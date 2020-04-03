#include <iostream>

using namespace std;

struct ColaA{
    int n;
    ColaA *next;
};

struct ColaB{
    int n;
    ColaB *next;
};



//Lista para agregar otro elemento
bool agregarOtroElemento();

ColaA *crearPila(int n);
ColaB *crearCola(int n);

void push(ColaA*);
void enqueue(ColaB*);

ColaA *pop();
ColaB *dequeue();

struct ColaA *p = NULL, *w;
struct ColaB *inicial = NULL, *final = NULL, *nuevo = NULL, *k;


int main()
{
    
    for(int i = 1; i <= 10; i++){
        push(crearPila(i));
    }
    
    
    cout << "ColaA"<<endl<<endl;
    while(NULL != (w = pop()) ){
        cout << w->n << endl;
        enqueue(crearCola(w->n));
        delete w;
    }
    
    cout << endl <<"ColaB"<<endl<<endl;
    while(NULL != (k = dequeue()) ){
        cout << k->n << endl;
        delete k;
    }
    //enqueue(crearCola(w->n));
    
    
    return 0;
}

bool agregarOtroElemento(){
    char s;
    cout << endl <<"¿Deseas agregar otro elemento?" << endl;
    cin >> s;
    return s == 'S' || s == 's';
}

ColaA *crearPila(int n){
    ColaA *r = new ColaA;
    r->n = n;
    return r;
}

ColaB *crearCola(int n){
    ColaB *q = new ColaB;
    q->n = n;
    return q;
}

ColaA *pop(){
    ColaA *q;
    q = p;
    if(p!=NULL){
        p = p->next;
    }
    return q;
}

void push(ColaA *q){
    q->next = p;
    p = q;
}

void enqueue(ColaB *q){
    nuevo = q;
    nuevo->next = NULL;
    
    if(final == NULL){
        inicial = nuevo;    
    }else{
        final->next = nuevo;
    }
    
    final = nuevo;
}

ColaB *dequeue(){
    if(inicial==NULL){
        return NULL;
    }
    ColaB *q = inicial;
    inicial = inicial->next;
    q->next =  NULL;
    
    if(inicial == NULL)
        inicial = NULL;
        
    return q;
}
