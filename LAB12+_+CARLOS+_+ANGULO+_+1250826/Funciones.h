#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Gestor.h"

// Función 01 - Validar la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Limpiar la pantalla.
void limpiarPantalla();

// Función 03 - Validación decimales
double validacionDouble(double& numero, double min, double max);

// Menú
void menu();

// Menú - Ejercicio pilas
void menuPilas(Gestor& gestor);

// Función P.1 - Visita una página nueva
void nuevaPagina(Gestor& gestor, string*& actual);

// Función P.2 - Retrocede a la anterior página
void retroceder(Gestor& gestor, string*& actual);

// Función P.3 - Avanza a la siguiente página
void avanzar(Gestor& gestor, string*& actual);

// Función P.4 - Muestra el estado actual
void estadoActual(Gestor& gestor, string*& actual);

// Ejercicio Colas
void ejercicioCola(Gestor& gestor);


#endif