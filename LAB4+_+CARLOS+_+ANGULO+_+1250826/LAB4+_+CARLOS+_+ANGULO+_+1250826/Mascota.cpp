#include "Mascota.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int validacionDatoEspecifico(int& numero, int min, int max) {
	bool valido = false;
	do {
		try {
			cin >> numero;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error: Ingrese un número válido");
			}
			else if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido");
			}
			valido = true;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
			valido = false;
		}
	} while (!valido);
	return numero;
}

void Mascota::funcionExtra() {
	if (tipo == 1) {
		int optPerro;
		cout << "¿Requiere paseo diario?"
			<< "\n1. Sí"
			<< "\n2. No" << endl;
		validacionDatoEspecifico(optPerro, 1, 2);
		if (optPerro == 1) {
			cout << "El perro necesita paseo diario" << endl;
			datoEspecifico = true;
		}
		else {
			cout << "El perro no necesita paseo diario" << endl;
		}
	}
	else if (tipo == 2) {
		int optGato;
		cout << "¿El gato requiere caja de arena especial?"
			<< "\n1. Sí"
			<< "\n2. No" << endl;
		validacionDatoEspecifico(optGato, 1, 2);
		if (optGato == 1) {
			cout << "El gato necesita caja de arena especial" << endl;
			datoEspecifico = true;
		}
		else {
			cout << "El gato no necesita caja de arena especial" << endl;
		}
	}
}

void Mascota::registrarMascota(string nombre, int tipo) {
	this->nombre = nombre;
	this->tipo = tipo;
}

string Mascota::getNombre() { return nombre; }

double Mascota::gastoTotalMascota() { return gastoMascota * 1.12; }