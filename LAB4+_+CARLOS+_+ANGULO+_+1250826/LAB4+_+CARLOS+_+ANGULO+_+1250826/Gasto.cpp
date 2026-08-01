#include "Gasto.h"
#include <iostream>

using namespace std;

Gasto::Gasto() {
    fecha = "";
    costoUnidad = 0;
    unidades = 0;
    descripcion = "";
}

void Gasto::registrarGasto(
    Mascota mascota,
    Dueno dueno,
    string fecha,
    double costoUnidad,
    int unidades,
    string descripcion
) {
    this->mascota = mascota;
    this->dueno = dueno;
    this->fecha = fecha;
    this->costoUnidad = costoUnidad;
    this->unidades = unidades;
    this->descripcion = descripcion;
}

void Gasto::detallesGasto() {
    cout << "Dueño: " << dueno.getNombre() << endl;
    cout << "Mascota: " << mascota.getNombre() << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Costo por unidad: Q" << costoUnidad << endl;
    cout << "Unidades: " << unidades << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Subtotal: Q" << costoUnidad * unidades << endl;
    cout << "Total con IVA: Q" << costoUnidad * unidades * 1.12 << endl;
}

string Gasto::getDescripcion() {
    return descripcion;
}

Dueno Gasto::getDueno() {
    return dueno;
}