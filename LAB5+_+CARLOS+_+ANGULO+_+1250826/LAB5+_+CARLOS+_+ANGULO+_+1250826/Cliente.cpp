#include "Cliente.h"
#include <iostream>

Cliente::Cliente() {};

Cliente::Cliente(string nombre, string direccion, int telefono) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
}

void Cliente::mostrarInfo() {
	std::cout << "Cliente: " << nombre
		<< "\nDireccion: " << direccion
		<< "\nTeléfono: " << telefono << endl;
}