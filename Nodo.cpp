
#include <iostream>
#include <string>
//#include "Nodo.cpp" 

using namespace std;

#ifndef NODO_CPP
#define NODO_CPP

class Nodo {
	
	private:
		string valorNodo;
		Nodo * next_nodo;
	
	public:
		
		Nodo (string valor) {
			valorNodo = valor;
			next_nodo = NULL;
		}
		
		void setNext(Nodo * nuevoNext) {
			next_nodo = nuevoNext;
		}
		
		Nodo * getNext() {
			return next_nodo;
		}
		
		string getValor() {
			return valorNodo;
		}
};

#endif
