#include <iostream>
#include <string>

using namespace std;

// Clase Base - Transporte
class Transporte {
private:
    string codigo;
    string destino;
    int capacidad;
    int pasajerosRegistrados;
    double tarifaBase;

public:
    Transporte(string codigo, string destino, int capacidad, int pasajerosRegistrados, double tarifaBase) {
        this->codigo = codigo;
        this->destino = destino;
        this->capacidad = capacidad;
        this->pasajerosRegistrados = pasajerosRegistrados;
        this->tarifaBase = tarifaBase;
    }

    void mostrarDatos() {
        cout << "Datos del transporte: " << codigo
            << "\nDestino: " << destino
            << "\nCapacidad: " << capacidad
            << "\nPasajeros registrados: " << pasajerosRegistrados
            << "\nTarifa base: " << tarifaBase << endl;
    }

    void reservarAsiento() {
        if (pasajerosRegistrados == capacidad) {
            cout << "Todos los asientos han sido ocupados" << endl;
        }
        else {
            pasajerosRegistrados++;
            cout << "Asiento reservado exitosamente" << endl;
        }
    }

    void reservarAsiento(int cantidad) {
        if (pasajerosRegistrados == capacidad) {
            cout << "Todos los asientos han sido ocupados" << endl;
        }
        else {
            if (cantidad + pasajerosRegistrados <= capacidad) {
                pasajerosRegistrados = pasajerosRegistrados + cantidad;
                cout << "Asientos registrados exitosamente" << endl;
            }
            else {
                cout << "No se puede registrar esa cantidad de asientos" << endl;
            }
        }
    }

    void cancelarReservacion(int cantidad) {
        if (pasajerosRegistrados == 0) {
            cout << "No hay ningún asiento ocupado" << endl;
        }
        else {
            if (cantidad > pasajerosRegistrados) {
                cout << "Se han cancelado más asientos de los que están ocupados" << endl;
            }
            else {
                pasajerosRegistrados = pasajerosRegistrados - cantidad;
                cout << "Asientos cancelados correctamente" << endl;
            }
        }
    }

    virtual void iniciarViaje() {}
    virtual void calcularTarifa() {}

    // Métodos get
    string getCodigo() { return codigo; }
    int getCapacidad() { return capacidad; }
    int getPasajerosRegistrados() { return pasajerosRegistrados; }
    double getTarifaBase() { return tarifaBase; }

    ~Transporte() {
        cout << "Objeto destruido exitosamente" << endl;
    }
};

// Clase derivada 01 - Bus Turístico
class BusTuristico : public Transporte {
private:
    int cantidadFilas;

public:
    BusTuristico(string codigo, string destino, int capacidad, int pasajerosRegistrados, double tarifaBase, int cantidadFilas)
        : Transporte(codigo, destino, capacidad, pasajerosRegistrados, tarifaBase), cantidadFilas(cantidadFilas) {};

    void iniciarViaje() override {
        cout << "El bus turístico " << getCodigo() << " inició su viaje" << endl;
    }

    virtual void mostrarDisponibilidad() {
        cout << "Asientos disponibles en " << getCodigo() << ": " << (getCapacidad() - getPasajerosRegistrados()) << endl;
    }

    void calcularTarifa() {
        double tarifa = getTarifaBase() * getPasajerosRegistrados();
        cout << "La tarifa para el bus " << getCodigo() << " es de: " << to_string(tarifa) << endl;
    }
};

class LanchaTuristica : public Transporte {
private:
    string tipoMotor;

public:
    LanchaTuristica(string codigo, string destino, int capacidad, int pasajerosRegistrados, double tarifaBase, string tipoMotor)
        : Transporte(codigo, destino, capacidad, pasajerosRegistrados, tarifaBase), tipoMotor(tipoMotor) {};

    void iniciarViaje() override {
        cout << "La lancha turística " << getCodigo() << " inició su viaje" << endl;
    }

    virtual void mostrarDisponibilidad() {
        cout << "Asientos disponibles en " << getCodigo() << ": " << (getCapacidad() - getPasajerosRegistrados()) << endl;
    }

    void calcularTarifa() {
        double tarifa = getTarifaBase() * getPasajerosRegistrados();
        cout << "La tarifa para la lancha " << getCodigo() << " es de: " << to_string(tarifa) << endl;
    }
};
int main()
{
    // Creación de Objetos
    BusTuristico bus01("BUS0001", "Quetzaltenango", 64, 48, 50.0, 16);
    BusTuristico bus02("BUS0002", "Alta Verapaz", 72, 70, 100.50, 18);
    LanchaTuristica lancha01("LAN0001", "Río Dulce", 24, 12, 150.00, "Fueraborda");
    LanchaTuristica lancha02("LAN0002", "Atitlán", 12, 12, 125.00, "Propulsión a Chorro");

    // Utilización Reserva de Asientos - Sin parámetros
    bus01.reservarAsiento();
    lancha01.reservarAsiento();

    // Utilización Reserva de Asientos - Con parámetros
    bus02.reservarAsiento(2);
    lancha02.reservarAsiento(14);

    bus01.mostrarDisponibilidad();
    bus02.mostrarDisponibilidad();
    lancha01.mostrarDisponibilidad();
    lancha02.mostrarDisponibilidad();

    bus01.iniciarViaje();
    bus02.iniciarViaje();
    lancha01.iniciarViaje();
    lancha02.iniciarViaje();
    return 0;
}