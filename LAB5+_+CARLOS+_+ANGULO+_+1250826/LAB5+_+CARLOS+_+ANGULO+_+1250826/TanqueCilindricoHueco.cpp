#include "TanqueCilindricoHueco.h"
#include <math.h>

TanqueCilindricoHueco::TanqueCilindricoHueco() {};
TanqueCilindricoHueco::TanqueCilindricoHueco(double radioExterno, double radioInterno, double altura)
	:Tanque("Cilíndrico Hueco", 130, 60) {
	this->radioExterno = radioExterno;
	this->radioInterno = radioInterno;
	this->altura = altura;

	setVolumen(calcularVolumen());
	setPrecio(calcularPrecio());
}

void TanqueCilindricoHueco::registrarRadios(double radioExterno, double radioInterno) {
	this->radioExterno = radioExterno;
	this->radioInterno = radioInterno;
}

void TanqueCilindricoHueco::registrarAltura(double altura) {
	this->altura = altura;
}

double TanqueCilindricoHueco::calcularVolumen() {
	const double pi = 3.1416;
	double volumen = pi * altura * (pow(radioExterno, 2) - pow(radioInterno, 2));
	return volumen;
}