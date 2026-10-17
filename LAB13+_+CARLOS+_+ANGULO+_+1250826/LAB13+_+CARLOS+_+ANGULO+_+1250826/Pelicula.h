#pragma once
#ifndef PELICULA_H
#define PELICULA_H
#include <string>

using namespace std;

class Pelicula
{
private:
	string titulo = "";
	string genero = "";
	double precioAlquiler = 0;
	int anyoEstreno = 0;
	int copiasDisponibles = 0;

public:
	// Constructores
	Pelicula(string titulo, string genero, double precioAlquiler, int anyoEstreno, int copiasDisponibles);
	Pelicula();

	// Métodos get
	string getTitulo();
	string getGenero();
	double getPrecioAlquiler();
	int getAnyoEstreno();
	int getCopiasDisponibles();

	// Métodos set
	void setTitulo(string titulo);
	void setGenero(string genero);
	void setPrecioAlquiler(double precioAlquier);
	void setAnyoEstreno(int anyoEstreno);
	void setCopiasDisponibles(int copiasDisponibles);

	// Otros métodos
	void mostrarPelicula();
};

#endif