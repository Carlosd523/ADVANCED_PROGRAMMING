#include "List.h"
#include <iostream>
#include "Excepciones.h"

using namespace std;

void List::Add(int item) {
	Node* nuevoNodo = new Node();
	nuevoNodo->data = item;

	if (header == nullptr) {
		header = nuevoNodo;
	}
	else {
		Node* nodoSiguiente = header;
		while (nodoSiguiente->next != nullptr) {
			nodoSiguiente = nodoSiguiente->next;
		}
		nodoSiguiente->next = nuevoNodo;
	}

	cout << "Elemento agregado correcetamente" << endl;
}

void List::Clear() {
	if (header == nullptr) {
		cout << "No hay elementos para borrar" << endl;
	}
	else {
		while (header != nullptr) {
			Node* nodoActual = header;
			header = header->next;
			delete nodoActual;
		}

		cout << "Elementos borrados correctamente" << endl;
	}
}

int List::Count() {
	int contador = 0;
	if (header != nullptr) {
		Node* nodoSiguiente = header;
		while (nodoSiguiente != nullptr) {
			nodoSiguiente = nodoSiguiente->next;
			contador++;
		}
	}
	return contador;
}

bool List::Contains(int item) {
	if (header != nullptr) {
		Node* nodoSiguiente = header;
		while (nodoSiguiente != nullptr) {
			if (nodoSiguiente->data == item) {
				return true;
			}
			nodoSiguiente = nodoSiguiente->next;
		}
	}
	return false;
}

int List::IndexOf(int item) {
	int contador = 0;
	Node* nodoSiguiente = header;
	while (nodoSiguiente != nullptr) {
		if (nodoSiguiente->data == item) {
			return contador;
		}
		contador++;
		nodoSiguiente = nodoSiguiente->next;
	}
	return -1;
}

void List::Insert(int index, int item) {
	Node* nuevoNodo = new Node();
	nuevoNodo->data = item;

	if (header == nullptr) {
		cout << "La lista está vacía, no se puede insertar el elemento en la posición deseada."
			<< "\nEl elemento se insertará en la primera posición." << endl;
		header = nuevoNodo;
		return;
	}

	if (index == 1) {
		nuevoNodo->next = header;
		header = nuevoNodo;
		cout << "Elemento insertado en la primera posición" << endl;
		return;
	}

	Node* nodoSiguiente = header;

	try {
		for (int i = 0; i < index; i++) {
			if (i == index - 1 && nodoSiguiente->next != nullptr) {
				nuevoNodo->next = nodoSiguiente->next;
				nodoSiguiente->next = nuevoNodo;
				cout << "Elemento insertado correctamente" << endl;
				return;
			}
			else if (i == index - 1 && nodoSiguiente->next == nullptr) {
				nuevoNodo->next = nullptr;
				nodoSiguiente->next = nuevoNodo;
				cout << "Elemento insertado correctamente" << endl;
				return;
			}
			if (nodoSiguiente->next == nullptr) {
				throw IndiceInvalido(index);
			}
			nodoSiguiente = nodoSiguiente->next;
		}
	}
	catch (IndiceInvalido& e) {
		cout << e.what() << endl;
	}
}

int List::GetItem(int index) {
	if (header == nullptr) {
		return -1;
	}
	try {
		Node* nodoSiguiente = header;

		for (int i = 0; i < index; i++) {
			if (i == index - 1) {
				return nodoSiguiente->data;
			}

			if (nodoSiguiente->next == nullptr) {
				throw IndiceInvalido(index);
			}
			nodoSiguiente = nodoSiguiente->next;
		}
	}
	catch (IndiceInvalido& e) {
		cout << e.what() << endl;
	}
	return -1;
}

void List::SetItem(int index, int item) {
	if (header == nullptr) {
		cout << "No hay elementos en la lista" << endl;
		return;
	}

	try {
		Node* nodoSiguiente = header;
		for (int i = 0; i < index; i++) {
			if (i == index - 1) {
				nodoSiguiente->data = item;
				cout << "Cambio realizado exitosamente" << endl;
				return;
			}

			if (nodoSiguiente->next == nullptr) {
				throw IndiceInvalido(index);
			}
			nodoSiguiente = nodoSiguiente->next;
		}
	}
	catch (IndiceInvalido& e) {
		cout << e.what() << endl;
	}
}

int List::LastIndexOf(int item) {
	if (header == nullptr) {
		return -1;
	}

	Node* nodoSiguiente = header;
	int indiceFinal = -1, contador = 0;
	while (nodoSiguiente != nullptr) {
		if (nodoSiguiente->data == item) {
			indiceFinal = contador;
		}

		nodoSiguiente = nodoSiguiente->next;
		contador++;
	}

	return indiceFinal;
}

bool List::Remove(int item) {
	if (header == nullptr) {
		return false;
	}

	Node* nodoEliminar = header;

	if (header->data == item) {
		header = header->next;
		delete nodoEliminar;
		return true;
	}

	Node* nodoSiguiente = header;

	while (nodoSiguiente != nullptr) {
		if (nodoSiguiente->next != nullptr && nodoSiguiente->next->data == item) {
			nodoEliminar = nodoSiguiente->next;
			nodoSiguiente->next = nodoSiguiente->next->next;
			delete nodoEliminar;
			return true;
		}

		nodoSiguiente = nodoSiguiente->next;
	}
	return false;
}

void List::RemoveAt(int index) {
	if (header == nullptr) {
		cout << "No hay elemenos para eliminar" << endl;
		return;
	}

	Node* nodoEliminar = header;

	if (index == 1) {
		header = header->next;
		delete nodoEliminar;
		return;
	}

	try {
		Node* nodoSiguiente = header;

		for (int i = 1; i < index; i++) {
			if (i == index - 1 && nodoSiguiente->next != nullptr) {
				nodoEliminar = nodoSiguiente->next;
				nodoSiguiente->next = nodoSiguiente->next->next;
				delete nodoEliminar;
				return;
			}

			if (nodoSiguiente->next == nullptr) {
				throw IndiceInvalido(index);
			}

			nodoSiguiente = nodoSiguiente->next;
		}
	}
	catch (IndiceInvalido& e) {
		cout << e.what() << endl;
	}

	cout << "No se eliminó ningún elemento" << endl;
}

void List::ShowList() {
	if (header == nullptr) {
		cout << "La lista no contiene ningún elemento" << endl;
		return;
	}

	Node* nodoSiguiente = header;

	cout << "La lista contiene los siguientes elementos:" << endl;
	while (nodoSiguiente != nullptr) {
		cout << nodoSiguiente->data << endl;
		nodoSiguiente = nodoSiguiente->next;
	}
}

List::~List() {
	while (header != nullptr) {
		Node* nodoEliminar = header;
		header = header->next;
		delete nodoEliminar;
	}
}