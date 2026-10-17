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
	int fechaAlquiler;
	int fechaDevolucion;
	double montoTotal;

public:
	// Constructor
	Alquiler(Pelicula* pelicula, Cliente* cliente, int fechaAlquiler, int fechaDevolucion, double montoTotal);

	// Métodos get
	Pelicula* getPelicula();
	Cliente* getCliente();
	int getFechaAlquiler();
	int getFechaDevolucion();
	double getMontoTotal();

	// Métodos set
	void setPelicula(Pelicula* pelicula);
	void setCliente(Cliente* cliente);
	void setFechaAlquiler(int fechaAlquiler);
	void setFechaDevolucion(int fechaDevolucion);
	void setMontoTotal(double montoTotal);

	// Otros métodos
	void mostrarAlquiler();
};

#endif