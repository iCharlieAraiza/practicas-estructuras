#include <iostream>

using namespace std;

struct time_{
    int minutes;
    int seconds;
    int hours;
    time_ *next;
};

struct time_ *p = NULL, *w = NULL;

//Lista para agregar otro elemento
bool agregarOtroElemento();

time_ *crearelemento();
void push(time_*);
time_ *pop();

int main()
{
    int s = true, cont = 0;
    struct time_ *q=NULL;
    
    
    do{
        push(crearelemento());
    }while(agregarOtroElemento());
    
    
    while(NULL != ( w=pop() ) ){
        cout << w->hours << ":" << w->minutes << ":" << w->seconds << endl; 
        delete w;
    }

    while(q!=NULL){
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

time_ *crearelemento(){
    
    time_ *q = new time_;
    cout <<endl<<"Agrega las horas: "<<endl;
    cin >> q->hours;
    cout << "Agrega los minutos: "<<endl;
    cin >> q->minutes;
    cout << "Agrega los segundos: "<<endl;
    cin >> q->seconds;
    
    return q;
}

void push(time_ *q){
    q->next = p;
    p = q;
}

time_ *pop(){
    time_ *q;
    q = p;
    if(p!=NULL){
        p = p->next;
    }
    return q;
}
