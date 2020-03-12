#include <iostream>

using namespace std;

float mayor(float*, int);

int main()
{
    int n;
    
    cout<<"¿Cuántos elementos deseas agregar? "<<endl;
    cin >> n;
    
    float arr[n];
    
    for(int i = 0; i<n; i++){
        cout<<"Escribe un valor: ";
        cin>>arr[i];
    }
    
    cout<<"El númeor mayor es: "<< mayor(arr, n)<<endl;
    

    return 0;
}

float mayor(float *arr, int n){
    float m = 0;
    
    for(int i = 0; i < n; i++){
        m = *arr>m ? *arr : m;
        arr++;
    }
    
    return m;
}
