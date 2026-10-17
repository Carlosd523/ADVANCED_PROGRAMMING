#pragma once
#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include "Excepciones.h"
#include "Gestor.h"

using namespace std;

// Función 01 - Validar la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max);

// Función 02 - Limpiar la pantalla.
void limpiarPantalla();

// Función 03 - Menú
void menu();

// Función 04 - Menú tareas
void menuTareas(Gestor& gestor);

// Función 05 - Menú actividades
void menuActividades(Gestor& gestor);

// Funciones ListaTareas
// Función LT.1 - Agregar una tarea
void agregarTarea(Gestor& gestor);

// Función LT.2 - Eliminar una tarea por Nombre
void eliminarTarea(Gestor& gestor);

// Función LT.3 - Buscar una tarea
void buscarTarea(Gestor& gestor);

// Función LT.4 - Mostrar las tareas
void mostrarTodasTareas(Gestor& gestor);

// Función LT.5 - Mostrar las tareas inversamente
void mostrarTodasTareasInversamente(Gestor& gestor);

// Función Validación LT.1 - Valida que el nombre de la tarea sea válido
bool validacionNombre(Gestor& gestor, string nombre);

// Funciones RelojActividades
// Función RA.1 - Agregar actividad
void agregarActividad(Gestor& gestor);

// Función RA.2 - Eliminar actividad por hora
void eliminarActividad(Gestor& gestor);

// Función RA.3 - Mostrar Actividad actual
void mostrarActividadActual(Gestor& gestor);

// Función RA.4 - Avanzar al siguiente bloque horario
void avanzarBloqueHorario(Gestor& gestor);

// Función RA.5 - Retroceder bloque horario
void retrocederBloqueHorario(Gestor& gestor);

// Función RA.6 - Recorrer actividades
void recorrerActividades(Gestor& gestor);

// Función Validación RA.1 - Valida que la hora de la tarea sea válida
bool validacionHora(Gestor& gestor, int hora);

#endif