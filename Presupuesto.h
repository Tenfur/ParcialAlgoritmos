#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;
template<class T1, class T2>
class Presupuesto {
	private:
		T1 departamento;
		T2 presupuesto;
		Presupuesto *inicio;
		Presupuesto *final;
		Presupuesto *siguiente;
		int contador = 0;
	public:
		Presupuesto(T1 departamento, T2 presupuesto) {
			this->departamento = departamento;
			this->presupuesto = presupuesto;
			this->siguiente = NULL;
		}
		Presupuesto() {
			this->final = NULL;
			this->inicio = NULL;
		}
		int getContador() {
			ifstream archivo;
			string registro, departamento, presupuesto, id;
			int Nid;
			archivo.open("Presupuestos.txt", ios::in);
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, departamento, ',');
				getline(ss, presupuesto, ',');
				getline(ss, id, ',');
				Nid = atoi(id.c_str());
			}
			archivo.close();
			return Nid;
		}
		void registrarPresupuesto(T1 departamento, T2 presupuesto, int numeroPresupuestos) {
			Presupuesto *nuevo = new Presupuesto(departamento, presupuesto);
			ofstream archivo;
			contador = numeroPresupuestos;
			if (contador == 0) {
				++contador;
				archivo.open("Presupuestos.txt", ios::out);
				archivo << departamento << ',' << presupuesto << ',' << contador << endl;
				cout << endl;
				archivo.close();
			}
			else {
				++contador;
				ifstream archivo2;
				string registro, Sdepartamento, Spresupuestos;
				int Npresupuestos;
				archivo2.open("Presupuestos.txt", ios::in);
				while (getline(archivo2, registro)) {
					stringstream ss(registro);
					getline(ss, Sdepartamento, ',');
					getline(ss, Spresupuestos, ',');
					Npresupuestos = atoi(Spresupuestos.c_str());
				}
				archivo2.close();
				Presupuesto *nuevo2 = new Presupuesto(Sdepartamento, Npresupuestos);
				final = nuevo2;
				final->siguiente = nuevo;
				final = nuevo;
				archivo.open("Presupuestos.txt", ios::app);
				archivo << departamento << ',' << presupuesto << ',' << contador << endl;
				cout << endl;
				archivo.close();
			}
		}
		void mostrarPresupuestos() {
			ifstream archivo;
			string registro, Sdepartamento, Spresupuestos;
			archivo.open("Presupuestos.txt", ios::in);
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, Sdepartamento, ',');
				getline(ss, Spresupuestos, ',');
				cout << "Departamento: " << Sdepartamento << endl;
				cout << "Presupuesto: " << Spresupuestos << endl;
				cout << endl;
			}
			archivo.close();
		}



};