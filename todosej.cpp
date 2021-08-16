//Ximena González A01028604
//Carolina Ortega A01025254
#include <iostream>
#include <string>
using namespace std;

//ejercicio 1
int potencia(int n , int a,int resultado=0){
    if (a==0){
        return resultado;
    }
    else {
        resultado=n+resultado;
        return potencia (n,a-1,resultado);;
    } 
};

//ejercicio 2
int potencia_(int n_ , int a_ ,int resultado_=1){
    if (a_==0){
        return resultado_;
    }
    else {
        resultado_=n_*resultado_;
        return potencia_ (n_,a_-1,resultado_);;
    } 
};

//ejercicio 3
int fibonacci(int n, int i=0, int r=0, int sec_1=1, int sec_2=0){

    if (i==n){
        return r;
    }
    else{
        r= sec_1 + sec_2;
        sec_1=sec_2;
        sec_2= r;
        return fibonacci(n,i+=1, r, sec_1, sec_2);
    }
}
//ejercicio 4
string invertir (string f, string fn, int i){
   
    if (fn.length()==f.length()){
        fn+=f[0];
        return fn;
    }
    else{
        fn+=f[i];
        return invertir (f,fn, i-1);
    }
};

//main ejercicio 1
int main(){
    int n;
    cout << "Ingrese número a multiplicar: ";
    cin >> n;
    int a;
    cout << "Ingrese otro número a multiplicar: ";
    cin >> a;
    int resultado= potencia (n,a);
    potencia(n,a,resultado);
    cout << resultado <<endl;

    //main ejercicio 2
    int n_;
    cout << "Ingrese número base: ";
    cin >> n_;
    int a_;
    cout << "Ingrese la potencia a elevar: ";
    cin >> a_;
    int resultado_= potencia_ (n_,a_);
    potencia_(n_,a_,resultado_);
    cout << resultado_ << endl;

    //main ejercicio 3
    cout << fibonacci(5) << endl;

    //main ejercicio 4
    string t="hola";
    cout << "Palabra a invertir: hola" << endl;
    cout << "La palabra invertida es : " << invertir(t,"",t.length()) << endl;
    return 0;
}
//FIN :)