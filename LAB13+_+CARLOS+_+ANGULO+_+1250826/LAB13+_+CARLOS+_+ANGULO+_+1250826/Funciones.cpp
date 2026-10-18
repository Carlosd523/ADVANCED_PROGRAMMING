#include "Funciones.h"
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

// Función 02 - Limpia la pantalla.
void limpiarPantalla() {
	cout << "Presione Enter para continuar...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	system("cls");
}

// Función 03 - Validación decimales
double validacionDouble(double& numero, double min, double max) {
	bool valido = false;
	do {
		try {
			cin >> numero;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error: Ingrese un número válido (decimal permitido)");
			}
			else if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido");
			}
			valido = true;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
			valido = false;
		}
	} while (!valido);
	return numero;
}

// Función 04 - Pasar un string a mayúsculas
void aMayusculas(string& s) {
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(static_cast<unsigned char>(s[i]));
	}
}

// Función 05 - Validación de que un string no quede vacío
void validacionString(string& texto) {
	getline(cin, texto);
	while (texto.empty()) {
		cout << "El campo no puede quedar vacio, intente nuevamente: ";
		getline(cin, texto);
	}
}