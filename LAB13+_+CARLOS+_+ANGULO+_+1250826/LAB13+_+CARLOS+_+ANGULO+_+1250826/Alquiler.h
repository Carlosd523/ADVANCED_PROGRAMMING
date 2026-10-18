#pragma once
#ifndef ALQUILER_H
#define ALQUILER_H
#include "Pelicula.h"
#include "Cliente.h"

class Alquiler
{
private:
	Pelicula* pelicula;
	Cliente* cliente;
	string fechaAlquiler;
	string fechaDevolucion = "Película aún en alquiler";
	double montoTotal;

public:
	// Constructor
	Alquiler(Pelicula* pelicula, Cliente* cliente, string fechaAlquiler, double montoTotal);

	// Métodos get
	Pelicula* getPelicula();
	Cliente* getCliente();
	string getFechaAlquiler();
	string getFechaDevolucion();
	double getMontoTotal();

	// Métodos set
	void setPelicula(Pelicula* pelicula);
	void setCliente(Cliente* cliente);
	void setFechaAlquiler(string fechaAlquiler);
	void setFechaDevolucion(string fechaDevolucion);
	void setMontoTotal(double montoTotal);

	// Otros métodos
	void mostrarDetalles();
};

#endif