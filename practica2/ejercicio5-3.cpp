#include <iostream>

using namespace std;

struct Pila{
    int n;
    struct Pila *next;
};

struct Pila *p_ = NULL, *w_, *inicio_=NULL;

Pila *crearElemento(int);

void push(Pila*);
Pila *pop();

int main()
{
    
    
    for(int i = 0; i < 10; i++){
        push( crearElemento(i) );
    }
    
    
    cout << "Recorre dos veces del 0 al 9"<<endl<<endl;
    for(int i = 0; i < 20; i++){
        w_=pop();
        cout << w_->n <<endl;
    }
    
    for(int i = 0; i < 10; i++){
        w_=pop();
        delete w_;
    }

    return 0;
}

Pila *crearElemento(int n){
    Pila *q = new Pila;
    q->n = n;
    return q;
}

void push(Pila *q){
    q->next = p_;
    if(p_==NULL)
        inicio_ = q;
    inicio_->next = q;    
    p_ = q;
}

Pila *pop(){
    Pila *q;
    q = p_;
    if(p_!=NULL){
        p_ = p_->next;
    }
    return q;
}
