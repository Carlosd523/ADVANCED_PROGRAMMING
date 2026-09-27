#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include  <string>
#include <iostream>

using namespace std;

double resistenciaEquivalente(double resistenciaSerie, double resistenciaParalela, int n);

string retornarPalabraInvertida(const string& palabra, int n);

void menu();

void opcionResistencia();

void opcionPalindroma();

int validacionEntero(int& numero, int min, int max);

double validacionDouble(double& numero, double min, double max);

void LimpiarPantalla();
#endif