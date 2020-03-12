#include <iostream>
using namespace std;

void memoriaEstatica();
void memoriaDinamica();

int main() {
    
    return 0;
}


void memoriaEstatica(){
    int arr[2][5][3], cont = 0;

    for(int i = 0; i<2; i++){
        for(int j = 0; j<5; j++){
            for (int k = 0; k < 3; ++k) {
                cout<< ++cont <<".- Agrega un elemnto: ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout<<endl;
    cont = 0;

    for(int i = 0; i<2; i++){
        for(int j = 0; j<5; j++){
            for (int k = 0; k < 3; ++k) {
                cout<< ++cont <<".-  " << arr[i][j][k] << endl;
            }
        }
    }

}

void memoriaDinamica(){

    int ***arr, m=2, n=5, l=3, cont = 0;

    arr = new int **[m];

    for(int i = 0; i < m; i++){
        arr[i] = new int *[n];
        for(int j=0; j<n; j++){
            arr[i][j] = new int[l];
        }
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k < l; k++){
                cout << ++cont <<" Agrega un valor: ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout<<endl;

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k < l; k++){
                cout << arr[i][j][k]<<endl;
            }
        }
    }

    if(arr!=NULL){
        for(int i = 0; i<m; i++){
            if(arr[i]!=NULL){
                for(int j=0; j<n; j++){
                    if(arr[i][j]!=NULL){
                        delete[] arr[i][j];
                    }
                }
                delete [] arr[i];
            }
        }delete [] arr;
    }
}
