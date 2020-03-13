#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int  n, cont = 0;
    char cadena[300];
    string r, m[100];
    bool s = true;

    ifstream fe("nombre.txt");
    fe.getline(cadena, 100);


    for(int i = 0; i < 4; i++){
        r = r + cadena[i];
        if(cadena[i+1]==' '){
            i = 8;
        }
    }

    n = stof(r);

    float A[100] = {0}, B[100] = {0}, test;

    r ="";

    for(int i = 0; i < 100 && s; i++){
        if(cadena[i]==' '){
            m[cont++] = r;
            r="";
            s = cadena[i+1] == NULL ? false : true;
        }else{
            r = r + cadena[i];

            if(cadena[i+1]=='\0'){
                m[cont++] = r;
                s = false;
            }
        }
    }


    for(int i = 0; i<n; i++){
        A[i] = m[i+1] == "" ? 0 : stof(m[i+1]);
    }

    int j = 0;
    for(int i = n-1; i>=0; i--){
        B[j++] = A[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << B[i] << endl;
    }

    return 0;
}
