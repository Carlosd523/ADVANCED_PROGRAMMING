#include "Funciones.h"
#include <iostream>

using namespace std;

// Función 01 - Valida la entrada de un dato tipo int.
void validacionInt(int& num, int min, int max) {
	bool validacion = false;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw DatoInvalido();
			}
			else if (num < min || num > max) {
				throw DatoFueraDelRango(num, min, max);
			}
			else {
				validacion = true;
			}
		}
		catch (DatoInvalido& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
		catch (DatoFueraDelRango& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
		}
	} while (!validacion);
}

// Función 02 - Limpia la pantalla.
void limpiarPantalla() {
	cout << "Presione Enter para continuar...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	system("cls");
}

// Función 03 - Menú
void menu() {

	List* lista = new List();

	// Arreglo de punteros a funciones
	void(*menu[12])(List*& lista) = {
		&usoAdd,
		&usoClear,
		&usoCount,
		&usoContains,
		&usoIndexOf,
		&usoInsert,
		&usoGetItem,
		&usoSetItem,
		&usoLastIndexOf,
		&usoRemove,
		&usoRemoveAt,
		&usoShowList
	};

	int optMenu = 0;

	cout << "=============== USO DE LISTAS ===============" << endl;
	do{
		cout << "¿Qué método de la lista desea probar?"
			<< "\n1. Add"
			<< "\n2. Clear"
			<< "\n3. Count"
			<< "\n4. Contains"
			<< "\n5. IndexOf"
			<< "\n6. Insert"
			<< "\n7. GetItem"
			<< "\n8. SetItem"
			<< "\n9. LasIndexOf"
			<< "\n10. Remove"
			<< "\n11. RemoveAt"
			<< "\n12. ShowList"
			<< "\n13. Salir"
			<< "\nIngrese lo que desea hacer: ";
		validacionInt(optMenu, 1, 13);
		limpiarPantalla();
		(*menu[optMenu - 1])(lista);
	} while (optMenu != 13);

	lista->~List();
	delete lista;
}

// Función Menú #1 - Uso de Add
void usoAdd(List*& lista) {
	int numeroAgregar;

	cout << "========== ADD ==========" << endl;
	cout << "Ingrese el número que desea agregar (-1000, 1000): ";
	validacionInt(numeroAgregar, -1000, 1000);

	lista->Add(numeroAgregar);
	limpiarPantalla();
}

// Función Menú #2 - Uso de Clear
void usoClear(List*& lista) {
	cout << "========== CLEAR ==========" << endl;
	lista->Clear();
	limpiarPantalla();
}

// Función Menú #3 - Uso de Count
void usoCount(List*& lista) {
	cout << "======== COUNT ========" << endl;
	cout << "La lista contiene " << lista->Count() << " elementos" << endl;
	limpiarPantalla();
}

// Función Menú #4 - Uso de Contains
void usoContains(List*& lista) {
	int numeroDeseado;

	cout << "======== CONTAINS ========" << endl;
	cout << "Ingrese el número que desea buscar (-1000, 1000): ";
	validacionInt(numeroDeseado, -1000, 1000);

	if (lista->Contains(numeroDeseado)) {
		cout << "El número " << numeroDeseado << " se encuentra en la lista" << endl;
	}
	else {
		cout << "El número " << numeroDeseado << " no es parte de la lista" << endl;
	}
	limpiarPantalla();
}

// Función Menú #5 - Uso de IndexOf
void usoIndexOf(List*& lista) {
	int numeroDeseado;

	cout << "======== INDEXOF ========" << endl;
	cout << "Ingrese el número que desea buscar (-1000, 1000): ";
	validacionInt(numeroDeseado, -1000, 1000);

	if (lista->IndexOf(numeroDeseado) == -1) {
		cout << "No hay ningún elemento que contenga el número ingresado" << endl;
	}
	else {
		cout << "El número " << numeroDeseado << " se encuentra en la posición " << lista->IndexOf(numeroDeseado) << endl;
	}
	limpiarPantalla();
}

// Función Menú #6 - Uso de Insert
void usoInsert(List*& lista) {
	int numeroInsertar;
	int indiceInsercion;

	cout << "======== INSERT ========" << endl;
	cout << "Ingrese el número que desea insertar (-1000, 1000): ";
	validacionInt(numeroInsertar, -1000, 1000);
	cout << "Ingrese la posición en la que desea insertarlo: ";
	validacionInt(indiceInsercion, 1, 1000);
	lista->Insert(indiceInsercion, numeroInsertar);
	limpiarPantalla();
}

// Función Menú #7 - Uso de GetItem
void usoGetItem(List*& lista) {
	int indice;

	cout << "========== GETITEM ==========" << endl;
	cout << "Ingrese la posición para obtener el valor que se encuentra ahí: ";
	validacionInt(indice, 1, 1000);
	cout << "En la posición " << indice << " se encuentra el valor " << lista->GetItem(indice) << endl;
	limpiarPantalla();
}

// Función Menú #8 - Uso de SetItem
void usoSetItem(List*& lista) {
	int nuevaData, indice;
	
	cout << "========== SETITEM ==========" << endl;
	cout << "Ingrese el nuevo dato que desea ingresar: ";
	validacionInt(nuevaData, -1000, 1000);
	cout << "Ingrese la posición en la que quiera poner el nuevo dato: ";
	validacionInt(indice, 1, 1000);
	lista->SetItem(indice, nuevaData);
	limpiarPantalla();
}

// Función Menú #9 - Uso de LastIndexOf
void usoLastIndexOf(List*& lista) {
	int dato;

	cout << "========== LASTINDEXOF ==========" << endl;
	cout << "Ingrese el número que desea buscar en la lista: ";
	validacionInt(dato, -1000, 1000);
	cout << "La última coincidencia en la lista del número " << dato << " se encuentra en la posición " << lista->LastIndexOf(dato) + 1 << endl;
	limpiarPantalla();
}

// Función Menú #10 - Uso de Remove
void usoRemove(List*& lista) {
	int dato;

	cout << "========== REMOVE ==========" << endl;
	cout << "Ingrese el dato que desea eliminar: ";
	validacionInt(dato, -1000, 1000);
	if (lista->Remove(dato)) {
		cout << "Elemento borrado exitosamente" << endl;
	}
	else {
		cout << "No se encontró ninguna coincidencia, por lo tanto, ningún elemento fue borrado" << endl;
	}
	limpiarPantalla();
}

// Función Menú #11 - Uso de RemoveAt
void usoRemoveAt(List*& lista) {
	int indice;

	cout << "========== REMOVEAT ==========" << endl;
	cout << "Ingrese la posición que desea eliminar: ";
	validacionInt(indice, 0, 1000);
	lista->RemoveAt(indice);
	limpiarPantalla();
}

// Función Menú #12 - Uso de ShowList
void usoShowList(List*& lista) {
	cout << "========== SHOWLIST ==========" << endl;
	lista->ShowList();
	limpiarPantalla();
}