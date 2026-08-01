#include "Dueno.h"
#include <string>

void Dueno::registrarDueno(std::string nombre, std::string ID) {
	this->nombre = nombre;
	this->ID = ID;
}

Dueno::Dueno() {}

std::string Dueno::getNombre() { return nombre; }
int Dueno::getContadorMascotas() { return contadorMascotas; }