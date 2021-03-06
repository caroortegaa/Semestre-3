//Ximena Gonzalez Carolina Ortega
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;

template <class T>
T busquedaSecuencial(vector<T> a, T buscado){
	for(int i=0; i<a.size(); i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

template <class T>
T busquedaOrdenada1(vector<T> a, T buscado){
	for(int i=0; i<a.size(); i++){
		if(a[i]>buscado){
			return -1;
		}
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

template <class T>
T busquedaOrdenada2(vector<T> a, T buscado){
	int paso=2;
	int inicio=0;
	int fin;
	while(inicio<a.size()){
		fin=inicio+paso;
		if(fin>a.size()){
			fin=a.size();
		}
		if(a[fin-1]>=buscado){
			for(int i=inicio; i<fin; i++){
				if(a[i]==buscado){
					return i;
				}
			}
			return -1;
		}
		inicio=fin;
	}
	return -1;
}

template <class T>
T busquedaBinaria(vector<T> a, T buscado){
	int inicio=0;
	int fin=a.size()-1;
	if(buscado>a[fin] || buscado<a[inicio]){
		return -1;
	}
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(a[medio]==buscado){
			return medio;
		}else if(buscado>a[medio]){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}

int main(){
	vector<int> a;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,10000000);
	for(int i=0; i<1000000; i++){
		//a.push_back(i);
		a.push_back(distribution(generator));
	}
	
	sort(a.begin(), a.end());
	int buscado=a[325];
	int x;
	//Busqueda secuencial
	cout<<"Secuencial ";
	auto inicio=high_resolution_clock::now();
	x=busquedaSecuencial(a,buscado);
	auto fin=high_resolution_clock::now();
	auto tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	//Busqueda Ordenada 1
	cout<<"Ordenada 1 ";
	inicio=high_resolution_clock::now();
	x=busquedaOrdenada1(a,buscado);
	fin=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	//Busqueda Ordenada 2
	cout<<"Ordenada 2 ";
	inicio=high_resolution_clock::now();
	x=busquedaOrdenada2(a,buscado);
	fin=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	//Busqueda binaria
	cout<<"Binaria ";
	inicio=high_resolution_clock::now();
	x=busquedaBinaria(a,buscado);
	fin=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	return 0;
}