#pragma once
#ifndef FACTURA_H
#define FACTURA_H
#include "Cliente.h"
#include "TanqueCubico.h"
#include "TanqueEsferico.h"
#include "TanqueCilindrico.h"
#include "TanqueCilindricoHueco.h"

class Factura
{
public:
	Cliente cliente;
	double total = 0;

public:
	Factura(Cliente cliente);

	void mostrarEncabezado();

	void mostrarTanque(TanqueCubico tanque);
	void mostrarTanque(TanqueEsferico tanque);
	void mostrarTanque(TanqueCilindrico tanque);
	void mostrarTanque(TanqueCilindricoHueco tanque);

	void mostrarFinal();
};

#endif