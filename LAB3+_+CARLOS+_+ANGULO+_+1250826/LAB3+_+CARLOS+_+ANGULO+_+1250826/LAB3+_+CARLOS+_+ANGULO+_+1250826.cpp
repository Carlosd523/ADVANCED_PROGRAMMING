// LAB3+_+CARLOS+_+ANGULO+_+1250826.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

// FUNCIONES
// Función 01 - Limpia la pantalla
void LimpiarPantalla() {
	cout << "Presione Enter para continuar...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	system("cls");
}

//Función 02 - Valida un número entero dentro de cierto rango
int validacionEntero(int& numero, int min, int max) {
	bool valido = false;
	do {
		try {
			cin >> numero;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error: Ingrese un número válido");
			}
			else if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido");
			}
			valido = true;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
			valido = false;
		}
	} while (!valido);
	return numero;
}

// Función 03 - Validación decimales
double validacionDouble(double& numero, double min, double max) {
	bool valido = false;
	do {
		try {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numero;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error: Ingrese un número válido (decimal permitido)");
			}
			else if (numero < min || numero > max) {
				throw out_of_range("Error: El número ingresado está fuera del rango permitido");
			}
			valido = true;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << "Intente nuevamente: ";
			valido = false;
		}
	} while (!valido);
	return numero;
}

// CLASES
class IAsistencia {
public:
	virtual void registrarEntrada() = 0;
	virtual void registrarSalida() = 0;

	virtual ~IAsistencia() {};
};

class Empleado : public IAsistencia {
protected:
	string codigo = "";
	string nombre = "";
	int edad = 0;
	string departamento = "";
	double salarioBase = 0.0;
	bool registrado = false;

public:
	Empleado() {};

	Empleado(string codigo, string nombre, int edad, string departamento, double salarioBase) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->edad = edad;
		this->departamento = departamento;
		this->salarioBase = salarioBase;
	}

	virtual void mostrarInformacion() = 0;
	virtual double calcularSalario() = 0;

	void registrarEntrada() override {
		if (registrado == true) { return; }
		else {
			cout << "Empleado " << codigo << " ha registrado su entrada" << endl;
			registrado = true;
		}
	}

	void registrarSalida() override {
		if (registrado == false) { return; }
		else {
			cout << "Empleado " << codigo << " ha registrado su salida" << endl;
			registrado = false;
		}
	}

	string getCodigo() { return codigo; }
	string getNombre() { return nombre; }
	int getEdad() { return edad; }
	string getDepartamento() { return departamento; }
	double getSalarioBase() { return salarioBase; }
	
	void mostrarSalario() {
		cout << fixed << setprecision(2);
		cout << "El salario del empleado " << codigo << " es de: Q" << calcularSalario() << endl;
	}


	virtual ~Empleado() {};
};

class Administrativo : public Empleado {
protected:
	double bonoAdministrativo = 0.0;

public:
	// Constructor por defecto
	Administrativo() {};

	double calcularSalario() override {
		return salarioBase + bonoAdministrativo;
	}

	void mostrarInformacion() override {
		cout << "Empleado: " << codigo
			<< "\nNombre: " << nombre
			<< "\nEdad: " << edad
			<< "\nDepartamento: " << departamento
			<< "\nBono administrativo: " << bonoAdministrativo
			<< "\nSalario: " << to_string(calcularSalario()) << endl;
	}

	void registrarAdministrativo(string codigo, string nombre, int edad, string departamento, double salarioBase, double bonoAdministrativo) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->edad = edad;
		this->departamento = departamento;
		this->salarioBase = salarioBase;
		this->bonoAdministrativo = bonoAdministrativo;
	}

	~Administrativo() {};
};

class Vendedor : public Empleado {
protected:
	int ventas = 0;
	double porcentajeComision = 0.0;

public:
	// Constructor por defecto
	Vendedor() {};

	double calcularSalario() override {
		return salarioBase + (ventas * porcentajeComision);
	}

	void mostrarInformacion() override {
		cout << "Empleado: " << codigo
			<< "\nNombre: " << nombre
			<< "\nEdad: " << edad
			<< "\nDepartamento: " << departamento
			<< "\nVentas: " << ventas
			<< "\nPorcentaje de comisión: " << porcentajeComision 
			<< "\nSalario: " << to_string(calcularSalario()) << endl;
	}

	void registrarVendedor(string codigo, string nombre, int edad, string departamento, double salarioBase, int ventas, double porcentajeComision) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->edad = edad;
		this->departamento = departamento;
		this->salarioBase = salarioBase;
		this->ventas = ventas;
		this->porcentajeComision = porcentajeComision;
	}

	~Vendedor() {};
};

