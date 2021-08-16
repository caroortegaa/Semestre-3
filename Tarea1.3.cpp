#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

class F{
    public:
    string frase;
    string palabra;

    void conteo (string frase, string palabra){
        int i=0;
        int j=0;
        int contador=0;
        for (int i=0; i < frase.length(); i+=1){
            if (frase[i]==palabra[j])
            {
                j += 1;
            }
            else if (frase[i]!= palabra[j]){
                j=0;
            }
            if (j==palabra.length()-1){
                contador += 1;
                j=0;
            }
        }
        cout<<"la palabra se repitio:" << contador << endl;
    }
};

int main(){
    string frase_;
    cout<< "escribe tu frase" << endl;
    getline (cin,frase_); // para guardar frases

    string palabra_;
    cout<< "escribe tu palabra" << endl;
    cin >> palabra_;

    F frase_o;
    frase_o.conteo(frase_ , palabra_);

    return 0;
}