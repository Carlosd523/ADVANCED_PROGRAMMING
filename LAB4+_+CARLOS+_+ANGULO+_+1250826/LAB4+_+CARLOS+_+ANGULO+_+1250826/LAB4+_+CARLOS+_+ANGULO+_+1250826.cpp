// LAB4+_+CARLOS+_+ANGULO+_+1250826.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Mascota.h"
#include "Gasto.h"
#include "Dueno.h"
#include <limits>
#include <stdexcept>

using namespace std;

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

double validacionDouble(double& numero, double min, double max) {
	bool valido = false;
	do {
		try {
			cin >> numero;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error: Ingrese un número válido");
			}
			else if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido (1 - 1000)");
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

int main()
{
	Gasto gastos[100];
	Dueno duenos[10];
	int contDuenos = 0, contGastos = 0, optMenu, optMascota, optDueno;
	string nombre, ID, descripcion;
	double ingresos = 0;
	do {
		cout << "2 de agosto del 2026" << endl;
		cout << "=============== BIENVENIDO A LA VETERINARIA ANGULO ==============="
			<< "\n1. Registrar dueño"
			<< "\n2. Registrar mascota"
			<< "\n3. Registrar gasto"
			<< "\n4. Calcular total gastado"
			<< "\n5. Mostrar historial de gastos de un dueño"
			<< "\n6. Finalizar día" << endl;
		validacionEntero(optMenu, 1, 6);
		switch (optMenu) {
		case 1: {
			if (contDuenos == 10) {
				cout << "El límite de dueños registrables hoy ha llegado a su límite" << endl;
				break;
			}
			cout << "=============== REGISTRAR DUEÑO ===============" << endl;
			cout << "Ingrese el nombre del dueño: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, nombre);
			cout << "Ingrese el ID del dueño: ";
			cin >> ID;

			duenos[contDuenos].registrarDueno(nombre, ID);
			contDuenos++;
			cout << "Dueño registrado exitosamente" << endl;
			break;
		}

		case 2: {
			if (contDuenos == 0) {
				cout << "Aún no hay dueños registrados" << endl;
				break;
			}

			cout << "=============== REGISTRAR MASCOTA ===============" << endl;
			cout << "¿A qué dueño desea asignarle una mascota?" << endl;

			for (int i = 0; i < contDuenos; i++) {
				cout << i + 1 << ". " << duenos[i].getNombre() << endl;
			}

			validacionEntero(optDueno, 1, contDuenos);

			if (duenos[optDueno - 1].contadorMascotas >= 10) {
				cout << "Este dueño ya tiene el máximo de mascotas registradas" << endl;
				break;
			}

			cout << "Decida qué tipo de mascota agregar"
				<< "\n1. Perro"
				<< "\n2. Gato" << endl;

			validacionEntero(optMascota, 1, 2);

			cout << "Ingrese el nombre de su mascota: ";
			cin >> nombre;

			int posicionMascota = duenos[optDueno - 1].contadorMascotas;

			duenos[optDueno - 1].mascotas[posicionMascota].registrarMascota(nombre, optMascota);
			duenos[optDueno - 1].mascotas[posicionMascota].funcionExtra();
			duenos[optDueno - 1].contadorMascotas++;

			cout << "Mascota registrada exitosamente" << endl;
			break;
		}

		case 3: {
			if (contDuenos == 0) {
				cout << "Aún no hay dueños registrados" << endl;
				break;
			}

			if (contGastos >= 100) {
				cout << "Se alcanzó el límite de gastos registrados" << endl;
				break;
			}

			cout << "=============== REGISTRAR GASTO ===============" << endl;
			cout << "¿A qué dueño desea registrarle un gasto?" << endl;

			for (int i = 0; i < contDuenos; i++) {
				cout << i + 1 << ". " << duenos[i].getNombre() << endl;
			}

			validacionEntero(optDueno, 1, contDuenos);

			if (duenos[optDueno - 1].getContadorMascotas() == 0) {
				cout << "Este dueño aún no tiene mascotas registradas" << endl;
				break;
			}

			cout << "¿A qué mascota del dueño "
				<< duenos[optDueno - 1].getNombre()
				<< " desea asignarle el gasto?" << endl;

			for (int i = 0;
				i < duenos[optDueno - 1].getContadorMascotas();
				i++) {

				cout << i + 1 << ". "
					<< duenos[optDueno - 1].mascotas[i].getNombre()
					<< endl;
			}

			validacionEntero(
				optMascota,
				1,
				duenos[optDueno - 1].getContadorMascotas()
			);

			double costoUnidad = 0;
			int unidades = 0;

			cout << "Ingrese el costo por unidad: ";
			validacionDouble(costoUnidad, 1, 1000);

			cout << "Ingrese las unidades: ";
			validacionEntero(unidades, 1, 10);

			cout << "Ingrese la descripción del gasto: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, descripcion);

			gastos[contGastos].registrarGasto(duenos[optDueno - 1].mascotas[optMascota - 1], duenos[optDueno - 1], "02/08/2026", costoUnidad, unidades, descripcion);

			duenos[optDueno - 1].mascotas[optMascota - 1].gastoMascota += costoUnidad * unidades;
			ingresos += costoUnidad * unidades;
			contGastos++;

			cout << "Gasto registrado exitosamente" << endl;
			break;
		}

		case 4: {
			if (contDuenos == 0) {
				cout << "Aún no hay dueños registrados" << endl;
				break;
			}

			cout << "¿A qué dueño desea calcularle sus gastos?" << endl;

			for (int i = 0; i < contDuenos; i++) {
				cout << i + 1 << ". " << duenos[i].getNombre() << endl;
			}

			validacionEntero(optDueno, 1, contDuenos);

			if (duenos[optDueno - 1].getContadorMascotas() == 0) {
				cout << "Este dueño aún no tiene mascotas registradas" << endl;
				break;
			}

			cout << "A qué mascota del dueño " << duenos[optDueno - 1].getNombre() << " desea calcularle sus gastos" << endl;
			int contador = 1;
			for (int i = 0; i < duenos[optDueno - 1].getContadorMascotas(); i++) {
				cout << contador << ". " << duenos[optDueno - 1].mascotas[i].getNombre() << endl;
				contador++;
			}
			validacionEntero(optMascota, 1, contador - 1);

			cout << "El gasto por la mascota " << duenos[optDueno - 1].mascotas[optMascota - 1].getNombre() << " del dueño " << duenos[optDueno - 1].getNombre() << " es de: " << duenos[optDueno - 1].mascotas[optMascota - 1].gastoTotalMascota() << endl;
			break;
		}

		case 5: {
			if (contDuenos == 0) {
				cout << "Aún no hay dueños registrados" << endl;
				break;
			}
			cout << "=============== HISTORIAL DE GASTOS ===============" << endl;
			cout << "¿De qué dueño desea mostrar los gastos" << endl;
			for (int i = 0; i < contDuenos; i++) {
				cout << i + 1 << ". " << duenos[i].getNombre() << endl;
			}
			validacionEntero(optDueno, 1, contDuenos);

			cout << "Historial de gastos de: " << duenos[optDueno - 1].getNombre() << endl;
			bool tieneGastos = false;
			for (int i = 0; i < contGastos; i++) {
				if (gastos[i].getDueno().getNombre() == duenos[optDueno - 1].getNombre()) {
					gastos[i].detallesGasto();
					tieneGastos = true;
				}
			}

			if (!tieneGastos) {
				cout << "Este dueño aún no tiene gastos" << endl;
			}

			break;
		}
		}
	} while (optMenu != 6);
	cout << "Día finalizado" << endl;
	cout << "Total de ingresos generados hoy: " << ingresos * 1.12 << endl;
}