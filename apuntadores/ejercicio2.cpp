#include <iostream>

using namespace std;

int main(){
    
    double a = 100, b = 200, *p1, *p2;
    
    p1 = &a;
    p2 = &b;
    
    double **p3 = &p2;
    
    a = *p1 + 2*b;
    
    *p2 = 3*a + 3*(**p3);
    
    *p3 = &b;
    
    p3 = &p2;
    
    *p3 = &a;
    
    **p3 = *p2 - (*p1)*b;
    
    cout << "a: "<< a << " b: " << b;
    
}
