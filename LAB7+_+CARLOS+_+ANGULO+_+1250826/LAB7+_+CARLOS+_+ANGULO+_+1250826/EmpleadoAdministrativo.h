#pragma once
#ifndef EMPLEADOADMINISTRATIVO_H
#define EMPLEADOADMINISTRATIVO_H
#include "Empleado.h"
class EmpleadoAdministrativo :
    public Empleado
{
private:
    string departamento;
    double bonificacion;

public:
    EmpleadoAdministrativo(string nombre, string id, double salario, string departamento, double bonificacion);

    void mostrarInfo() override;
    double calcularSalarioTotal() override;
    virtual string getTipo() override;

    ~EmpleadoAdministrativo() override;
};

#endif