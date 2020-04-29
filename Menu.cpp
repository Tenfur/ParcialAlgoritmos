#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <functional>
#include "Hospitales.h"

using namespace std;

int main() {
	int opcion, opcion2, opcion3, numeroDePacientes, numeroRespiradores;
	string departamento, nombre;
	Hospital <string, string, int, int> *obj = new Hospital<string, string, int, int>();
	do {
		system("cls");
		cout << "\tMinisterio de salud" << endl;
		cout << "1) Registrar hospital " << endl;
		cout << "2) Registrar personal" << endl;
		cout << "3) Mostrar informacion completa" << endl;
		cout << "4) Ver datos en especifico" << endl;
		cout << "5) Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;
		if (opcion == 1) {
			system("cls");
			cin.ignore();
			//char *nombre = new char[20];
			int numero = obj->getContador();
			cout << "Nombre: ";
			//cin.getline(nombre, 20);
			cin >> nombre;
			cout << "Departamento: ";
			cin >> departamento;
			cout << "Numero de respiradores mecanicos: ";
			cin >> numeroRespiradores;
			cout << "Numero de pacientes: ";
			cin >> numeroDePacientes;
			obj->registrarHospital(nombre, departamento, numeroRespiradores, numeroDePacientes, numero);
			cout << "Hospital registrado correctamente!" << endl;
			_getch();
		}
		else if (opcion == 2) {
			do {
				system("cls");
				cin.ignore();
				int anios;
				string nombre, departamento, profesion;
				cout << "\t Menu de personal" << endl;
				cout << "1) Registrar " << endl;
				cout << "2) Visualizar personal registrado" << endl;
				cout << "3) Salir" << endl;
				cout << "Ingrese opcion: ";
				cin >> opcion3;
				if (opcion3 == 1) {
					system("cls");
					cout << "\t Registrar nuevo personal" << endl;
					cout << "Nombre: ";
					cin >> nombre;
					cout << "Anios: ";
					cin >> anios;
					cout << "Profesion: ";
					cin >> profesion;
					cout << "Departamento asignado: ";
					cin >> departamento;
					cout << "Personal registrado correctamente!" << endl;
					_getch();
				}
				else if (opcion3 == 2) {
					int opcion1;
					do {
						system("cls");
						cout << "\t Personal del Ministerio de Salud" << endl;
						cout << "1) Doctores" << endl;
						cout << "2) Enfermeras" << endl;
						cout << "3) Salir" << endl;
						cout << "Ingrese opcion: ";
						cin >> opcion1;
						if (opcion1 == 1) {
							system("cls");
							_getch();
						}
						else if (opcion == 2) {
							system("cls");
							_getch();
						}
					} while (opcion1 != 3);
				}
			} while (opcion3 != 3);
		}
		else if (opcion == 3) {
			system("cls");
			cout << "Hospitales registrados: " << endl;
			obj->mostrarHospitales();
			_getch();
		}
		else if (opcion == 4) {
			do {
				system("cls");
				cout << "\t Informacion detallada" << endl;
				cout << "1) Hospitales saturados de pacientes" << endl;
				cout << "2) Hospitales con insuficientes respiradores mecanicos" << endl;
				cout << "3) Hospitales por departamento" << endl;
				cout << "4) Salir" << endl;
				cout << "Ingrese opcion: ";
				cin >> opcion2;
				if (opcion2 == 1) {
					system("cls");
					auto hospitalesSaturados = [](Hospital<string, string, int, int> *obj2) {
						return (obj2->getPacientes() > 1000) ? true : false;
					};
					cout << "\t Hospitales saturados" << endl;
					obj->mostrarHospitalesSaturados(hospitalesSaturados);
					_getch();
				}
				else if (opcion2 == 2) {
					system("cls");
					auto respiradoresInsuficientes = [](Hospital <string, string, int, int> *obj) {
						return (obj->getRespiradores() < 500) ? true : false;
					};
					cout << "\t Hospitales con insuficientes " << endl;
					obj->mostrarHospitalesConRespiradoresInsuficientes(respiradoresInsuficientes);
					_getch();
				}
				else if (opcion2 == 3) {
					system("cls");
					string departamento2;
					cout << "Ingrese departamento: ";
					cin >> departamento2;
					system("cls");
					auto hospitalesPorDepartamento = [departamento2](Hospital <string, string, int, int> * obj) {
						return (obj->getDepartamento() == departamento2) ? true : false;
					};
					cout << "\t Hospitales en " << departamento2 << endl;
					obj->mostrarHospitalesPorDepartamento(hospitalesPorDepartamento);
					_getch();
				}
			} while (opcion2 != 4);
		}
	} while (opcion !=5);



	return 0;
}