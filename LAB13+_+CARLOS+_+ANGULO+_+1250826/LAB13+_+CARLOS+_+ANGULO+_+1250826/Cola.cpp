#include "Cola.h"
#include <iostream>

// Agregar un cliente
void Cola::agregarCliente(Cliente* cliente) {
	Nodo<Cliente*>* nodoAgregar = new Nodo<Cliente*>(cliente);

	if (frente == nullptr) {
		frente = nodoAgregar;
		final = nodoAgregar;
		return;
	}

	final->next = nodoAgregar;
	final = nodoAgregar;
}

// Atender un cliente
Cliente* Cola::atenderCliente() {
	if (frente == nullptr) {
		cout << "La cola está vacía" << endl;
		return nullptr;
	}

	Nodo<Cliente*>* nodoEliminar = frente;
	Cliente* cliente = nodoEliminar->dato;

	if (frente == final) {
		frente = nullptr;
		final = nullptr;
	}
	else {
		frente = frente->next;
	}

	delete nodoEliminar;
	return cliente;
}

// Mostrar cola
void Cola::mostrarCola() {
	if (frente == nullptr) {
		cout << "La cola está vacía" << endl;
		return;
	}

	Nodo<Cliente*>* nodoActual = frente;
	while (nodoActual != nullptr) {
		nodoActual->dato->mostrarDetalles();
		cout << endl;
		nodoActual = nodoActual->next;
	}
}

// Get frente
Cliente* Cola::getFrente() { return frente->dato; }

// Destructor
Cola::~Cola() {}