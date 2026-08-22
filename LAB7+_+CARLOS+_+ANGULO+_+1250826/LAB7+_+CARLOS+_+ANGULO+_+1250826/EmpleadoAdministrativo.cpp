#include "EmpleadoAdministrativo.h"
#include <iostream>

EmpleadoAdministrativo::EmpleadoAdministrativo(string nombre, string id, double salario, string departamento, double bonificacion)
	:Empleado(nombre, id, salario) {
	this->departamento = departamento;
	this->bonificacion = bonificacion;
}

void EmpleadoAdministrativo::mostrarInfo() {
	cout << "Información empleado administrativo " << getID()
		<< "\nNombre: " << getNombre()
		<< "\nSalario: " << getSalario()
		<< "\nDepartamento: " << departamento
		<< "\nBonificación: " << bonificacion
		<< "\nSalario total: " << calcularSalarioTotal() << endl;
}

double EmpleadoAdministrativo::calcularSalarioTotal() { return getSalario() + bonificacion; }

string EmpleadoAdministrativo::getTipo() { return "Adminsitrativo"; }

EmpleadoAdministrativo::~EmpleadoAdministrativo() {}