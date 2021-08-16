//Ximena Gonzalez , Carolina Ortega
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>

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


int main(){
	leerDatos("/Volumes/CARO_DRIVE/Programacion/VStudioC/Programacionestructuras/Reto/nuevo7.csv");
	unordered_map<string, ConexionesComputadora> cc;
	unordered_set<string> us; 
	unordered_set<string> ipF;
	int contador=0; 
	for(Record r: conexiones){
		if(r.ipFuente!="-"){
			if(cc.find(r.ipFuente)==cc.end()){
				ConexionesComputadora a(r.ipFuente, r.nombreFuente);
				cc[r.ipFuente]=a;
			}
			cc[r.ipFuente].nuevaSaliente(r.puertoDestino, r.ipDestino, r.nombreDestino);
		}
		
		if(r.ipDestino!="-"){
			if(cc.find(r.ipDestino)==cc.end()){
				ConexionesComputadora a(r.ipDestino, r.nombreDestino);
				cc[r.ipDestino]=a;
			}
			cc[r.ipDestino].nuevaEntrante(r.puertoFuente, r.ipFuente, r.nombreFuente);
	
		}

		if (r.nombreFuente != "-" && r.nombreFuente.find("reto.com") == string::npos){
			us.insert(r.nombreFuente);
		}
		
		if (r.nombreDestino!= "-" && r.nombreDestino.find("reto.com") == string::npos){
			us.insert(r.nombreDestino);
		}

		//pregunta 2
		if (r.nombreFuente== "-"){
			ipF.insert(r.ipFuente);
			cout<< "Ip fuente (-): " << r.ipFuente << endl;
		}
	}

	for (string r: us){
		cout << "No hay reto.com: " << r << endl; 
	}

	//pregunta 4
	unordered_set<string> ip_u;
	for(auto p4: cc["172.27.197.7"].entrantes){
		ip_u.insert(p4.ipRemota);
	};

	for(auto p4: cc["172.27.197.48"].entrantes){
		ip_u.insert(p4.ipRemota);
	};

	for(auto p4: cc["172.27.197.99"].entrantes){
		ip_u.insert(p4.ipRemota);
	};

	for(auto p4: cc["172.27.197.58"].entrantes){
		ip_u.insert(p4.ipRemota);
	};

	for(auto p4: cc["172.27.197.146"].entrantes){
		ip_u.insert(p4.ipRemota);
	};

	for(string iterar: ip_u){
		cout << "ip: " << iterar << endl;
	};

	//pregunta 6
	for(auto p6: cc["172.27.197.23"].salientes){
		p6.nombreRemoto == "nc2j89cd57yvv7kj5v3v.org";
		cout << "Se conecto con nc2 " << endl;
		p6.nombreRemoto == "3eg5687sark5nxh9n3oh.net";
		cout << "Se conecto con 3eg " << endl;
	};

	string ip_ = "172.27.197." ;
	for (int i=1; i<=254; i++){
		string ip_completo= ip_ + to_string(i);
		if (cc.find(ip_completo)!= cc.end()){ //si encontro la ip
			//checar pregunta 3
			if (cc[ip_completo].entrantes.size()>=1){
				contador++;
			}
			
		}	
		
	}
	cout << "Conexiones entrantes mayor a 1: " << contador << endl;	
}