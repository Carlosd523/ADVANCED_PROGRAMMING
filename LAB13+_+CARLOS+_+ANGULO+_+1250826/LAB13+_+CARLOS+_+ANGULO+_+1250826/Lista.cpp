#include "Lista.h"
#include <iostream>

using namespace std;

// Agregar elemento a la lista
void Lista::agregarElemento(Pelicula pelicula) {
	Nodo<Pelicula>* nodoAgregar = new Nodo<Pelicula>(pelicula);

	if (header == nullptr) {
		header = nodoAgregar;
		return;
	}

	Nodo<Pelicula>* nodoActual = header;
	while (nodoActual != nullptr) {
		nodoActual = nodoActual->next;
	}
	nodoActual = nodoAgregar;
}

// Eleminar elemento de la lista
void Lista::eliminarElemento(Pelicula pelicula) {
	if (header == nullptr) {
		cout << "No hay películas disponibles" << endl;
		return;
	}

	bool encontrado = false;
	Nodo<Pelicula>* nodoActual = header;
	Nodo<Pelicula>* nodoBorrar = nullptr;

	while (nodoActual->next != nullptr) {
		if (nodoActual->next->dato.getTitulo() == pelicula.getTitulo()) {
			encontrado = true;
			nodoBorrar = nodoActual->next;
			break;
		}
		nodoActual = nodoActual->next;
	}

	if (encontrado) {
		cout << "Elemento borrado exitosamente" << endl;
		nodoActual->next = nodoBorrar->next;
		delete nodoBorrar;
	}
	else {
		cout << "No se ha encontrado ninguna coincidencia" << endl;
	}
}

// Mostrar elementos
void Lista::mostrarElementos() {
	if (header == nullptr) {
		cout << "No hay elementos en la lista" << endl;
		return;
	}

	Nodo<Pelicula>* nodoActual = header;

	while (nodoActual != nullptr) {
		nodoActual->dato;
		nodoActual->dato.mostrarPelicula();
		nodoActual = nodoActual->next;
	}
}

// Ordenación por título (Bubble Sort)
void Lista::ordenarPorTítulo() {
	if (header == nullptr) {
		cout << "La lista está vacía" << endl;
		return;
	}

	bool huboCambios;
	Nodo<Pelicula>* limite = nullptr;

	do {
		huboCambios = false;
		Nodo<Pelicula>* nodoActual = header;
		while (nodoActual->next != limite) {
			if (nodoActual->dato.getTitulo() > nodoActual->next->dato.getTitulo()) {
				swap(nodoActual->dato, nodoActual->next->dato);
				huboCambios = true;
			}
			nodoActual = nodoActual->next;
		}
		limite = nodoActual;
	} while (huboCambios);
}

// Destructor
Lista::~Lista() {}