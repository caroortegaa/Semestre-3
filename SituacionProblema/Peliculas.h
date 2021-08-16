#include"Video.h"
#include"Rating.h"

using namespace std;
#pragma once

class Peliculas : public virtual Video , public virtual Rating
{
    protected:
    string clasificacion;

    public:
    Peliculas(){};
    Peliculas(int ID , string nombre , int tiempo , string genero, string clasificacion) 
    : Video(ID , nombre , tiempo , genero) , clasificacion(clasificacion){}




    void mostrarVideo(){
     cout << ID << endl;
     cout << nombre << endl;
     cout << tiempo << endl;
     cout << genero << endl;
     cout << clasificacion << endl;
    }

    string getClasificacion()
  {
    return this->clasificacion;
  }

};