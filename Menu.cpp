#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <functional>
#include "Hospitales.h"
#include "Personal.h"
#include "Presupuesto.h"

using namespace std;

int main() {
	int opcionMenu, numeroDePacientes, numeroRespiradores;
	string departamento, nombre;
	Hospital <string, string, int, int> *obj = new Hospital<string, string, int, int>();
	Personal <string, string, string, int> *obj2 = new Personal<string, string, string, int>();
	Presupuesto <string, int> *obj3 = new Presupuesto<string, int>();
	do {
		system("cls");
		cout << "\tMinisterio de salud" << endl;
		cout << "1) Hospitales " << endl;
		cout << "2) Personal" << endl;
		cout << "3) Presupuesto para afrontar la pandemia" << endl;
		cout << "4) Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcionMenu;
		if (opcionMenu == 1) {
			int opcionHospitales;
			do {
				cin.ignore();
				system("cls");
				cout << "\t Hospitales" << endl;
				cout << "1) Registrar" << endl;
				cout << "2) Informacion completa de los hospitales" << endl;
				cout << "3) Ver datos en especifico" << endl;
				cout << "4) Salir" << endl;
				cout << "Ingrese opcion: ";
				cin >> opcionHospitales;
				if (opcionHospitales == 1) {
					system("cls");
					int numero = obj->getContador();
					cout << "\t Registrar hospital" << endl;
					cout << "Nombre: ";
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
				else if (opcionHospitales == 2) {
					system("cls");
					cout << "Hospitales registrados: " << endl;
					obj->mostrarHospitales();
					_getch();
				}
				else if (opcionHospitales == 3) {
					int opcionHospitalDetallado;
					do {
						system("cls");
						cout << "\t Informacion detallada" << endl;
						cout << "1) Hospitales saturados de pacientes" << endl;
						cout << "2) Hospitales con insuficientes respiradores mecanicos" << endl;
						cout << "3) Hospitales por departamento" << endl;
						cout << "4) Salir" << endl;
						cout << "Ingrese opcion: ";
						cin >> opcionHospitalDetallado;
						if (opcionHospitalDetallado == 1) {
							system("cls");
							auto hospitalesSaturados = [](Hospital<string, string, int, int> *obj2) {
								return (obj2->getPacientes() > 1000) ? true : false;
							};
							cout << "\t Hospitales saturados" << endl;
							obj->mostrarHospitalesSaturados(hospitalesSaturados);
							_getch();
						}
						else if (opcionHospitalDetallado == 2) {
							system("cls");
							auto respiradoresInsuficientes = [](Hospital <string, string, int, int> *obj) {
								return (obj->getRespiradores() < 500) ? true : false;
							};
							cout << "\t Hospitales con insuficientes " << endl;
							obj->mostrarHospitalesConRespiradoresInsuficientes(respiradoresInsuficientes);
							_getch();
						}
						else if (opcionHospitalDetallado == 3) {
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
					} while (opcionHospitalDetallado != 4);
				}
			} while (opcionHospitales != 4);
		}
		else if (opcionMenu == 2) {
			int menuPersonal;
			do {
				system("cls");
				cin.ignore();
				string nombre, departamento, profesion;
				int anios, contador;
				cout << "\t Menu de personal" << endl;
				cout << "1) Registrar " << endl;
				cout << "2) Visualizar personal registrado" << endl;
				cout << "3) Salir" << endl;
				cout << "Ingrese opcion: ";
				cin >> menuPersonal;
				if (menuPersonal == 1) {
					system("cls");
					cout << "\t Registrar nuevo personal" << endl;
					contador = obj2->getContador();
					cout << "Nombre: ";
					cin >> nombre;
					cout << "Anios: ";
					cin >> anios;
					cout << "Profesion: ";
					cin >> profesion;
					cout << "Departamento asignado: ";
					cin >> departamento;
					obj2->registrarPersonal(nombre, departamento, profesion, anios, contador);
					cout << "Personal registrado correctamente!" << endl;
					_getch();
				}
				else if (menuPersonal == 2) {
					int menuPersonalDetallado;
					do {
						system("cls");
						cout << "\t Personal del Ministerio de Salud" << endl;
						cout << "1) Doctores" << endl;
						cout << "2) Enfermeras" << endl;
						cout << "3) Salir" << endl;
						cout << "Ingrese opcion: ";
						cin >> menuPersonalDetallado;
						if (menuPersonalDetallado == 1) {
							system("cls");
							cout << "\t Doctores del Ministerio de Salud" << endl;
							auto mostrarDoctores = [](Personal<string, string, string, int> *obj2) {
								return(obj2->getProfesion() ==  "Doctor" || obj2->getProfesion() == "Doctora" || obj2->getProfesion() == "doctor" || obj2->getProfesion() == "doctora") ? true: false;
							};
							obj2->mostrarDoctores(mostrarDoctores);
							_getch();
						}
						else if (menuPersonalDetallado == 2) {
							system("cls");
							cout << "\t Enfermeras del Ministerio de Salud" << endl;
							auto mostrarEnfermeros = [](Personal<string, string, string, int> *obj2) {
								return(obj2->getProfesion() == "Enfermero" || obj2->getProfesion() == "Enfermera" || obj2->getProfesion() == "enfermero" || obj2->getProfesion() == "enfermera") ? true : false;
							};
							obj2->mostrarEnfermeros(mostrarEnfermeros);
							_getch();
						}
					} while (menuPersonalDetallado != 3);
				}
			} while (menuPersonal != 3);
		}
		else if (opcionMenu == 3) {
			int opcionPresupuestoDepartamento;
			do {
				system("cls");
				int presupuesto, contador;
				contador = obj3->getContador();
				cout << "\t Prespuestos por departamento" << endl << endl;
				cout << "1) Registrar" << endl;
				cout << "2) Mostrar" << endl;
				cout << "3) Salir" << endl;
				cout << "Ingrese opcion: ";
				cin >> opcionPresupuestoDepartamento;
				if (opcionPresupuestoDepartamento == 1) {
					system("cls");
					cout << "\t Registrando presupuesto" << endl;
					cout << "Departamento: ";
					cin >> departamento;
					if (obj3->comprobarDepartamento(departamento) == true) {
						cout << "Error, este departamento ya esta registrado!" << endl;
						_getch();
						break;
					}
					else {
						cout << "Presupuesto: ";
						cin >> presupuesto;
						obj3->registrarPresupuesto(departamento, presupuesto, contador);
						cout << "Registrado correctamente!" << endl;
						_getch();
					}
				}
				else if (opcionPresupuestoDepartamento == 2) {
					system("cls");
					cout << "\tDepartamentos registrados" << endl << endl;
					obj3->mostrarPresupuestos();
					_getch();
				}
			} while (opcionPresupuestoDepartamento != 3);
		}
	} while (opcionMenu !=4);
	return 0;
}