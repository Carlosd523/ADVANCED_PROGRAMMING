#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

using namespace std;

class Cliente
{
private:
	
	string nombre = "";
	// El ID es la clave de Cliente
	string Id = "";
	string correo = "";

public:
	// Constructores
	Cliente(string nombre, string ID, string correo);
	Cliente();

	// Métodos get
	string getNombre();
	string getClave();
	string getCorreo();

	// Métodos set
	void setNombre(string nombre);
	void setId(int ID);
	void setCorreo(string correo);

	// Otros métodos
	void mostrarDetalles();
};

#endif