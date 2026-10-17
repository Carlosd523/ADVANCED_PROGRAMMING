#pragma once
#ifndef GESTOR_H
#define GESTOR_H
#include "Pila.h"
#include "Cola.h"

struct Gestor {
	Pila paginasSiguientes;
	Pila paginasAnteriores;
	Cola cola;
};

#endif