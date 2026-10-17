#include "Cola.h"
#include <iostream>

// Enqueue - Agrega un elemento a la cola
void Cola::enqueue(TrabajoImpresion trabajo) {
	NodoCircular* nodoAgregar = new NodoCircular();
	nodoAgregar->trabajo = trabajo;

	if (frente == nullptr) {
		frente = nodoAgregar;
		final = nodoAgregar;
		nodoAgregar->next = nodoAgregar;
		nodoAgregar->prev = nodoAgregar;
		return;
	}

	nodoAgregar->next = frente;
	nodoAgregar->prev = final;
	final->next = nodoAgregar;
	frente->prev = nodoAgregar;
	final = nodoAgregar;
}

// Dequeue - Elimina un elemento de la cola
void Cola::dequeue() {
	if (frente == nullptr) {
		cout << "La cola está vacía" << endl;
		return;
	}

	NodoCircular* nodoBorrar = frente;

	if (frente == final) {
		frente = nullptr;
		final = nullptr;
	}
	else {
		final->next = frente->next;
		frente->next->prev = final;
		frente = frente->next;
	}
	delete nodoBorrar;
}

// Front - Muestra la información del trabajo que se encuentra en el frente
TrabajoImpresion Cola::front() const {
	if (frente == nullptr) {
		cout << "La cola está vacía" << endl;
		return TrabajoImpresion();
	}

	return frente->trabajo;
}

bool Cola::isEmpty() {
	if (frente == nullptr) { return true; }
	return false;
}

// Destructor
Cola::~Cola() {
	while (!isEmpty()) {
		dequeue();
	}
}