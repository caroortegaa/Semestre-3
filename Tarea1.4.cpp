#include <iostream>

using namespace std;

template<class T>
class Calculadora {
    public:
    void sumar (T a, T b){
        T c=a+b;
        cout << "La suma es: " << c << endl;
    }

    void restar (T a, T b){
        T c=a-b;
        cout << "La resta es: " << c << endl;
    }

    void multiplicar (T a, T b){
        T c=a*b;
        cout << "La multiplicación es: " << c << endl;
    }

    void dividir (T a, T b){
        T c=a/b;
        cout << "La división es: " << c << endl;
    }
};

int main(){
    Calculadora<int> p;
    p.sumar(8,2);
    p.restar(8,2);
    p.multiplicar(8,2);
    p.dividir(8,2);

    return 0;
}