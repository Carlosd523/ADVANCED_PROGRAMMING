#include "TanqueCilindrico.h"
#include <math.h>

TanqueCilindrico::TanqueCilindrico() {};
TanqueCilindrico::TanqueCilindrico(double radio, double altura)
	:Tanque("Cilíndrico", 100, 50) {
	this->radio = radio;
	this->altura = altura;

	setVolumen(calcularVolumen());
	setPrecio(calcularPrecio());
}

void TanqueCilindrico::registrarRadio(double radio) {
	this->radio = radio;
}

void TanqueCilindrico::registrarAltura(double altura) {
	this->altura = altura;
}

double TanqueCilindrico::calcularVolumen() {
	const double pi = 3.1416;
	double volumen = pi * pow(radio, 2) * altura;
	return volumen;
}