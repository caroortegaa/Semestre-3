#include <iostream>

using namespace std;

void sumar(){
    int cantidad;
    int numeros;
    int suma=0;
    cout << "Ingrese la cantidad de números: " ;
    cin >> cantidad;
    for(int i=0; i<cantidad; i++){
        cout<< "Ingrese el siguiente número a sumar" << endl;
        cin >> numeros;
        suma=suma+numeros;
    }
    cout << suma << endl;
}

int main(){
    sumar();
    return 0;
}