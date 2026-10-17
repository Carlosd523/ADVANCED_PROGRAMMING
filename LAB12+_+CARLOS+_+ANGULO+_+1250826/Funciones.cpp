#include <iostream>
#include "Funciones.h"
#include "Excepciones.h"
#include <limits>

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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

// Menú
void menu() {
	int optMenuP;
	Gestor gestor;

	// Arreglo de punteros a funciones
	void (*menuP[2])(Gestor & gestor) = {
		&menuPilas,
		&ejercicioCola
	};

	do {
		cout << "¿Qué ejercicio desea realizar?"
			<< "\n1. Ejercicio 1"
			<< "\n2. Ejercicio 2"
			<< "\n3. Salir" << endl;
		cout << "Ingrese la opción que desea realizar: ";
		validacionInt(optMenuP, 1, 3);
		limpiarPantalla();
		if (optMenuP != 3) { (*menuP[optMenuP - 1])(gestor); }
		limpiarPantalla();
	} while (optMenuP != 3);
}

// Menú - Ejercicio pilas
void menuPilas(Gestor& gestor) {
	int optMenu;
	string* actual = new string();

	// Arreglo de punteros a funciones
	void (*menuP[4])(Gestor& gestor, string*& actual) = {
		&nuevaPagina,
		&retroceder,
		&avanzar,
		&estadoActual
	};


	do {
		cout << "Bienvenido al navegador web ANGULO" << endl;
		cout << "¿Qué desea hacer?"
			<< "\n1. Ingresar a una nueva página"
			<< "\n2. Retroceder"
			<< "\n3. Avanzar"
			<< "\n4. Mostrar el estado actual"
			<< "\n5. Salir" << endl;
		cout << "Ingrese la opción que desea realizar: ";
		validacionInt(optMenu, 1, 5);
		limpiarPantalla();
		if (optMenu != 5) {
			(*menuP[optMenu - 1])(gestor, actual);
			if (!actual->empty()) {
				cout << endl;
				cout << "Página actual: " << *actual << endl;
			}
		}
		limpiarPantalla();
	} while (optMenu != 5);

	delete actual;
}

// Función P.1 - Visita una página nueva
void nuevaPagina(Gestor& gestor, string*& actual) {
	string nuevaPagina;
	cout << "=============== NUEVA PÁGINA ===============" << endl;
	cout << "Ingrese la página a la que desea acceder: ";
	cin >> nuevaPagina;

	if (!actual->empty()) {
		gestor.paginasAnteriores.push(*actual);
	}
	
	while (!gestor.paginasSiguientes.isEmpty()) {
		gestor.paginasSiguientes.pop();
	}

	*actual = nuevaPagina;
}

// Función P.2 - Retrocede a la anterior página
void retroceder(Gestor& gestor, string*& actual) {
	cout << "=============== RETROCEDER ===============" << endl;
	if (gestor.paginasAnteriores.isEmpty()) {
		cout << "No hay páginas anteriores" << endl;
		return;
	}

	gestor.paginasSiguientes.push(*actual);
	*actual = gestor.paginasAnteriores.top();
	gestor.paginasAnteriores.pop();
	cout << "Se retrocedió exitosamente" << endl;
}

// Función P.3 - Avanza a la siguiente página
void avanzar(Gestor& gestor, string*& actual) {
	cout << "=============== AVANZAR ===============" << endl;
	if (gestor.paginasSiguientes.isEmpty()) {
		cout << "No hay páginas siguientes" << endl;
		return;
	}

	gestor.paginasAnteriores.push(*actual);
	*actual = gestor.paginasSiguientes.top();
	gestor.paginasSiguientes.pop();
	cout << "Se avanzó exitosamente" << endl;
}

// Función P.4 - Muestra el estado actuañ
void estadoActual(Gestor& gestor, string*& actual) {
	cout << "=============== ESTADO ACTUAL ===============" << endl;
	cout << "Páginas siguientes" << endl;
	if (gestor.paginasSiguientes.isEmpty()) {
		cout << "No hay páginas siguientes" << endl;
	}
	else {
		gestor.paginasSiguientes.mostrar();
	}
	cout << endl;

	cout << "Página actual" << endl;
	if (actual->empty()) {
		cout << "No se ha ingresado a ninguna página" << endl;
	}
	else {
		cout << *actual << endl;
	}
	cout << endl;

	cout << "Páginas anteriores" << endl;
	if (gestor.paginasAnteriores.isEmpty()) {
		cout << "No hay páginas anteriores" << endl;
	}
	else {
		gestor.paginasAnteriores.mostrar();
	}
}

// Ejercicio Colas
void ejercicioCola(Gestor& gestor) {
	int cantTrabajos, numeroPags, contador = 0, cantPaginas = 0;
	double vImpresion, tiempoTranscurrido = 0;
	string nombreDocumento;

	cout << "=============== EJERCICIO COLA ===============" << endl;
	cout << "Ingrese la cantidad de trabajos que la impresora deberá imprimir: ";
	validacionInt(cantTrabajos, 1, 100);

	cout << "Ingrese la velocidad de la impreosa en segundos por página: ";
	validacionDouble(vImpresion, 0.1, 10);
	limpiarPantalla();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < cantTrabajos; i++) {
		cout << "Ingrese el nombre del documento: ";
		getline(cin, nombreDocumento);

		cout << "Ingrese el número de páginas: ";
		validacionInt(numeroPags, 1, 100);
		contador++;

		TrabajoImpresion nuevoTrabajo = TrabajoImpresion(contador, nombreDocumento, numeroPags);
		gestor.cola.enqueue(nuevoTrabajo);
		limpiarPantalla();
	}

	while (!gestor.cola.isEmpty()) {
		TrabajoImpresion trabajo = gestor.cola.front();
		double tiempoImpresion = trabajo.numeroPaginas * vImpresion;
		gestor.cola.dequeue();

		cout << "Imprimiendo trabajo #" << trabajo.idTrabajo << "(" << trabajo.numeroPaginas << " páginas, " << tiempoImpresion << " segundos)" << endl;
		cout << endl;

		tiempoTranscurrido += tiempoImpresion;
		cantPaginas += trabajo.numeroPaginas;
	}

	cout << "Tiempo total de impresión: " << tiempoTranscurrido
		<< "\nTotal páginas impresas: " << cantPaginas << endl;
	limpiarPantalla();
}