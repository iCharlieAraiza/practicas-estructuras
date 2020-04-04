#include <iostream>

using namespace std;

struct student{
    char name[50];
    int enrollment;
    float average;
    student *next;
};

struct student *n = NULL, *i=NULL, *f=NULL;

//Lista para agregar otro elemento
bool agregarOtroElemento();

student *crearElemento();

void enqueue(student*);
student *dequeue();

int main()
{
    struct student *w;
    
    do{
        enqueue(crearElemento());
    }while(agregarOtroElemento());

    while(NULL!= (w = dequeue()) ){
        cout << w->name << endl;
        cout << w->enrollment << endl;
        cout << w->average << endl<<endl;
        
        delete w;
    }
    
    return 0;
}

bool agregarOtroElemento(){
    char s;
    cout << endl <<"¿Deseas agregar otro elemento?" << endl;
    cin >> s;
    return s == 'S' || s == 's';
}

student *crearElemento(){
    n = new student;
    cout <<"Nombre del estudiante: ";
    cin >> n->name;
    cout<<"Matricula: ";
    cin >> n->enrollment;
    cout <<"Pomedio: ";
    cin >> n->average;
    
    return n;
}

void enqueue(student *q){
    q->next = NULL;
    if(f==NULL)
        i=q;
    else
        f->next = q;
    f = q;
}

student *dequeue(){
    if(i == NULL)
        return NULL;
    student *q = i;
    i = i->next;
    q->next = NULL;
    
    if(i == NULL)
        f = NULL;
    return q;
}
