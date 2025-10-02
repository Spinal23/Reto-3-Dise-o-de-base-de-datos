#ifndef DB2_BIBLIOTECA_H
#define DB2_BIBLIOTECA_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// Estructuras para datos
struct Autor {
    int id_autor;
    string nombre;
};

struct Libro {
    int id_libro;
    string titulo;
    int anio_publicacion;
    int id_autor;  // Clave foranea a Autor
    string estado;
    int stock_total;
};

struct Estudiante {
    int id_estudiante;
    string nombre;
    string carnet;
};

struct Prestamo {
    int id_prestamo;
    int id_libro;  // Clave foranea
    int id_estudiante;  // Clave foranea
    string fecha_prestamo;
    string fecha_limite;
    string fecha_devolucion;
};

// Funciones para validar IDs
bool idDuplicado(const vector<Autor>& autores, int id);
bool idDuplicado(const vector<Libro>& libros, int id);
bool idDuplicado(const vector<Estudiante>& estudiantes, int id);
bool idDuplicado(const vector<Prestamo>& prestamos, int id);
bool existeAutor(const vector<Autor>& autores, int id_autor);
bool existeLibro(const vector<Libro>& libros, int id_libro);
bool existeEstudiante(const vector<Estudiante>& estudiantes, int id_estudiante);

// Funciones para Autor
void agregarAutor(vector<Autor>& autores, Autor nuevo_autor);
void editarAutor(vector<Autor>& autores, int id_autor);
void listarAutores(const vector<Autor>& autores);
void guardarAutores(const vector<Autor>& autores);
void cargarAutores(vector<Autor>& autores);
void eliminarAutor(vector<Autor>& autores, vector<Libro>& libros, int id_autor);

// Funciones para Libro
void agregarLibro(vector<Libro>& libros, Libro nuevo_libro);
void editarLibro(vector<Libro>& libros, int id_libro);
void listarLibros(const vector<Libro>& libros);
void guardarLibros(const vector<Libro>& libros);
void cargarLibros(vector<Libro>& libros);
void eliminarLibro(vector<Libro>& libros, vector<Prestamo>& prestamos, int id_libro);

// Funciones para Estudiante
void agregarEstudiante(vector<Estudiante>& estudiantes, Estudiante nuevo_estudiante);
void editarEstudiante(vector<Estudiante>& estudiantes, int id_estudiante);
void listarEstudiantes(const vector<Estudiante>& estudiantes);
void guardarEstudiantes(const vector<Estudiante>& estudiantes);
void cargarEstudiantes(vector<Estudiante>& estudiantes);
void eliminarEstudiante(vector<Estudiante>& estudiantes, vector<Prestamo>& prestamos, int id_estudiante);

// Funciones para Prestamo
void agregarPrestamo(vector<Prestamo>& prestamos, vector<Libro>& libros, vector<Estudiante>& estudiantes, Prestamo nuevo_prestamo);
void listarPrestamos(const vector<Prestamo>& prestamos);
void guardarPrestamos(const vector<Prestamo>& prestamos);
void cargarPrestamos(vector<Prestamo>& prestamos);
void registrarDevolucion(vector<Prestamo>& prestamos, vector<Libro>& libros, int id_prestamo, const string& fecha_devolucion);
void eliminarPrestamosCompletados(vector<Prestamo>& prestamos);
void buscarPrestamosPorEstudiante(const vector<Prestamo>& prestamos, int id_estudiante);

#endif