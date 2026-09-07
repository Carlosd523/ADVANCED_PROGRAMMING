#include "Funciones.h"
#include <iostream>

using namespace std;

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

// Función 03 - Calcular la potencia recursivamente
int calcularPotencia(int base, int potencia) {
	if (potencia == 0) { return 1; }
	return base * calcularPotencia(base, potencia - 1);
}

// Función 04 - Contar los dígitos de un número
int contarDigitos(int n) {
	if (n == 0) { return 0; }
	return 1 + contarDigitos(n / 10);
}

// Función 05 - Invertir un número
int invertirNumero(int n, int invertido) {
	if (n == 0) { return invertido; }
	return invertirNumero(n / 10, (invertido * 10) + (n % 10));
}

// Función 06 - Sumar los dígitos de un número
int sumarDigitos(int n) {
	if (n == 0) { return 0; }
	return (n % 10) + sumarDigitos(n / 10);
}

// Función 07 - Obtener el dígito mayor
int digitoMayor(int n) {
	if (n == 0) { return 0; }

	int ultimo = n % 10;

	int mayorDelResto = digitoMayor(n / 10);

	if (ultimo > mayorDelResto) { return ultimo; }
	else { return mayorDelResto; }
}

// Función 08 - Opción 1 del menú
void menu1() {
	// Declaración variables
	int base, exponente;

	// Procesos de la función
	cout << "=============== CALCULAR LA POTENCIA ===============" << endl;
	cout << "Ingrese la base de la potencia: ";
	validacionInt(base, 0, 100000);
	cout << "Ingrese el exponente de la potencia: ";
	validacionInt(exponente, 0, 100000);
	cout << calcularPotencia(base, exponente) << endl;
	limpiarPantalla();
}

// Función 09 - Opción 2 del menú
void menu2() {
	// Declaración variables
	int n;

	// Procesos de la función
	cout << "=============== CONTEO DE DÍGITOS ===============" << endl;
	cout << "Ingrese el número que desea evaluar: ";
	validacionInt(n, 0, 100000);
	cout << contarDigitos(n) << endl;
	limpiarPantalla();
}

// Función 10 - Opción 3 del menú
void menu3() {
	// Declaración variables
	int n;

	// Procesos de la función
	cout << "=============== INVERTIR UN NÚMERO ===============" << endl;
	cout << "Ingrese el número que desea invertir: ";
	validacionInt(n, 0, 100000);
	cout << invertirNumero(n, 0) << endl;
	limpiarPantalla();
}

// Función 11 - Opción 4 del menú
void menu4() {
	// Declaración de variables
	int n;

	// Procesos de la función
	cout << "=============== SUMATORIA DE DÍGITOS ===============" << endl;
	cout << "Ingrese el número que desea evaluar: ";
	validacionInt(n, 0, 100000);
	cout << sumarDigitos(n) << endl;
	limpiarPantalla();
}

// Función 12 - Opción 5 del menú
void menu5() {
	// Declaración de variables
	int n;

	// Procesos de la función
	cout << "=============== DIGITO MAYOR ===============" << endl;
	cout << "Ingrese el número que desea evaluar: ";
	validacionInt(n, 0, 100000);
	cout << digitoMayor(n) << endl;
	limpiarPantalla();
}