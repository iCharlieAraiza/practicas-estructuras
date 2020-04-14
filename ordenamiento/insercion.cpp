#include <iostream>

using namespace std;

int main()
{
    int j, temp, n = 6;
    int a[n] = {6, 14, 12, 4, 2, 0};
    
    for(int i = 0; i < n; i++){
        temp = a[i];
        for(j = i-1; j>= 0 && a[j] < temp; j--){
            a[i] = a[j];
        }
        a[j+1] = temp;
    }
    
    cout << "El arreglo ordenado es: ";
    for(int i =0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
