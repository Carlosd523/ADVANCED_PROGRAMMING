#pragma once
#ifndef TANQUECILINDRICO_H
#define TANQUECILINDRICO_H

#include "Tanque.h"
class TanqueCilindrico :
    public Tanque
{
private:
    double radio;
    double altura;

public:
    TanqueCilindrico();
    TanqueCilindrico(double radio, double altura);

    void registrarRadio(double radio);
    void registrarAltura(double altura);

    double calcularVolumen() override;
};

#endif