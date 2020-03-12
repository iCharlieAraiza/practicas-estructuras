#include <iostream>

using namespace std;

int main(){

    int *a, *b, *c, i, j;
    
    a = &i;
    b = &i;
    c = &j; 

    *b = 4;
    *c = 3;
    
    *a = 2*(*b)+(*c);
    
    cout << "i: " << i << " j: " << j <<endl;
    
}
