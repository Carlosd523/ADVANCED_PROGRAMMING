#pragma once
#ifndef GASTO_H
#define GASTO_H

#include <string>
#include "Mascota.h"
#include "Dueno.h"

using namespace std;

class Gasto {
private:
    Mascota mascota;
    Dueno dueno;
    string fecha;
    double costoUnidad;
    int unidades;
    string descripcion;

public:
    Gasto();

    void registrarGasto(
        Mascota mascota,
        Dueno dueno,
        string fecha,
        double costoUnidad,
        int unidades,
        string descripcion
    );

    void detallesGasto();

    string getDescripcion();
    Dueno getDueno();

    ~Gasto() {}
};

#endif