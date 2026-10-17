#include "Funciones.h"
#include <iostream>

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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función 02 - Limpia la pantalla.
void limpiarPantalla() {
	cout << "Presione Enter para continuar...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	system("cls");
}

// Función 03 - Menú Genereal
void menu() {
	Gestor gestor;

	// Arreglo de punteros a funciones
	int opt;

	void (*menu[2])(Gestor & gestor) = {
		&menuTareas,
		&menuActividades
	};

	do {
		cout << "Ejercicios:"
			<< "\n1. Sistema Gestión de Tareas con Prioridad"
			<< "\n2. Reloj de Actividades Diarias"
			<< "\n3. Salir" << endl;
		validacionInt(opt, 1, 3);
		limpiarPantalla();
		if (opt != 3) { (*menu[opt - 1])(gestor); }
		limpiarPantalla();
	} while (opt != 3);

}

// Función 04 - Menú Tareas
void menuTareas(Gestor& gestor) {
	int optMenu = 0;

	// Arreglo de punteros a funciones
	void (*menuTareas[5])(Gestor & gestor) = {
		&agregarTarea,
		&eliminarTarea,
		&buscarTarea,
		&mostrarTodasTareas,
		&mostrarTodasTareasInversamente
	};

	do {
		cout << "Puede realizar las siguientes opciones en su lista de tareas:"
			<< "\n1. Agregar Tarea"
			<< "\n2. Eliminar Tarea"
			<< "\n3. Buscar Tarea"
			<< "\n4. Mostrar Tareas"
			<< "\n5. Mostrar Tareas Inversamente" 
			<< "\n6. Salir" << endl;
		cout << "Ingrese la opción que desee realizar: ";
		validacionInt(optMenu, 1, 6);
		limpiarPantalla();
		if (optMenu != 6) { (*menuTareas[optMenu - 1])(gestor); }
		limpiarPantalla();
	} while (optMenu != 6);
}

// Función 05 - Menú actividades
void menuActividades(Gestor& gestor) {
	int optMenu = 0;

	// Arreglo de punteros a funciones
	void (*menuActividades[6])(Gestor & gestor) = {
		&agregarActividad,
		&eliminarActividad,
		&mostrarActividadActual,
		&avanzarBloqueHorario,
		&retrocederBloqueHorario,
		&recorrerActividades
	};

	do {
		cout << "Puede realizar las siguientes opciones en su lista de actividades:"
			<< "\n1. Agregar Actividad"
			<< "\n2. Eliminar Actividad"
			<< "\n3. Mostrar Actividad Actual"
			<< "\n4. Avanzar Bloque Horario"
			<< "\n5. Retroceder Bloque Horario"
			<< "\n6. Recorrer Actividades"
			<< "\n7. Salir" << endl;
		cout << "Ingrese la opción que desee realizar: ";
		validacionInt(optMenu, 1, 7);
		limpiarPantalla();
		if (optMenu != 7) { (*menuActividades[optMenu - 1])(gestor); }
		limpiarPantalla();
	} while (optMenu != 7);
}

// Funciones ListaTareas
// Función LT.1 - Agregar una tarea
void agregarTarea(Gestor& gestor) {
	cout << "=============== AGREGAR TAREA ===============" << endl;
	string nombre, descripcion, fechaLimite;
	int prioridad;
	bool avanzar = false;
	cout << "Ingrese el nombre de la tarea: ";

	while (!avanzar) {
		getline(cin, nombre);
		if (validacionNombre(gestor, nombre)) {
			avanzar = true;
		}
		else {
			cout << "Una tarea ya tiene este nombre. Ingrese otro nombre: " << endl;
		}
	}

	cout << "Ingrese la descripción: ";
	getline(cin, descripcion);

	cout << "Ingrese la fecha límite: ";
	getline(cin, fechaLimite);

	cout << "Ingrese la prioridad: ";
	validacionInt(prioridad, 1, 3);

	Tarea tareaAgregar = Tarea(nombre, descripcion, fechaLimite, prioridad);

	gestor.lista.agregarTarea(tareaAgregar);
	cout << "Tarea agregada exitosamente" << endl;
}

