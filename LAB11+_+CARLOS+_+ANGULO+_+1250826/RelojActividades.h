#pragma once
#ifndef RELOJACTIVIDADES_H
#define RELOJACTIVIDADES_H
#include "Actividad.h"
#include "NodoCircular.h"

class RelojActividades
{
private:
	NodoCircular* entrada = nullptr;
	NodoCircular* actual = nullptr;

public:
	void agregarActividad(Actividad actividad);

	void eliminarActividad(int hora);

	void mostrarActividadActual();

	void avanzarBloqueHorario();

	void retrocederBloqueHorario();

	void recorrerActividades();

	NodoCircular* getEntrada();
	
	~RelojActividades();
};

#endif