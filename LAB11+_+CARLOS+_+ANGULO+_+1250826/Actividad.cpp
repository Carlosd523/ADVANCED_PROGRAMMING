#include "Actividad.h"
#include <iostream>

Actividad::Actividad(string nombre, string descripcion, int hora) {
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->hora = hora;
}

Actividad::Actividad() {}

string Actividad::getNombre() { return nombre; }
void Actividad::setNombre(string nommbre) { this->nombre = nommbre; }

string Actividad::getDescripcion() { return descripcion; }
void Actividad::setDescripcion(string descripcion) { this->descripcion = descripcion; }

int Actividad::getHora() { return hora; }
void Actividad::setHora(int hora) { this->hora = hora; }

void Actividad::mostrarActividad() {
	cout << "Detalles Actividad"
		<< "\nNombre: " << nombre
		<< "\nDescripción: " << descripcion
		<< "\nHora: " << hora << endl;
}