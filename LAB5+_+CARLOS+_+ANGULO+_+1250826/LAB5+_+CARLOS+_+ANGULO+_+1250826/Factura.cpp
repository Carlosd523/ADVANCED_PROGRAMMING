#include "Factura.h"
#include <iostream>

using namespace std;

Factura::Factura(Cliente cliente) {
	this->cliente = cliente;
}

void Factura::mostrarEncabezado() {
	cout << " ========== FACTURA ==========" << endl;
	cliente.mostrarInfo();
	cout << "Productos adquiridos:" << endl;
}

void Factura::mostrarTanque(TanqueCubico tanque) {
	cout << "Tipo de tanque: Cúbico"
		<< "\nVolumen: " << tanque.getVolumen()
		<< "\nPrecio: Q" << tanque.getPrecio() << endl;
	total += tanque.getPrecio();
}

void Factura::mostrarTanque(TanqueEsferico tanque) {
	cout << "Tipo de tanque: Esférico"
		<< "\nVolumen: " << tanque.getVolumen()
		<< "\nPrecio: Q" << tanque.getPrecio() << endl;
	total += tanque.getPrecio();
}

void Factura::mostrarTanque(TanqueCilindrico tanque) {
	cout << "Tipo de tanque: Cilíndrico"
		<< "\nVolumen: " << tanque.getVolumen()
		<< "\nPrecio: Q" << tanque.getPrecio() << endl;
	total += tanque.getPrecio();
}

void Factura::mostrarTanque(TanqueCilindricoHueco tanque) {
	cout << "Tipo de tanque: Cilíndrico hueco"
		<< "\nVolumen: " << tanque.getVolumen()
		<< "\nPrecio: Q" << tanque.getPrecio() << endl;
	total += tanque.getPrecio();
}

void Factura::mostrarFinal() {
	cout << "Total gastado: Q" << total << endl;
}