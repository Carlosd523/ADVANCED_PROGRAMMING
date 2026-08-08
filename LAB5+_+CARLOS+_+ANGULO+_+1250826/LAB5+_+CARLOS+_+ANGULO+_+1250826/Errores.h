#pragma once
#ifndef ERRORES_H
#define ERRORES_H
#include <exception>
#include <string>

using namespace std;

class DimensionesNoValidasException : public exception {
private:
	string mensaje;

public:
	DimensionesNoValidasException(double dimension);
	const char* what() const noexcept override;
};

class RadioExteriorEsMenorException : public exception {
private:
	string mensaje;

public:
	RadioExteriorEsMenorException(double radioExterior, double radioInterior);
	const char* what() const noexcept override;
};

class DatosInvalidosException : public exception {
private:
	string mensaje;

public:
	DatosInvalidosException();
	const char* what() const noexcept override;
};
#endif