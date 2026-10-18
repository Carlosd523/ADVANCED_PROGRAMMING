#pragma once
#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Alquiler.h"

class Pila
{
private:
	Nodo<Alquiler*>* cima = nullptr;
public:
	// Método push
	void pushAlquiler(Alquiler* alquiler);

	// Método pop
	Alquiler* popAlquiler();

	// Mostrar la pila
	void mostrarPila();

	// Determina si la pila está vacía
	bool pilaVacia();

	// Get Cima
	Alquiler* getCima();

	// Destructor
	~Pila();
};

#endif