#pragma once
#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include "Excepciones.h"
#include "List.h"

using namespace std;

// Función 01 - Validar la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Limpiar la pantalla.
void limpiarPantalla();

// Función 03 - Menú
void menu();

// Función Menú #1 - Uso de Add
void usoAdd(List*& lista);

// Función Menú #2 - Uso de Clear
void usoClear(List*& lista);

// Función Menú #3 - Uso de Count
void usoCount(List*& lista);

// Función Menú #4 - Uso de Contains
void usoContains(List*& lista);

// Función Menú #5 - Uso de IndexOf
void usoIndexOf(List*& lista);

// Función Menú #6 - Uso de Insert
void usoInsert(List*& lista);

// Función Menú #7 - Uso de GetItem
void usoGetItem(List*& lista);

// Función Menú #8 - Uso de SetItem
void usoSetItem(List*& lista);

// Función Menú #9 - Uso de LastIndexOf
void usoLastIndexOf(List*& lista);

// Función Menú #10 - Uso de Remove
void usoRemove(List*& lista);

// Función Menú #11 - Uso de RemoveAt
void usoRemoveAt(List*& lista);

// Función Menú #12 - Uso de Show List
void usoShowList(List*& lista);
#endif