#pragma once
#include "Tarea.h"
#ifndef NODO_H
#define NODO_H

struct Nodo {
	Tarea tarea;
	Nodo* prev = nullptr;
	Nodo* next = nullptr;
};

#endif