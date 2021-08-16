#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	bool visited;
	unordered_map<Nodo<T> *, int> siguientes;
	
	Nodo(T val){
		value=val;
		visited=false;
	}
	
	void agregarArcoDirigidoConPeso(Nodo<T> *sig, int peso){
		if(siguientes.find(sig)==siguientes.end()){
			siguientes[sig]=peso;
		}
	}
	
	void agregarArcoDirigido(Nodo<T> *sig){
		agregarArcoDirigidoConPeso(sig, 1);
	}
	
	void imprimirNodo(){
			cout<<value<<":";
			for(auto nodoSiguiente:siguientes){
				cout<<nodoSiguiente.first->value<<","<<nodoSiguiente.second<<";";
			}
			cout<<endl;
	}
	
	/*bool conexion(Nodo<T> *nodo){
	}
	
	void modificarPeso(Nodo<T> *nodo, nuevoPeso){
	}*/
};

template <class T>
class Graph{
	public:
	unordered_map<T, Nodo<T> *> nodos;
	//como acceder al apuntador de un nodo nodos[nodo1]
	//da la direccion de memoria de donde apunta
	void agregarNodo(T value){
		if(nodos.find(value)==nodos.end()){ //si el valor asignado o esta
			Nodo<T> *nuevo=new Nodo<T>(value);
			nodos[value]=nuevo;
		}
	}
	
	void agregarArcoDirigidoConPeso(T nodo1, T nodo2, int peso){
		if(nodos.find(nodo1)!=nodos.end() && nodos.find(nodo2)!=nodos.end()){
			nodos[nodo1]->agregarArcoDirigidoConPeso(nodos[nodo2], peso);
		}			
	}
	
	void agregarArcoDirigido(T nodo1, T nodo2){
		agregarArcoDirigidoConPeso(nodo1, nodo2, 1);
	}
	
	void agregarArcoConPeso(T nodo1, T nodo2, int peso){
		agregarArcoDirigidoConPeso(nodo1, nodo2, peso);
		agregarArcoDirigidoConPeso(nodo2, nodo1, peso);
	}
	
	void agregarArco(T nodo1, T nodo2){
		agregarArcoConPeso(nodo1, nodo2, 1);
	}
	
	void imprimirGrafo(){
		for(auto parValorNodo: nodos){
			parValorNodo.second->imprimirNodo();
		}
	}

	int contar(T nodo1){
		int contadorxc = 0;
		for(auto xc: nodos){
			if(xc.second->siguientes.find(nodos[nodo1])!=xc.second->siguientes.end()){
				contadorxc++;
			}
		}
		return contadorxc;
	}
	
	/*unordered_map<string, int> ordenarPorDia(){
		unordered_map<string, int> a;
		//llenar el mapa
		return a;
	}*/
	/*void modificar(T nodo1, T nodo2, int nuevoPeso){
		//Encontrar que existan
		//buscar si existe el arco nodo1-nodo2 y modificarlo
	}*/
};

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
				//cout<<"error"<<pD<<endl;
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
				//cout<<"error"<<pD<<endl;
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



int main() {
    leerDatos("/Volumes/CARO_DRIVE/Programacion/VStudioC/Programacionestructuras/Reto/nuevo7.csv");
    Graph<string> conexionesA;
    string ip = "172.27.197.23"; 

    for (Record r: conexiones){
        if (r.ipFuente.find("172.27.197.")!=string::npos && r.ipDestino.find("172.27.197.")!=string::npos){
            conexionesA.agregarNodo(r.ipDestino); //grafo de strings, llenado
			conexionesA.agregarNodo(r.ipFuente);
			conexionesA.agregarArcoDirigido(r.ipFuente, r.ipDestino);
        }
    }
	//conexionesA.imprimirGrafo();
	if(conexionesA.nodos.find(ip)!=conexionesA.nodos.end()){
		cout << "Compus con las que A se ha conectado: " << conexionesA.nodos[ip]->siguientes.size()<< endl;
	}
	cout << "Compus que se conectan a A: "<< conexionesA.contar(ip) << endl;
	
	Graph<string> conexionesB;
	string B = "nc2j89cd57yvv7kj5v3v.org"; 
	string C = "theguardian.com";

    for (Record r: conexiones){
        if (r.nombreDestino.find("reto.com")==string::npos){
	//poner la fecha del dia del ataque- && r.fecha.find("17-8-2020")==string::npos){
            conexionesB.agregarNodo(r.nombreDestino); //grafo de strings, llenado
			conexionesB.agregarNodo(r.nombreFuente);
			conexionesB.agregarArcoDirigido(r.nombreFuente, r.nombreDestino);
			//cout << r.ipDestino << endl;
        }
    }
	//conexionesB.imprimirGrafo();
	cout << "Compus que se conectan a B: " << conexionesB.contar(B) << endl;
	cout << "Compus que se conectan a C: " << conexionesB.contar(C) << endl;
}