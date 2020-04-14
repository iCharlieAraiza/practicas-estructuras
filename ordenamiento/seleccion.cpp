#include <iostream>

using namespace std;

int main()
{
    int menor, temp, indice;
    int n = 6;
    int a[n]={6,14,12,4,2,0};
    
    for(int i = 0; i < n-1; i++){
        menor = a[i];
        indice = i;
        for(int j = i; j < n; j++){
            if(menor > a[j]){
                menor = a[j];
                indice = j;
            }
        }
        
        temp = a[i];
        a[i] = a[indice];
        a[indice] = temp;
    }
    
    cout << "El arreglo ordenado: ";
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    

    return 0;
}
