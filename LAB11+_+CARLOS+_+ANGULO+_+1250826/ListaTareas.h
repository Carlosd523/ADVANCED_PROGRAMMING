#pragma once
#ifndef LISTATAREAS_H
#define LISTATAREAS_H
#include "Nodo.h"
class ListaTareas
{
private:
	Nodo* header = new Nodo();
	Nodo* tail = new Nodo();
public:
	ListaTareas();

	void agregarTarea(Tarea tarea);

	void eliminarTarea(string nombre);

	void buscarTarea(string nomnre);

	void mostrarTareas();

	void mostrarTareasInversamente();

	Nodo* getHeader();

	Nodo* getTail();

	~ListaTareas();
};

#endif