#pragma once
#ifndef EMPLEADOVENTAS_H
#define EMPLEADOVENTAS_H
#include "Empleado.h"
class EmpleadoVentas :
    public Empleado
{
private:
    double ventasRealizadas;
    int comision;

public:
    EmpleadoVentas(string nombre, string id, double salario, int ventasRealizadas, double comision);

    void mostrarInfo() override;
    double calcularSalarioTotal() override;
    virtual string getTipo() override;

    ~EmpleadoVentas() override;
};

#endif