

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Pila.cpp"

using namespace std;

int main() {
	
	int opcionMenu = 0; // CONTROLA LA OPCION DEL MENU
	string operacionBase = ""; // ES LA OPERACION A ENVIAR A PILA
	string subCadena = "";
	string acumuladorCadena = "";
	
	Pila pila;
	
	while (opcionMenu != 2) {
		
		cout << "MENU" << endl;
		cout << "1. Ingresar cadena" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: "; 
		cin >> opcionMenu;
		
		system("CLS");
		
		if (opcionMenu == 1) {
			// Opcion de agregar
			cout << "INGRESE UNA OPERACION" << endl;
			cin >> operacionBase;
			
		//	cout << endl << operacionBase;
			
			while (operacionBase.size() > 0) {
				
				subCadena = operacionBase[0];
				operacionBase = operacionBase.substr(1,operacionBase.size());
				
				if (subCadena == "+" or subCadena == "*" or subCadena == "/") {
					cout << "Numero: " <<acumuladorCadena << endl << "Operacion: " << subCadena << endl;
					
					if (acumuladorCadena.size() == 1) {
						acumuladorCadena = "0" + acumuladorCadena;
					}
					
					pila.push(acumuladorCadena);
					
					pila.push(subCadena);
					acumuladorCadena = "";
				}else{
					acumuladorCadena += subCadena;
				}
			
			}
			
			cout << "Numero: " << acumuladorCadena << endl;
			pila.push(acumuladorCadena);
			
			string numero1;
			bool banderaWhile = true;
			
			while (banderaWhile) {
				numero1 = pila.pop()->getValor();
				string operacion;
				string numero2;
				int parseoNumero1 = 0;
				int parseoNumero2 = 0;
				int resultado = 0;
				stringstream ss; // Se encargan de pisar :V
				stringstream kk; // Rico
				
				if (!pila.isEmpty()) {
					operacion = pila.pop()->getValor();
					numero2 = pila.pop()->getValor();
					
					cout << numero1 << operacion << numero2 << " es: ";
					
					ss << numero1;
					kk << numero2;
					
					ss >> parseoNumero1;
					kk >> parseoNumero2;
					
					cout << parseoNumero1 << operacion << parseoNumero2 << "=";
					
					if (operacion == "+") {
						resultado = parseoNumero2 + parseoNumero1;
					}
					if (operacion == "*") {
						resultado = parseoNumero2 * parseoNumero1;
					}
					if (operacion == "/") {
						resultado = parseoNumero2 / parseoNumero1;
					}
					
					cout << resultado<<endl;
					
					ofstream Escribir;
					Escribir.open("./Historial.txt",ios::app); // Sin el ios :: app, lo sobreescribe, si lo hay solo escribe al final
					
					if (Escribir.is_open()) {
						Escribir << parseoNumero1 << operacion << parseoNumero2 << "=" << resultado << endl;
					}else{
						cout << "No es pudo abrir el archivo!";
					}
					
					Escribir.close();
					
					string pushear;
					stringstream pp;
					
					pp << resultado;
					pp >> pushear;

					cout << "Pushear: " << pushear << endl;
					
					pila.push(pushear);
				}else{
					banderaWhile = false;
				}
				
			}
		
			cout << "= " << numero1 << endl;
		}
		
		system("pause");
		system("CLS");
	}
	
	cout << "...::: Bye, bye :::..." << endl;
	
	
}
