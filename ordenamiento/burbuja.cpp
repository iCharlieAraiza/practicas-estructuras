#include <iostream>

using namespace std;

int main()
{
    int temp, n=6;
    int a[6]={6,14,12,4,2,0};
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }    
    }
    
    cout << "El arreglo ordenado es: ";
    
    for(int i=0; i <n; i++){
        cout << a[i] << " ";
    }
    
    return 0;
}
