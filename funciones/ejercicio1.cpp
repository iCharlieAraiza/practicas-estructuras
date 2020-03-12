#include <iostream>

using namespace std;

double Far_to_Cent(double);

int main()
{
    double t;
    
    cout << "Escribe la temperatura en grados Fahrenheit: ";
    cin >> t;
    
    cout<< t <<"ºF es "<< Far_to_Cent(t) <<"ºC";
    
    return 0;
}

double Far_to_Cent(double F){
    return (F - 32) * 5/9;
}
