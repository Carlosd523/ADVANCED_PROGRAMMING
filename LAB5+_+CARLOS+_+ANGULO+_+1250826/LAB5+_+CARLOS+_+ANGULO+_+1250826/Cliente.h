#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Tanque.h"

using namespace std;

class Cliente
{
private:
	string nombre;
	string direccion;
	int telefono;

public:
	// Constructores
	Cliente();

	Cliente(string nombre, string direccion, int telefono);

	void mostrarInfo();
};

#endif