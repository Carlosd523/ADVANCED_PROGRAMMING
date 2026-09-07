#include <iostream>
#include "Funciones.h"

using namespace std;

int main()
{
    // Declaración de variables
    int optMenu = 0;

    // Menú
    do {
        cout << "=============== RECURSIVIDAD Y PUNTEROS ===============" << endl;
        cout << "Usted puede realizar lo siguiente con un número"
            << "\n1. Calcular la potencia"
            << "\n2. Contar los dígitos"
            << "\n3. Invertirlo"
            << "\n4. Sumar los dígitos"
            << "\n5. Obtener el dígito mayor"
            << "\n6. Salir" << endl;
        cout << "Ingrese la opción que desea hacer: ";
        validacionInt(optMenu, 1, 6);
        limpiarPantalla();

        // Arreglo de puntero a funciones
        void(*opcionesMenu[5])() = {
            menu1,
            menu2,
            menu3,
            menu4,
            menu5
        };
 
        (*opcionesMenu[optMenu - 1])();
    } while (optMenu != 6);
}