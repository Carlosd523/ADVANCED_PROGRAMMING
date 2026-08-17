#pragma once
#ifndef COMIC_H
#define COMIC_H
#include <string>
#include <iostream>

using namespace std;

class Comic
{
private:
	string titulo;
	string editorial;
	int issue;
	string codigoBarras;
	double precio;
	int anyoPublicacion;
	char estado;
	bool edicionLimitada;
	string genero;

public:
	// Constructor
	Comic(string titulo, string editorial, int issue, string codigoBarras, double precio, char estado, bool edicionLimitada, string genero);


	// Métodos
	void mostrarInformacion();

	string getTitulo();
	string getCodigoBarras();
	string getEditorial();
	int getNumeroEdicion();
};

#endif