#pragma once
#ifndef TAREA_H
#define TAREA_H
#include <string>

using namespace std;

class Tarea
{
private:
	string nombre;
	string descripcion;
	string fechaLimite;
	int prioridad = 0;

public:
	// Constructores
	Tarea(string nombre, string descripcion, string fechaLimite, int prioridad);

	Tarea();

	// Métodos set y get
	string getNombre();
	void setNombre(string nombre);

	string getDescripcion();
	void setDescripcion(string descripcion);

	string getFechaLimite();
	void setFechaLimite(string fechaLimite);

	int getPrioridad();
	void setPrioridad(int prioridad);

	// Otros métodos
	void mostrarDetallesTarea();
};

#endif