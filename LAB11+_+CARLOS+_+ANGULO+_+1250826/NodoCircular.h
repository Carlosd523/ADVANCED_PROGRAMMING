#pragma once
#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

struct NodoCircular {
	Actividad actividad;
	NodoCircular* next = nullptr;
	NodoCircular* prev = nullptr;
};

#endif