#include "Pila.h"
#include <iostream>

void Pila::pushAlquiler(Alquiler alquiler) {
	Nodo<Alquiler>* nodoAgregar = new Nodo<Alquiler>(alquiler);
	nodoAgregar->dato = alquiler;
	nodoAgregar->next = cima;
	cima = nodoAgregar;
}

void Pila::popAlquiler() {
	if (cima == nullptr) {
		cout << "La pila está vacía" << endl;
		return;
	}

	Nodo<Alquiler>* nodoEliminar = cima;
	cima = cima->next;
	delete nodoEliminar;
}

void Pila::mostrarPila() {
	if (cima == nullptr) {
		cout << "La cola está vacía" << endl;
		return;
	}

	Nodo<Alquiler>* nodoActual = cima;
	while (nodoActual != nullptr) {
		nodoActual->dato.mostrarAlquiler();
		nodoActual = nodoActual->next;
	}
}

Pila::~Pila() {}