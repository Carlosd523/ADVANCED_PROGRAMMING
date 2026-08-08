#include "Errores.h"
#include<string>

DimensionesNoValidasException::DimensionesNoValidasException(double dimension) {
	mensaje = "Dimensión inválida. La dimensión debe de estar adentro del rango.\nLa dimensión actual es: "
		+ to_string(dimension);
}

const char* DimensionesNoValidasException::what() const noexcept {
	return mensaje.c_str();
}

RadioExteriorEsMenorException::RadioExteriorEsMenorException(double radioExterior, double radioInterior) {
	mensaje = string("El radio interior no puede ser mayor al radio exterior.")
		+ string("\nRadio exterior actual: ") + to_string(radioExterior)
		+ string("\nRadio interior actual: ") + to_string(radioInterior);
}

const char* RadioExteriorEsMenorException::what() const noexcept {
	return mensaje.c_str();
}

DatosInvalidosException::DatosInvalidosException() {
	mensaje = "Los datos ingresados son erróneos";
}

const char* DatosInvalidosException::what() const noexcept {
	return mensaje.c_str();
}