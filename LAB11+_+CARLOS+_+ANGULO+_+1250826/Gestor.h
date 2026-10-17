#pragma once
#ifndef GESTOR_H
#define GESTOR_H
#include "ListaTareas.h"
#include "RelojActividades.h"

struct Gestor {
	ListaTareas lista;
	RelojActividades reloj;
};

#endif