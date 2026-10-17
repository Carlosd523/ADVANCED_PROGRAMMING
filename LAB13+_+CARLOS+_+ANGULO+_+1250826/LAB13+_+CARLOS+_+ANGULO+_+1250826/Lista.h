#pragma once
#ifndef LISTA_H
#define LISTA_H
#include "Pelicula.h"
#include "Nodo.h"

class Lista
{
private:
	Nodo<Pelicula>* header = nullptr;

public:
	// Agregar elemento a la lista
	void agregarElemento(Pelicula pelicula);

	// Eleminar elemento de la lista
	void eliminarElemento(Pelicula pelicula);

	// Mostrar elementos
	void mostrarElementos();

	// Ordenación por título (Bubble Sort)
	void ordenarPorTítulo();

	// Destructor
	~Lista();
};

#endif