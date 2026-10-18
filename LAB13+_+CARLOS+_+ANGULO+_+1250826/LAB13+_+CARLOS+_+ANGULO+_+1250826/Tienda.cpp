#include "Tienda.h"
#include "Funciones.h"
#include <iostream>

Tienda::Tienda() {
    Pelicula peliculas[] = {
    Pelicula("THE MATRIX", "CIENCIA FICCION", 3.50, 1999, 5),
    Pelicula("TITANIC", "ROMANCE", 3.00, 1997, 4),
    Pelicula("EL PADRINO", "CRIMEN", 3.50, 1972, 3),
    Pelicula("JURASSIC PARK", "AVENTURA", 3.00, 1993, 6),
    Pelicula("AVATAR", "CIENCIA FICCION", 4.00, 2009, 7),
    Pelicula("EL REY LEON", "ANIMACION", 2.50, 1994, 8),
    Pelicula("GLADIATOR", "ACCION", 3.50, 2000, 4),
    Pelicula("FORREST GUMP", "DRAMA", 3.00, 1994, 5),
    Pelicula("INTERESTELAR", "CIENCIA FICCION", 4.00, 2014, 6),
    Pelicula("BATMAN: EL CABALLERO DE LA NOCHE", "ACCION", 4.00, 2008, 5)
    };

    for (int i = 0; i < 10; i++) {
        catalogoPeliculas.agregarElemento(peliculas[i]);
    }

    Cliente c[] = {
    Cliente("CARLOS MENDEZ", "1001", "carlos.mendez@email.com"),
    Cliente("ANA LOPEZ", "1002", "ana.lopez@email.com"),
    Cliente("JOSE RAMIREZ", "1003", "jose.ramirez@email.com"),
    Cliente("MARIA GARCIA", "1004", "maria.garcia@email.com"),
    Cliente("LUIS HERNANDEZ", "1005", "luis.hernandez@email.com")
    };

    for (int i = 0; i < 5; i++) {
        clientes.agregarElemento(c[i]);
    }
}

// Gestionar la tienda
void Tienda::gestionarTienda() {
    int optMenu = 0;

    // Arreglo de punteros a funciones
    void (Tienda::*menu[12])() = {
        &Tienda::agregarPelicula,
        &Tienda::eliminarPelicula,
        &Tienda::registrarCliente,
        &Tienda::registrarAlquiler,
        &Tienda::registrarDevolucion,
        &Tienda::atenderClienteEspera,
        &Tienda::mostrarCatalogo,
        &Tienda::mostrarClientes,
        &Tienda::mostrarHistorial,
        &Tienda::mostrarDevoluciones,
        &Tienda::mostrarSolicitudes,
        &Tienda::metodosOrdenamiento
    };

    cout << "BIENVENIDO A LA TIENDA DE PELÍCULAS MÁS FAMOSA DEL BARRIO"
        << "\nTU TRABAJO SERÁ GESTIONAR LA TIENDA" << endl;
    cout << "Puedes realizar cualquiera de las siguientes opciones:" << endl;
    do {
        cout << "1. Agrear una película al catálogo"
            << "\n2. Eliminar una película del catálogo"
            << "\n3. Registrar un cliente nuevo"
            << "\n4. Registrar un alquiler"
            << "\n5. Registrar una devolución"
            << "\n6. Procesar solicitud del primer cliente en cola"
            << "\n7. Mostrar catálogo"
            << "\n8. Mostrar clientes"
            << "\n9. Mostrar historial de alquileres"
            << "\n10. Mostrar alquileres activos"
            << "\n11. Mostrar clientes en espera"
            << "\n12. Ordenar las películas"
            << "\n13. Salir" << endl;
        cout << "Ingrese la opción que desea realizar: ";
        validacionInt(optMenu, 1, 13);
        limpiarPantalla();
        if (optMenu < 13) { (this->*menu[optMenu - 1])(); }
        limpiarPantalla();
    } while (optMenu != 13);
}

