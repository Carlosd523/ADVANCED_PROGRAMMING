#pragma once
#include <string>
#ifndef MASCOTA_H
#define MASCOTA_H

struct Mascota
{
	std::string nombre = "";
	int tipo = 0;
	bool datoEspecifico = false;
	double gastoMascota = 0;

	void funcionExtra();

	void registrarMascota(std::string nombre, int tipo);

	std::string getNombre();

	double gastoTotalMascota();

	~Mascota() {}
};

#endif