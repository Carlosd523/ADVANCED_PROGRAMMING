#include "Cliente.h"
#include <iostream>

// Constructores
Cliente::Cliente(string nombre, int ID, string correo) {
	this->nombre = nombre;
	this->Id = ID;
	this->correo = correo;
}
Cliente::Cliente(){}

// Métodos get
string Cliente::getNombre() { return nombre; }
int Cliente::getId() { return Id; }
string Cliente::getCorreo() { return correo; }

// Métodos set
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setId(int ID) { this->Id = ID; }
void Cliente::setCorreo(string correo) { this->correo = correo; }

// Otros métodos
void Cliente::mostrarCliente() {
	cout << "Cliente: " << nombre
		<< "\nID: " << Id
		<< "\nCorreo electrónico: " << correo << endl;
}