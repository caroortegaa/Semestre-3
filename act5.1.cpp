#include <iostream>
#include <unordered_map>
#include <vector> 

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
class Queue{
	public:
	Nodo<T> *front;
	Nodo<T> *back;
	
	Queue(){
		front=NULL;
		back=NULL;
	}
	
	void enqueue(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(back==NULL){
			back=nuevo;
			front=back;
		}else{
			back->next=nuevo;
			nuevo->prev=back;
			back=nuevo;
		}
	}
	
	void dequeue(){
		if(front!=NULL){
			Nodo<T> *aBorrar=front;
			if(front==back){
				front=NULL;
				back=NULL;
			}else{
				front=front->next;
				front->prev=NULL;
			}
			delete aBorrar;
		}
	}
	
	T check(){
		if(front!=NULL){
			return front->value;
		}else{
			return NULL;
		}
	}
	
	void print(){
		Nodo<T> *temp=front;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}
		cout<<endl;
		
	}
	
};

template <class T>
class Stack{
	public:
	Nodo<T> *top;
	
	Stack(){
		top=NULL;
	}
	
	void push(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(top==NULL){
			top=nuevo;
		}else{
			nuevo->next=top;
			top->prev=nuevo;
			top=nuevo;
		}
	}
	
	T check(){
		if(top!=NULL){
			return top->value;
		}else{
			return NULL;
		}
	}
	
	void pop(){
		if(top!=NULL){
			Nodo<T> *aBorrar=top;
			top=top->next;
			top->prev=NULL;
			delete aBorrar;
		}
	}
	
	void print(){
		Nodo<T> *temp=top;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}
		cout<<endl;
		
	}
};

template <class T>
class Graph{
	public:
	unordered_map<T, Nodo<T> *> nodos;
	
	void agregarNodo(T value){
		if(nodos.find(value)==nodos.end()){
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
	
	unordered_map<string, int> ordenarPorDia(){
		unordered_map<string, int> a;
		//llenar el mapa
		return a;
	}
	/*void modificar(T nodo1, T nodo2, int nuevoPeso){
		//Encontrar que existan
		//buscar si existe el arco nodo1-nodo2 y modificarlo
	}*/

	bool BFS (T nodo1, T nodo2){
	Nodo<T> *temp;
	Nodo<T> *temp_v;
	Queue <Nodo <T>*> q;//agregan apuntadores
	temp=nodos[nodo1];
	if (temp != NULL){
		q.enqueue(temp);
		while (q.check()!= NULL){
			temp_v= q.check();
			temp_v->visited=true;
			q.dequeue();
			if (temp_v -> value == nodo2){
				return true;
			}
			else {
				for (auto it : temp_v->siguientes){
					if (it.first->visited==false){
						q.enqueue(it.first);
					}
				}
			}
		}
		
		return false;

	}
	else {
		return false;
	}
	}

	bool DFS (T nodo1, T nodo2){
	Nodo<T> *temp;
	Nodo<T> *temp_v;
	Stack<Nodo <T>*> s;
	temp=nodos[nodo1];
	if (temp != NULL){
		s.push(temp);
		while (s.check()!= NULL){
			temp_v=s.check();
			temp_v->visited=true; //lo marca como que ya paso por ahi
			s.pop();
			if (temp_v -> value == nodo2){
				return true;
			}
			else {
				for (auto i: temp_v->siguientes){
					if (i.first->visited==false){
						s.push(i.first);
					}
				}
			}

		}
		
		return false;
		
	}
	else {
		return false;
	}
	}
};

int main(){
	Graph<string> g;
	g.agregarNodo("CDMX");
	g.agregarNodo("Tlaxcala");
	g.agregarNodo("Puebla");
	g.agregarNodo("Toluca");
	g.agregarArcoDirigidoConPeso("CDMX", "Tlaxcala", 50);
	g.agregarArcoConPeso("CDMX", "CDMX", 20);
	g.agregarArcoConPeso("CDMX", "Puebla", 100);
	g.agregarArco("Puebla", "Puebla");
	g.imprimirGrafo();
	//g.BFS("CDMX", "Puebla");
	//g.DFS("Tlaxcala", "Toluca");
	
}