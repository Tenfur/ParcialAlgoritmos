#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
template<class T1, class T2, class T3, class T4>

class Paciente {
private:
	T1 nombre;
	T2 prueba;
	T3 edad;
	T4 DNI;
	Paciente* inicio;
	Paciente* final;
	Paciente* siguiente;
	Paciente* anterior;
	int contador = 0;
public:
	Paciente(T1 nombre, T2 prueba, T3 edad, T4 DNI) {
		this->nombre = nombre;
		this->prueba = prueba;
		this->edad = edad;
		this->DNI = DNI;
		this->siguiente = NULL;
	}
	T2 getPrueba() {
		return prueba;
	}
	Paciente() {
		this->inicio = NULL;
		this->final = NULL;
	}
	int getContador() {
		ifstream archivo;
		string registro, nombre, prueba, edad, DNI, contador;
		int numero;
		archivo.open("Pacientes.txt", ios::in);
		while (getline(archivo, registro)) {
			stringstream ss(registro);
			getline(ss, nombre, ',');
			getline(ss, prueba, ',');
			getline(ss, edad, ',');
			getline(ss, DNI, ',');
			getline(ss, contador);
			numero = atoi(contador.c_str());
		}
		archivo.close();
		return numero;
	}
	void registrarPaciente(T1 nombre, T2 prueba, T3 edad, T4 DNI, int numeroContador) {
		Paciente* nuevo = new Paciente(nombre, prueba, edad, DNI);
		ofstream archivo;
		contador = numeroContador;
		if (contador == 0) {
			++contador;
			inicio = final = nuevo;
			archivo.open("Pacientes.txt", ios::out);
			archivo << nombre << ',' << prueba << ',' << edad << ',' << DNI << ',' << contador << endl;
			archivo.close();
		}
		else {
			++contador;
			ifstream archivo2;
			string registro, Snombre, Sprueba, Sedad, SDNI;
			int Nedad, NDNI;
			archivo2.open("Pacientes.txt", ios::in);
			while (getline(archivo2, registro)) {
				stringstream ss(registro);
				getline(ss, Snombre, ',');
				getline(ss, Sprueba, ',');
				getline(ss, Sedad, ',');
				getline(ss, SDNI, ',');
				Nedad = atoi(Sedad.c_str());
				NDNI = atoi(SDNI.c_str());
			}
			archivo2.close();
			Paciente* aux = new Paciente(Snombre, Sprueba, Nedad, NDNI);
			final = aux;
			nuevo->anterior = final;
			final->siguiente = nuevo;
			final = nuevo;
			archivo.open("Pacientes.txt", ios::app);
			archivo << nombre << ',' << prueba << ',' << edad << ',' << DNI << ',' << contador << endl;
			archivo.close();
		}
	}
	void mostrarPacientesConCovid(function<bool(Paciente < string, string, int, int>*)>condicion) {
		ifstream archivo;
		string registro, nombre, prueba, edad, DNI;
		int Nedad, NDNI;
		archivo.open("Pacientes.txt", ios::in);
		while (getline(archivo, registro)) {
			stringstream ss(registro);
			getline(ss, nombre, ',');
			getline(ss, prueba, ',');
			getline(ss, edad, ',');
			getline(ss, DNI, ',');
			Nedad = atoi(edad.c_str());
			NDNI = atoi(DNI.c_str());
			Paciente* aux = new Paciente(nombre, prueba, Nedad, NDNI);
			if (condicion(aux)) {
				cout << "Nombre: " << aux->nombre << endl;
				cout << "Resultado de prueba: " << aux->prueba << endl;
				cout << "Anios: " << aux->edad << endl;
				cout << "DNI: " << aux->DNI << endl;
				cout << endl;
			}
		}
		archivo.close();
	}
	void mostrarPacientesConOtraprueba(function<bool(Paciente < string, string, int, int>*)>condicion) {
		ifstream archivo;
		string registro, nombre, prueba, edad, DNI;
		int Nedad, NDNI;
		archivo.open("Pacientes.txt", ios::in);
		while (getline(archivo, registro)) {
			stringstream ss(registro);
			getline(ss, nombre, ',');
			getline(ss, prueba, ',');
			getline(ss, edad, ',');
			getline(ss, DNI, ',');
			Nedad = atoi(edad.c_str());
			NDNI = atoi(DNI.c_str());
			Paciente* aux = new Paciente(nombre, prueba, Nedad, NDNI);
			if (condicion(aux)) {
				cout << "Nombre: " << aux->nombre << endl;
				cout << "Resultados de prueba: " << aux->prueba << endl;
				cout << "Anios: " << aux->edad << endl;
				cout << "DNI: " << aux->DNI << endl;
				cout << endl;
			}
		}
		archivo.close();
	}

};