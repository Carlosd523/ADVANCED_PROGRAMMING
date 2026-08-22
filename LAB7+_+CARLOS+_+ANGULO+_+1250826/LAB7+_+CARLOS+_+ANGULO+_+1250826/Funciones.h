#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include "Empleado.h"
#include "Excepciones.h"

using namespace std;

// Función 01 - Validar la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Validar la entrada de un dato tipo double.
void validacionDouble(double& num, double min, double max);

// Función 03 - Limpiar la pantalla.
void limpiarPantalla();

// Función 04 - Asignación de empleado
void asignarEmpleado(Empleado* nuevoEmpleado, Empleado**& empleados, int& capacidad, int& cantidad);

// Función 05 - Eliminar espacios vacíos entre espacios ocupados
void eliminarVacios(Empleado**& empleados, int cantidad);

// Función 06 - Aumentar salario en un 10%
void aumentarSalario(Empleado* empleado);

// Función 07 - Disminuir salario en un 10%
void disminuirSalario(Empleado* empleado);

// Función 08 - Cambiar el salario de un empleado
void cambiarSalario(Empleado* empleado);

// Función 09 - Ordenar empleados por salario en orden ascendente
void salarioAscendente(Empleado**& empleados, int capacidad, int cantidad);

// Función 10 - Ordenar empleados por salario descendente
void salarioDescendente(Empleado**& empleados, int capacidad, int cantidad);

// Función 11 - Ordenar empleados alfabéticamente
void ordenAlfabetico(Empleado**& empleados, int capacidad, int cantidad);

// Función 12 - Mostrar empleados
void mostrarEmpleados(Empleado** empleados, int cantidad);

// Función 13 - Calcular salario total
void calcularSalarioTotal(Empleado** empleados, int cantidad);

// Función 14 - Contar empleados por tipo
void contarTipoEmpleados(Empleado** empleados, int cantidad);

// Función 15 - Mostrar información por salario
void mostrarInfoSalario(Empleado** empleados, int cantidad);
#endif