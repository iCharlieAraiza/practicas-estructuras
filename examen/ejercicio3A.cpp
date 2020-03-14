#include <iostream>

using namespace std;

const int m =2 , n=2, l=2;

void LeerMatriz(int(&a)[m][n][l],int,int,int);
void ImprimirMatriz(int[m][n][l],int,int,int);

int main()
{

    int arr[m][n][l];
    LeerMatriz(arr,m,n,l);
    ImprimirMatriz(arr,m,n,l);
/*

1. Hacer un programa que capture los datos de un arreglo multidimensional de taman ̃o 2x5x3 (3 dimensiones) y que, una vez capturados, los despliegue en la pantalla.
Usando memoria est ́atica.
Usando memoria din ́amica.
NOTA: Se REQUIERE crear dos ”funciones”: Una llamada ”LeerMatriz” y otra llamada ”ImprimirMatriz”. Ambas funciones deben de tener paso de par ́ametros: nombre arreglo, dimension 1, dimension 2, dimension 3.

*/


    return 0;
}

void LeerMatriz(int(&a)[m][n][l], int m, int n, int l){
    for(int i= 0; i<m; i++){
        for(int j= 0; j <n; j++){
            for(int k= 0; k<l; k++){
                cout<<"Escribe un valor entero: "<<endl;
                cin>>a[i][j][k];
            }
        }
    }
}

void ImprimirMatriz(int a[m][n][l], int m, int n, int l){
    cout << "\nLos valores que agregasate son: "<<endl;
    for(int i= 0; i<m; i++){
        for(int j= 0; j <n; j++){
            for(int k= 0; k<l; k++){
                cout<<a[i][j][k]<<endl;
            }
        }
    }
}
