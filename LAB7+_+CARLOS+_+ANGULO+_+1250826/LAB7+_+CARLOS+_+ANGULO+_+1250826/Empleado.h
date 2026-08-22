#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

using namespace std;

class Empleado
{
private:
	string nombre;
	string id;
	double salario;

public:
	Empleado(string nombre, string id, double salario);

	virtual void mostrarInfo() = 0;
	virtual double calcularSalarioTotal() = 0;
	virtual string getTipo() = 0;

	string getNombre();
	string getID();
	double getSalario();

	void setSalario(double salario);

	virtual ~Empleado();
};

#endif