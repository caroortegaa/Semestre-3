//Carolina Ortega A01025254
//Ximena González A01028604
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

//ejercicio 1
class Bisiesto{
    public: 
    int año;
    
    void division (int año){

        if (año%4==0 && año%100==0 && año%400==0){
            cout<< "el año es bisiesto" << endl;
        }
        else if (año%4==0 && año%100!=0){
            cout<< "el año es bisiesto" << endl;
        }
        else {
            cout<< "el año no es bisiesto"<< endl;
        }
    }
};

//ejercicio 2
void sumar (){ 
    int cantidad;
    int numeros;
    int suma=0;
    cout << "ingrese la cantidad de numeros" ;
    cin >> cantidad;
    for (int i=0; i<cantidad; i++){
        cout<< "ingrese el siguiente numero a sumar" << endl;
        cin >> numeros;
        suma = suma + numeros;
    } 
    cout << suma << endl;     
}

//ejercicio 3
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


//ejercicio 4
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

//ejercicio 5
class Animal {
    public:
        bool pico;
        bool cola;
        string nombre;
        string especie;
        int patas;
        bool alas;
        string color;
        string sonido;
        float peso;

        void hacerSonido(){
            cout<<sonido<<endl;
        }
};

class Perro:public Animal{
    public:
    Perro (){ //constructor
        pico = false;
        cola = true;
        nombre = "perro";
        especie="canis";
		patas=4;
		sonido="guau";
    }
};

class Gato: public Animal{
    public:
    Gato (){
        pico=false;
		cola=true;
		nombre="gato";
		especie="felino";
		patas=4;
		sonido="miau";
    }
};

template <class T> 
class Veterinario{
    public: 
    void inyectar (T mascota){
        mascota.hacerSonido();
    }
};

int main(){
    //main ej.1
    Bisiesto b;
    int añito;
    cout << "Ingrese su año: " << endl;
    cin >> añito;
    b.division(añito);

    //main ej.2
    sumar();

    //main ej.3
    string frase_; 
    cout<< "escribe tu frase" << endl;
    getline (cin,frase_); // para guardar frases

    string palabra_;
    cout<< "escribe tu palabra" << endl;
    cin >> palabra_;

    F frase_o;
    frase_o.conteo(frase_ , palabra_);

    //main ej.4
    Calculadora<int> p;
    p.sumar(8,2);
    p.restar(8,2);
    p.multiplicar(8,2);
    p.dividir(8,2);

    //main ej.5
    Perro piquis;
	Gato malfoy;
	Veterinario<Perro> xime;
    Veterinario<Gato> caro;
	xime.inyectar(piquis);
	caro.inyectar(malfoy);

    return 0;
}