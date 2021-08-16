#include <iostream>

using namespace std;

class Bisiesto{
    public:
    int año;
    
    void division(int año){
        if (año%4==0 && año%100==0 && año%400==0){
            cout<<"El año es bisiesto"<<endl;
        }
        else if (año%4==0 && año%100!=0){
            cout<<"El año es bisiesto"<<endl;
        }
        else {
            cout<<"El año NO es bisiesto"<<endl;
        }
    }
};

int main(){
    Bisiesto b;
    int añito;
    cout << "Ingrese su año: " << endl;
    cin >> añito;
    b.division(añito);

    return 0;
}