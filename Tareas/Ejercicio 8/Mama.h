#include<iostream>
#include <string>

using namespace std;
#pragma once

class Generaciones{
    private:
    string nombre;
    int edad;
    string mama;
    int num_antecesores;
    string antecesores;

    public:
    Generaciones(){};
    Generaciones(string _nombre , int _edad , string _mama){
        nombre=_nombre;
        edad=_edad;
        mama=_mama;
    }

    void getName(string nombre);
    void getAge(int edad);
    void getMother(string mama);
    void getNumOfAntecessors(int num_antecesores);
    void getAntecessor(string antecesores);
    void getOldestAntecessor(int edad);
    void getYoungestAntecessor(string nombre , int edad);
};

void Generaciones::getName(string nombre){
    cout << "La persona elegida es: " << this->nombre << endl;
}

void Generaciones::getAge(int edad){
    cout << "La edad de esa persona es: " << this->edad << endl;
}

void Generaciones::getMother (string mama){
    cout << "La mamá de esa persona es: " << this->mama << endl;
}

void Generaciones::getNumOfAntecessors(int num_antecesores){
    cout << "¿Cuántos antecesores tiene? " << num_antecesores << endl;
    cin >> "Sara , Leticia , Laura , Soledad , Camila" >> endl;
    if (getNumOfAntecessors==Sara)
        return "0";
    elif (getNumOfAntecessors==Laura)
        return "1";
    elif (getNumOfAntecessors==Soledad)
        return "2";
    elif (getNumOfAntecessors==Leticia)
        return "3";
    else (getNumOfAntecessors==Camila)
        return "4";
}

void Generaciones::getAntecessor(string antecesores){
    cout << "¿Quiénes son tus antecesores? " << antecesores << endl;
    cin >> "Sara , Leticia , Laura , Soledad , Camila" >> endl;
    if (getAntecessors==Sara)
        return "No tienes antecesores";
    elif (getAntecessors==Laura)
        return "Tu antecesor es : Sara";
    elif (getAntecessors==Soledad)
        return "Tu antecesor es : Sara, Laura";
    elif (getAntecessors==Leticia)
        return "Tu antecesor es : Sara, Laura , Soledad";
    else (getAntecessors==Camila)
        return "Tu antecesor es : Sara, Laura , Soledad, Leticia";
}

void Generaciones::getOldestAntecessor(int edad , int viejo){
    edad > this->edad=viejo;
    cout << "El antecesor más viejo es:" << viejo << "Sara" << endl;
}

void Generaciones::getYoungestAntecessor(string nombre , int edad){
    cout << "El antecesor más joven es: " << "Camila" << endl;
}

int main(){
    Sara=97;
    Leticia=28;
    Laura=53;
    Soledad=34;
    Camila=18;

    
    Generaciones* persona1= new Generaciones(Camila);
    Generaciones* persona2= new Generaciones(Sara);
    Generaciones* persona3= new Generaciones(Laura);

    delete persona1;
    delete persona2;
    delete persona3;

    return 0;
}