#include "Pila.h"
#include <iostream>

void Pila::pushAlquiler(Alquiler* alquiler) {
	Nodo<Alquiler*>* nodoAgregar = new Nodo<Alquiler*>(alquiler);
	nodoAgregar->next = cima;
	cima = nodoAgregar;
}

Alquiler* Pila::popAlquiler() {
	if (cima == nullptr) {
		cout << "La pila está vacía" << endl;
		return nullptr;
	}

	Nodo<Alquiler*>* nodoEliminar = cima;
	Alquiler* alquiler = nodoEliminar->dato;
	cima = cima->next;
	delete nodoEliminar;
	return alquiler;
}

void Pila::mostrarPila() {
	if (cima == nullptr) {
		cout << "La pila está vacía" << endl;
		return;
	}

	Nodo<Alquiler*>* nodoActual = cima;
	while (nodoActual != nullptr) {
		nodoActual->dato->mostrarDetalles();
		cout << endl;
		nodoActual = nodoActual->next;
	}
}

// Get Cima
Alquiler* Pila::getCima() { return cima->dato; }

// Determina si la pila está vacía
bool Pila::pilaVacia() {
	if (cima == nullptr) { return true; }
	return false;
}

Pila::~Pila() {}