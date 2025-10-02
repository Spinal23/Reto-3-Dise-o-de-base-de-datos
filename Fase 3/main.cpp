#include <iostream>
#include <vector>
#include <limits>
#include "Biblioteca.h"
using namespace std;

// Lee numero entero, evita errores
int leerEnteroValido(const string& mensaje) {
    int valor;
    cout << mensaje;
    while (!(cin >> valor) || valor < 0) {
        cout << "Error: Ingrese un numero entero no negativo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    return valor;
}

int main() {
    vector<Autor> autores;
    vector<Libro> libros;
    vector<Estudiante> estudiantes;
    vector<Prestamo> prestamos;

    // Carga datos al empezar, con debug
    cout << "Cargando datos...\n";
    cargarAutores(autores);
    cout << "Debug: Vector autores tiene " << autores.size() << " elementos.\n";
    cargarLibros(libros);
    cargarEstudiantes(estudiantes);
    cargarPrestamos(prestamos);
    cout << "Carga completada.\n\n";

    int opcion;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Agregar Autor\n";
        cout << "2. Listar Autores\n";
        cout << "3. Listar Libros\n";
        cout << "4. Agregar Estudiante\n";
        cout << "5. Listar Estudiantes\n";
        cout << "6. Agregar Prestamo\n";
        cout << "7. Listar Prestamos\n";
        cout << "8. Eliminar Autor\n";
        cout << "9. Eliminar Libro\n";
        cout << "10. Registrar Devolucion de Prestamo\n";
        cout << "11. Eliminar Prestamos Completados\n";
        cout << "12. Editar Autor\n";
        cout << "13. Editar Libro\n";
        cout << "14. Editar Estudiante\n";
        cout << "15. Eliminar Estudiante\n";
        cout << "16. Buscar Prestamos por Estudiante\n";
        cout << "0. Salir\n";
        opcion = leerEnteroValido("Seleccione una opcion: ");

        switch (opcion) {
            case 1: {
                // Pide datos y agrega autor
                Autor nuevo_autor;
                nuevo_autor.id_autor = leerEnteroValido("Ingrese ID del Autor: ");
                cout << "Ingrese Nombre del Autor: ";
                getline(cin, nuevo_autor.nombre);

                agregarAutor(autores, nuevo_autor);
                guardarAutores(autores);
                break;
            }
            case 2:
                // Muestra todos los autores
                listarAutores(autores);
                break;
            case 3:
                // Muestra todos los libros
                listarLibros(libros);
                break;
            case 4: {
                // Pide datos y agrega estudiante
                Estudiante nuevo_estudiante;
                nuevo_estudiante.id_estudiante = leerEnteroValido("Ingrese ID Estudiante: ");
                cout << "Ingrese Nombre: ";
                getline(cin, nuevo_estudiante.nombre);
                cout << "Ingrese Carnet: ";
                getline(cin, nuevo_estudiante.carnet);

                agregarEstudiante(estudiantes, nuevo_estudiante);
                guardarEstudiantes(estudiantes);
                break;
            }
            case 5:
                // Muestra todos los estudiantes
                listarEstudiantes(estudiantes);
                break;
            case 6: {
                // Pide datos y agrega prestamo
                Prestamo nuevo_prestamo;
                nuevo_prestamo.id_prestamo = leerEnteroValido("Ingrese ID Prestamo: ");
                nuevo_prestamo.id_libro = leerEnteroValido("Ingrese ID Libro: ");
                nuevo_prestamo.id_estudiante = leerEnteroValido("Ingrese ID Estudiante: ");
                cout << "Ingrese Fecha de Prestamo: ";
                getline(cin, nuevo_prestamo.fecha_prestamo);
                cout << "Ingrese Fecha Limite: ";
                getline(cin, nuevo_prestamo.fecha_limite);
                nuevo_prestamo.fecha_devolucion = "";

                agregarPrestamo(prestamos, libros, estudiantes, nuevo_prestamo);
                guardarPrestamos(prestamos);
                break;
            }
            case 7:
                // Muestra todos los prestamos
                listarPrestamos(prestamos);
                break;
            case 8: {
                // Borra autor por ID
                int id_autor = leerEnteroValido("Ingrese ID del Autor a eliminar: ");
                eliminarAutor(autores, libros, id_autor);
                break;
            }
            case 9: {
                // Borra libro por ID
                int id_libro = leerEnteroValido("Ingrese ID del Libro a eliminar: ");
                eliminarLibro(libros, prestamos, id_libro);
                break;
            }
            case 10: {
                // Marca prestamo como devuelto
                int id_prestamo = leerEnteroValido("Ingrese ID del Prestamo a devolver: ");
                string fecha_devolucion;
                cout << "Ingrese Fecha de Devolucion (DD/MM/YYYY): ";
                getline(cin, fecha_devolucion);

                registrarDevolucion(prestamos, libros, id_prestamo, fecha_devolucion);
                break;
            }
            case 11:
                // Borra prestamos ya devueltos
                eliminarPrestamosCompletados(prestamos);
                break;
            case 12: {
                // Edita autor por ID
                int id_autor = leerEnteroValido("Ingrese ID del Autor a editar: ");
                editarAutor(autores, id_autor);
                break;
            }
            case 13: {
                // Edita libro por ID
                int id_libro = leerEnteroValido("Ingrese ID del Libro a editar: ");
                editarLibro(libros, id_libro);
                break;
            }
            case 14: {
                // Edita estudiante por ID
                int id_estudiante = leerEnteroValido("Ingrese ID del Estudiante a editar: ");
                editarEstudiante(estudiantes, id_estudiante);
                break;
            }
            case 15: {
                // Borra estudiante por ID
                int id_estudiante = leerEnteroValido("Ingrese ID del Estudiante a eliminar: ");
                eliminarEstudiante(estudiantes, prestamos, id_estudiante);
                break;
            }
            case 16: {
                // Busca prestamos de estudiante
                int id_estudiante = leerEnteroValido("Ingrese ID del Estudiante: ");
                buscarPrestamosPorEstudiante(prestamos, id_estudiante);
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Opcion no valida\n";
        }
    }
}