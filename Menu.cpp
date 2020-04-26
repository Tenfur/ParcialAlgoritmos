#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <functional>
#include "Hospitales.h"

using namespace std;

int main() {
	int opcion, opcion2, numeroDePacientes, numeroRespiradores;
	string departamento, nombre;
	Hospital <string, string, int, int> *obj = new Hospital<string, string, int, int>();
	auto respiradoresSuficientes = [](Hospital <char, string, int, int> *obj) {
		if (obj->getRespiradores() < 500) {
			return true;
		}
		else {
			return false;
		}
	};
	do {
		system("cls");
		cout << "\tMinisterio de salud" << endl;
		cout << "1) Registrar hospital " << endl;
		cout << "2) Registrar paciente" << endl;
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
		else if (opcion == 3) {
			system("cls");
			cout << "Hospitales registrados: " << endl;
			obj->mostrarHospitales();
			_getch();
		}
		/*else if (opcion == 4) {
			system("cls");
			cout << "\t Información detallada" << endl;
			cout << "1) Hospitales saturados de pacientes" << endl;
			cout << "2) Hospitales con insuficientes respiradores mecanicos" << endl;
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
		}*/
	} while (opcion !=5);



	return 0;
}