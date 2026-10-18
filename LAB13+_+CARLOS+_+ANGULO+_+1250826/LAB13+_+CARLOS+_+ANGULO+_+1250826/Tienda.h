#pragma once
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"

class Tienda
{
private:
	Lista<Pelicula> catalogoPeliculas;
	Lista<Cliente> clientes;
	Lista<Alquiler> historialAlquileres;
	Pila devoluciones;
	Cola solicitudesReserva;

public:
	// Constructor - Se realiza la sobrecarga de películas y clientes
	Tienda();

	// Gestionar la tienda
	void gestionarTienda();

	// Agregar películas al catálogo
	void agregarPelicula();

	// Eliminar películas del catálogo
	void eliminarPelicula();
	
	// Registrar cliente nuevo
	void registrarCliente();

	// Registrar un alquiler
	void registrarAlquiler();

	// Registrar una devolución
	void registrarDevolucion();

	// Procesar un cliente en espera
	void atenderClienteEspera();

	// Realizar el alquiler
	void realizarAlquiler(Pelicula* p, Cliente* c);

	// Mostrar catálogo de películas
	void mostrarCatalogo();

	// Mostrar clientes
	void mostrarClientes();

	// Mostrar historial de alquileres
	void mostrarHistorial();

	// Mostrar devoluciones
	void mostrarDevoluciones();

	// Mostrar solicitudes de reserva
	void mostrarSolicitudes();

	// Menú para métodos de ordenamiento
	void metodosOrdenamiento();

	// Pedir resultado
	template <typename T>
	T* pedirElemento(Lista<T>& lista, const string& mensaje);
};