#include "Cliente.h"
#include <iostream>

// Constructores
Cliente::Cliente(string nombre, string ID, string correo) {
	this->nombre = nombre;
	this->Id = ID;
	this->correo = correo;
}
Cliente::Cliente(){}

// Métodos get
string Cliente::getNombre() { return nombre; }
string Cliente::getClave() { return Id; }
string Cliente::getCorreo() { return correo; }

// Métodos set
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setId(int ID) { this->Id = ID; }
void Cliente::setCorreo(string correo) { this->correo = correo; }

// Otros métodos
void Cliente::mostrarDetalles() {
	cout << "Cliente: " << nombre
		<< "\nID: " << Id
		<< "\nCorreo electrónico: " << correo << endl;
}