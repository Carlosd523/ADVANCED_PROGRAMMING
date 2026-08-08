#pragma once
#ifndef TANQUE_H
#define TANQUE_H

#include <string>

using namespace std;

class Tanque
{
private:
	string tipo;
	double volumen = 0;
	double precio = 0;
	double costoFijo;
	double costoM3;

public:
	// Constructores
	Tanque();
	Tanque(string tipo, double costoFijo, double costoM3);

	// Métodos
	virtual double calcularVolumen() = 0;
	double calcularPrecio();
	void mostrarInformacion();

	// Métodos get
	double getVolumen();
	double getPrecio();

	// Métodos set
	void setVolumen(double volumen);
	void setPrecio(double precio);
};

#endif