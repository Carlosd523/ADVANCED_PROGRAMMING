#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class MaterialBibliografico {
private:
    string nombre;
    string codigo;
    int anioPublicacion;
    bool disponible;

public:
    MaterialBibliografico(string nombre, string codigo, int anioPublicacion, bool disponible) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->anioPublicacion = anioPublicacion;
        this->disponible = disponible;
    }

    void mostrarInformacion() {
    }

    void prestarMaterial() {
        if(!disponible){
            throw runtime_error("El material bibliográfico ya ha sido prestado");
        }
        else {
            disponible = false;
        }
    }

    void prestarMaterial(int diasPrestamo) {
        if (!disponible) {
            throw runtime_error("El material bibliográfico ya ha sido prestado");
        }
        else {
            cout << "El material será prestado por: " + to_string(diasPrestamo) << endl;
            disponible = false;
        }
    }

    void devolverMaterial() {
        if (disponible) {
            throw runtime_error("El material bibliográfico no se encuentra en préstamo");
        }
        else {
            disponible = true;
            cout << "Material devuelto" << endl;
        }

    }

    string getNombre() {
        return nombre;
    }

    string getCodigo() {
        return codigo;
    }

    int getAnioPublicacion() {
        return anioPublicacion;
    }

    string getDisponibilidad() {
        if (disponible) {
            return "Sí";
        }
        else {
            return "No";
        }
    }

    virtual void mostrarDetalle() {
    }

};

class Libro : public MaterialBibliografico {
private:
    string autor;
    int numeroPaginas;

public:

    Libro(string n, string c, int aP, bool d, string autor, int numeroPaginas)
        : MaterialBibliografico(n, c, aP, d), autor(autor), numeroPaginas(numeroPaginas) {}

    void mostrarDetalle() override {
        cout << "Información de " << getNombre()
            << "\nCódigo; " << getCodigo()
            << "\nAño de publicación: " << getAnioPublicacion()
            << "\nDisponible: " + getDisponibilidad()
            << "\nAutor: " << autor
            << "\nNúmero de páginas: " << numeroPaginas << endl;
    }

    void calcularTiempoLectura() {
        double tiempoLectura = (numeroPaginas * 2) / 60;
        cout << "El tiempo aproximado de lectura es de: " + to_string(tiempoLectura) << endl;
    }
};

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    string categoria;

public:
    Revista(string n, string c, int aP, bool d, int numeroEdicion, string categoria)
        : MaterialBibliografico(n, c, aP, d), numeroEdicion(numeroEdicion), categoria(categoria) {}

    void mostrarDetalle() override {
        cout << "Información de " + getNombre()
            << "\nCódigo; " + getCodigo()
            << "\nAño de publicación: " + getAnioPublicacion()
            << "\nDisponible: " + getDisponibilidad()
            << "\nNúmero de edición: " + numeroEdicion
            << "\nCategoría: " + categoria << endl;
    }

    void mostrarCategoria() {
        cout << "la revista " + getNombre() + " pertenece a la categoría " + categoria + "." << endl;
    }
};

int main()
{
    return 0;
}