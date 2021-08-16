//Carolina Ortega A01025254
#include "Netflix.h"
#include<limits>

using namespace std;

// Mostrar los videos en general con una cierta calificación o de un cierto género
// Mostrar los episodios de una determinada serie con una calificacion determinada
// Mostrar las películas con cierta calificacion
// Calificar un video:
//pedir titulo a calificar
//pedir valor otorgado
// Salir

int main(){

    Series s;
    Peliculas p;
    Netflix n;

    n.addVideo(new Netflix(1,"Avengers:Los vengadores de Marvel",120, "Acción","PG-13",0,0));
    n.addVideo(new Netflix(2,"Mamma Mia",78,"Musical","PG-13",0,0));
    n.addVideo(new Netflix(3,"Becoming",80,"Documental","PG",0,0));
    n.addVideo(new Netflix(4,"Son como niños",110,"Comedia","PG-13",0,0));

    n.addVideo(new Netflix(11,"Friends",24,"Comedia","",236,10));
    n.addVideo(new Netflix(22,"La casa de papel",45,"Thriller","",38,4));
    n.addVideo(new Netflix(33,"Gossip Girl",42,"Drama adolescente","",121,6));
    n.addVideo(new Netflix(44,"Cake Boss",35,"Telerrealidad","",236,10));


    char opcion = 'P';

    while (opcion == 'P'|| opcion == 'S')
    {
        cout << "Desea calificar una P(película) o S(serie): " << endl;
        cin >> opcion;

        if (opcion == 'P' )
        {
            cout << "Tiene estas opciones : " << endl;
            n.printVideo("Peliculas");
            cout << "¿Qué película desea calificar? : " << endl;
            string nombrepelicula;
            cin >> nombrepelicula ;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "¿Qué puntaje le otorga? (Puntaje del 1 al 5) : " << endl;
            int calificacion;
            cin >> calificacion ;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            n.rateVideo(nombrepelicula,calificacion);
            cout << "Calificaste " << nombrepelicula << " con " << calificacion << "/5 estrellas!!" << endl;
        }

        if (opcion != 'P' )
        {
            cout << "Para salir escribir una letra diferente a P ó S " << endl;
        }
        
        if (opcion == 'S' )
        {
            cout << "Tiene estas opciones : "  << endl;
            //s.mostrarVideo();
            n.printVideo("Series");
            cout << "¿Qué serie desea calificar? : " << endl;
            string nombreseries;
            cin >> nombreseries ;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "¿Qué puntaje le otorga? (Puntaje del 1 al 5) : " << endl;
            int calificacion ;
            cin >> calificacion ;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            n.rateVideo(nombreseries,calificacion);
            cout << "Calificaste " << nombreseries << " con " << calificacion << "/5 estrellas!!" << endl;
        }
    }
}




