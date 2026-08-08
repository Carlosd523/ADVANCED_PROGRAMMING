#include "TanqueEsferico.h"
#include <math.h>

TanqueEsferico::TanqueEsferico() {};
TanqueEsferico::TanqueEsferico(double radio)
	:Tanque("Esférico", 150, 65) {
	this->radio = radio;

	setVolumen(calcularVolumen());
	setPrecio(calcularPrecio());
}

void TanqueEsferico::registrarRadio(double radio) {
	this->radio = radio;
}

double TanqueEsferico::calcularVolumen() {
	const double pi = 3.1416;
	double volumen = (4 / 3) * pi * pow(radio, 3);
	return volumen;
}