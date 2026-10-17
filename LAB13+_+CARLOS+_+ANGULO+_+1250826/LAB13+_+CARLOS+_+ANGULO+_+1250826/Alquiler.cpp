#include "Alquiler.h"
#include <iostream>

// Constructor
Alquiler::Alquiler(Pelicula* pelicula, Cliente* cliente, int fechaAlquiler, int fechaDevolucion, double montoTotal) {
	this->pelicula = pelicula;
	this->cliente = cliente;
	this->fechaAlquiler = fechaAlquiler;
	this->fechaDevolucion = fechaDevolucion;
	this->montoTotal = montoTotal;
}

// Métodos get
Pelicula* Alquiler::getPelicula() { return pelicula; }
Cliente* Alquiler::getCliente() { return cliente; }
int Alquiler::getFechaAlquiler() { return fechaAlquiler; }
int Alquiler::getFechaDevolucion() { return fechaDevolucion; }
double Alquiler::getMontoTotal() { return montoTotal; }

// Métodos set
void Alquiler::setPelicula(Pelicula* pelicula) { this->pelicula = pelicula; }
void Alquiler::setCliente(Cliente* cliente) { this->cliente = cliente; }
void Alquiler::setFechaAlquiler(int fechaAlquiler) { this->fechaAlquiler = fechaAlquiler; }
void Alquiler::setFechaDevolucion(int fechaDevolucion) { this->fechaDevolucion = fechaDevolucion; }
void Alquiler::setMontoTotal(double montoTotal) { this->montoTotal = montoTotal; }

// Otros métodos
void Alquiler::mostrarAlquiler() {
	cout << "Película alquilada: " << pelicula->getTitulo()
		<< "\nNombre del cliente: " << cliente->getNombre()
		<< "\nID del cliente: " << cliente->getId()
		<< "\nFecha de alquiler: " << fechaAlquiler
		<< "\nFecha de devolución: " << fechaDevolucion
		<< "\nMonto total: Q" << montoTotal << endl;
}