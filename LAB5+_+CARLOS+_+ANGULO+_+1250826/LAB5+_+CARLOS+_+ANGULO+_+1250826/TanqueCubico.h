#pragma once
#ifndef TANQUECUBICO_H
#define TANQUECUBICO_H

#include "Tanque.h"
class TanqueCubico :
    public Tanque
{
private:
    double lado;

public:
    TanqueCubico();
    TanqueCubico(double lado);

    void registrarLado(double lado);

    double calcularVolumen() override;
};

#endif