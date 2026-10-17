#pragma once
#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>

using namespace std;

class Actividad
{
private:
	string nombre;
	string descripcion;
	int hora = 0;

public:
	// Constructores
	Actividad(string nombre, string descripcion, int hora);

	Actividad();

	// Métodos set y get
	string getNombre();
	void setNombre(string nombre);

	string getDescripcion();
	void setDescripcion(string descripcion);

	int getHora();
	void setHora(int hora);

	// Método #1 - Mostrar Actividad
	void mostrarActividad();
};

#endif