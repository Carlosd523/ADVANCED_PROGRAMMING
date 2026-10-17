#pragma once
#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Alquiler.h"

class Pila
{
private:
	Nodo<Alquiler>* cima = nullptr;
public:
	// Método push
	void pushAlquiler(Alquiler alquiler);

	// Método pop
	void popAlquiler();

	// Mostrar la pila
	void mostrarPila();

	// Destructor
	~Pila();
};

#endif