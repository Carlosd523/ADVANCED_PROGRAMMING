#pragma once
#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H
#include "TrabajoImpresion.h"

struct NodoCircular {
	TrabajoImpresion trabajo;
	NodoCircular* next = nullptr;
	NodoCircular* prev = nullptr;
};

#endif