// Función LT.2 - Eliminar una tarea por nombre
void eliminarTarea(Gestor& gestor) {
	cout << "=============== ELIMINAR TAREA ===============" << endl;
	string nombre;
	cout << "Ingrese el nombre de la tarea que desee eliminar: ";
	getline(cin, nombre);
	gestor.lista.eliminarTarea(nombre);
}

// Función LT.3 - Buscar una tarea
void buscarTarea(Gestor& gestor) {
	cout << "=============== BUSCAR TAREA ===============" << endl;
	string nombre;
	cout << "Ingrese el nombre de la tarea que desee buscar: ";
	getline(cin, nombre);
	gestor.lista.buscarTarea(nombre);
}

// Función LT.4 - Mostrar las tareas
void mostrarTodasTareas(Gestor& gestor) {
	cout << "=============== MOSTRAR TAREAS ===============" << endl;
	gestor.lista.mostrarTareas();
}

// Función LT.5 - Mostrar las tareas inversamente
void mostrarTodasTareasInversamente(Gestor& gestor) {
	cout << "=============== MOSTRAR TAREAS INVERSAMENTE ===============" << endl;
	gestor.lista.mostrarTareasInversamente();
}

// Función Validación LT.1 - Valida que el nombre de la tarea sea válido
bool validacionNombre(Gestor& gestor, string nombre) {
	Nodo* nodoActual = gestor.lista.getHeader();

	while (nodoActual != gestor.lista.getTail()) {
		if (nodoActual->tarea.getNombre() == nombre) { return false; }
		nodoActual = nodoActual->next;
	}

	return true;
}

// Funciones RelojActividades
// Función RA.1 - Agregar actividad
void agregarActividad(Gestor& gestor) {
	cout << "=============== AGREGAR ACTIVIDAD ===============" << endl;
	string nombre, descripcion;
	int hora;

	cout << "Ingrese el nombre de la actividad: ";
	getline(cin, nombre);

	cout << "Ingrese la descripción: ";
	getline(cin, descripcion);

	cout << "Ingrese la hora: ";
	bool avanzar = false;
	do {
		validacionInt(hora, 0, 23);
		if (!validacionHora(gestor, hora)) {
			cout << "Una actividad ya está asignada a esta hora. Asigne otra hora: ";
		}
		else {
			avanzar = true;
		}
	} while (!avanzar);

	Actividad actividadAgregar = Actividad(nombre, descripcion, hora);

	gestor.reloj.agregarActividad(actividadAgregar);
	cout << "Actividad agregada exitosamente" << endl;
}

// Función RA.2 - Eliminar actividad por hora
void eliminarActividad(Gestor& gestor) {
	cout << "=============== ELIMINAR TAREA ===============" << endl;
	int hora;
	cout << "Ingrese el nombre de la tarea que desee eliminar: ";
	validacionInt(hora, 0, 23);
	gestor.reloj.eliminarActividad(hora);
}

// Función RA.3 - Mostrar Actividad actual
void mostrarActividadActual(Gestor& gestor) {
	cout << "=============== ACTIVIDAD ACTUAL ===============" << endl;
	gestor.reloj.mostrarActividadActual();
}

// Función RA.4 - Avanzar al siguiente bloque horario
void avanzarBloqueHorario(Gestor& gestor) {
	cout << "=============== AVANZAR BLOQUE HORARIO ===============" << endl;
	gestor.reloj.avanzarBloqueHorario();
}

// Función RA.5 - Retroceder bloque horario
void retrocederBloqueHorario(Gestor& gestor) {
	cout << "=============== RETROCEDER BLOQUE HORARIO ===============" << endl;
	gestor.reloj.retrocederBloqueHorario();
}

// Función RA.6 - Recorrer actividades
void recorrerActividades(Gestor& gestor) {
	cout << "=============== RECORRER ACTIVIDADES ===============" << endl;
	gestor.reloj.recorrerActividades();
}

// Función Validación RA.1 - Valida que la hora de la tarea sea válida
bool validacionHora(Gestor& gestor, int hora) {
	NodoCircular* nodoActual = gestor.reloj.getEntrada();

	if (nodoActual == nullptr) { return true; }

	do {
		if (nodoActual->actividad.getHora() == hora) { return false; }
		nodoActual = nodoActual->next;
	} while (nodoActual != gestor.reloj.getEntrada());
}