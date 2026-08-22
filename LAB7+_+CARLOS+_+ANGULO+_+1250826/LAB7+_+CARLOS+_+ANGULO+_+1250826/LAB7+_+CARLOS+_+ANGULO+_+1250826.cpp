#include <iostream>
#include "Empleado.h"
#include "EmpleadoAdministrativo.h"
#include "EmpleadoTecnico.h"
#include "EmpleadoVentas.h"
#include "Funciones.h"

int main()
{
	// Declaración de Variables
	int capacidad = 2, cantidad = 0;
	int optMenu = 0, optTipoEmpleado, optSalario, optReportes;
	double salarioTotal = 0;
	Empleado** empleados = new Empleado * [capacidad];
	for (int i = 0; i < capacidad; i++) {
		empleados[i] = nullptr;
	}
	Empleado* nuevoEmpleado = nullptr;

	// Declaración de Variables para empleados
	string nombre, id, departamento, especialidad;
	double salario, bonificacion, comision;
	int horasExtra, ventasRealizadas;

	// Menú interactivo
	cout << "Bienvenido a Angulema´s Company" << endl;
	do {
		cout << "1. Agregar empleado"
			<< "\n2. Mostrar Empelados"
			<< "\n3. Buscar Empleado"
			<< "\n4. Eliminar Empleado"
			<< "\n5. Actualizar Salario"
			<< "\n6. Ordenar Empleados"
			<< "\n7. Generar Reportes"
			<< "\n8. Mostrar Estadísticas"
			<< "\n9. Salir"
			<< "\nIngrese la opción que desee realizar: ";
		validacionInt(optMenu, 1, 9);
		limpiarPantalla();

		switch (optMenu) {
		case 1: {
			cout << "=============== AGREGAR EMPLEADO ===============" << endl;
			cout << "Ingrese el nombre del empleado: ";
			getline(cin >> ws, nombre);
			bool avanzar = false;
			while (!avanzar) {
				cout << "Ingrese el ID del empleado: ";
				cin >> id;
				bool idExiste = false;
				for (int i = 0; i < cantidad; i++) {
					if (empleados[i]->getID() == id) {
						cout << "ID ya existente, por favor ingrese uno nuevo" << endl;
						idExiste = true;
						break;
					}
				}
				if (!idExiste) {
					avanzar = true;
				}
			}
			cout << "Ingrese el salario del empleado (5000 - 50000): ";
			validacionDouble(salario, 5000, 50000);

			cout << "¿Qué tipo de empleado será?"
				<< "\n1. Empleado Administrativo"
				<< "\n2. Empleado Técnico"
				<< "\n3. Empleado de Ventas" << endl;
			validacionInt(optTipoEmpleado, 1, 3);
			switch (optTipoEmpleado) {
			case 1: {
				cout << "Ingrese el departamento del empleado: ";
				getline(cin >> ws, departamento);
				cout << "La bonificación del empleado es un 5% de su salario" << endl;
				bonificacion = salario * 0.05;

				// Declaración del empleado
				nuevoEmpleado = new EmpleadoAdministrativo(nombre, id, salario, departamento, bonificacion);
				break;
			}
			case 2: {
				cout << "Ingrese la especialidad del empleado: ";
				getline(cin >> ws, especialidad);
				cout << "Ingrese las horas extras que trabajó el empleado (1-20): ";
				validacionInt(horasExtra, 1, 20);

				// Declaración del empleado
				nuevoEmpleado = new EmpleadoTecnico(nombre, id, salario, especialidad, horasExtra);
				break;
			}
			case 3: {
				cout << "Ingrese las ventas realizadas del empleado (1-100): ";
				validacionInt(ventasRealizadas, 1, 100);
				cout << "El empleado recibirá Q100.75 de comisión por cada venta realizada";
				comision = 100.75 * ventasRealizadas;

				// Declaración del empleado
				nuevoEmpleado = new EmpleadoVentas(nombre, id, salario, ventasRealizadas, comision);
				break;
			}
			}

			// Asignación del empleado al arreglo dinámico
			asignarEmpleado(nuevoEmpleado, empleados, capacidad, cantidad);

			limpiarPantalla();
			break;
		}
		case 2: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== MOSTRAR EMPLEADOS ===============" << endl;
			for (int i = 0; i < cantidad; i++) {
				empleados[i]->mostrarInfo();
				cout << endl;
			}
			limpiarPantalla();
			break;
		}
		case 3: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== BUSCAR EMPLEADO ===============" << endl;
			cout << "Ingrese el ID que desea buscar: ";
			cin >> id;
			bool encontrado = false;
			for (int i = 0; i < cantidad; i++) {
				if (empleados[i]->getID() == id) {
					empleados[i]->mostrarInfo();
					encontrado = true;
					break;
				}
			}

			if (!encontrado) {
				cout << "No hay empleados con el ID ingresado" << endl;
			}
			limpiarPantalla();
			break;
		}
		case 4: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== ElIMINAR EMPLEADO ===============" << endl;
			cout << "Ingrese el ID del empleado que desea eliminar: ";
			cin >> id;
			bool encontrado = false;
			for (int i = 0; i < cantidad; i++) {
				if (empleados[i]->getID() == id) {
					delete empleados[i];
					empleados[i] = nullptr;
					encontrado = true;
					break;
				}
			}

			if (encontrado) {
				eliminarVacios(empleados, cantidad);
				cantidad--;
			}
			else {
				cout << "No se han encontrar empleados con el ID ingresado" << endl;
			}
			limpiarPantalla();
			break;
		}
		case 5: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== ACTUALIZAR SALARIO ===============" << endl;
			void (*actualizarSalarios[3])(Empleado*) = {
				aumentarSalario,
				disminuirSalario,
				cambiarSalario
			};

			Empleado* empleadoSalarioACambiar = nullptr;
			cout << "Ingrese el ID que desea buscar: ";
			cin >> id;
			bool encontrado = false;
			for (int i = 0; i < cantidad; i++) {
				if (empleados[i]->getID() == id) {
					empleadoSalarioACambiar = empleados[i];
					encontrado = true;
					break;
				}
			}
			if (!encontrado) {
				cout << "No hay empleados con el ID ingresado" << endl;
				break;
			}


			cout << "Ingrese la opción que desea realizar"
				<< "\n1. Aumentar Salario 10%"
				<< "\n2. Disminuir Salario 10%"
				<< "\n3. Cambiar Salario" << endl;
			validacionInt(optSalario, 1, 3);
			(*actualizarSalarios[optSalario - 1])(empleadoSalarioACambiar);
			limpiarPantalla();
			break;
		}
		case 6: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== ORDENAR EMPLEADOS ===============" << endl;
			void (*ordenarEmpleados[3])(Empleado**&, int, int) = {
				salarioAscendente,
				salarioDescendente,
				ordenAlfabetico
			};

			cout << "Ingrese la opción que desea realizar"
				<< "\n1. Ordenar empleados por salario en orden ascendente"
				<< "\n2. Ordenar empleados por salario en orden descendente"
				<< "\n3. Ordenar empleados por orden alfabético" << endl;
			validacionInt(optSalario, 1, 3);
			(*ordenarEmpleados[optSalario - 1])(empleados, capacidad, cantidad);
			limpiarPantalla();
			break;
		}
		case 7: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== GENERAR REPORTES ===============" << endl;
			void (*reportes[4])(Empleado**, int) = {
				mostrarEmpleados,
				calcularSalarioTotal,
				contarTipoEmpleados,
				mostrarInfoSalario
			};

			cout << "Ingresa la opción que desee realizar"
				<< "\n1. Mostrar todos los empleados"
				<< "\n2. Calcular el salario total"
				<< "\n3. Contar empleados por tipo"
				<< "\n4. Filtrar información por salario" << endl;
			validacionInt(optReportes, 1, 4);
			(*reportes[optReportes - 1])(empleados, cantidad);
			limpiarPantalla();
			break;
		}
		case 8: {
			if (cantidad == 0) {
				cout << "No se han registrado empleados todavía" << endl;
				limpiarPantalla();
				break;
			}

			cout << "=============== ESTADÍSTICAS ===============" << endl;
			double salarioPromedio = 0;
			for (int i = 0; i < cantidad; i++) {
				salarioPromedio += empleados[i]->calcularSalarioTotal();
			}
			salarioPromedio = salarioPromedio / cantidad;
			cout << "El salario promedio es: " << salarioPromedio << endl;

			Empleado* mayorSalario = empleados[0];
			Empleado* menorSalario = empleados[0];
			for (int i = 1; i < cantidad; i++) {
				if (empleados[i]->calcularSalarioTotal() > mayorSalario->calcularSalarioTotal()) {
					mayorSalario = empleados[i];
				}
				else if (empleados[i]->calcularSalarioTotal() < menorSalario->calcularSalarioTotal()) {
					menorSalario = empleados[i];
				}
			}

			cout << "Empleado con mayor salario" << endl;
			mayorSalario->mostrarInfo();
			cout << "Empleado con menor salario" << endl;
			menorSalario->mostrarInfo();

			contarTipoEmpleados(empleados, cantidad);
			limpiarPantalla();
			break;
		}
		}
	} while (optMenu != 9);
	for (int i = 0; i < cantidad; i++) {
		delete empleados[i];
		empleados[i] = nullptr;
	}

	delete[] empleados;
	empleados = nullptr;

	cout << "Memoria liberada exitosamente. Hasta la próxima" << endl;
	limpiarPantalla();
}