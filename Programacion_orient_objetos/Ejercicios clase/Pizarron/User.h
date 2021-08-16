#include<string>
using namespace std;

#pragma once //para no repetir librerías
class User
{
    string nombre;

     public:
    User()=default; //otra forma de ponerlo es User(){}
    void writeOnBoard(string message);
};