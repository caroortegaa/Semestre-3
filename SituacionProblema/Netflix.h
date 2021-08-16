//#include "Rating.h"
#include"Series.h"
#include"Peliculas.h"
//#include"Video.h"
#include<vector>
#include<cstdlib>

using namespace std;
#pragma once

class Netflix : public virtual Series , public virtual Peliculas , public virtual Rating
{
    protected:
    vector<Netflix*> guardar;
    void mostrarVideo(){}
    public:
    Netflix(){}; 
    Netflix(int ID , string nombre , int tiempo , string genero, string clasificacion ,int capitulos , int temporada)
    : Peliculas(ID , nombre  ,tiempo ,genero, clasificacion) , Series(ID ,  nombre , tiempo ,  genero, capitulos , temporada)
    {
        this->ID =ID;
        this->nombre=nombre;
        this->tiempo=tiempo;
        this->genero=genero;
        this->clasificacion=clasificacion;
        this->capitulos=capitulos;
        this->temporada=temporada;
    }
    void addVideo(Netflix* g);
    Netflix* buscarNombre (string nombre);
    void printVideo(string tipo);
    void rateVideo(string nombrepelicula, int calificacion);
    
};

void Netflix :: addVideo(Netflix* g){
    guardar.push_back(g);
}

Netflix* Netflix :: buscarNombre(string nombre){
    for(vector<Netflix*>::iterator it = guardar.begin(); it!= guardar.end();it++)
    {
        if(nombre== (*it)->getNombre()) 
        {
            return (*it);
        }
    }
    return 0;
}

void Netflix :: printVideo(string tipo){
    for(vector<Netflix*>::iterator it = guardar.begin(); it!= guardar.end();it++)
    {
        if (tipo == "Peliculas")
        {
            if ((*it)->getTemporada()==0)
            {
                (*it)->getNombre();
                cout << "Nombre de película: " << (*it)->getNombre() << "   Género: "<< (*it)->getGenero()<< "  Clasificación: "<<(*it)->getClasificacion()<<"  Duración: "<<(*it)->getTiempo()<< " minutos" <<"   ID: "<< (*it)->getID() << endl;
            }
        }
        if (tipo == "Series")
        {
            if ((*it)->getTemporada()!=0)
            {
                (*it)->getNombre();
                cout << "Nombre de serie: " << (*it)->getNombre() << "   Género de serie: " << (*it)->getGenero() << "  Temporadas: "<<(*it)->getTemporada()<<"  Capítulos: "<<(*it)->getCapitulo()<<"  Duración: "<<(*it)->getTiempo()<<" minutos"<<"  ID: "<< (*it)->getID() << endl;
            }
        }
        
    }
}
void Netflix :: rateVideo(string nombr, int calificacion){
       for(vector<Netflix*>::iterator it = guardar.begin(); it!= guardar.end();it++)
    {
        if (nombr==(*it)->getNombre()){
            (*it)->setEstrellas(calificacion);
        }
    } 
}
    