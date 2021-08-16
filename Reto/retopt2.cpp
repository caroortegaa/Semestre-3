//Ximena Gonzalez , Carolina Ortega
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Nodo{
	public:
	string ip;
    Nodo *next;	

    Nodo(string iP){
        ip=iP;
        next=NULL;
    }
};

class Record{
	public:
	string fecha;
	string hora;
	string nombreFuente;
	string nombreDestino;
    string ipSalida;
    string ipDestino;
    string puertoSalida;
    string puertoDestino;

	Record(string f, string h, string iS, string pS , string nF , string iD , string pD , string nD){
		fecha=f;
		hora=h;
		ipSalida=iS;
		puertoSalida=pS;
		nombreFuente=nF;
		ipDestino=iD;
		puertoDestino=pD;
		nombreDestino=nD;
	}
	
};

vector<Record> conexiones;
void leerDatos(string path){
	ifstream fileIn;
	fileIn.open(path);
	string line, partes;
	vector<string> valores;
	while(getline(fileIn, line)){
		istringstream sIn(line);
		while(getline(sIn, partes, ',')){
			valores.push_back(partes);
		}
		if(valores[7].find('\r')!=valores[7].npos){
			valores[7]=valores[7].substr(0, valores[7].size()-1);
		}
		Record r(valores[0], valores [1] , valores [2] , valores[3], valores[4], valores [5] , valores [6],valores[7]);
		conexiones.push_back(r);
		valores.clear();
	}
};

class ConexionesComputadora{
    public:
    string ip;
    string nombre;
    Nodo *conexionesEntrantes;
    Nodo *conexionesSalientes;
	
	ConexionesComputadora(string IP, string NOMBRE){
        ip=IP;
        nombre=NOMBRE;
        conexionesEntrantes=NULL;
        conexionesSalientes=NULL;
	}
   
    void print(){
        Nodo *temp=conexionesEntrantes;
        int counterr=0;
        while (temp!=NULL){
            cout << temp->ip << endl;
            temp=temp->next;
            counterr++;
        }
        cout <<"# de CE: " << counterr << endl;
    }

    void print2(){
        Nodo *temp=conexionesSalientes;
        int counter=0;
        while (temp!=NULL){
            //cout << temp->ip << endl;
            temp=temp->next;
            counter++;
        }
        cout << counter << endl;
    }

};

 //Conexiones Entrantes -> ipDestino
void cargarS(Record a, ConexionesComputadora &aa){
    Nodo *nuevo=new Nodo(a.ipDestino);
    if (aa.conexionesSalientes == NULL){
        aa.conexionesSalientes=nuevo;
    }else{
    Nodo *contador = aa.conexionesSalientes;

        while (contador -> next != NULL){
            contador=contador->next;
        }
        contador->next= nuevo;
    }
}

 //Conexiones Salientes -> ipSalida
void cargarE(Record b, ConexionesComputadora &bb){
    
    Nodo *nuevo=new Nodo(b.ipSalida);
    if (bb.conexionesEntrantes == NULL){
        bb.conexionesEntrantes=nuevo;
    }
    else{
        nuevo-> next = bb.conexionesEntrantes;
        bb.conexionesEntrantes=nuevo;
    }
}


int main(){
    leerDatos("/Volumes/CARO_DRIVE/Programacion/VStudioC/Programacionestructuras/Reto/nuevo7.csv");
	cout << "Datos leidos: " << conexiones.size() << endl;
    Record r ("", "", "", "", "", "", "", "");
    cout << "Introduzca un número entre 1 y 150: " << endl;
    int g;
    cin >> g;
    string ip = "172.27.197." + to_string (g);
    ConexionesComputadora s (ip ,"pamela.reto.com"); 
    cout << ip << endl;
 
    for (Record r : conexiones){
        if (r.ipSalida==ip){
            cargarS (r,s);   
        }
    }

    for (Record r : conexiones){
        if (r.ipDestino==ip){
            cargarE (r,s);
        }
    }
    cout << "Conexiones entrantes: " << endl;
    s.print();
    cout << "Conexiones salientes: " << endl;
    s.print2();
  
};



