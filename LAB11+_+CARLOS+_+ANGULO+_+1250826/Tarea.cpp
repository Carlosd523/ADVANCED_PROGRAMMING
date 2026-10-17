#include "Tarea.h"
#include <iostream>

// Constructor
Tarea::Tarea(string nombre, string descripcion, string fechaLimite, int prioridad) {
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->fechaLimite = fechaLimite;
	this->prioridad = prioridad;
}

Tarea::Tarea() {}

// Métodos get y set
string Tarea::getNombre() { return nombre; }
void Tarea::setNombre(string nombre) { this->nombre = nombre; }

string Tarea::getDescripcion() { return descripcion; }
void Tarea::setDescripcion(string descripcion) { this->descripcion = descripcion; }

string Tarea::getFechaLimite() { return fechaLimite; }
void Tarea::setFechaLimite(string fechaLimite) { this->fechaLimite = fechaLimite; }

int Tarea::getPrioridad() { return prioridad; }
void Tarea::setPrioridad(int prioridad) { this->prioridad = prioridad; }

// Otros métodos
void Tarea::mostrarDetallesTarea() {
	cout << "Tarea: " << nombre
		<< "\nDescripción:"
		<< "\n" << descripcion
		<< "\nFecha límite: " << fechaLimite
		<< "\nPrioridad ";
	if (prioridad == 1) {
		cout << "alta" << endl;
	}
	else if (prioridad == 2) {
		cout << "media" << endl;
	}
	else {
		cout << "baja" << endl;
	}
}