#pragma once
#ifndef NODOBASE_H
#define NODOBASE_H
#include <string>

using namespace std;

struct Nodo {
	string pagina;
	Nodo* next = nullptr;
};

#endif