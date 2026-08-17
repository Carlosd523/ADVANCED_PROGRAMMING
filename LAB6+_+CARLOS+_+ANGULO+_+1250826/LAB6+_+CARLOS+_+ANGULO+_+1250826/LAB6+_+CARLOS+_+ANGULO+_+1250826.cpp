#include <iostream>
#include "Comic.h"
#include "Funciones.h"

using namespace std;

int main()
{
    // Declaración de Variables
    int optMenu = 0;
    Comic* c1 = nullptr;
    Comic* c2 = nullptr;
    Comic* c3 = nullptr;
    Comic* c4 = nullptr;
    Comic* c5 = nullptr;

    string titulo, editorial, codigoBarras, genero;
    int issue, anyoPublicacion;
    double precio;
    bool edicionLimitada;
    char estado;

    cout << "========== BIENVENIDO A LA TIENDA DE COMICS ANGULO ==========" << endl;
    do {
        // Menú interactivo
        cout << "¿Qué desea hacer?"
            << "\n1. Registrar Comic"
            << "\n2. Mostrar commics"
            << "\n3. Buscar comic"
            << "\n4. Eliminar comic"
            << "\n5. Salir" << endl;
        validacionInt(optMenu, 1, 5);
        limpiarPantalla();

        // Opciones del menú
        switch (optMenu) {
        case 1: {
            // Este bloque if evita ejectuar el resto del código del caso 1 en vano
            if (!punteroVacio(c1) && !punteroVacio(c2) && !punteroVacio(c3) && !punteroVacio(c4) && !punteroVacio(c5)) {
                cout << "No se pueden registrar más comics" << endl;
                limpiarPantalla();
                break;
            }

            cout << "=============== REGISTRAR COMIC ===============" << endl;
            cout << "Ingrese el título del comic: ";
            cin >> titulo;
            cout << "Ingrese la editorial del comic: ";
            cin >> editorial;
            cout << "Ingrese el número de edición del comic: ";
            validacionInt(issue, 1, 1000);
            bool avanzar = false;
            while (!avanzar) {
                cout << "Ingrese el código de barras del comic (12 dígitos): ";
                validacionCodigoBarras(codigoBarras);

                if (coincidenciaCodigoBarras(c1, codigoBarras)) { continue; }
                else if (coincidenciaCodigoBarras(c2, codigoBarras)) { continue; }
                else if (coincidenciaCodigoBarras(c3, codigoBarras)) { continue; }
                else if (coincidenciaCodigoBarras(c4, codigoBarras)) { continue; }
                else if (coincidenciaCodigoBarras(c5, codigoBarras)) { continue; }
                else { avanzar = true; }
            }
            cout << "Ingrese el precio del comic: ";
            validacionDouble(precio, 1, 20000);
            /* La selección de que el año mínimo para publicar un comic sea 1837,
            * se debe a que este fue el año en el que se publicó el primer comic de la historia según Google.
            * El primer comic de la historia se titula Los Amores del señor Vieux */
            cout << "Ingrese el año de publicación: ";
            validacionInt(anyoPublicacion, 1837, 2026);
            int optEstado = 0;
            cout << "Ingrese el estado de conservación del comic"
                << "\n1. Nuevo"
                << "\n2. Usado - Bueno"
                << "\n3. Usado - Regular" << endl;
            validacionInt(optEstado, 1, 3);
            if (optEstado == 1) {
                estado = 'N';
            }
            else if (optEstado == 2) {
                estado = 'B';
            }
            else {
                estado = 'R';
            }
            int optEdicion = 0;
            cout << "¿El comic es edición limitada?"
                << "\n1. Sí"
                << "\n2. No" << endl;
            validacionInt(optEdicion, 1, 2);
            if (optEdicion == 1) {
                edicionLimitada = true;
            }
            else {
                edicionLimitada = false;
            }
            cout << "Ingrese el género del comic: ";
            cin >> genero;
            limpiarPantalla();

            Comic* nuevoComic = new Comic(titulo, editorial, issue, codigoBarras, precio, anyoPublicacion, edicionLimitada, genero);
            if (intentarRegistrar(c1, nuevoComic)) { break; }
            if (intentarRegistrar(c2, nuevoComic)) { break; }
            if (intentarRegistrar(c3, nuevoComic)) { break; }
            if (intentarRegistrar(c4, nuevoComic)) { break; }
            if (intentarRegistrar(c5, nuevoComic)) { break; }
            break;
        }
        case 2: {
            // Este bloque if evita ejectuar el resto del código del caso 1 en vano
            if (punteroVacio(c1) && punteroVacio(c2) && punteroVacio(c3) && punteroVacio(c4) && punteroVacio(c5)) {
                cout << "No se han registrado comics" << endl;
                limpiarPantalla();
                break;
            }

            cout << "=============== MOSTRAR INFORMACIÓN DE LOS COMICS ===============" << endl;
            if (!punteroVacio(c1)) { c1->mostrarInformacion(); }
            if (!punteroVacio(c2)) { c2->mostrarInformacion(); }
            if (!punteroVacio(c3)) { c3->mostrarInformacion(); }
            if (!punteroVacio(c4)) { c4->mostrarInformacion(); }
            if (!punteroVacio(c5)) { c5->mostrarInformacion(); }
            limpiarPantalla();
            break;
        }
        case 3: {
            // Este bloque if evita ejectuar el resto del código del caso 1 en vano
            if (punteroVacio(c1) && punteroVacio(c2) && punteroVacio(c3) && punteroVacio(c4) && punteroVacio(c5)) {
                cout << "No se han registrado comics" << endl;
                break;
                limpiarPantalla();
            }
            int coincidencias = 0;
            int optBusqueda = 0;
            cout << "=============== BUSCAR COMIC ===============" << endl;
            cout << "¿Qué característica desea filtrar?"
                << "\n1. Título"
                << "\n2. Código de barras"
                << "\n3. Editorial"
                << "\n4. Número de edición" << endl;
            validacionInt(optBusqueda, 1, 4);
            switch (optBusqueda) {
            case 1: {
                cout << "Ingrese el título del comic: ";
                cin >> titulo;

                revisarTitulo(c1, titulo, coincidencias);
                revisarTitulo(c2, titulo, coincidencias);
                revisarTitulo(c3, titulo, coincidencias);
                revisarTitulo(c4, titulo, coincidencias);
                revisarTitulo(c5, titulo, coincidencias);
                break;
            }
            case 2: {
                cout << "Ingrese el código de barras del comic: ";
                cin >> codigoBarras;

                revisarCodigoBarras(c1, codigoBarras, coincidencias);
                revisarCodigoBarras(c2, codigoBarras, coincidencias);
                revisarCodigoBarras(c3, codigoBarras, coincidencias);
                revisarCodigoBarras(c4, codigoBarras, coincidencias);
                revisarCodigoBarras(c5, codigoBarras, coincidencias);

                break;
            }
            case 3: {
                cout << "Ingrese la editorial del comic: ";
                cin >> editorial;

                revisarEditorial(c1, editorial, coincidencias);
                revisarEditorial(c2, editorial, coincidencias);
                revisarEditorial(c3, editorial, coincidencias);
                revisarEditorial(c4, editorial, coincidencias);
                revisarEditorial(c5, editorial, coincidencias);

                break;
            }
            case 4: {
                cout << "Ingrese el número de edición del comic: ";
                validacionInt(issue, 1, 1000);

                revisarIssue(c1, issue, coincidencias);
                revisarIssue(c2, issue, coincidencias);
                revisarIssue(c3, issue, coincidencias);
                revisarIssue(c4, issue, coincidencias);
                revisarIssue(c5, issue, coincidencias);
            }
            }

            if (coincidencias == 0) {
                cout << "No hubo coincidencias" << endl;
            }
            coincidencias = 0;
            limpiarPantalla();
            break;

        }
        case 4:
            if (punteroVacio(c1) && punteroVacio(c2) && punteroVacio(c3) && punteroVacio(c4) && punteroVacio(c5)) {
                cout << "No hay comics registrados para eliminar." << endl;
                limpiarPantalla();
                break;
            }

            bool eliminado = false;
            int optEliminar = 0;

            cout << "=============== ELIMINAR COMIC ===============" << endl;
            cout << "¿Por qué criterio desea eliminar?"
                << "\n1. Título"
                << "\n2. Código de barras"
                << "\n3. Editorial"
                << "\n4. Número de edición" << endl;
            validacionInt(optEliminar, 1, 4);

            switch (optEliminar) {
            case 1: {
                cout << "Ingrese el título a eliminar: ";
                cin >> titulo;
                eliminarPorTitulo(c1, titulo, eliminado);
                eliminarPorTitulo(c2, titulo, eliminado);
                eliminarPorTitulo(c3, titulo, eliminado);
                eliminarPorTitulo(c4, titulo, eliminado);
                eliminarPorTitulo(c5, titulo, eliminado);
                break;
            }
            case 2: {
                cout << "Ingrese el código de barras a eliminar: ";
                cin >> codigoBarras;
                eliminarPorCodigoBarras(c1, codigoBarras, eliminado);
                eliminarPorCodigoBarras(c2, codigoBarras, eliminado);
                eliminarPorCodigoBarras(c3, codigoBarras, eliminado);
                eliminarPorCodigoBarras(c4, codigoBarras, eliminado);
                eliminarPorCodigoBarras(c5, codigoBarras, eliminado);
                break;
            }
            case 3: {
                cout << "Ingrese la editorial a eliminar: ";
                cin >> editorial;
                eliminarPorEditorial(c1, editorial, eliminado);
                eliminarPorEditorial(c2, editorial, eliminado);
                eliminarPorEditorial(c3, editorial, eliminado);
                eliminarPorEditorial(c4, editorial, eliminado);
                eliminarPorEditorial(c5, editorial, eliminado);
                break;
            }
            case 4: {
                cout << "Ingrese el número de edición a eliminar: ";
                validacionInt(issue, 1, 1000);
                eliminarPorIssue(c1, issue, eliminado);
                eliminarPorIssue(c2, issue, eliminado);
                eliminarPorIssue(c3, issue, eliminado);
                eliminarPorIssue(c4, issue, eliminado);
                eliminarPorIssue(c5, issue, eliminado);
                break;
            }
            }

            if (!eliminado) {
                cout << "No se eliminó ningún comic." << endl;
            }
            limpiarPantalla();
            break;
        }
        
    } while (optMenu != 5);

    // Se borran los punteros para liberar memoria
    delete c1; c1 = nullptr;
    delete c2; c2 = nullptr;
    delete c3; c3 = nullptr;
    delete c4; c4 = nullptr;
    delete c5; c5 = nullptr;

    return 0;
}