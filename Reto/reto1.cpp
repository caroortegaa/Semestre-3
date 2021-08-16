//Carolina Ortega , Ximena Gonzalez
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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
	
	void imprimirRecord(){
		cout << nombreFuente << endl;
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
}

int compararPorNombreFuente(Record a, Record b){
	if(a.nombreFuente<b.nombreFuente){
		return -1;
	}else if (a.nombreFuente==b.nombreFuente){
		return 0;
	}else{
		return 1;
	}
}


int compararPorIpDestino(Record a, Record b){
	if(a.ipDestino<b.ipDestino){
		return -1;
	}else if (a.ipDestino==b.ipDestino){
		return 0;
	}else{
		return 1;
	}
}

int compararPorNombreDestino(Record a, Record b){
	if(a.nombreDestino<b.nombreDestino){
		return -1;
	}else if (a.nombreDestino==b.nombreDestino){
		return 0;
	}else{
		return 1;
	}
}


int compararPorPuertoDestino(Record a,Record b){
	if(a.puertoDestino < b.puertoDestino){
		return -1;
		//cout<<a.puertoDestino<<endl;
	}else if (a.puertoDestino==b.puertoDestino){
		return 0;
	}else{
		return 1;
	}
}



template <class T>
class Sort{
	public:
	virtual void sort(vector<T> &data, int comparador(T a, T b))=0;
	void intercambiar(vector<T> &data, int posI, int posJ){
		T temp=data[posI];
		data[posI]=data[posJ];
		data[posJ]=temp;
	}
	
};


template <class T>
class MergeSort: public Sort<T>{
	
	public:
	void sort(vector<T> &data, int comparador(T a, T b)){
		sortAux(data, 0, data.size()-1, comparador);
	}
	private:
	void sortAux(vector<T> &data, int lo, int hi, int comparador(T a, T b)){
		if(lo>=hi){
			return;
		}
		int mid=(lo+hi)/2;
		sortAux(data, lo, mid, comparador);
		sortAux(data, mid+1, hi, comparador);
		merge(data, lo, mid, hi, comparador);
	}
	
	
	
	void merge(vector<T> &data, int low, int mid, int hi, int comparador(T a, T b)){
	int sizeA=mid-low+1;
	int sizeB=hi-mid;
	vector<T> copiaA;
	vector<T> copiaB;
	
	for(int i=0; i<sizeA; i++){
		copiaA.push_back(data[low+i]);
	}
	
	for(int i=0; i<sizeB; i++){
		copiaB.push_back(data[mid+i+1]);
	}
	
	int indexA=0;
	int indexB=0;
	int indexData=low;
	while(indexA<sizeA&&indexB<sizeB){
		//if(copiaA[indexA]<copiaB[indexB]){
		if(comparador(copiaA[indexA],copiaB[indexB])<0){
			data[indexData]=copiaA[indexA];
			indexA++;
		}else{
			data[indexData]=copiaB[indexB];
			indexB++;
		}
		indexData++;
	}
	
	while(indexA<sizeA){
		data[indexData]=copiaA[indexA];
		indexA++;
		indexData++;
	}
	
	while(indexB<sizeB){
		data[indexData]=copiaB[indexB];
		indexB++;
		indexData++;
	}
}
	
};

int compararPorNombreDestino2(Record a, string b){
	if(a.nombreDestino<b){
		return -1;
	}else if (a.nombreDestino==b){
		return 0;
	}else{
		return 1;
	}
}


template <class T, class M>
int busquedaBinaria2(vector<T> a, M buscado, int comparador(T a, M b)){
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0){
			return medio;
		}else if(comparador(a[medio], buscado)<0){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}

template <class T>
int busquedaBinaria(vector<T> a, T buscado, int comparador(T a, T b)){
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0){
			return medio;
		}else if(comparador(buscado,a[medio])>0){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}


int main(){
	leerDatos("/Volumes/CARO_DRIVE/Programacion/VStudioC/Programacionestructuras/Reto/equipo7.csv");
	cout<<"Datos leidos"<<endl;
	MergeSort<Record> s;
    s.sort(conexiones, compararPorNombreFuente);
	cout<<"Datos ordenados" << endl; 
    /*for(int i=0; i<conexiones.size(); i++){
        conexiones[i].imprimirRecord();
    };*/
	Record r("", "", "", "", "jeffrey.reto.com", "", "", "");//checar 3
    int pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado jeffrey ;)"<<endl;
	}
    else{
        cout<< "no esta jeffrey :(" << endl;
    }

    r.nombreFuente= "betty.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado betty ;)"<<endl;
	}
    else{
        cout<< "no esta betty :(" << endl;
    }

    r.nombreFuente="katherine.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado katherine ;)"<<endl;
	}
    else{
        cout<< "no esta katherine :(" << endl;
    }

    r.nombreFuente="scott.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado scott ;)"<<endl;
	}
    else{
        cout<< "no esta scott :(" << endl;
    }

    r.nombreFuente="benjamin.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado benja ;) "<<endl;
	}
    else{
        cout<< "no esta benja :(" << endl;
    }

    r.nombreFuente="samuel.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado samuel ;)"<<endl;
	}
    else{
        cout<< "no esta samuel :(" << endl;
    }

    r.nombreFuente="raymond.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado raymond ;)"<<endl;
	}
    else{
        cout<< "no esta raymond :(" << endl;
    }

    r.nombreFuente="server.reto.com";
    pos=busquedaBinaria(conexiones, r, compararPorNombreFuente);
    if(pos!=-1){
		cout<<"encontrado server ;)"<<endl;
	}
    else{
        cout<< "no esta server :(" << endl;
    }
    
	string a="google.com";
	pos=busquedaBinaria2(conexiones, a, compararPorNombreDestino2);
	if(pos!=-1){
		cout<<"encontrado"<<endl;
	}
    cout << "El tamaño del archivo es de: " << conexiones.size() << endl; // 1

	/*for (int i=0; i<conexiones.size(); i++){
		conexiones[i].imprimirRecord();
	}*/

	s.sort(conexiones,compararPorPuertoDestino);
	for(int i=0; i<1000 ; i++){
		//Record u("", "", "", "", "", "", "", "");
		r.puertoDestino = to_string (i);//convierto el valor entero a string
		int pos1=busquedaBinaria(conexiones, r, compararPorPuertoDestino);
    	if(pos1!=-1){//cuando lo encuentre que imprima pD
			cout << r.puertoDestino << endl;
		}	
	}
	
	return 0;
}
