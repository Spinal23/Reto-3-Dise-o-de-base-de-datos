//
// Created by leand on 1/10/2025.
//
#ifndef DB2_BIBLIOTECA_H
#define DB2_BIBLIOTECA_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// Definición de las estructuras
struct Autor {
    int id_autor;
    string nombre;
};

struct Libro {
    int id_libro;
    string titulo;
    int anio_publicacion;
    int id_autor;  // FK a Autor
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
    int id_libro;  // FK
    int id_estudiante;  // FK
    string fecha_prestamo;
    string fecha_limite;
    string fecha_devolucion;
};

// Funciones para CRUD de Autor
void agregarAutor(vector<Autor>& autores, Autor nuevo_autor);
void listarAutores(const vector<Autor>& autores);
void guardarAutores(const vector<Autor>& autores);
void cargarAutores(vector<Autor>& autores);
void eliminarAutor(vector<Autor>& autores, vector<Libro>& libros, int id_autor);

// Funciones para CRUD de Libro
void agregarLibro(vector<Libro>& libros, Libro nuevo_libro);
void listarLibros(const vector<Libro>& libros);
void guardarLibros(const vector<Libro>& libros);
void cargarLibros(vector<Libro>& libros);
void eliminarLibro(vector<Libro>& libros, vector<Prestamo>& prestamos, int id_libro);

// Funciones para CRUD de Estudiante
void agregarEstudiante(vector<Estudiante>& estudiantes, Estudiante nuevo_estudiante);
void listarEstudiantes(const vector<Estudiante>& estudiantes);
void guardarEstudiantes(const vector<Estudiante>& estudiantes);
void cargarEstudiantes(vector<Estudiante>& estudiantes);

// Funciones para CRUD de Prestamo
void agregarPrestamo(vector<Prestamo>& prestamos, Prestamo nuevo_prestamo);
void listarPrestamos(const vector<Prestamo>& prestamos);
void guardarPrestamos(const vector<Prestamo>& prestamos);
void cargarPrestamos(vector<Prestamo>& prestamos);
void registrarDevolucion(vector<Prestamo>& prestamos, vector<Libro>& libros, int id_prestamo, const string& fecha_devolucion);
void eliminarPrestamosCompletados(vector<Prestamo>& prestamos);

#endif