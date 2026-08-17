#include "Excepciones.h"
#include "Comic.h"
#include <iostream>
#include <cctype>

// Función 01 - Valida la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max) {
	bool validacion = false;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw DatoInvalido();
			}
			else if (num < min || num > max) {
				throw DatoFueraDelRango(num, min, max);
			}
			else {
				validacion = true;
			}
		}
		catch (DatoInvalido& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
		catch (DatoFueraDelRango& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
	} while (!validacion);
}

// Función 02 - Valida la entrada de un dato tipo double.
void validacionDouble(double& num, double min, double max) {
	bool validacion = false;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw DatoInvalido();
			}
			else if (num < min || num > max) {
				throw DatoFueraDelRango(num, min, max);
			}
			else {
				validacion = true;
			}
		}
		catch (DatoInvalido& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
		catch (DatoFueraDelRango& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
	} while (!validacion);
}

// Función 03 - Limpia la pantalla.
void limpiarPantalla() {
	cout << "Presione Enter para continuar...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	system("cls");
}

// Función 04 - Recibe como parámetro un puntero. En caso de que el puntero sea nulo permite registrar un cómic.
bool intentarRegistrar(Comic*& p, Comic* nuevoComic) {
	if (p == nullptr) {
		p = nuevoComic;
		return true;
	}
	else {
		return false;
	}
}

// Función 05 - Recibe como parámetro un puntero para indicar si contiene un valor nulo
bool punteroVacio(Comic* p) {
	if (p == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// Función 06 - Búsqueda por título
void revisarTitulo(Comic* p, const string& busqueda, int& coincidencias) {
	if (p != nullptr && p->getTitulo() == busqueda) {
		p->mostrarInformacion();
		coincidencias++;
	}
}

// Función 07 - Búsqueda por Código de Barras
void revisarCodigoBarras(Comic* p, const string& busqueda, int& coincidencias) {
	if (p != nullptr && p->getCodigoBarras() == busqueda) {
		p->mostrarInformacion();
		coincidencias++;
	}
}

// Función 08 - Búsqueda por Editorial
void revisarEditorial(Comic* p, const string& busqueda, int& coincidencias) {
	if (p != nullptr && p->getEditorial() == busqueda) {
		p->mostrarInformacion();
		coincidencias++;
	}
}

// Función 09 - Búsqueda por Número de Edición (Issue)
void revisarIssue(Comic* p, int busqueda, int& coincidencias) {
	if (p != nullptr && p->getNumeroEdicion() == busqueda) {
		p->mostrarInformacion();
		coincidencias++;
	}
}

// Función 10 - Eliminar por Título
void eliminarPorTitulo(Comic*& p, const string& busqueda, bool& eliminado) {
	if (p != nullptr && p->getTitulo() == busqueda) {
		delete p;
		p = nullptr;
		eliminado = true;
		cout << "¡Comic eliminado exitosamente!" << endl;
	}
}

// Función 11 - Eliminar por Código de Barras
void eliminarPorCodigoBarras(Comic*& p, const string& busqueda, bool& eliminado) {
	if (p != nullptr && p->getCodigoBarras() == busqueda) {
		delete p;
		p = nullptr;
		eliminado = true;
		cout << "¡Comic eliminado exitosamente!" << endl;
	}
}

// Función 12 - Eliminar por Editorial
void eliminarPorEditorial(Comic*& p, const string& busqueda, bool& eliminado) {
	if (p != nullptr && p->getEditorial() == busqueda) {
		delete p;
		p = nullptr;
		eliminado = true;
		cout << "¡Comic eliminado exitosamente!" << endl;
	}
}

// Función 13 - Eliminar por Número de Edición (Issue)
void eliminarPorIssue(Comic*& p, int busqueda, bool& eliminado) {
	if (p != nullptr && p->getNumeroEdicion() == busqueda) {
		delete p;
		p = nullptr;
		eliminado = true;
		cout << "¡Comic eliminado exitosamente!" << endl;
	}
}

// Fúnción 14 - Indica si hay coincidencia entre códigos de barras
bool coincidenciaCodigoBarras(Comic* p, string codigoBarras) {
	if (p != nullptr && codigoBarras == p->getCodigoBarras()) {
		cout << "Coincidencia con otro código de barras. No pueden haber dos códigos de barras iguales"
			<< "\nIntente nuevamente." << endl;
		return true;
	}
	else {
		return false;
	}
}

// Función 15 - Lee si un string posee solo dígitos
bool esSoloNumeros(const string& str) {
	if (str.empty()) return false;

	for (int i = 0; i < 12; i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

// Función 16 - Valida el código de barras
void validacionCodigoBarras(string& codigoBarras) {
	bool terminar = false;
	while (!terminar) {
		cin >> codigoBarras;

		if (codigoBarras.length() != 12) {
			cout << "Error: Debe tener exactamente 12 dígitos (ingresó " << codigoBarras.length() << "). Intente nuevamente: ";
			continue;
		}
		else if (!esSoloNumeros(codigoBarras)) {
			cout << "Error: Solo se permiten números (no letras ni símbolos). Intente nuevamente: ";
		}
		else {
			terminar = true;
		}
	}
}