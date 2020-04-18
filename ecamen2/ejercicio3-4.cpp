#include <iostream>

using namespace std;

struct alumno {
    char nombre[25];
    char matricula[10];
    float calificacion_final;
    alumno *siguiente;
};

struct alumno *inicial = NULL, *final = NULL, *nuevo = NULL;
void promedio();

bool nuevoElemento();
alumno *crearElemento();
void enqueue(alumno*);
alumno *dequeue();
char *buscarMatricula(char[]);

int main()
{
    alumno *w;
    int op, n;
    char matricula[10];

    do{
        enqueue(crearElemento());
    }while( nuevoElemento() );


    cout << "\nElige una opción: (1) Buscar alumno por matrícula (2) Quitar los elementos de la cola (3) Promedio de los alumnos"<<endl;
    cin >> op;

    switch(op){
        case 1:
            cout << "Escribe la matrícula: ";
            cin >> matricula;

            if(NULL!=buscarMatricula(matricula)){
                cout << "\nEl nombre es: " << buscarMatricula(matricula) << endl;
            }else{
                cout << "\nNo se encontraron resultados para la búsqueda" << endl;
            }
            break;

        case 2:
            while( NULL!=(w = dequeue()) ){
                cout<<"Se ha sacado de la cola "<< w->nombre<<endl;
                delete w;
            }
            break;

        case 3:
            promedio();
            break;
        default:
            cout << "¡Ups! has agregado una opción incorrecta";
    }

    return 0;
}

bool nuevoElemento(){
    char c;
    cout<< "¿Deseas agregar otro elemento? (presiona 's' o 'S'): ";
    cin>> c;
    return c == 's' || c == 'S';
}


alumno *crearElemento(){
    alumno *q = new alumno;

    cout << "Escribe el nombre: ";
    cin >> q->nombre;
    cout << "Escribe la matrícula: ";
    cin >> q->matricula;
    cout << "Escribe la calificación final: ";
    cin >> q->calificacion_final;
    cout << endl;

    return q;
}

void enqueue(alumno *q){
    nuevo = q;
    nuevo->siguiente = NULL;

    if(final == NULL){
        inicial = nuevo;
    }else{
        final->siguiente = nuevo;
    }

    final = nuevo;
}

alumno *dequeue(){
    if(inicial==NULL){
        return NULL;
    }
    alumno *q = inicial;
    inicial = inicial->siguiente;
    q->siguiente =  NULL;

    if(inicial == NULL)
        inicial = NULL;

    return q;
}

char *buscarMatricula(char matricula[]){
    alumno *q = inicial;

    while(q!=NULL){
        if(strcmp(q->matricula, matricula) == 0)
            return q->nombre;

        q = q->siguiente;
    }
    return NULL;
}

void promedio(){
    struct alumno *q = inicial;
    int cont = 0;
    float promedioFinal = 0;
    while(q!=NULL){
        cont++;
        promedioFinal = promedioFinal + q->calificacion_final;
        q = q->siguiente;
    }

    cout << "El promedio final es: " << promedioFinal / cont;
}
