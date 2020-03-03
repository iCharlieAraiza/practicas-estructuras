#include <iostream>

struct jugador{
    int equipo, numero, ID;
    char nombre[25];
    jugador *siguiente;
    jugador *anterior;
    jugador *link;
};

using namespace std;
/**
 *
 * @param p Parametro p tipo apuntador a estructura.
 * @param q Parametro q tipo apuntador a estructura.
 */
void ImprimeListaC(jugador *p, jugador *q);
/**
 *
 * @param p Parametro p tipo apuntador a estructura.
 * @param q Parametro q tipo apuntador a estructura.
 */
void ImprimeListaL(jugador *p, jugador *q);

/**
 *
 * @return Retorna 0 si el código se ejecuta con éxito.
 */
int main() {
    struct jugador *p, *q;
    int opcion;
    char c;
    p = NULL;
    q = NULL;
    
    int id = 1;

        do {
            cout << "\n\n1.- Lista ligada circular" << endl;
            cout << "2.- Lista doblemente enlazada" << endl;
            cout << "3.- Salir" << endl;

            cout << "\nIntroduza su opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    do {
                        cout << "\nDeseas agregar una caja?, presiona 'S': ";
                        cin >> c;

                        if (c == 'S' || c == 's') {
                            q = new jugador;
                            cout << "\n***********" << endl;
                            /*cout << "Introduce tu ID: ";
                            cin >> q->ID;*/
                            q->ID = id;
                            
                            cout << "Introduce tu nombre: ";
                            cin >> q->nombre;

                            cout << "Introduce tu equipo: ";
                            cin >> q->equipo;

                            cout << "Introduce tu numero: ";
                            cin >> q->numero;
                            q->link = q;

                            if (p == NULL) {
                                p = q;
                            }
                            q->link = p->link;
                            p->link = q;
                            
                            id++;
                            
                        }
                    } while (c == 'S' || c == 's'); 
                    
                    id = 1;
                    //Imprimiendo Datos.
                    ImprimeListaC(p, q);
                    break;
                case 2:
                    do {
                        cout << "\nDeseas agregar una caja?, presiona 'S': ";
                        cin >> c;

                        if (c == 'S' || c == 's') {
                            q = new jugador;
                            cout << "\n***********" << endl;
                            cout << "Introduce tu nombre: ";
                            cin >> q->nombre;

                            cout << "Introduce tu equipo: ";
                            cin >> q->equipo;

                            cout << "Introduce tu numero: ";
                            cin >> q->numero;

                            q->siguiente = p;
                            q->anterior = NULL;

                            if (p != NULL) {
                                p->anterior = q;
                            }
                            p = q;
                        }
                    } while (c == 'S' || c == 's');

                    //Imprimiendo datos.
                    cout << "\nImprimiendo datos...\n";
                    ImprimeListaL(p, q);
                    break;
                case 3:
                    cout << "\nHasta luego :D";
                    break;
                default:
                    cout << "\nEsa opcion no existe, elige una valida";
            }
        } while (opcion != 3);

    return 0;
}

void ImprimeListaC(jugador *p, jugador *q){
    
    int id = q->ID;
    
    for(; id >= 1;){
        cout << "\n************" << endl;
        cout << q->ID << endl;
        cout << "Tu nombre es: " << q->nombre << endl;
        cout << "Tu equipo es: " << q->equipo << endl;
        cout << "Tu numero es: " << q->numero << endl;
        cout << "La caja vale: " << q << endl;
        cout << "El link vale: " << q->link;
        
        id = q->ID == 1 ? 0 : q->ID;
        
        q = q->link;
        delete p;
        p = q;
    }
}

void ImprimeListaL(jugador *p, jugador *q){

    for (;p!= NULL;){
        cout << "\n************" << endl;
        cout << "Tu nombre es: " << q->nombre << endl;
        cout << "Tu equipo es: " << q->equipo << endl;
        cout << "Tu numero es: " << q->numero << endl;
        cout << "La caja siguiente vale: " << q->siguiente << endl;
        cout << "La caja anterior vale: " << q->anterior << endl;
        cout << "La caja vale: " << q << endl;
        cout << "El link vale: " << q->link;

        q = q->siguiente;
        delete p;
        p = q;
    }
}
