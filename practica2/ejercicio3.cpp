#include <iostream>

using namespace std;

struct Moviedata{
    char movieTitle[70];
    char movieDirector[100];
    int yearReleased;
    int runningTime;
    Moviedata *next;
};

//Lista para agregar otro elemento
bool agregarOtroElemento();

//Imprimirt Lista
void imprimirLista(Moviedata*,int);


int main()
{
    int s = true, cont = 0;
    struct Moviedata *p, *q=NULL;
    
    do{
        p = new Moviedata;
        
        cout <<endl<< ++cont <<".- Nombre de la película: ";
        cin >> p->movieTitle;
        cout << cont <<".- Director: ";
        cin >> p->movieDirector;
        cout << cont <<".- Año: ";
        cin >> p->yearReleased;
        cout << cont << ".- Duración: ";
        cin >> p->runningTime;
        
        p->next = q;
        
        if(q==NULL)
            q = p;
        p->next = q->next;
        q->next = p;
        
        if(cont>=5)
            s = agregarOtroElemento();
    }while(s);

    imprimirLista(p, cont);
    
    for(int i =0; i<cont; i++){
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

void imprimirLista(Moviedata *p, int n){
    for(int i = 0; i<n, i++){
        cout << p->movieTitle << endl;
    }
}
