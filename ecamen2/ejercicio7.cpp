#include <iostream>

using namespace std;

struct s_jugador_arbol {
    int numero;
    float puntaje;
    char nombre[25];
    s_jugador_arbol *left;
    s_jugador_arbol *right;
};

bool nuevoElemento(int);

s_jugador_arbol *crearArbolJugador();
s_jugador_arbol *BusquedaBinaria( s_jugador_arbol*, int);

int main()
{
    struct s_jugador_arbol *arbol =  crearArbolJugador(), *p;

    int n;

    cout << "Pon el número del jugador que deseas buscar: "<<endl;
    cin >> n;
    p = BusquedaBinaria(arbol, n);
    if(p)
        cout << "El número que buscaste fue: "<< p->nombre <<endl;
    else
        cout << "Ups, no se encotró el número buscado";


    return 0;
}

bool nuevoElemento(int i){
    string el = i == 1 ? "izquierda" : "derecha";
    char c;

    cout<< "Escribe 's' si deseas agregar un nodo a la "<< el<<": ";
    cin >> c;
    return c == 's' ? true : false;
}


s_jugador_arbol *crearArbolJugador(){
    s_jugador_arbol *nodo = new s_jugador_arbol;
    cout << "Agrega el numero: ";
    cin >> nodo->numero;

    cout << "Agrega el puntaje: ";
    cin >> nodo->puntaje;

    cout << "Agrega el nombre: ";
    cin >> nodo->nombre;

    nodo->left = NULL;
    nodo->right = NULL;

    if( nuevoElemento(1) )
        nodo->left = crearArbolJugador();
    if( nuevoElemento(2) )
        nodo->right = crearArbolJugador();

    return nodo;
}

s_jugador_arbol * BusquedaBinaria( s_jugador_arbol *p, int num ) {
    if (p == NULL)
        return NULL;
    if (num == p->numero)
        return p;
    if (num < p->numero)
        return BusquedaBinaria (p->left, num);
    if (num > p->numero)
        return BusquedaBinaria (p->right, num);
}

