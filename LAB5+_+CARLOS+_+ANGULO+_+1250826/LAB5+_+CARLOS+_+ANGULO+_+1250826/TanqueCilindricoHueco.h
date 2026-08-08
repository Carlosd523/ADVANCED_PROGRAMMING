#pragma once
#ifndef TANQUECILINDRICOHUECO_H
#define TANQUECILINDRICOHUECO_H

#include "Tanque.h"
class TanqueCilindricoHueco :
    public Tanque
{
private:
    double radioExterno;
    double radioInterno;
    double altura;

public:
    TanqueCilindricoHueco();
    TanqueCilindricoHueco(double radioExterno, double radioInterno, double altura);

    void registrarRadios(double radioExterno, double radioInterno);
    void registrarAltura(double altura);

    double calcularVolumen() override;
};

#endif