#pragma once
#ifndef TANQUEESFERICO_H
#define TANQUEESFERICO_H

#include "Tanque.h"
class TanqueEsferico :
    public Tanque
{
private:
    double radio;

public:
    TanqueEsferico();
    TanqueEsferico(double radio);

    void registrarRadio(double radio);

    double calcularVolumen() override;
};

#endif