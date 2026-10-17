#pragma once
#ifndef NODO_H
#define NODO_H

template <typename T>
struct Nodo {
	T dato;
	Nodo<T>* next = nullptr;

	Nodo(const T& dato) : dato(dato) {}
};

#endif