#include <iostream>
#include <vector>
#include "Biblioteca.h"

using namespace std;

int main() {
    vector<Autor> autores;
    vector<Libro> libros;
    vector<Estudiante> estudiantes;
    vector<Prestamo> prestamos;

    // Cargar los datos de los archivos al iniciar
    cargarAutores(autores);
    cargarLibros(libros);
    cargarEstudiantes(estudiantes);
    cargarPrestamos(prestamos);

    int opcion;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Agregar Libro\n";
        cout << "2. Listar Libros\n";
        cout << "3. Agregar Estudiante\n";
        cout << "4. Listar Estudiantes\n";
        cout << "5. Agregar Prestamo\n";
        cout << "6. Listar Prestamos\n";
        cout << "0. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar Libro
                Libro nuevo_libro;
                cout << "Ingrese ID: ";
                cin >> nuevo_libro.id_libro;
                cout << "Ingrese Titulo: ";
                cin.ignore();
                getline(cin, nuevo_libro.titulo);
                cout << "Ingrese Año de Publicación: ";
                cin >> nuevo_libro.anio_publicacion;
                cout << "Ingrese ID del Autor: ";
                cin >> nuevo_libro.id_autor;
                cout << "Ingrese Estado: ";
                cin >> nuevo_libro.estado;
                cout << "Ingrese Stock Total: ";
                cin >> nuevo_libro.stock_total;

                agregarLibro(libros, nuevo_libro);
                guardarLibros(libros);
                break;
            }
            case 2:
                // Listar Libros
                listarLibros(libros);
                break;
            case 3: {
                // Agregar Estudiante
                Estudiante nuevo_estudiante;
                cout << "Ingrese ID Estudiante: ";
                cin >> nuevo_estudiante.id_estudiante;
                cout << "Ingrese Nombre: ";
                cin.ignore();
                getline(cin, nuevo_estudiante.nombre);
                cout << "Ingrese Carnet: ";
                cin >> nuevo_estudiante.carnet;

                agregarEstudiante(estudiantes, nuevo_estudiante);
                guardarEstudiantes(estudiantes);
                break;
            }
            case 4:
                // Listar Estudiantes
                listarEstudiantes(estudiantes);
                break;
            case 5: {
                // Agregar Prestamo
                Prestamo nuevo_prestamo;
                cout << "Ingrese ID Prestamo: ";
                cin >> nuevo_prestamo.id_prestamo;
                cout << "Ingrese ID Libro: ";
                cin >> nuevo_prestamo.id_libro;
                cout << "Ingrese ID Estudiante: ";
                cin >> nuevo_prestamo.id_estudiante;
                cout << "Ingrese Fecha de Prestamo: ";
                cin >> nuevo_prestamo.fecha_prestamo;
                cout << "Ingrese Fecha Limite: ";
                cin >> nuevo_prestamo.fecha_limite;
                nuevo_prestamo.fecha_devolucion = "";

                agregarPrestamo(prestamos, nuevo_prestamo);
                guardarPrestamos(prestamos);
                break;
            }
            case 6:
                // Listar Prestamos
                listarPrestamos(prestamos);
                break;
            case 0:
                return 0;
            default:
                cout << "Opción no válida\n";
        }
    }
}
