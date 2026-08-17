#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Comic.h"

// Función 01 - Valida la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Valida la entrada de un dato tipo double.
void validacionDouble(double& num, double min, double max);

// Función 03 - Limpia la pantalla.
void limpiarPantalla();

// Función 04 - Recibe como parámetro un puntero. En caso de que el puntero sea nulo permite registrar un cómic.
bool intentarRegistrar(Comic*& p, Comic* nuevoComic);

// Función 05 - Recibe como parámetro un puntero para indicar si contiene un valor nulo
bool punteroVacio(Comic* p);

// Función 06 - Búsqueda por título
void revisarTitulo(Comic* p, const string& busqueda, int& coincidencias);

// Función 07 - Búsqueda por Código de Barras
void revisarCodigoBarras(Comic* p, const string& busqueda, int& coincidencias);

// Función 08 - Búsqueda por Editorial
void revisarEditorial(Comic* p, const string& busqueda, int& coincidencias);

// Función 09 - Búsqueda por Número de Edición (Issue)
void revisarIssue(Comic* p, int busqueda, int& coincidencias);

// Función 10 - Eliminar por Título
void eliminarPorTitulo(Comic*& p, const string& busqueda, bool& eliminado);

// Función 11 - Eliminar por Código de Barras
void eliminarPorCodigoBarras(Comic*& p, const string& busqueda, bool& eliminado);

// Función 12 - Eliminar por Editorial
void eliminarPorEditorial(Comic*& p, const string& busqueda, bool& eliminado);

// Función 13 - Eliminar por Número de Edición (Issue)
void eliminarPorIssue(Comic*& p, int busqueda, bool& eliminado);

// Fúnción 14 - Indica si hay coincidencia entre códigos de barras
bool coincidenciaCodigoBarras(Comic* p, string codigoBarras);

// Función 15 - Lee si un string posee solo dígitos
bool esSoloNumeros(const string& str);

// Función 16 - Valida el código de barras
void validacionCodigoBarras(string& codigoBarras);

#endif