// Agregar películas al catálogo
void Tienda::agregarPelicula() {
    string nombre, genero;
    double precioAlquiler;
    int anyoEstreno, copiasDisponibles;
    cout << "=============== AGREGAR PELíCULA ===============" << endl;
    cout << "Ingrese el nombre de la película: ";
    do {
        validacionString(nombre);
        aMayusculas(nombre);
        if (catalogoPeliculas.existe(nombre)) {
            cout << "Esta película ya está incluida en el catálogo, por favor, ingrese otro nombre: ";
        }
    } while (catalogoPeliculas.existe(nombre));

    cout << "Ingrese el género de la película: ";
    validacionString(genero);
    aMayusculas(genero);

    cout << "Ingrese el precio de alquiler de la película: Q";
    validacionDouble(precioAlquiler, 1, 5);

    cout << "Ingrese el año de estreno de la película: ";
    validacionInt(anyoEstreno, 1888, 2026);

    cout << "Ingrese las copias disponibles: ";
    validacionInt(copiasDisponibles, 1, 20);

    Pelicula peliculaAgregar = Pelicula(nombre, genero, precioAlquiler, anyoEstreno, copiasDisponibles);

    catalogoPeliculas.agregarElemento(peliculaAgregar);
    cout << "Película agregada exitosamente" << endl;
}

// Eliminar películas del catálogo
void Tienda::eliminarPelicula() {
    cout << "=============== ELIMINAR PELÍCULA ===============" << endl;
    if (catalogoPeliculas.getHeader() == nullptr) {
        cout << "No hay películas en el catálogo" << endl;
        return;
    }

    string nombre;
    cout << "Películas que se encuentran en el catálogo" << endl;
    catalogoPeliculas.mostrarElementos();
    cout << "Ingrese el nombre de la película que desea eliminar: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    validacionString(nombre);
    catalogoPeliculas.eliminarElemento(nombre);
}

// Registrar cliente nuevo
void Tienda::registrarCliente() {
    string nombre, Id, correo;
    cout << "=============== REGISTRAR CLIENTE ===============" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese el nombre del cliente: ";
    validacionString(nombre);
    cout << "Ingrese el ID del cliente: ";
    do {
        validacionString(Id);
        if (catalogoPeliculas.existe(Id)) {
            cout << "Este ID ya le pertenece a otr cliente, por favor, ingrese otro ID: ";;
        }
    } while (!clientes.existe(Id));
    cout << "Ingrese el correo electrónico del cliente: ";
    cin >> correo;

    Cliente clienteNuevo = Cliente(nombre, Id, correo);
    clientes.agregarElemento(clienteNuevo);
}

// Registrar un alquiler
void Tienda::registrarAlquiler() {
    Pelicula* p = nullptr;
    Cliente* c = nullptr;

    cout << "=============== REGISTRAR ALQUILER ===============" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clientes.mostrarElementos();
    c = pedirElemento(clientes, "Ingrese el ID del cliente que desea ser atendido: ");

    catalogoPeliculas.mostrarElementos();
    p = pedirElemento(catalogoPeliculas, "Ingrese el nombre de la película que se alquilará: ");

    if (p->getCopiasDisponibles() == 0) {
        cout << "La película no cuenta con copias disponibles actualmente"
            << "\nEl cliente se agregará a la cola de usuarios en espera" << endl; 
        solicitudesReserva.agregarCliente(c);
        return;
    }

    realizarAlquiler(p, c);
}

// Registrar una devolución
void Tienda::registrarDevolucion() {
    string fechaDevolucion;
    Alquiler* alquilerDevuelto = devoluciones.getCima();

    cout << "=============== REGISTRAR DEVOLUCIÓN ===============" << endl;

    if (alquilerDevuelto == nullptr) {
        cout << "No se han hecho alquileres" << endl;
        return;
    }

    cout << "Ingrese la fecha de devolución: ";
    validacionString(fechaDevolucion);
    alquilerDevuelto->setFechaDevolucion(fechaDevolucion);
    alquilerDevuelto->getPelicula()->setCopiasDisponibles(alquilerDevuelto->getPelicula()->getCopiasDisponibles() + 1);
    devoluciones.popAlquiler();
    cout << "Devolución registrada exitosamente" << endl;
}

