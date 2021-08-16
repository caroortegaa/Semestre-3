//Carolina Ortega A01025254
//Ximena González A01028604
#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
		T value;
		Nodo<T> *next;
		
		Nodo(T val){
			value=val;
			next=NULL;
		}
};

template <class T>
class LinkedList{
	public:
	Nodo<T> *root;
	
	
	LinkedList(){
		root=NULL;
		
	}
	
	//Esta funcion agrega un valor al final de la lista 
	//Complejidad de la función = O(n)
	void append(Nodo<T> *nuevo){
		if(root==NULL){ // condición = complejidad 1
			root=nuevo;
		}else{
			Nodo<T> *temp=root;
			while(temp->next!=NULL){ //loop = complejidad n
				temp=temp->next;	
									
			}
			temp->next=nuevo;
		}
	}
	
	//O(n)
	void append(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		append(nuevo);
	}
	
	//O(n)
	T getElementAt(int pos){
		Nodo<T> *temp=root;
		int i=0;
		while(temp!=NULL && i<pos){
			temp=temp->next;
			i++;
		}
		if(i==pos && temp!=NULL){
			return temp->value;
		}else{
			return NULL;
		}
	}
	
	//O(n)
	void setElementAt(int pos, T value){
		Nodo<T> *temp=root;
		int i=0;
		while(temp!=NULL && i<pos){
			temp=temp->next;
			i++;
		}
		if(i==pos && temp!=NULL){
			 temp->value=value;
		}
	}
	
	//O(n)
	void insert(Nodo<T> *nuevo, int pos){
		if(root==NULL){
			root=nuevo;
		}else if(pos==0){
			nuevo->next=root;
			root=nuevo;
		}else{
			Nodo<T> *temp=root;
			int i=0;
			while(temp->next!=NULL && i<pos-1){
				temp=temp->next;
				i++;
			}
			nuevo->next=temp->next;
			temp->next=nuevo;
		}
	}
	
	//O(n)
	void insert(T value, int pos){
		Nodo<T> *nuevo=new Nodo<T>(value);
		insert(nuevo, pos);
	}
	
	//O(n)
	void remove(T value){
		if(root==NULL){
			return;
		}else if(root->value==value){
			Nodo<T> *aBorrar=root;
			root=root->next;
			delete aBorrar;
		}else{
			Nodo<T> *temp=root;
			while(temp->next!=NULL){
				//cout<<temp->value<<endl;
				if(temp->next->value==value){
					Nodo<T> *aBorrar=temp->next;
					//temp->next=temp->next->next
					temp->next=aBorrar->next;
					delete aBorrar;
					return;
				}
				temp=temp->next;
			}
		}
	}

	//O(n)
    void duplicar(){
        Nodo<T> *temp=root;
        while (temp != NULL){
            Nodo<T> *n= new Nodo<T> (temp->value);
            temp -> next = n;
            n = temp ->next->value;
        }
    }
	//O(n)
    void quitar(T valor){
        Nodo<T> *temp= root;
        while (temp-> next!= NULL){
            if (temp->next-> value== valor){
                Nodo<T> *borrar= temp->next;
                temp->next= temp->next->next;
                
            }
            else{
                temp=temp->next;
            }
        }
    }
	//O(n)
	void print(){
		Nodo<T> *temp=root;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}	
		cout<<endl;
	}
	// 1 count
	//O(n)
    int count (T searchFor) {
        int conteo=0;
        Nodo<T> *temp= root;
        while (temp != NULL){
            if (searchFor == temp -> value ){
                conteo++;
            }
            temp=temp->next;
        }
        cout << conteo << endl;
        return conteo;
    }

	// 2
	//O(n)
    void deleteList(){
        Nodo<T> *temp=root;
        Nodo<T> *sig= NULL;
        while (temp != NULL){
            sig= temp ->next;
            delete temp;
            temp= sig;
        }
        root= NULL;
    }

	// 3
	//O(n)
    void sortedInsert (T valor){
        Nodo<T> *temp=root;
       while (temp != NULL){
            if (temp->next->value < valor){
                temp = temp->next;
            }
            else{
                Nodo<T> *nuevo= new Nodo<T> (valor);
                nuevo->next=temp->next;
                temp->next=nuevo;
				return;
            }
        }
    }

	//4
    //O(n)
    void removeDuplicates(){
        Nodo<T> *temp=root;
        while(temp!=NULL && temp->next != NULL){
            if (temp->value == temp->next->value){
                Nodo<T> *borrar=temp->next;
                temp->next=borrar->next;
                delete borrar;
            }
            else{
                temp=temp->next;
            }
        }
    }

	//5
	//O(n)
	void reverse(){
		if (root==NULL){
			return;
		}
		Nodo<T> *temp=root;
		Nodo<T> *a;
		Nodo<T> *s=temp->next;
		while(s){
			a=temp;
			temp=s;
			s=s->next;
			if(a==root){
				a->next=NULL;
			}
			temp->next=a;
		}
		root=temp;
		cout<<"La lista en orden inverso es: " << endl;
	}
};


int main(){
	LinkedList<int> list;
	//Nodo<int> *nuevo=new Nodo<int>(3);
	//list.append(nuevo);
	//agregando valores
	list.append(3);
	list.append(5);
    list.append(5);
	list.append(7);
	list.append(20);
    list.append(21);
	list.print();
	//Cuenta cuantas veces está el 5 (en este caso)
    list.count(5);
	//Inserta el 4 (en este caso)
	list.sortedInsert(4);
    list.print();
	//Remueve los números repetidos
    list.removeDuplicates();
	cout<< "La lista sin duplicados es: " << endl;
    list.print();
	//Invierte la lista
    list.reverse();
    list.print();
	//Elimina la lista
    list.deleteList();
	cout << "Se eliminó la lista :) " << endl;
    list.print();

};