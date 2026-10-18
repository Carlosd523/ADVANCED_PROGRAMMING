#pragma once
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Pelicula.h"
#include "Nodo.h"
#include <vector>

using namespace std;

template <typename T>
class Lista
{
private:
	Nodo<T>* header = nullptr;

public:
	/*Tuve que hacer un solo archivo para lista.
	No h y cpp para lista, porque, como tengo templates no me dejaba compilar cuando separaba 
	las implementaciones de las declaraciones*/ 

	// Validación de nombres
	bool existe(const string& clave) {
		Nodo<T>* nodoActual = header;
		while (nodoActual != nullptr) {
			if (nodoActual->dato.getClave() == clave) { return true; }
			nodoActual = nodoActual->next;
		}
		return false;
	}

	// Convertir a un arreglo la lista
	vector<Nodo<T>*> convertirVector() {
		vector<Nodo<T>*> nodos;
		for (Nodo<T>* p = header; p != nullptr; p = p->next) {
			nodos.push_back(p);
		}
		return nodos;
	}

	// Rehace la lista
	void reconstruirLista(const vector<Nodo<T>*>& nodos) {
		if (nodos.empty()) { return; }
		header = nodos[0];
		for (size_t i = 0; i + 1 < nodos.size(); i++)
			nodos[i]->next = nodos[i + 1];
		nodos.back()->next = nullptr;
	}

	// Función recursiva para quicksort
	void quickSort(vector<Nodo<T>*>& nodos, int inicio, int final) {
		if (final <= inicio) { return; }

		int indicePivote = particion(nodos, inicio, final);
		quickSort(nodos, inicio, indicePivote - 1);
		quickSort(nodos, indicePivote + 1, final);
	}

	// Devolverá la ubicación del pivote
	int particion(vector<Nodo<T>*>& nodos, int inicio, int final) {
		string valorPivote = nodos[final]->dato.getGenero();
		int i = inicio - 1;

		for (int j = inicio; j < final; j++) {
			if (nodos[j]->dato.getGenero() < valorPivote) {
				i++;
				Nodo<T>* temporal = nodos[i];
				nodos[i] = nodos[j];
				nodos[j] = temporal;
			}
		}
		i++;
		Nodo<T>* temporal = nodos[i];
		nodos[i] = nodos[final];
		nodos[final] = temporal;

		return i;
	}

	// Agregar elemento a la lista
	T* agregarElemento(const T& elemento) {
		Nodo<T>* nodoAgregar = new Nodo<T>(elemento);

		if (header == nullptr) {
			header = nodoAgregar;
			return &nodoAgregar->dato;
		}

		Nodo<T>* nodoActual = header;
		while (nodoActual->next != nullptr) {
			nodoActual = nodoActual->next;
		}
		nodoActual->next = nodoAgregar;
		return &nodoAgregar->dato;
	}

	// Eleminar elemento de la lista
	void eliminarElemento(const string& clave) {
		if (header == nullptr) {
			cout << "No hay elementos disponibles" << endl;
			return;
		}

		bool encontrado = false;
		Nodo<T>* nodoActual = header;
		Nodo<T>* anterior = nullptr;

		while (nodoActual != nullptr) {
			if (nodoActual->dato.getClave() == clave) {
				encontrado = true;
				break;
			}
			anterior = nodoActual;
			nodoActual = nodoActual->next;
		}

		if (encontrado) {
			if (anterior == nullptr) {
				header = nodoActual->next;
			}
			else {
				anterior->next = nodoActual->next;
			}
			delete nodoActual;
			cout << "Elemento borrado exitosamente" << endl;
		}
		else {
			cout << "No se ha encontrado ninguna coincidencia" << endl;
		}
	}

	// Mostrar elementos
	void mostrarElementos() {
		if (header == nullptr) {
			cout << "No hay elementos en la lista" << endl;
			return;
		}

		Nodo<T>* nodoActual = header;

		while (nodoActual != nullptr) {
			nodoActual->dato;
			nodoActual->dato.mostrarDetalles();
			cout << endl;
			nodoActual = nodoActual->next;
		}
	}

	// Ordenación por título (Bubble Sort)
	void ordenarPorTitulo() {
		if (header == nullptr) {
			cout << "La lista está vacía" << endl;
			return;
		}

		bool huboCambios;
		Nodo<T>* limite = nullptr;

		do {
			huboCambios = false;
			Nodo<T>* anterior = nullptr;
			Nodo<T>* nodoActual = header;
			while (nodoActual->next != limite) {
				Nodo<T>* siguiente = nodoActual->next;

				if (nodoActual->dato.getClave() > siguiente->dato.getClave()) {
					nodoActual->next = siguiente->next;
					siguiente->next = nodoActual;

					if (anterior == nullptr) {
						header = siguiente;
					}
					else {
						anterior->next = siguiente;
					}
					anterior = siguiente;
					huboCambios = true;
				}
				else {
					anterior = nodoActual;
					nodoActual = nodoActual->next;
				}
			}
			limite = nodoActual;
		} while (huboCambios);
	}

	// Ordenación por género (Quick Sort)
	void ordenarPorGenero() {
		vector<Nodo<T>*> nodos = convertirVector();
		int n = nodos.size();
		if (n < 2) { return; }

		quickSort(nodos, 0, nodos.size() - 1);
		reconstruirLista(nodos);
	}

	// Ordenación por precio de alquiler (Shell Sort)
	void ordenarPorPrecioAlquiler() {
		if (header == nullptr) {
			cout << "No hay elementos en la lista" << endl;
			return;
		}

		vector<Nodo<T>*> nodos = convertirVector();
		int n = nodos.size();

		if (n == 1) {
			cout << "Solamente hay un elemento en la lista" << endl;
			return;
		}

		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; i++) {
				Nodo<T>* p = nodos[i];
				int j = i;

				while (j >= gap && nodos[j - gap]->dato.getPrecioAlquiler() > p->dato.getPrecioAlquiler()) {
					nodos[j] = nodos[j - gap];
					j -= gap;
				}

				nodos[j] = p;
			}
		}

		reconstruirLista(nodos);
	}

	// Ordenación por año de estreno
	void ordenarPorAnyoEstreno() {
		if (header == nullptr) {
			cout << "La lista está vacía" << endl;
			return;
		}

		vector<Nodo<T>*> nodos = convertirVector();

		int n = nodos.size();
		if (n == 1) {
			cout << "La lista contiene solamente un elemento" << endl;
			return;
		}

		for (int i = 0; i < n - 1; i++) {
			int indiceMin = i;

			for (int j = i + 1; j < n; j++) {
				if (nodos[j]->dato.getAnyoEstreno() < nodos[indiceMin]->dato.getAnyoEstreno()) {
					indiceMin = j;
				}
			}

			if (indiceMin != i) {
				Nodo<T>* temporal = nodos[i];
				nodos[i] = nodos[indiceMin];
				nodos[indiceMin] = temporal;
			}
		}

		reconstruirLista(nodos);
	}

	// Método get
	Nodo<T>* getHeader() { return header; }

	// Retornar elemento
	T* getElemento(const string& clave) {
		Nodo<T>* nodoActual = header;
		while (nodoActual != nullptr) {
			if (nodoActual->dato.getClave() == clave) { return &nodoActual->dato; }
			nodoActual = nodoActual->next;
		}

		return nullptr;
	}

	// Destructor
	~Lista() {}
};

#endif