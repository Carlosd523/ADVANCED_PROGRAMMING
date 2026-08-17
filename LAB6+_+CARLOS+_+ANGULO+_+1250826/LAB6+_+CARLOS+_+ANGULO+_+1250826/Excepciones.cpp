#include "Excepciones.h"

DatoFueraDelRango::DatoFueraDelRango(double dato, double min, double max) {
	mensaje = "El dato proporcionado está afuera del rango. Rango actual: (" + to_string(min) + ", " + to_string(max)
		+ "). Dato actual: " + to_string(dato);
}

const char* DatoFueraDelRango::what() const noexcept {
	return mensaje.c_str();
}

DatoInvalido::DatoInvalido() {
	mensaje = "El dato proporcionado es un string y solamente se permiten números";
}

const char* DatoInvalido::what() const noexcept {
	return mensaje.c_str();
}