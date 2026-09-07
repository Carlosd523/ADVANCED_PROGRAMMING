#pragma once
#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include "Excepciones.h"

using namespace std;

// Función 01 - Validar la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Limpiar la pantalla.
void limpiarPantalla();

// Función 03 - Calcular la potencia recursivamente
int calcularPotencia(int base, int potencia);

// Función 04 - Contar los dígitos de un número
int contarDigitos(int n);

// Función 05 - Invertir un número
int invertirNumero(int n, int invertido);

// Función 06 - Sumar los dígitos de un número
int sumarDigitos(int n);

// Función 07 - Obtener el dígito mayor
int digitoMayor(int n);

// Función 08 - Opción 1 del menú
void menu1();

// Función 09 - Opción 2 del menú
void menu2();

// Función 10 - Opción 3 del menú
void menu3();

// Función 11 - Opción 4 del menú
void menu4();

// Función 12 - Opción 5 del menú
void menu5();
#endif