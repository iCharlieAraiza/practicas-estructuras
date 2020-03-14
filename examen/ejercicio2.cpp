#include <iostream>

using namespace std;

int main()
{
    /*
    0.2 Arreglos Din ́amicos (1.5 punto)
    • Hacer un programa que pida al usuario el número n, que aloje memoria para los arreglos G y Q (de tipo double) el arreglo G ser ́a de taman ̃o n y el arreglo Q de taman ̃o 2n.
    • Una vez alojados los arreglos, pedir los elementos de los arreglos G y Q. En G se guarda el resultado de multiplicar por 4 a cada uno de sus elementos, mientras que en Q se suma un 3 a cada uno de sus elementos.
    */
    
    int n, val;
    
    cout << "Escribe el numero de elemntos: "<<endl;
    cin>>n;
    
    double *G = new double[n], *Q = new double[2*n];
    
    cout << "Arreglo G"<<endl;
    for(int i = 0; i < n; i++){
        cout <<i+1 <<".- Escribe el valor: ";
        cin>>val;
        G[i] = val *4;
    }
    
    cout << "\nArreglo Q"<<endl;
    for(int i = 0; i < 2*n; i++){
        cout <<i+1 <<".- Escribe el valor: ";
        cin>>val;
        Q[i] = val +3;
    }

    cout << "\nLo que almacena el arreglo G"<<endl;
    for(int i = 0; i < n; i++){
        cout <<G[i]<<endl;
    }

    cout << "\nLo que almacena el arreglo Q"<<endl;
    for(int i = 0; i < 2*n; i++){
        cout <<Q[i]<<endl;
    }

    if(Q!=NULL)
        delete [] Q;
    if(G!=NULL)
        delete []G;

    return 0;
}
