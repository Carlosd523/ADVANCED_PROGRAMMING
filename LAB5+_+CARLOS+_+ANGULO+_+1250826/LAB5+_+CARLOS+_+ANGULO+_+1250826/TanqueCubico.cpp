#include "TanqueCubico.h"
#include <iostream>
#include <math.h>

TanqueCubico::TanqueCubico() {};
TanqueCubico::TanqueCubico(double lado)
	:Tanque("Cúbico", 80, 45) {
	this->lado = lado;

	setVolumen(calcularVolumen());
	setPrecio(calcularPrecio());
}

void TanqueCubico::registrarLado(double lado) {
	this->lado = lado;
}

double TanqueCubico::calcularVolumen() {
	double volumen = pow(lado, 3);
	return volumen;
}