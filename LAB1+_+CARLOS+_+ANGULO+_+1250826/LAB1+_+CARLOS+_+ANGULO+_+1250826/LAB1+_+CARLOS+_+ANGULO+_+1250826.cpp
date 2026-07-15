#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <sstream>
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
void ValidacionEntero(int& numero, int min, int max) {
    bool validacion = false;
    do {
        cin >> numero;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Ingrese un número entero válido" << endl;
            cout << "Intente nuevamente: ";
            continue;
        }
        else if (numero < min || numero > max) {
            cout << "Error: El número ingresado está fuera del rango permitido" << endl;
            cout << "Intente nuevamente: ";
            continue;
        }
        validacion = true;
    } while (!validacion);
}

// Función 03 - Valida un número Decimal dentro de cierto rango
void ValidacionDecimal(double& numero, double min, double max) {
    bool validacion = false;
    do {
        cin >> numero;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Ingrese un número decimal válido" << endl;
            cout << "Intente nuevamente: ";
            continue;
        }
        else if (numero < min || numero > max) {
            cout << "Error: El número ingresado está fuera del rango permitido" << endl;
            cout << "Intente nuevamente: ";
            continue;
        }
        validacion = true;
    } while (!validacion);
}

// Función 04 - Consultar saldo
void ConsultarSaldo(double saldo) {
    cout << fixed << setprecision(2);
    cout << "Su saldo actual es: " << saldo << endl;
}

// Función 05 - Aumentar historial de operaciones
void AumentarHistorial(string historialOperaciones[], string operacion, int& contador, double cantidad) {
    if (contador < 20) {
        stringstream texto;
        texto << fixed << setprecision(2) << cantidad;

        historialOperaciones[contador] = operacion + ": Q" + texto.str();
        contador++;
    }
}

// Función 06 - Realizar deposito
void RealizarDeposito(double& saldo, int& totalDepositos, string historialOperaciones[], int& contador) {
    double deposito = 0;
    cout << "El monto mínimo para depositar es de Q1.00 y el máximo es de Q1,000,000.00" << endl;
    cout << "Ingrese el monto a depositar: ";
    ValidacionDecimal(deposito, 1, 1000000);
    saldo += deposito;
    totalDepositos++;
    AumentarHistorial(historialOperaciones, "Deposito", contador, deposito);
}

// Función 07 - Realizar retiro
void RealizarRetiro(double& saldo, int& totalRetiros, string historialOperaciones[], int& contador) {
    if (saldo < 1) {
        cout << "No posee saldo suficiente para realizar un retiro" << endl;
    }
    else {
        double retiro = 0;
        cout << "El monto mínimo para retirar es de Q1.00" << endl;
        cout << "Ingrese el monto a retirar: ";
        ValidacionDecimal(retiro, 1, saldo);
        saldo -= retiro;
        totalRetiros++;
        AumentarHistorial(historialOperaciones, "Retiro", contador, retiro);
    }
}

// Función 08 - Realizar transferencia
void RealizarTransferencia(double& saldo, int& totalTransferencias, string historialOperaciones[], int& contador) {
    if (saldo < 1) {
        cout << "No tiene saldo suficiente para realizar un retiro" << endl;
    }
    else {
        double transferencia = 0;
        cout << "El monto mínimo para transferir es de Q1.00" << endl;
        cout << "Ingrese el monto a transferir: ";
        ValidacionDecimal(transferencia, 1, saldo);
        saldo -= transferencia;
        totalTransferencias++;
        AumentarHistorial(historialOperaciones, "Transferencia", contador, transferencia);
    }
}

// Función 09 - Mostrar historial de operaciones
void MostrarHistorial(string historialOperaciones[], int contador) {
    if (contador == 0) {
        cout << "No se han hecho transacciones" << endl;
    }
    else {
        for (int i = 0; i < contador; i++) {
            cout << historialOperaciones[i] << endl;
        }
    }
}
int main() {
    int option = 0, minOpt = 1, maxOpt = 6, contador = 0;
    int totalDepositos = 0, totalRetiros = 0, totalTransferencias = 0;
    string historialOperaciones[20];
    double saldo = 5000;

    do {
        //MENÚ
        cout << "======== BANCO URL ========" << endl;
        cout << "1. CONSULTAR SALDO" << endl;
        cout << "2. REALIZAAR DÉPOSITO" << endl;
        cout << "3. REALIZAR RETIRO" << endl;
        cout << "4. REALIZAR TRANSFERENCIA" << endl;
        cout << "5. VER HISTORIAL DE OPERACIONES" << endl;
        cout << "6. SALIR" << endl;

        cout << "Ingrese una opción: ";
        ValidacionEntero(option, minOpt, maxOpt);
        LimpiarPantalla();
        switch (option) {
        case 1:
            cout << "CONSULTA DE SALDO" << endl;
            ConsultarSaldo(saldo);
            LimpiarPantalla();
            break;
        case 2:
            cout << "REALIZAR DEPOSITO" << endl;
            RealizarDeposito(saldo, totalDepositos, historialOperaciones, contador);
            LimpiarPantalla();
            break;
        case 3:
            cout << "REALIZAR RETIRO" << endl;
            RealizarRetiro(saldo, totalRetiros, historialOperaciones, contador);
            LimpiarPantalla();
            break;
        case 4:
            cout << "TRANSFERENCIA" << endl;
            RealizarTransferencia(saldo, totalTransferencias, historialOperaciones, contador);
            LimpiarPantalla();
            break;
        case 5:
            cout << " HISTORIAL DE OPERACIONES" << endl;
            MostrarHistorial(historialOperaciones, contador);
            LimpiarPantalla();
            break;
        }
    } while (option != maxOpt);

    cout << fixed << setprecision(2);
    cout << "Saldo final: " << saldo << endl;
    cout << "Número total de dépositos: " << totalDepositos << endl;
    cout << "Número total de retiros: " << totalRetiros << endl;
    cout << "Número total de transferencias: " << totalTransferencias << endl;
    return 0;
}