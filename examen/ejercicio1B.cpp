
#include <iostream>

using namespace std;

int main()
{
    //Encontrar el número máximo de datos enteros
    int n, cont = 0, max;
    
    cout << "Ingresa el número total de elementos que tenrá el arreglo: " <<endl;
    cin>>n;
    
    int *arr = new int[n];
    
    while(cont<n){
        cout<< cont+1 <<".- Agrega un número entero: "<< endl;
        cin >> arr[cont];
        cont++;
    }
    
    max = arr[0];
    
    for(int i = 0; i<n; i++){
        max = arr[i] > max ? arr[i] : max;
    }
    
    int *z = &max;
    
    cout << "Valor de lo que apunta z: "<< *z <<endl;
    cout << "Dirección de memoria que guarda z: "<< z <<endl;
    cout << "Dirección de memoria de z: " << &z;
    
    if(arr!=NULL)
        delete [] arr;
    return 0;
}
