#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <functional>
#include "Hospitales.h"
#include "Personal.h"
#include "Presupuesto.h"
#include "Paciente.h"

using namespace std;

int main() {
	int opcionMenu, numeroDePacientes, numeroRespiradores, edad, DNI;
	string departamento, nombre, enfermedad;
	Hospital <string, string, int, int>* obj = new Hospital<string, string, int, int>();
	Personal <string, string, string, int>* obj2 = new Personal<string, string, string, int>();
	Presupuesto <string, int>* obj3 = new Presupuesto<string, int>();
	Paciente <string, string, int, int>* obj4 = new Paciente<string, string, int, int>();
	do {
		system("cls");
		cout << "\tMinisterio de salud" << endl;
		cout << "1) Hospitales " << endl;
		cout << "2) Personal" << endl;
		cout << "3) Pruebas Rapidas" << endl;
		cout << "4) Presupuesto para afrontar la pandemia" << endl;
		cout << "5) Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcionMenu;
		if (opcionMenu == 1) {
			int opcionHospitales;
			do {
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
					cin.ignore();
					getline(cin, nombre);
					cout << "Departamento: ";
					getline(cin, departamento);
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
							auto hospitalesSaturados = [](Hospital<string, string, int, int>* obj2) {
								return (obj2->getPacientes() > 1000) ? true : false;
							};
							cout << "\t Hospitales saturados" << endl;
							obj->mostrarHospitalesSaturados(hospitalesSaturados);
							_getch();
						}
						else if (opcionHospitalDetallado == 2) {
							system("cls");
							auto respiradoresInsuficientes = [](Hospital <string, string, int, int>* obj) {
								return (obj->getRespiradores() < obj->getPacientes()) ? true : false;
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
							auto hospitalesPorDepartamento = [departamento2](Hospital <string, string, int, int>* obj) {
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
					cin.ignore();
					getline(cin, nombre);
					cout << "Anios: ";
					cin >> anios;
					cout << "Profesion: ";
					cin.ignore();
					getline(cin, profesion);
					cout << "Departamento asignado: ";
					getline(cin, departamento);

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
							auto mostrarDoctores = [](Personal<string, string, string, int>* obj2) {
								return(obj2->getProfesion() == "Doctor" || obj2->getProfesion() == "Doctora" || obj2->getProfesion() == "doctor" || obj2->getProfesion() == "doctora") ? true : false;
							};
							obj2->mostrarDoctores(mostrarDoctores);
							_getch();
						}
						else if (menuPersonalDetallado == 2) {
							system("cls");
							cout << "\t Enfermeras del Ministerio de Salud" << endl;
							auto mostrarEnfermeros = [](Personal<string, string, string, int>* obj2) {
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
			int opcionPaciente, contador;
			do {
				system("cls");
				cout << "\t Registro de pruebas" << endl;
				cout << "1) Registrar" << endl;
				cout << "2) Mostrar a pacientes" << endl;
				cout << "3) Salir" << endl;
				cout << "Ingrese opcion: ";
				cin >> opcionPaciente;
				if (opcionPaciente == 1) {
					system("cls");
					contador = obj4->getContador();

					cout << "\t Registrar Prueba" << endl;
					cout << "Nombre: ";
					cin.ignore();
					getline(cin, nombre);
					cout << "Rsultado de prueba: ";
					getline(cin, enfermedad);
					cout << "Edad: ";
					cin >> edad;
					cout << "DNI: ";
					cin >> DNI;
					obj4->registrarPaciente(nombre, enfermedad, edad, DNI, contador);
					cin.ignore();
					cout << "Resultado registrado correctamente!";
					_getch();
				}
				else if (opcionPaciente == 2) {
					int opcionPacienteRegistrado;
					do {
						system("cls");
						cout << "\t Personas que se realizaron la prueba" << endl;
						cout << "1) COVID19" << endl;
						cout << "2) No COVID19" << endl;
						cout << "3) Salir" << endl;
						cout << "Ingrese opcion: ";
						cin >> opcionPacienteRegistrado;
						if (opcionPacienteRegistrado == 1) {
							system("cls");
							cout << "\t Pacientes con COVID19" << endl;
							auto pacientesConCovid19 = [](Paciente<string, string, int, int>* obj) {
								return(obj->getPrueba() == "Positivo" || obj->getPrueba() == "positivo" || obj->getPrueba() == "POSITIVO") ? true : false;
							};
							obj4->mostrarPacientesConCovid(pacientesConCovid19);
							_getch();
						}
						else if (opcionPacienteRegistrado == 2) {
							system("cls");
							cout << "\t Pacientes que no tienen Covid19" << endl;
							auto pacienteSinCovid19 = [](Paciente<string, string, int, int>* obj) {
								return(obj->getPrueba() != "Positivo" && obj->getPrueba() != "positivo" && obj->getPrueba() != "POSITIVO") ? true : false;
							};
							obj4->mostrarPacientesConOtraprueba(pacienteSinCovid19);
							_getch();
						}
					} while (opcionPacienteRegistrado != 3);
				}
			} while (opcionPaciente != 3);
		}
		else if (opcionMenu == 4) {
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
					cin.ignore();
					getline(cin, departamento);
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
	} while (opcionMenu != 5);
	return 0;
}