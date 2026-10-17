#include "TrabajoImpresion.h"

TrabajoImpresion::TrabajoImpresion() {}

TrabajoImpresion::TrabajoImpresion(int idTrabajo, string document, int numeroPaginas) {
	this->idTrabajo = idTrabajo;
	this->document = document;
	this->numeroPaginas = numeroPaginas;
}