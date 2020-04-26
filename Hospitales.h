#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <functional>

using namespace std;
template <class T1, class T2, class T3, class T4>
class Hospital {
	private:
		Hospital *inicio;
		Hospital *final;
		Hospital *siguiente;
		Hospital *anterior;
		T1 nombre;
		T2 departamento;
		T3 respiradoresMecanicos;
		T4 pacientes;
		int contador = 0;
	public:
		Hospital(T1 nombre, T2 departamento, T3 respiradoresMecanicos, T4 pacientes) {
			this->nombre = nombre;
			this->departamento = departamento;
			this->respiradoresMecanicos = respiradoresMecanicos;
			this->pacientes = pacientes;
			this->siguiente = NULL;
		}
		Hospital() {
			this->inicio = NULL;
			this->final = NULL;
			this->anterior = NULL;
		}
		T3 getRespiradores() {
			return respiradoresMecanicos;
		}
		T4 getPacientes() {
			return pacientes;
		}

		int getContador() {
			ifstream archivo;
			string registro, nombre, departamento, numeroRespiradores, numeroPacientes, id;
			int numero;
			archivo.open("archivo.txt", ios::in);
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, nombre, ',');
				getline(ss, departamento, ',');
				getline(ss, numeroRespiradores, ',');
				getline(ss, numeroPacientes, ',');
				getline(ss, id);
				numero = atoi(id.c_str());
			}
			archivo.close();
			return numero;
		}

		void registrarHospital(T1 nombre, T2 departamento, T3 respiradoresMecanicos, T4 pacientes, int numeroPacientes) {
			Hospital *nuevo = new Hospital(nombre, departamento, respiradoresMecanicos, pacientes);
			contador = numeroPacientes;
			ofstream archivo;
			if (contador == 0) {
				++contador;
				inicio = final = nuevo;
				archivo.open("archivo.txt", ios::out);
				archivo << nombre << ',' << departamento << ',' << respiradoresMecanicos << ',' << pacientes << ',' << contador << endl;
				cout << endl;
				archivo.close();
				
			}
			else{
				++contador;
				ifstream archivo2;
				string registro, Snombre, Sdepartamento, SnumeroRespiradores, SnumeroPacientes;
				int NnumeroRespiradores, NnumeroPacientes;
				archivo2.open("archivo.txt", ios::in);
				while (getline(archivo2, registro)) {
					stringstream ss(registro);
					getline(ss, Snombre, ',');
					getline(ss, Sdepartamento, ',');
					getline(ss, SnumeroRespiradores, ',');
					getline(ss, SnumeroPacientes, ',');
					NnumeroRespiradores = atoi(SnumeroRespiradores.c_str());
					NnumeroPacientes = atoi(SnumeroPacientes.c_str());
				}
				archivo2.close();
				Hospital *nuevo2 = new Hospital(Snombre, Sdepartamento, NnumeroRespiradores, NnumeroPacientes);
				final = nuevo2;
				final->siguiente = nuevo;
				final = nuevo;
				archivo.open("archivo.txt", ios::app);
				archivo << nombre << ',' << departamento << ',' << respiradoresMecanicos << ',' << pacientes << ','  << contador << endl;
				cout << endl;
				archivo.close();
			}
		}
		void mostrarHospitales() {
			ifstream archivo;
			archivo.open("archivo.txt", ios::in);
			string registro, nombre, departamento, numeroRespiradores, numeroPacientes;
			int cont = 0;
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, nombre, ',');
				getline(ss, departamento, ',');
				getline(ss, numeroRespiradores, ',');
				getline(ss, numeroPacientes, ',');
				cout << "Nombre: " << nombre << endl;
				cout << "Departamento: " << departamento << endl;
				cout << "Numero de respiradores: " << numeroRespiradores << endl;
				cout << "Numero de pacientes: " << numeroPacientes << endl;
				cout << endl << endl;
				++cont;
			}
			cout << "Hospitales registrados: " << cont << endl;
			_getch();
			archivo.close();
		}
		void mostrarHospitalesSaturados(function<bool(Hospital<string,string,int,int>*)> condicion) {
			ifstream archivo;
			archivo.open("archivo.txt", ios::in);
			string registro, nombre, departamento, numeroRespiradores, numeroPacientes;
			int cont = 0, numeroPac, numeroRes;
			while (getline(archivo, registro)) {
				stringstream ss(registro);
				getline(ss, nombre, ',');
				getline(ss, departamento, ',');
				getline(ss, numeroRespiradores, ',');
				getline(ss, numeroPacientes, ',');
				numeroPac = atoi(numeroPacientes.c_str());
				numeroRes = atoi(numeroRespiradores.c_str());
				Hospital *nuevo = new Hospital(nombre, departamento, numeroRes, numeroPac);
				if (condicion(nuevo)) {
					cout << nuevo->nombre << endl;
				}
			}
			archivo.close();
		}


};