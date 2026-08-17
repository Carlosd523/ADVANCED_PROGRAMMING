#include "Comic.h"
#include <random>

Comic::Comic(string titulo, string editorial, int issue, string codigoBarras, double precio, char estado, bool edicionLimitada, string genero) {
	this->titulo = titulo;
	this->editorial = editorial;
	this->issue = issue;
	this->codigoBarras = codigoBarras;
	this->precio = precio;
	this->estado = estado;
	this->edicionLimitada = edicionLimitada;
	this->genero = genero;
}

void Comic::mostrarInformacion() {
	cout << "Comic: " + titulo
		<< "\nEditorial: " + editorial
		<< "\nNúmero de edición: " << issue
		<< "\nCódigo de barras: " << codigoBarras
		<< "\nPrecio: " << precio
		<< "\nAño de publicación: " << anyoPublicacion
		<< "\nEstado de conservación: " << estado
		<< "\n¿Es edición limitada? ";
	if (edicionLimitada) {
		cout << "Sí" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << "Género: " << genero << endl;
	cout << endl;
}

string Comic::getTitulo() { return titulo; }
string Comic::getCodigoBarras() { return codigoBarras; }
string Comic::getEditorial() { return editorial; }
int Comic::getNumeroEdicion() { return issue; }