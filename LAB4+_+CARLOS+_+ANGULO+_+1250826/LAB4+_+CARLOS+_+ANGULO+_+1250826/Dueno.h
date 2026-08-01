#pragma once
#ifndef DUENO_H
#define DUENO_H

#include <string>
#include "Mascota.h"

using namespace std;

struct Dueno
{
	string nombre;
	string ID;
	Mascota mascotas[10];
	int contadorMascotas = 0;

	Dueno();

	void registrarDueno(string nombre, string ID);

	string getNombre();
	int getContadorMascotas();	

	~Dueno() {};
};

#endif