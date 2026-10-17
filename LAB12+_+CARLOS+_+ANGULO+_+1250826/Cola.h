#pragma once
#ifndef COLA_H
#define COLA_H
#include "NodoCricular.h"

class Cola
{
private:
	NodoCircular* frente = nullptr;
	NodoCircular* final = nullptr;
public:
	// Enqueue - Agrega un elemento a la cola
	void enqueue(TrabajoImpresion trabajo);

	// Dequeue - Elimina un elemento de la cola
	void dequeue();

	// Front - Muestra la información del trabajo que se encuentra en el frente
	TrabajoImpresion front() const;

	// IsEmpty - Determina si la cola está vacía
	bool isEmpty();

	// Destructor
	~Cola();
};

#endif