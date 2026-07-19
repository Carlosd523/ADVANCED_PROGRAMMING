#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Clase Base - Material Bibliográfico
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
        cout << "Información de " << nombre
            << "\nCódigo; " << codigo
            << "\nAño de publicación: " << anioPublicacion
            << "\nDisponible: " + getDisponibilidad() << endl;
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
            cout << "El material será prestado por: " + to_string(diasPrestamo) << " días." << endl;
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

    virtual ~MaterialBibliografico(){
        cout << "Objeto destruido" << endl;
    }
};

// Clase Derivada 02 - Libro
class Libro : public MaterialBibliografico {
private:
    string autor;
    int numeroPaginas;

public:

    Libro(string n, string c, int aP, bool d, string autor, int numeroPaginas)
        : MaterialBibliografico(n, c, aP, d), autor(autor), numeroPaginas(numeroPaginas) {}

    void mostrarDetalle() override {
        cout << "\nAutor: " << autor
            << "\nNúmero de páginas: " << numeroPaginas << endl;
    }

    void calcularTiempoLectura() {
        double tiempoLectura = (numeroPaginas * 2) / 60;
        cout << "El tiempo aproximado de lectura es de: " + to_string(tiempoLectura) << endl;
    }

};

// Clase Derivada 02 - Revista
class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    string categoria;

public:
    Revista(string n, string c, int aP, bool d, int numeroEdicion, string categoria)
        : MaterialBibliografico(n, c, aP, d), numeroEdicion(numeroEdicion), categoria(categoria) {}

    void mostrarDetalle() override {
        cout << "\nNúmero de edición: " + to_string(numeroEdicion)
            << "\nCategoría: " + categoria << endl;
    }

    void mostrarCategoria() {
        cout << "la revista " + getNombre() + " pertenece a la categoría " + categoria + "." << endl;
    }
};

int main()
{
    // Creación de Objetos
    Libro libro01("El Señor de los Anillos", "L001", 1954, true, "J. R. R. Tolkien", 1392);
    Libro libro02("Las Crónicas de Narnia: El Príncipe Caspian", "L002", 1951, true, "C. S. Lweis", 280);

    Revista revista01("Productos para un Salón de Belleza", "R001", 2017, true, 4, "Belleza");
    Revista revista02("Productos para tu Cocina", "R002", 2023, true, 7, "Gastronomía");

    // Utilización de prestarMaterial sin parámetros
    libro01.prestarMaterial();
    revista01.prestarMaterial();

    // Utilización de prestarMaterial con un parámetro
    libro02.prestarMaterial(25);
    revista02.prestarMaterial(45);

    libro01.mostrarInformacion();
    libro02.mostrarInformacion();
    revista01.mostrarInformacion();
    revista02.mostrarInformacion();

    libro01.mostrarDetalle();
    libro02.mostrarDetalle();
    revista01.mostrarDetalle();
    revista02.mostrarDetalle();
    return 0;
}