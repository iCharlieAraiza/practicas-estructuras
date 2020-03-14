#include <iostream>

using namespace std;

const int m =2 , n=5, l=3;

void LeerMatriz(int ***a,int,int,int);
void ImprimirMatriz(int***,int,int,int);

int main()
{

    int ***arr;
    
    arr = new int **[m];

    for(int i = 0; i < m; i++){
        arr[i] = new int *[n];
        for(int j=0; j<n; j++){
            arr[i][j] = new int[l];
        }
    }
    
    LeerMatriz(arr,m,n,l);
    ImprimirMatriz(arr,m,n,l);

    if(arr!=NULL){
        for(int i = 0; i < m; i++){
            if(arr[i]!=NULL){
                delete [] arr[i];
            }
        }
        delete []arr;
    }
    
    return 0;
}

void LeerMatriz(int ***a, int m, int n, int l){
    for(int i= 0; i<m; i++){
        for(int j= 0; j <n; j++){
            for(int k= 0; k<l; k++){
                cout<<"Escribe un valor entero: "<<endl;
                cin>>a[i][j][k];
            }
        }
    }
}

void ImprimirMatriz(int ***a, int m, int n, int l){
    cout << "\nLos valores que agregasate son: "<<endl;
    for(int i= 0; i<m; i++){
        for(int j= 0; j <n; j++){
            for(int k= 0; k<l; k++){
                cout<<a[i][j][k]<<endl;
            }
        }
    }
}
