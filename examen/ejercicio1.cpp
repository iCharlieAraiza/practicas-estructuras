#include <iostream>

using namespace std;

int main()
{
    float *x, *y, *z, m, n;
    x = &m;
    y= &m;
    z = &n;
    
    *y = 45;
    *z = 10;
    
    *x = 3*(*y)+2*(*z);
    
    cout << "m: " << m << " n: "<< n;

    return 0;
}
