#include "Empleado.h"

Empleado::Empleado(string nombre, string id, double salario) {
	this->nombre = nombre;
	this->id = id;
	this->salario = salario;
}

string Empleado::getNombre() { return nombre; }
string Empleado::getID() { return id; }
double Empleado::getSalario() { return salario; }

void Empleado::setSalario(double salario) { this->salario = salario; }

Empleado::~Empleado() {}