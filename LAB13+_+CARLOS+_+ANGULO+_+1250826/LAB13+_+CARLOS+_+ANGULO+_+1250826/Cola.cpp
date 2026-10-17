#include "Cola.h"
#include <iostream>

// Agregar un cliente
void Cola::agregarCliente(Cliente cliente) {
	Nodo<Cliente>* nodoAgregar = new Nodo<Cliente>(cliente);
	nodoAgregar->dato = cliente;

	if (frente == nullptr) {
		frente = nodoAgregar;
		final = nodoAgregar;
		return;
	}

	final->next = nodoAgregar;
	nodoAgregar = final;
}

// Atender un cliente
void Cola::atenderCliente() {
	if (frente == nullptr) {
		cout << "La cola está vacía" << endl;
	}

	Nodo<Cliente>* nodoEliminar = frente;
	if (frente == final) {
		delete nodoEliminar;
		frente == nullptr;
		final == nullptr;
	}
	else {
		frente = frente->next;
		delete nodoEliminar;
	}
}

// Mostrar cola
void Cola::mostrarCola() {
	if (frente == nullptr) {
		cout << "La cola está vacía" << endl;
		return;
	}

	Nodo<Cliente>* nodoActual = frente;
	while (nodoActual != nullptr) {
		nodoActual->dato.mostrarCliente();
		nodoActual = nodoActual->next;
	}
}

// Destructor
Cola::~Cola() {}