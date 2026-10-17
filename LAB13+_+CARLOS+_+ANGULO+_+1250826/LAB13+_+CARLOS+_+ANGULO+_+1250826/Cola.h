#pragma once
#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
#include "Cliente.h"
class Cola
{
private:
	Nodo<Cliente>* frente = nullptr;
	Nodo<Cliente>* final = nullptr;

public:
	// Agregar un cliente
	void agregarCliente(Cliente cliente);

	// Atender un cliente
	void atenderCliente();

	// Mostrar cola
	void mostrarCola();

	// Destructor
	~Cola();
};

#endif