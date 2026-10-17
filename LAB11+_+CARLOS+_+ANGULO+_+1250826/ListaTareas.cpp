#include "ListaTareas.h"
#include <iostream>

ListaTareas::ListaTareas() {
	header->next = tail;
	tail->prev = header;
}

void ListaTareas::agregarTarea(Tarea tarea) {
	Nodo* nodoAgregar = new Nodo();
	nodoAgregar->tarea = tarea;

	if (header->next == tail) {
		header->next = nodoAgregar;
		tail->prev = nodoAgregar;
		nodoAgregar->next = tail;
		nodoAgregar->prev = header;
	}
	else if (nodoAgregar->tarea.getPrioridad() == 3) {
		tail->prev->next = nodoAgregar;
		nodoAgregar->prev = tail->prev;
		nodoAgregar->next = tail;
		tail->prev = nodoAgregar;
	}
	else {
		Nodo* nodoActual = header;

		if (nodoAgregar->tarea.getPrioridad() == 1) {
			while (nodoActual->next != tail && nodoActual->next->tarea.getPrioridad() == 1) {
				nodoActual = nodoActual->next;
			}
		}
		else if (nodoAgregar->tarea.getPrioridad() == 2) {
			while (nodoActual->next != tail && nodoActual->next->tarea.getPrioridad() <= 2) {
				nodoActual = nodoActual->next;
			}
		}
		
		nodoAgregar->next = nodoActual->next;
		nodoAgregar->prev = nodoActual;
		nodoActual->next->prev = nodoAgregar;
		nodoActual->next = nodoAgregar;
	}
}

void ListaTareas::eliminarTarea(string nombre) {
	if (header->next == tail) {
		cout << "La lista está vacía, no se puede eliminar nada" << endl;
		return;
	}

	Nodo* nodoActual = header->next;
	bool encontrado = false;

	while (nodoActual != tail) {
		if (nodoActual->tarea.getNombre() == nombre) {
			encontrado = true;
			break;
		}
		nodoActual = nodoActual->next;
	}

	if (encontrado) {
		nodoActual->prev->next = nodoActual->next;
		nodoActual->next->prev = nodoActual->prev;
		delete nodoActual;
	}
	else {
		cout << "No se encontró ninguna coincidencia. Ningún elemento fue borrado" << endl;
	}
}

void ListaTareas::buscarTarea(string nombre) {
	if (header->next == tail) {
		cout << "La lista está vacía" << endl;
		return;
	}

	Nodo* nodoActual = header->next;

	while (nodoActual != tail) {
		if (nodoActual->tarea.getNombre() == nombre) {
			nodoActual->tarea.mostrarDetallesTarea();
			return;
		}
	}

	cout << "No se encontró ninguna coincidencia" << endl;
}

void ListaTareas::mostrarTareas() {
	if (header->next == tail) {
		cout << "La lista está vacía" << endl;
		return;
	}

	Nodo* nodoActual = header->next;

	while (nodoActual != tail) {
		nodoActual->tarea.mostrarDetallesTarea();
		cout << endl;
		nodoActual = nodoActual->next;
	}
}

void ListaTareas::mostrarTareasInversamente() {
	if (header->next == tail) {
		cout << "La lista está vacía" << endl;
		return;
	}

	Nodo* nodoActual = tail->prev;

	while (nodoActual != header) {
		nodoActual->tarea.mostrarDetallesTarea();
		cout << endl;
		nodoActual = nodoActual->prev;
	}
}

Nodo* ListaTareas::getHeader() { return header; }

Nodo* ListaTareas::getTail() { return tail; }

ListaTareas::~ListaTareas() {
	while (header != nullptr) {
		Nodo* nodoEliminar = header;
		header = header->next;
		delete nodoEliminar;
	}
}