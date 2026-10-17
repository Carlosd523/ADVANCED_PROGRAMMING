#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

using namespace std;

class Cliente
{
private:
	string nombre = "";
	int Id = 0;
	string correo = "";

public:
	// Constructores
	Cliente(string nombre, int ID, string correo);
	Cliente();

	// Métodos get
	string getNombre();
	int getId();
	string getCorreo();

	// Métodos set
	void setNombre(string nombre);
	void setId(int ID);
	void setCorreo(string correo);

	// Otros métodos
	void mostrarCliente();
};

#endif