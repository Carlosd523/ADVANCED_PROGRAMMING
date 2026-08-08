#include "Tanque.h"
#include <iostream>

using namespace std;

Tanque::Tanque() {};
Tanque::Tanque(string tipo, double costoFijo, double costoM3) {
	this->tipo = tipo;
	this->costoFijo = costoFijo;
	this->costoM3 = costoM3;
}

double Tanque::calcularPrecio() {
	precio = costoFijo + (costoM3 * volumen);
	return precio;
}

void Tanque::mostrarInformacion() {
	cout << "Tipo: " << tipo
		<< "\nVolumen: " << volumen
		<< "\nPrecio: " << precio << endl;
}

double Tanque::getVolumen() { return volumen; }
double Tanque::getPrecio() { return precio; }

void Tanque::setVolumen(double volumen) { this->volumen = volumen; }
void Tanque::setPrecio(double precio) { this->precio = precio; }