#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Excepciones.h"
#include "Tienda.h"

using namespace std;

// Función 01 - Validar la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Limpiar la pantalla.
void limpiarPantalla();

// Función 03 - Validación decimales
double validacionDouble(double& numero, double min, double max);

// Función 04 - Pasar un string a mayúsculas
void aMayusculas(string& s);

// Función 05 - Validación de que un string no quede vacío
void validacionString(string& texto);

#endif