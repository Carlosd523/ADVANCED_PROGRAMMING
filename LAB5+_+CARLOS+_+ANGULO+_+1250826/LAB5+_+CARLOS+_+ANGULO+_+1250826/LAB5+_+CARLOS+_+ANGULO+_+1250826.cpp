// Bibliotecas
#include <iostream>
#include <string>
#include "Errores.h"
#include "Cliente.h"
#include "Tanque.h"
#include "TanqueCubico.h"
#include "TanqueEsferico.h"
#include "TanqueCilindrico.h"
#include "TanqueCilindricoHueco.h"
#include "Factura.h"

using namespace std;

// FUNCIONES
// Función 1 - Validación de un entero
void ValidacionEntero(int& numero, int min, int max) {
    bool validacion = false;
    do {
        try {
            cin >> numero;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw DatosInvalidosException();
            }
            else if (numero < min || numero > max) {
                throw DimensionesNoValidasException(numero);
            }
            else {
                validacion = true;
            }
        }
        catch (DatosInvalidosException& e) {
            cout << e.what() << endl;
            cout << "Intente nuevamente: ";
        }
        catch (DimensionesNoValidasException& e) {
            cout << e.what() << endl;
            cout << "Intente nuevamente: ";
        }
    } while (!validacion);
}

// Función 2 - Validación de un decimal
void ValidacionDecimal(double& numero, double min, double max) {
    bool validacion = false;
    do {
        try {
            cin >> numero;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw DatosInvalidosException();
            }
            else if (numero <= min || numero > max) {
                throw DimensionesNoValidasException(numero);
            }
            else {
                validacion = true;
            }
        }
        catch (DatosInvalidosException& e) {
            cout << e.what() << endl;
            cout << "Intente nuevamente: ";
        }
        catch (DimensionesNoValidasException& e) {
            cout << e.what() << endl;
            cout << "Intente nuevamente: ";
            }
    } while (!validacion);
}

// Función 3 - Limpia la consola
void LimpiarPantalla() {
    cout << "Presione Enter para continuar...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    system("cls");
}

int main()
{
    // Declaración de variables
    Cliente cliente;
    TanqueCubico cubicos[5];
    TanqueEsferico esfericos[5];
    TanqueCilindrico cilindricos[5];
    TanqueCilindricoHueco huecos[5];
    int contCubicos = 0, contEsfericos = 0, contCilindricos = 0, contHuecos = 0;
    string nombre, direccion;
    int telefono;
    int optMenu;
    double lado, radio, radioExterior, radioInterior, altura;

    // Creación de cliente
    cout << "BIENVENIDO A LA VENTA DE TANQUES DEL SEÑOR ANGULO" << endl;
    cout << "Para iniciar, por favor ingrese su nombre: ";
    cin >> nombre;
    cout << "Por favor ingrese su dirección: ";
    cin >> direccion;
    cout << "Por favor ingrese su número teléfonico: ";
    ValidacionEntero(telefono, 10000000, 99999999);
    cliente = Cliente(nombre, direccion, telefono);
    cout << "Resumen del cliente" << endl;
    cliente.mostrarInfo();
    LimpiarPantalla();

    // Menú para comprar tanques
    do {
        cout << "A continuación puede comprar sus tanques, decida cuáles comprar" << endl;
        cout << "Solamente puede comprar 5 tanques por tipo" << endl;
        cout << "1. Tanque Cúbico"
            << "\n2. Tanque Esférico"
            << "\n3. Tanque Cilíndrico"
            << "\n4. Tanque Cilíndrico Hueco"
            << "\n5. Terminar de comprar" << endl;
        ValidacionEntero(optMenu, 1, 5);
        LimpiarPantalla();

        switch (optMenu) {
        case 1:
            if (contCubicos >= 5) {
                cout << "Límite de tanques cúbicos comprados alcanzados" << endl;
                LimpiarPantalla();
                break;
            }
            cout << "========== Tanque Cúbico ==========" << endl;
            cout << "Ingrese la longitud de los lados para el tanque: ";
            ValidacionDecimal(lado, 0, 100);
            
            cubicos[contCubicos] = TanqueCubico(lado);
            contCubicos++;

            cout << "Tanque comprado exitosamente" << endl;
            LimpiarPantalla();
            break;

        case 2:
            if (contEsfericos >= 5) {
                cout << "Límite de tanques esféricos comprados alcanzado" << endl;
                LimpiarPantalla();
                break;
            }

            cout << "========== Tanque Esférico ==========" << endl;
            cout << "Ingrese el radio del tanque: ";
            ValidacionDecimal(radio, 0, 100);

            esfericos[contEsfericos] = TanqueEsferico(radio);
            contEsfericos++;

            cout << "Tanque comprado exitosamente" << endl;
            LimpiarPantalla();
            break;

        case 3:
            if (contCilindricos >= 5) {
                cout << "Límite de tanques cilíndricos comprados alcanzado" << endl;
                LimpiarPantalla();
                break;
            }

            cout << "========== Tanque Cilíndrico ==========" << endl;
            cout << "Ingrese el radio del tanque: ";
            ValidacionDecimal(radio, 0, 100);

            cout << "Ingrese la altura del tanque: ";
            ValidacionDecimal(altura, 0, 100);

            cilindricos[contCilindricos] = TanqueCilindrico(radio, altura);
            contCilindricos++;

            cout << "Tanque comprado exitosamente" << endl;
            LimpiarPantalla();
            break;

        case 4:
            if (contHuecos >= 5) {
                cout << "Límite de tanques cilíndricos huecos comprados alcanzado" << endl;
                LimpiarPantalla();
                break;
            }

            cout << "===== Tanque Cilíndrico Hueco =====" << endl;

            bool continuar = false;
            do {
                try {
                    cout << "Ingrese el radio exterior del tanque: ";
                    ValidacionDecimal(radioExterior, 0, 100);

                    cout << "Ingrese el radio interior del tanque: ";
                    ValidacionDecimal(radioInterior, 0, 100);

                    if (radioExterior <= radioInterior) {
                        throw RadioExteriorEsMenorException(radioExterior, radioInterior);
                    }

                    continuar = true;
                }
                catch (RadioExteriorEsMenorException& e) {
                    cout << e.what() << endl;
                    cout << "Intente nuevamente" << endl;
                }
            } while (!continuar);

            cout << "Ingrese la altura del tanque: ";
            ValidacionDecimal(altura, 0, 100);

            huecos[contHuecos] = TanqueCilindricoHueco(radioExterior, radioInterior, altura);
            contHuecos++;

            cout << "Tanque comprado exitosamente" << endl;
            LimpiarPantalla();
            break;
        }
    } while (optMenu != 5);

    Factura factura = Factura(cliente);

    factura.mostrarEncabezado();

    // Tanques cúbicos
    for (int i = 0; i < contCubicos; i++) {
        factura.mostrarTanque(cubicos[i]);
        cout << "===============================" << endl;
    }

    // Tanques esféricos
    for (int i = 0; i < contEsfericos; i++) {
        factura.mostrarTanque(esfericos[i]);
        cout << "===============================" << endl;
    }

    // Tanques cilíndricos
    for (int i = 0; i < contCilindricos; i++) {
        factura.mostrarTanque(cilindricos[i]);
        cout << "===============================" << endl;
    }

    // Tanques cilíndricos huecos
    for (int i = 0; i < contHuecos; i++) {
        factura.mostrarTanque(huecos[i]);
        cout << "===============================" << endl;
    }

    factura.mostrarFinal();
}