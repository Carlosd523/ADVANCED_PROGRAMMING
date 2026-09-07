#pragma once
#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H
#include <string>
#include <exception>

using namespace std;

class DatoFueraDelRango : public exception
{
private:
	string mensaje;

public:
	DatoFueraDelRango(double dato, double min, double max);
	const char* what() const noexcept override;
};

class DatoInvalido : public exception
{
private:
	string mensaje;
public:
	DatoInvalido();
	const char* what() const noexcept override;
};
#endif