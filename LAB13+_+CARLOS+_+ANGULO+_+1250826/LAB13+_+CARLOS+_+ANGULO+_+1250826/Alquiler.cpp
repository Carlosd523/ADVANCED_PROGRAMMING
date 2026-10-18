#include "Alquiler.h"
#include <iostream>

// Constructor
Alquiler::Alquiler(Pelicula* pelicula, Cliente* cliente, string fechaAlquiler, double montoTotal) {
	this->pelicula = pelicula;
	this->cliente = cliente;
	this->fechaAlquiler = fechaAlquiler;
	this->montoTotal = montoTotal;
}

// Métodos get
Pelicula* Alquiler::getPelicula() { return pelicula; }
Cliente* Alquiler::getCliente() { return cliente; }
string Alquiler::getFechaAlquiler() { return fechaAlquiler; }
string Alquiler::getFechaDevolucion() { return fechaDevolucion; }
double Alquiler::getMontoTotal() { return montoTotal; }

// Métodos set
void Alquiler::setPelicula(Pelicula* pelicula) { this->pelicula = pelicula; }
void Alquiler::setCliente(Cliente* cliente) { this->cliente = cliente; }
void Alquiler::setFechaAlquiler(string fechaAlquiler) { this->fechaAlquiler = fechaAlquiler; }
void Alquiler::setFechaDevolucion(string fechaDevolucion) { this->fechaDevolucion = fechaDevolucion; }
void Alquiler::setMontoTotal(double montoTotal) { this->montoTotal = montoTotal; }

// Otros métodos
void Alquiler::mostrarDetalles() {
	cout << "Película alquilada: " << pelicula->getClave()
		<< "\nNombre del cliente: " << cliente->getNombre()
		<< "\nID del cliente: " << cliente->getClave()
		<< "\nFecha de alquiler: " << fechaAlquiler
		<< "\nFecha de devolución: " << fechaDevolucion
		<< "\nMonto total: Q" << montoTotal << endl;
}