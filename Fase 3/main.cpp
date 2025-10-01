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
        cout << "7. Agregar Autor\n";
        cout << "8. Eliminar Autor\n";
        cout << "9. Eliminar Libro\n";
        cout << "10. Registrar Devolución de Préstamo\n";
        cout << "11. Eliminar Préstamos Completados\n";
        cout << "0. Salir\n";
        cin >> opcion;

        // Limpiar el buffer de entrada para evitar el problema con getline
        cin.ignore();  // Esto se agrega aquí para limpiar el buffer antes de leer un string

        switch (opcion) {
            case 1: {
                // Agregar Libro
                Libro nuevo_libro;
                cout << "Ingrese ID: ";
                cin >> nuevo_libro.id_libro;
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese Titulo: ";
                getline(cin, nuevo_libro.titulo);
                cout << "Ingrese Año de Publicación: ";
                cin >> nuevo_libro.anio_publicacion;
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese ID del Autor: ";
                cin >> nuevo_libro.id_autor;
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese Estado: ";
                getline(cin, nuevo_libro.estado);
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
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese Nombre: ";
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
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese ID Libro: ";
                cin >> nuevo_prestamo.id_libro;
                cout << "Ingrese ID Estudiante: ";
                cin >> nuevo_prestamo.id_estudiante;
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese Fecha de Prestamo: ";
                getline(cin, nuevo_prestamo.fecha_prestamo);
                cout << "Ingrese Fecha Limite: ";
                getline(cin, nuevo_prestamo.fecha_limite);
                nuevo_prestamo.fecha_devolucion = "";

                agregarPrestamo(prestamos, nuevo_prestamo);
                guardarPrestamos(prestamos);
                break;
            }
            case 6:
                // Listar Prestamos
                listarPrestamos(prestamos);
                break;
            case 7: {
                // Agregar Autor
                Autor nuevo_autor;
                cout << "Ingrese ID del Autor: ";
                cin >> nuevo_autor.id_autor;
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese Nombre del Autor: ";
                getline(cin, nuevo_autor.nombre);

                agregarAutor(autores, nuevo_autor);
                guardarAutores(autores);
                break;
            }
            case 8: {
                // Eliminar Autor
                int id_autor;
                cout << "Ingrese ID del Autor a eliminar: ";
                cin >> id_autor;
                eliminarAutor(autores, libros, id_autor);  // Pasamos libros a la función eliminarAutor
                break;
            }
            case 9: {
                // Eliminar Libro
                int id_libro;
                cout << "Ingrese ID del Libro a eliminar: ";
                cin >> id_libro;
                eliminarLibro(libros, prestamos, id_libro);  // Pasamos prestamos a la función eliminarLibro
                break;
            }
            case 10: {
                // Registrar Devolución de Préstamo
                int id_prestamo;
                string fecha_devolucion;
                cout << "Ingrese ID del Préstamo a devolver: ";
                cin >> id_prestamo;
                cin.ignore();  // Limpiar el buffer de entrada
                cout << "Ingrese Fecha de Devolución (DD/MM/YYYY): ";
                getline(cin, fecha_devolucion);

                registrarDevolucion(prestamos, libros, id_prestamo, fecha_devolucion); // Corrected call
                break;
            }
            case 11: {
                // Eliminar Préstamos Completados
                eliminarPrestamosCompletados(prestamos);
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Opción no válida\n";
        }
    }
}