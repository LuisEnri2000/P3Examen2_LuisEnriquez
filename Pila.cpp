
#include <iostream>
#include "Nodo.cpp" 

using namespace std;

#ifndef PILA_CPP
#define PILA_CPP

class Pila {
	
	private:
		Nodo * head;
		
	public:
		
		void push (string valor) {
			Nodo * temp = new Nodo(valor);
			temp->setNext(head);
			head = temp;
		}
		
		Nodo * pop() {
			Nodo * temp = head;
			this->head = head->getNext();
			return temp;
		}
	
		Nodo * top() {
			return head;
		}

		bool isEmpty() {
			if (head == NULL) {
				return true;
			}else{
				return false;
			}
		}
		
		
		
};

#endif
