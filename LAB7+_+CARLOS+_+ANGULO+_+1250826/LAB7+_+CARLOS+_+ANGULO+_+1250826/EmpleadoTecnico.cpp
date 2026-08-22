#include "EmpleadoTecnico.h"
#include <iostream>

EmpleadoTecnico::EmpleadoTecnico(string nombre, string id, double salario, string especialidad, int horasExtra)
	:Empleado(nombre, id, salario) {
	this->especialidad = especialidad;
	this->horasExtra = horasExtra;
}

void EmpleadoTecnico::mostrarInfo() {
	cout << "Información empleado administrativo " << getID()
		<< "\nNombre: " << getNombre()
		<< "\nSalario: " << getSalario()
		<< "\nDepartamento: " << especialidad
		<< "\nBonificación: " << horasExtra
		<< "\nSalario total: " << calcularSalarioTotal() << endl;
}

// El empleado recibirá Q200 por cada hora extra trabajada
double EmpleadoTecnico::calcularSalarioTotal() { return getSalario() + (horasExtra * 200); }

string EmpleadoTecnico::getTipo() { return "Técnico"; }

EmpleadoTecnico::~EmpleadoTecnico() {}