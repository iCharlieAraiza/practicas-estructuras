#include <iostream>

void arregloEstatico();
void arregloDinamico();

using namespace std;

int main()
{
    arregloEstatico();
    return 0;
}

void arregloEstatico(){
    int m=10, n=10;
    
    int arr[m][n];
    
    for(int i=0; i<m; i++){
        for(int j = 0; j < n; j++){
            cout<<"Agrega un valor: ";
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<endl;
        }
    }

}


void arregloDinamico(){
    int **arr, m=10, n=10;
    
    arr = new int *[m];
    
    for(int i = 0; i<m; i++){
        arr[i] = new int[n];
    }

    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Agrega un nuevo valor: ";
            cin>>arr[i][j];
        }
    }
    
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< arr[i][j]<<endl;
        }
    }
    
    if(arr!=NULL){
        for(int i = 0; i < m; i++){
            if(arr[i]!=NULL){
                delete [] arr[i];
            }
        }
        delete []arr;
    }
}