// Procesar un cliente en espera
void Tienda::atenderClienteEspera() {
    Cliente* c = solicitudesReserva.getFrente();
    Pelicula* p = nullptr;
    cout << "=============== ATENDER CLIENTE EN ESPERA ===============" << endl;

    if (c == nullptr) {
        cout << "No hay clientes en espera" << endl;
        return;
    }

    catalogoPeliculas.mostrarElementos();
    p = pedirElemento(catalogoPeliculas, "Ingrese el nombre de la película que el cliente en espera desea alquilar: ");

    if (p->getCopiasDisponibles() == 0) {
        cout << "La película aún no cuenta con copias disponibles" << endl;
        return;
    }

    realizarAlquiler(p, c);
    solicitudesReserva.atenderCliente();
}

// Realizar el alquiler
void Tienda::realizarAlquiler(Pelicula* p, Cliente* c) {
    string fechaAlquiler;
    double montoTotal;

    cout << "Ingrese la fecha de alquiler: ";
    validacionString(fechaAlquiler);

    montoTotal = p->getPrecioAlquiler();
    cout << "Monto total: Q" << montoTotal << endl;

    Alquiler alquiler(p, c, fechaAlquiler, montoTotal);
    Alquiler* a = historialAlquileres.agregarElemento(alquiler);
    p->setCopiasDisponibles(p->getCopiasDisponibles() - 1);
    devoluciones.pushAlquiler(a);
    cout << "Alquiler agregado correctamente" << endl;
}

// Mostrar catálogo de películas
void Tienda::mostrarCatalogo() {
    cout << "=============== MOSTRAR CATÁLOGO ===============" << endl;
    catalogoPeliculas.mostrarElementos();
}

// Mostrar clientes
void Tienda::mostrarClientes() {
    cout << "=============== MOSTRAR CLIENTES ===============" << endl;
    clientes.mostrarElementos();
}

// Mostrar historial de alquileres
void Tienda::mostrarHistorial() {
    cout << "=============== HISTORIAL ===============" << endl;
    historialAlquileres.mostrarElementos();
}

// Mostrar devoluciones
void Tienda::mostrarDevoluciones() {
    cout << "=============== MOSTRAR ALQUILERES ===============" << endl;
    devoluciones.mostrarPila();
}

// Mostrar solicitudes de reserva
void Tienda::mostrarSolicitudes() {
    cout << "=============== MOSTRAR CLIENTES EN ESPERA ===============" << endl;
    solicitudesReserva.mostrarCola();
}

// Menú para métodos de ordenamiento
void Tienda::metodosOrdenamiento() {
    int optOrdenamiento;
    // Arreglo de punteros a funciones
    void (Lista<Pelicula>::*ordenamientos[4])() = {
        &Lista<Pelicula>::ordenarPorTitulo,
        & Lista<Pelicula>::ordenarPorGenero,
        &Lista<Pelicula>::ordenarPorPrecioAlquiler,
        &Lista<Pelicula>::ordenarPorAnyoEstreno
    };

    cout << "=============== MÉTODOS DE ORDENAMIENTO ===============" << endl;
    cout << "1. Ordenar por título (Bubble Sort)"
        << "\n2. Ordenar por género (Quick Sort)"
        << "\n3. Ordenar por precio de alquiler (Shell Sort)"
        << "\n4. Ordenar por año de estreno (Selection Sort)" << endl;
    cout << "Ingrese la forma por la cual desea ordenar el catálogo: ";
    validacionInt(optOrdenamiento, 1, 4);
    limpiarPantalla();
    cout << "Catálogo antes de ordenar" << endl;
    catalogoPeliculas.mostrarElementos();
    (catalogoPeliculas.*ordenamientos[optOrdenamiento - 1])();
    cout << "Catálogo tras ordenar" << endl;
    catalogoPeliculas.mostrarElementos();
}

// Pedir resultado
template <typename T>
T* Tienda::pedirElemento(Lista<T>& lista, const string& mensaje) {
    string clave;
    T* resultado = nullptr;

    cout << mensaje;
    do {
        validacionString(clave);
        aMayusculas(clave);
        resultado = lista.getElemento(clave);
        if (resultado == nullptr) {
            cout << "No se ha encontrado ninguna coincidencia, intente nuevamente: ";
        }
    } while (resultado == nullptr);

    return resultado;
}