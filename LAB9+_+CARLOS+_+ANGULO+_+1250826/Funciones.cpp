#include "Funciones.h"
#include <cctype>

// Función Recursiva #1 - Determina la resistencia equivalente de un circuito
double resistenciaEquivalente(double resistenciaSerie, double resistenciaParalela, int n) {
	if (n == 1) { return resistenciaSerie + resistenciaParalela; }

	double resEq = 0;
	resEq = resistenciaEquivalente(resistenciaSerie, resistenciaParalela, n - 1);
	cout << "Resistencia equivalente en escalón " << n - 1 << ": " << resEq << endl;

	return resistenciaSerie + ((resistenciaParalela * resEq) / (resistenciaParalela + resEq));
}

// Función Recursiva #2 - Retorna una palabra invertida
string retornarPalabraInvertida(const string& palabra, int n) {
	if (n == 0) { return ""; }

	return palabra[n - 1] + retornarPalabraInvertida(palabra, n - 1);
}

// Función #1 - Muestra el menú interactivo
void menu() {
	// Arreglo de punteros a funciones
	void (*menu[2])() = {
		opcionResistencia,
		opcionPalindroma
	};

	// Menú interactivo
	int optMenu = 0;
	do {
		cout << "=============== FUNCIONES RECURSIVAS ==============="
			<< "\n1. Calcular la resistencia en serie"
			<< "\n2. Determinar si una palabra es palíndroma"
			<< "\n3. Salir" << endl;
		validacionEntero(optMenu, 1, 3);
		LimpiarPantalla();

		if (optMenu != 3) {
			(*menu[optMenu - 1])();
		}
	} while (optMenu != 3);
}

// Opción del menú #1 - Pide los valores de entrada para determinar la resistencia equivalente
void opcionResistencia() {
	// Declaración de variables
	double resistenciaSerie, resistenciaParalela;
	int escalones;

	// El usuario ingresa los datos de entrada
	cout << "=============== RESISTENCIA ===============" << endl;
	cout << "Ingrese la resistencia en serie: ";
	validacionDouble(resistenciaSerie, 0, 1000);
	cout << "Ingrese la resistencia paralela: ";
	validacionDouble(resistenciaParalela, 0, 1000);
	cout << "Ingrese el número de escalones: ";
	validacionEntero(escalones, 1, 100);

	// El programa muestra la resistencia equivalente
	cout << "La resistencia equivalente es: " << resistenciaEquivalente(resistenciaSerie, resistenciaParalela, escalones) << " ohmios" << endl;

	LimpiarPantalla();
}

// Opción del menú #2 - Pide una palabra para evaluar si es palíndroma o no
void opcionPalindroma() {
	// Declaración de variables
	string palabra;
	bool avanzar = false;

	// El programa valida la entrada de la palabra
	while (!avanzar) {
		cout << "Ingrese la palabra que desea evaluar: ";
		cin >> palabra;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Valida que la palabra ingresada no sea únicamente un carácter
		if (palabra.length() == 1) {
			cout << "La palabra ingresada solo contiene un carácter, debe de contener al menos dos" << endl;
		}
		else {
			avanzar = true;
		}

		// Valida que la palabra no contenga dígitos
		for (int i = 0; i < palabra.length(); i++) {
			if (isdigit(static_cast<unsigned char>(palabra[i]))) {
				cout << "La palabra no puede contener números" << endl;
				avanzar = false;
				break;
			}
		}
	}

	// Convierte toda la palabra en minúsculas
	for (int i = 0; i < palabra.length(); i++) {
		palabra[i] = tolower(palabra[i]);
	}

	// El programa determina si la palabra es palíndroma o no
	if (palabra == retornarPalabraInvertida(palabra, palabra.length())) {
		cout << "La palabra ingresada es palíndroma" << endl;
	}
	else {
		cout << "La palabra ingresada no es palíndroma" << endl;
	}

	LimpiarPantalla();
}

// Función de validación #1 - Valida un tipo de dato int
int validacionEntero(int& numero, int min, int max) {
	bool valido = false;
	do {
		try {
			cin >> numero;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error: Ingrese un número válido");
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido");
			}
			valido = true;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
	} while (!valido);
	return numero;
}

// Función de validación #2 - Valida un tipo de datos double
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido");
			}
			valido = true;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
	} while (!valido);
	return numero;
}

// Función de estética #1 - Limpia la pantalla de la consola
void LimpiarPantalla() {
	cout << "Presione Enter para continuar...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	system("cls");
}