class Operario : public Empleado {
protected:
	int horasExtra = 0;
	double pagoHoraExtra = 0.0;

public:
	// Constructor por defecto
	Operario() {};

	// Constructor con parámetros
	Operario(string codigo, string nombre, int edad, string departamento, double salarioBase, int horasExtra, double pagoHoraExtra)
		:Empleado(codigo, nombre, edad, departamento, salarioBase) {
		this->horasExtra = horasExtra;
		this->pagoHoraExtra = pagoHoraExtra;
	}

	double calcularSalario() override {
		return salarioBase + (horasExtra * pagoHoraExtra);
	}

	void mostrarInformacion() override {
		cout << "Empleado: " << codigo
			<< "\nNombre: " << nombre
			<< "\nEdad: " << edad
			<< "\nDepartamento: " << departamento
			<< "\nHoras extra: " << horasExtra
			<< "\nPago por hora extra: " << pagoHoraExtra
			<< "\nSalario: " << to_string(calcularSalario()) << endl;
	}

	void registrarOperario(string codigo, string nombre, int edad, string departamento, double salarioBase, int horasExtra, double pagoHoraExtra) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->edad = edad;
		this->departamento = departamento;
		this->salarioBase = salarioBase;
		this->horasExtra = horasExtra;
		this->pagoHoraExtra = pagoHoraExtra;
	}

	~Operario() {};
};
int main()
{
	int cantEmpleados = 0, cantAdmin = 0, cantVendedor = 0, cantOperario = 0;
	int optMenu;
	string codigo, nombre, departamento;
	int edad;
	Administrativo administrativos[10];
	Vendedor vendedores[10];
	Operario operarios[10];

	do {
		cout << "========= ANGULO'S BUSINESS =========" 
			<< "\n1. Registrar empleado"
			<< "\n2. Mostrar empleados"
			<< "\n3. Registrar entrada"
			<< "\n4. Registrar salida"
			<< "\n5. Mostrar salarios"
			<< "\n6. Mostrar total de planilla"
			<< "\n7. Salir" << endl;
		validacionEntero(optMenu, 1, 7);
		LimpiarPantalla();
		switch (optMenu) {
		case 1:
			cout << "========= REGISTRAR EMPLEADO =========" << endl;
			int optEmpleado;
			do {
				cout << "1. Administrativo"
					<< "\n2. Vendedor"
					<< "\n3. Operario"
					<< "\n4. Salir" << endl;
				validacionEntero(optEmpleado, 1, 4);
				LimpiarPantalla();

				switch (optEmpleado) {
				case 1:
					double salarioBase, bonoAdministrativo;
					if (cantEmpleados == 10) {
						cout << "Límite de empleados registrables alcanzado" << endl;
						optEmpleado = 4;
						break;
					}
					cout << "Código: "; cin >> codigo;
					cout << "Nombre: "; cin >> nombre;
					cout << "Edad: ";
					validacionEntero(edad, 18, 70);
					cout << "Departamento: "; cin >> departamento;
					cout << "Salario base: ";
					validacionDouble(salarioBase, 3000, 100000);
					cout << "Bono administrativo: ";
					validacionDouble(bonoAdministrativo, 1000, 20000);

					administrativos[cantAdmin].registrarAdministrativo(codigo, nombre, edad, departamento, salarioBase, bonoAdministrativo);
					cantAdmin++;
					cantEmpleados++;
					cout << "Administrativo registrado correctamente" << endl;
					LimpiarPantalla();
					break;
				case 2:
					int ventas;
					double porcentajeComision;
					if (cantEmpleados == 10) {
						cout << "Límite de empleados registrables alcanzado" << endl;
						optEmpleado = 4;
						break;
					}
					cout << "Código: "; cin >> codigo;
					cout << "Nombre: "; cin >> nombre;
					cout << "Edad: ";
					validacionEntero(edad, 18, 70);
					cout << "Departamento: "; cin >> departamento;
					cout << "Salario base: ";
					validacionDouble(salarioBase, 3000, 100000);
					cout << "Ventas: ";
					validacionEntero(ventas, 1, 10000);
					cout << "Porcentaje de comisión: ";
					validacionDouble(porcentajeComision, 1, 50);

					vendedores[cantVendedor].registrarVendedor(codigo, nombre, edad, departamento, salarioBase, ventas, porcentajeComision);
					cantVendedor++;
					cantEmpleados++;
					cout << "Vendedor registrado correctamente" << endl;
					LimpiarPantalla();
					break;
				case 3:
					int horasExtra;
					if (cantEmpleados == 10) {
						cout << "Límite de empleados registrables alcanzado" << endl;
						optEmpleado = 4;
						break;
					}
					cout << "Código: "; cin >> codigo;
					cout << "Nombre: "; cin >> nombre;
					cout << "Edad: ";
					validacionEntero(edad, 18, 70);
					cout << "Departamento: "; cin >> departamento;
					cout << "Salario base: ";
					validacionDouble(salarioBase, 3000, 100000);
					cout << "Horas extra: ";
					validacionEntero(horasExtra, 1, 180);
					double pagoHorasExtra = salarioBase / 180;
					// Esto suponiendo que un empleado trabaja 180 horas obligatorias al mes

					operarios[cantOperario].registrarOperario(codigo, nombre, edad, departamento, salarioBase, horasExtra, pagoHorasExtra);
					cantOperario++;
					cantEmpleados++;
					cout << "Operario registrado correctamente" << endl;
					LimpiarPantalla();
					break;
				}
			} while (optEmpleado != 4);
			break;
		case 2:
			if (cantEmpleados == 0) {
				cout << "No se han registrado empleados" << endl;
			}
			else {
				cout << "========= MOSTRAR EMPLEADOS =========" << endl;
				cout << "Administrativos" << endl;
				if (cantAdmin == 0) {
					cout << "No hay administrativos" << endl;
				}
				else {
					for (int i = 0; i < cantAdmin; i++) {
						administrativos[i].mostrarInformacion();
						cout << endl;
					}
				}

				cout << "====================================" << endl;
				cout << endl;

				cout << "Vendedores" << endl;
				if (cantVendedor == 0) {
					cout << "No hay vendedores" << endl;
				}
				else {
					for (int i = 0; i < cantVendedor; i++) {
						vendedores[i].mostrarInformacion();
						cout << endl;
					}
				}

				cout << "====================================" << endl;
				cout << endl;

				cout << "Operarios" << endl;
				if (cantOperario == 0) {
					cout << "No hay operarios" << endl;
				}
				else {
					for (int i = 0; i < cantOperario; i++) {
						operarios[i].mostrarInformacion();
						cout << endl;
					}
				}
			}
			LimpiarPantalla();
			break;
		case 3:
			cout << "========= REGISTRAR ENTRADA =========" << endl;
			for (int i = 0; i < cantAdmin; i++) { administrativos[i].registrarEntrada(); }
			for (int i = 0; i < cantVendedor; i++) { vendedores[i].registrarEntrada(); }
			for (int i = 0; i < cantOperario; i++) { operarios[i].registrarEntrada(); }
			LimpiarPantalla();
			break;
		case 4:
			cout << "========= REGISTRAR SALIDA =========" << endl;
			for (int i = 0; i < cantAdmin; i++) { administrativos[i].registrarSalida(); }
			for (int i = 0; i < cantVendedor; i++) { vendedores[i].registrarSalida(); }
			for (int i = 0; i < cantOperario; i++) { operarios[i].registrarSalida(); }
			LimpiarPantalla();
			break;
		case 5:
			if (cantEmpleados == 0) {
				cout << "No se han registrado empleados" << endl;
			}
			else {
				cout << "========= MOSTRAR SALARIOS =========" << endl;
				if (cantAdmin != 0) {
					for (int i = 0; i < cantAdmin; i++) {
						administrativos[i].mostrarSalario();
					}
				}

				if (cantVendedor != 0) {
					for (int i = 0; i < cantVendedor; i++) {
						vendedores[i].mostrarSalario();
					}
				}

				if (cantOperario != 0) {
					for (int i = 0; i < cantOperario; i++) {
						operarios[i].mostrarSalario();
					}
				}
			}
			LimpiarPantalla();
			break;
		case 6:;
			if (cantEmpleados == 0) {
				cout << "No se han registrado empleados" << endl;
			}
			else {
				cout << "========= MOSTRAR TOTAL DE PLANILLA =========" << endl;
				double totalPlanilla = 0;
				if (cantAdmin != 0) {
					for (int i = 0; i < cantAdmin; i++) {
						totalPlanilla += administrativos[i].calcularSalario();
					}
				}

				if (cantVendedor != 0) {
					for (int i = 0; i < cantVendedor; i++) {
						totalPlanilla += vendedores[i].calcularSalario();
					}
				}

				if (cantOperario != 0) {
					for (int i = 0; i < cantOperario; i++) {
						totalPlanilla += operarios[i].calcularSalario();
					}
				}

				cout << "Total de planilla: Q" << totalPlanilla << endl;
			}
			LimpiarPantalla();
			break;
		}
	} while (optMenu != 7);
	return 0;
}