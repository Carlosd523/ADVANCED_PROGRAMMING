#include "Pila.h"
#include <iostream>

// Constructor
Pila::Pila(){}

// Métodos
// Push - Agrega un elemento a la pila
void Pila::push(string pagina) {
	Nodo* nodoAgregar = new Nodo();
	nodoAgregar->pagina = pagina;
	nodoAgregar->next = cima;
	cima = nodoAgregar;
}

// Pop - Elimina un elemento de la pila
void Pila::pop() {
	if (isEmpty()) {
		cout << "La pila está vacía" << endl;
		return;
	}

	Nodo* nodoBorrar = cima;
	cima = cima->next;
	delete nodoBorrar;
}

// Top - Devuelve la página web que se encuentra en el tope de la pila
string Pila::top() {
	if (isEmpty()) {
		cout << "La pila está vacía" << endl;
		return "";
	}

	return cima->pagina;
}

// IsEmpty - Retorna false si la pila tiene algún elemento, retorna true si la pila no tiene ningún elemento
bool Pila::isEmpty() {
	if (cima == nullptr) {
		return true;
	}
	return false;
}

// Mostrar - Muestra todos los elementos de la pila
void Pila::mostrar() const {
	if (cima == nullptr) {
		return;
	}

	const Nodo* nodoActual = cima;
	while (nodoActual != nullptr) {
		cout << nodoActual->pagina << endl;
		nodoActual = nodoActual->next;
	}
}

// Destructor
Pila::~Pila() {
	while (!isEmpty()) {
		pop();
	}
}