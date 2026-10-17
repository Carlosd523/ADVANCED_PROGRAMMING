#pragma once
#ifndef PILA_H
#define PILA_H
#include <string>
#include "Nodo.h"

using namespace std;

class Pila
{
private:
	Nodo* cima = nullptr;

public:
	// Constructor
	Pila();

	// Métodos
	// Push - Agrega un elemento a la pila
	void push(string pagina);

	// Pop - Elimina un elemento de la pila
	void pop();

	// Top - Devuelve la página web que se encuentra en el tope de la pila
	string top();

	// IsEmpty - Retorna false si la pila tiene algún elemento, retorna true si la pila no tiene ningún elemento
	bool isEmpty();

	// Mostrar - Muestra todos los elementos de la pila
	void mostrar() const;

	// Destructor
	~Pila();
};

#endif