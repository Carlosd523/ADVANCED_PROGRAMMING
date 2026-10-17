#include "RelojActividades.h"
#include <iostream>

void RelojActividades::agregarActividad(Actividad actividad) {
	NodoCircular* nodoAgregar = new NodoCircular();
	nodoAgregar->actividad = actividad;

	if (entrada == nullptr) {
		entrada = nodoAgregar;
		nodoAgregar->next = nodoAgregar;
		nodoAgregar->prev = nodoAgregar;
		actual = nodoAgregar;
	}
	else {
		NodoCircular* nodoActual = entrada;
		bool nuevaEntrada = false;

		if (actividad.getHora() < entrada->actividad.getHora()) {
			nodoActual = entrada->prev;
			nuevaEntrada = true;
		}

		while (nodoActual->next != entrada && nodoActual->next->actividad.getHora() <= actividad.getHora()) {
			nodoActual = nodoActual->next;
		}

		nodoAgregar->next = nodoActual->next;
		nodoAgregar->prev = nodoActual;
		nodoActual->next->prev = nodoAgregar;
		nodoActual->next = nodoAgregar;

		if (nuevaEntrada) { entrada = nodoAgregar; }
	}	
}

void RelojActividades::eliminarActividad(int hora) {
	if (entrada == nullptr) {
		cout << "La lista está vacía" << endl;
		return;
	}

	if (entrada->actividad.getHora() == hora && entrada->next == entrada) {
		delete entrada;
		entrada = nullptr;
		actual = nullptr;
		cout << "Ya no hay actividades programadas" << endl;
		return;
	}

	NodoCircular* nodoActual = entrada;

	do {
		if (nodoActual->actividad.getHora() == hora) {
			nodoActual->next->prev = nodoActual->prev;
			nodoActual->prev->next = nodoActual->next;
			if (nodoActual == entrada) {
				entrada = entrada->next;
			}
			if (nodoActual == actual) {
				actual = actual->next;
				cout << "La actividad eliminada es la actual, se ha movido automáticamente a la siguiente" << endl;
			}
			delete nodoActual;
			return;
		}
		nodoActual = nodoActual->next;
	} while (nodoActual != entrada);

	cout << "No se encontró ninguna coincidencia" << endl;
}

void RelojActividades::mostrarActividadActual() {
	if (entrada == nullptr) {
		cout << "La lista está vacía" << endl;
		return;
	}
	actual->actividad.mostrarActividad();
}

void RelojActividades::avanzarBloqueHorario() {
	if (entrada == nullptr) {
		cout << "La lista está vacía" << endl;
		return;
	}

	if (entrada->next == entrada) {
		cout << "Solo hay un elemento en la lista" << endl;
		return;
	}

	actual = actual->next;
	cout << "Bloque horario movido exitosamente" << endl;
}

void RelojActividades::retrocederBloqueHorario() {
	if (entrada == nullptr) {
		cout << "La lista está vacía" << endl;
		return;
	}

	if (entrada->prev == entrada) {
		cout << "Solo hay un elemento en la lista" << endl;
		return;
	}

	actual = actual->prev;
	cout << "Bloque horario retrocedido exitosamente" << endl;
}

void RelojActividades::recorrerActividades() {
	if (entrada == nullptr) {
		cout << "La lista está vacía" << endl;
		return;
	}

	NodoCircular* nodoActual = entrada;

	do {
		nodoActual->actividad.mostrarActividad();
		cout << endl;
		nodoActual = nodoActual->next;
	} while (nodoActual != entrada);
}

NodoCircular* RelojActividades::getEntrada() { return entrada; }

RelojActividades::~RelojActividades() {
	if (entrada == nullptr) { return; }

	entrada->prev->next = nullptr;

	while (entrada != nullptr) {
		NodoCircular* nodoEliminar = entrada;
		entrada = entrada->next;
		delete nodoEliminar;
	}

	actual = nullptr;
}