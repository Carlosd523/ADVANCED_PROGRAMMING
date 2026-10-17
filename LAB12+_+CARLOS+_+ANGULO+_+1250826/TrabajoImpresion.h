#pragma once
#ifndef TRABAJOIMPRESION_H
#define TRABAJOIMPRESION_H
#include <string>

using namespace std;

struct TrabajoImpresion
{
	int idTrabajo = 0;
	string document = "";
	int numeroPaginas = 0;

	TrabajoImpresion();
	TrabajoImpresion(int idTrabajo, string document, int numeroPaginas);
};

#endif