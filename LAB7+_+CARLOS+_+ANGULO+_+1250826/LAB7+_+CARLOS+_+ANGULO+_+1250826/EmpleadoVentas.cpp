#include "EmpleadoVentas.h"
#include <iostream>

EmpleadoVentas::EmpleadoVentas(string nombre, string id, double salario, int ventasRealizadas, double comision)
	:Empleado(nombre, id, salario) {
	this->ventasRealizadas = ventasRealizadas;
	this->comision = comision;
}

void EmpleadoVentas::mostrarInfo() {
	cout << "Información empleado administrativo " << getID()
		<< "\nNombre: " << getNombre()
		<< "\nSalario: " << getSalario()
		<< "\nDepartamento: " << comision
		<< "\nBonificación: " << ventasRealizadas
		<< "\nSalario total: " << calcularSalarioTotal() << endl;
}

double EmpleadoVentas::calcularSalarioTotal() { return getSalario() + comision; }
string EmpleadoVentas::getTipo() { return "Ventas"; }

EmpleadoVentas::~EmpleadoVentas() {}