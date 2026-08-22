#include "Funciones.h"

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

// Función 04 - Asignar nuevos empleados
void asignarEmpleado(Empleado* nuevoEmpleado, Empleado**& empleados, int& capacidad, int& cantidad) {
	if (cantidad == capacidad) {
		capacidad *= 2;
		Empleado** nuevoArreglo = new Empleado * [capacidad];

		for (int i = 0; i < capacidad; i++) {
			nuevoArreglo[i] = nullptr;
		}

		for (int i = 0; i < (capacidad / 2); i++) {
			nuevoArreglo[i] = empleados[i];
		}

		delete[] empleados;
		empleados = nuevoArreglo;
	}

	empleados[cantidad] = nuevoEmpleado;
	cantidad++;
}

// Función 05 - Eliminar espacios vacíos entre espacios ocupados
void eliminarVacios(Empleado**& empleados, int cantidad) {
	for (int i = 0; i < cantidad - 1; i++) {
		if (empleados[i] == nullptr && empleados[i + 1] != nullptr) {
			empleados[i] = empleados[i + 1];
			empleados[i + 1] = nullptr;
		}
	}
}

// Función 06 - Aumentar salario en un 10%
void aumentarSalario(Empleado* empleado) {
	empleado->setSalario((empleado->getSalario() * 1.10));
}

// Función 07 - Disminuir salario en un 10%
void disminuirSalario(Empleado* empleado) {
	empleado->setSalario((empleado->getSalario() * 0.90));
}

// Función 08 - Cambiar el salario de un empleado
void cambiarSalario(Empleado* empleado) {
	double salario;
	cout << "Ingrese el nuevo salario del empleado(5000 - 50000): ";
	validacionDouble(salario, 5000, 50000);
	empleado->setSalario(salario);
}

// Función 09 - Ordenar empleados por salario en orden ascendente
void salarioAscendente(Empleado**& empleados, int capacidad, int cantidad) {
	Empleado* auxiliar = nullptr;

	for (int i = 0; i < cantidad - 1; i++) {
		for (int j = 0; j < cantidad - i - 1; j++) {
			if (empleados[j]->getSalario() < empleados[j + 1]->getSalario()) {
				auxiliar = empleados[j];
				empleados[j] = empleados[j + 1];
				empleados[j + 1] = auxiliar;
			}
		}
	}
}

// Función 10 - Ordenar empleados por salario descendente
void salarioDescendente(Empleado**& empleados, int capacidad, int cantidad) {
	Empleado* auxiliar = nullptr;

	for (int i = 0; i < cantidad - 1; i++) {
		for (int j = 0; j < cantidad - i - 1; j++) {
			if (empleados[j]->getSalario() > empleados[j + 1]->getSalario()) {
				auxiliar = empleados[j];
				empleados[j] = empleados[j + 1];
				empleados[j + 1] = auxiliar;
			}
		}
	}
}

// Función 11 - Ordenar empleados alfabéticamente
void ordenAlfabetico(Empleado**& empleados, int capacidad, int cantidad) {
	Empleado* auxiliar = nullptr;

	for (int i = 0; i < cantidad - 1; i++) {
		for (int j = 0; j < cantidad - i - 1; j++) {
			if (empleados[j]->getNombre() > empleados[j + 1]->getNombre()) {
				auxiliar = empleados[j];
				empleados[j] = empleados[j + 1];
				empleados[j + 1] = auxiliar;
			}
		}
	}
}

// Función 12 - Mostrar empleados
void mostrarEmpleados(Empleado** empleados, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		empleados[i]->mostrarInfo();
	}
}

// Función 13 - Calcular salario total
void calcularSalarioTotal(Empleado** empleados, int cantidad) {
	double salarioTotal = 0;
	for (int i = 0; i < cantidad; i++) {
		salarioTotal += empleados[i]->calcularSalarioTotal();
	}
	cout << "El salario total es: " << salarioTotal << endl;
}

//´Función 14 - Contar empleados por tipo
void contarTipoEmpleados(Empleado** empleados, int cantidad) {
	int empleadosAdministrativos = 0, empleadosTecnicos = 0, empleadosDeVentas = 0;
	for (int i = 0; i < cantidad; i++) {
		if (empleados[i]->getTipo() == "Adminsitrativo") { empleadosAdministrativos++; }
		else if (empleados[i]->getTipo() == "Técnico") { empleadosTecnicos++; }
		else if (empleados[i]->getTipo() == "Ventas") { empleadosDeVentas++; }
	}

	cout << "Hay " << empleadosAdministrativos << " empleados adminsitrativos."
		<< "\nHay " << empleadosTecnicos << " empleados técnicos."
		<< "\nHay " << empleadosDeVentas << " empleados de ventas." << endl;
}

// Función 15 - Mostrar información por salario
void mostrarInfoSalario(Empleado** empleados, int cantidad) {
	double salario;
	cout << "Ingrese el salario por el que desea filtrar a los empleados: ";
	cout << endl;
	validacionDouble(salario, 0, 100000);

	bool coincidencias = false;
	for (int i = 0; i < cantidad; i++) {
		if (empleados[i]->calcularSalarioTotal() >= salario) {
			empleados[i]->mostrarInfo();
			cout << endl;
			coincidencias = true;
		}
	}

	if (!coincidencias) {
		cout << "No se encontrar empleados con un salario igual o mayor al seleccionado" << endl;
	}
}