#include "Pelicula.h"
#include <iostream>

// Constructores
Pelicula::Pelicula(string titulo, string genero, double precioAlquiler, int anyoEstreno, int copiasDisponibles) {
	this->titulo = titulo;
	this->genero = genero;
	this->precioAlquiler = precioAlquiler;
	this->anyoEstreno = anyoEstreno;
	this->copiasDisponibles = copiasDisponibles;
}

Pelicula::Pelicula() {}

// Métodos get
string Pelicula::getClave() { return titulo; }
string Pelicula::getGenero() { return genero; }
double Pelicula::getPrecioAlquiler() { return precioAlquiler; }
int Pelicula::getAnyoEstreno() { return anyoEstreno; }
int Pelicula::getCopiasDisponibles() { return copiasDisponibles; }

// Métodos set
void Pelicula::setTitulo(string titulo) { this->titulo = titulo; }
void Pelicula::setGenero(string genero) { this->genero = genero; }
void Pelicula::setPrecioAlquiler(double precioAlquier) { this->precioAlquiler = precioAlquier; }
void Pelicula::setAnyoEstreno(int anyoEstreno) { this->anyoEstreno = anyoEstreno; }
void Pelicula::setCopiasDisponibles(int copiasDisponibles) { this->copiasDisponibles = copiasDisponibles; }

// Otros métodos
void Pelicula::mostrarDetalles() {
	cout << "Título de la película: " << titulo
		<< "\nGénero: " << genero
		<< "\nPrecio de alquiler: " << precioAlquiler
		<< "\nAño de estreno: " << anyoEstreno
		<< "\nCopias disponibles: " << copiasDisponibles << endl;
}