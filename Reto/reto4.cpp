//Ximena Gonzalez , Carolina Ortega
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;
class Record{
	public:
	string fecha;
	string hora;
	string ipFuente;
	int puertoFuente;
	string nombreFuente;
	string ipDestino;
	int puertoDestino;
	string nombreDestino;
	
	Record(string f, string h, string iF, string pF, string nF, string iD, string pD, string nD){
		fecha=f;
		hora=h;
		ipFuente=iF;
		if(pF=="-"){
			puertoFuente=0;
		}else{
			
			try{
				puertoFuente=stoi(pF);
			}catch (const std::invalid_argument& ia){
				puertoFuente=0;
				cout<<"error"<<pD<<endl;
			}
		}
		nombreFuente=nF;
		ipDestino=iD;
		if(pD=="-"){
			puertoDestino=0;
		}else{
			try{
				puertoDestino=stoi(pD);
			}catch (const std::invalid_argument& ia){
				puertoDestino=0;
				cout<<"error"<<pD<<endl;
			}
		}
		nombreDestino=nD;
	}
	
	void imprimirRecord(){
		cout<<nombreFuente<<endl;
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
		Record r(valores[0], valores[1], valores[2], valores[3], valores[4], valores[5], valores[6], valores[7]);
		conexiones.push_back(r);
		valores.clear();
	}
}

class infoConexion{
	public:
	int puertoRemoto;
	string ipRemota;
	string nombreRemoto;
	
	infoConexion(int pR, string ipR, string nR){
		puertoRemoto=pR;
		ipRemota=ipR;
		nombreRemoto=nR;
	}
};

class ConexionesComputadora{
	public:
	string ip;
	string nombre;
	list<infoConexion> entrantes;
	list<infoConexion> salientes;
	
	ConexionesComputadora(){
	}
	
	ConexionesComputadora(string ip, string nombre){
		this->ip=ip;
		this->nombre=nombre;
	}
	
	void nuevaEntrante(int puerto, string ip, string nombre){
		infoConexion a(puerto, ip, nombre);
		entrantes.push_front(a);
	}
	
	void nuevaSaliente(int puerto, string ip, string nombre){
		infoConexion a(puerto, ip, nombre);
		salientes.push_back(a);
	}
};

unordered_map<string,int> conexionesDia (string fecha2){
    unordered_map<string,int> cpd;
    for (auto i: conexiones){
        if (i.nombreDestino != "-" && i.nombreDestino.find("reto.com") == string::npos ){ //si lo encuentra
            if (i.fecha == fecha2){
                if (cpd.find(i.nombreDestino)==cpd.end()){
                    cpd[i.nombreDestino]=1;
                }
                else{
                    cpd[i.nombreDestino]++;
                }
            }
        }
    }
    return cpd;
}

void top (int n, string fecha3){
    unordered_map<string,int> cpd2= conexionesDia(fecha3);
    map <int,vector<string> > topD;
    for (auto c: cpd2){
        topD[c.second].push_back(c.first); //lo voltea
    }
    /*
    for (auto x : topD){
        cout << x.first << ":" << endl;
        for (string t: x.second){
            cout << t << "," << endl;
        } 
    }*/
    
    map<int, vector<string> >::iterator it= topD.end(); //se posiciona en el ultimo elemento del mapa
    it--;
    int contador= 0;
    cout << "AQUI EMPIEZA" << endl;
    while (contador < n){ //mientras sea diferente del principio
        cout << it->first << ":" << endl; //-> porque es un apuntador, iterador = apuntadpr
        for (string w: it->second){
            cout << w << "," << endl;
        } 
        it--; //el iterador va cambiando
        contador ++; 
    }
    cout << "AQUI TERMINA" << endl;
}

int main(){
	leerDatos("/Volumes/CARO_DRIVE/Programacion/VStudioC/Programacionestructuras/Reto/nuevo7.csv");
    cout<< conexiones.size()<<endl;
    for (auto o:conexionesDia("10-8-2020")){
        cout<<o.first<< "," << o.second << endl;
    }
    cout << "10-8-2020" << endl;
    top(5, "10-8-2020");
	cout << "*****" << endl;

    cout << "11-8-2020" << endl;
	top(5, "11-8-2020");
	cout << "*****" << endl;

    cout << "12-8-2020" << endl;
	top(5, "12-8-2020");
	cout << "*****" << endl;

    cout << "13-8-2020" << endl;
	top(5, "13-8-2020");
	cout << "*****" << endl;

    cout << "14-8-2020" << endl;
	top(5, "14-8-2020");
	cout << "*****" << endl;

    cout << "17-8-2020" << endl;
	top(5, "17-8-2020");
	cout << "*****" << endl;

    cout << "18-8-2020" << endl;
	top(5, "18-8-2020");
	cout << "*****" << endl;

    cout << "19-8-2020" << endl;
	top(5, "19-8-2020");
	cout << "*****" << endl;

    cout << "20-8-2020" << endl;
	top(5, "20-8-2020");
	cout << "*****" << endl;

    cout << "21-8-2020" << endl;
	top(5, "21-8-2020");
	cout << "*****" << endl;
}
