#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <functional>
using namespace std;
template<class T1, class T2, class T3, class T4> 

class Personal {
	private:
		T1 nombre;
		T2 departamento;
		T3 profesion;
		T4 anios;
		Personal *inicio;
		Personal *final;
		Personal *siguiente;
		int contador = 0;
	public:
		Personal(T1 nombre, T2 departamento, T3 profesion, T4 anios) {
			this->nombre = nombre;
			this->departamento = departamento;
			this->profesion = profesion;
			this->anios = anios;
			this->siguiente = NULL;
		}
		Personal() {
			this->inicio = NULL;
			this->final = NULL;
		}
		T3 getProfesion() {
			return profesion;
		}
		int getContador() {
			ifstream archivo;
			string registro, Snombre, Sdepartamento, Sprofesion, Sanios, Scontador;
			int contador2;
			archivo.open("Personal.txt", ios::in);
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, Snombre, ',');
				getline(ss, Sdepartamento, ',');
				getline(ss, Sprofesion, ',');
				getline(ss, Sanios, ',');
				getline(ss, Scontador);
				contador2 = atoi(Scontador.c_str());
			}
			archivo.close();
			return contador2;

		}
		void registrarPersonal(T1 nombre, T2 departamento, T3 profesion, T4 anios, int contadorPersonal) {
			Personal *nuevo = new Personal(nombre, departamento, profesion, anios);
			ofstream archivo;
			contador = contadorPersonal;
			if (contador == 0) {
				++contador;
				inicio = final = nuevo;
				archivo.open("Personal.txt", ios::out);
				archivo << nombre << ',' << departamento << ',' << profesion << ',' << anios << ',' << contador << endl;
				cout << endl;
				archivo.close();
			}
			else {
				++contador;
				ifstream archivo2;
				string registro,  Snombre, Sdepartamento, Sprofesion, Sanios;
				int Nanios;
				archivo2.open("Personal.txt", ios::in);
				while (getline(archivo2, registro)) {
					stringstream ss(registro);
					getline(ss, Snombre, ',');
					getline(ss, Sdepartamento, ',');
					getline(ss, Sprofesion, ',');
					getline(ss, Sanios, ',');
					Nanios = atoi(Sanios.c_str());
				}
				archivo2.close();
				Personal *nuevo2 = new Personal(Snombre, Sdepartamento, Sprofesion, Nanios);
				final = nuevo2;
				final->siguiente = nuevo;
				final = nuevo;
				archivo.open("Personal.txt", ios::app);
				archivo << nombre << ',' << departamento << ',' << profesion << ',' << anios << ',' << contador << endl;
				cout << endl;
				archivo.close();
			}
		}
		void mostrarDoctores(function<bool(Personal<string, string, string, int>*)> condicion) {
			ifstream archivo;
			string registro, Snombre, Sdepartamento, Sprofesion, Sanios;
			int Nanios;
			archivo.open("Personal.txt", ios::in);
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, Snombre, ',');
				getline(ss, Sdepartamento, ',');
				getline(ss, Sprofesion, ',');
				getline(ss, Sanios, ',');
				Nanios = atoi(Sanios.c_str());
				Personal *nuevo = new Personal(Snombre, Sdepartamento, Sprofesion, Nanios);
				if (condicion(nuevo)) {
					cout << "Nombre: " << nuevo->nombre << endl;
					cout << "Departamento asignado: " << nuevo->departamento << endl;
					cout << "Anios: " << nuevo->anios << endl;
					cout << endl << endl;
				}
			}
			archivo.close();
		}
		void mostrarEnfermeros(function<bool(Personal<string, string, string, int>*)> condicion) {
			ifstream archivo;
			string registro, Snombre, Sdepartamento, Sprofesion, Sanios;
			int Nanios;
			archivo.open("Personal.txt", ios::in);
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, Snombre, ',');
				getline(ss, Sdepartamento, ',');
				getline(ss, Sprofesion, ',');
				getline(ss, Sanios, ',');
				Nanios = atoi(Sanios.c_str());
				Personal *nuevo = new Personal(Snombre, Sdepartamento, Sprofesion, Nanios);
				if (condicion(nuevo)) {
					cout << "Nombre: " << nuevo->nombre << endl;
					cout << "Departamento asignado: " << nuevo->departamento << endl;
					cout << "Anios: " << nuevo->anios << endl;
					cout << endl << endl;
				}
			}
			archivo.close();
		}








};