#include <iostream>

using namespace std;

void ordenamientoBurbuja(int*, int);

int main()
{
    int a[] = {70,23,34,3,1,2,3,4,6,37,5,7,3,13,0};
    int aux, size = *(&a + 1) - a; 

    ordenamientoBurbuja(a, size);
    
    for(int i = 0; i <size; i++){
        cout << a[i]<< " ";
    }
    
    return 0;
}

void ordenamientoBurbuja(int *a, int size){
    int aux;
        
    for(int i=0; i < size; i++){
        for(int j=i+1; j< size; j++){
            if(a[i]>a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
    
}
