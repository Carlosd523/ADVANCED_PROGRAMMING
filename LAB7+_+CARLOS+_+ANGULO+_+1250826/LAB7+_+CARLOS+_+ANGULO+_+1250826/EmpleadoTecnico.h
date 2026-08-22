#pragma once
#ifndef EMPLEADOTECNICO_H
#define EMPLEADOTECNICO_H
#include "Empleado.h"
class EmpleadoTecnico :
    public Empleado
{
private:
    string especialidad;
    int horasExtra;

public:
    EmpleadoTecnico(string nombre, string id, double salario, string especialidad, int horasExtra);

    void mostrarInfo() override;
    double calcularSalarioTotal() override;
    virtual string getTipo() override;

    ~EmpleadoTecnico() override;
};
#endif