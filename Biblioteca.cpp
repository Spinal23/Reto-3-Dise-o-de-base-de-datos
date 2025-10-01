//
// Created by leand on 1/10/2025.
//

#include "Biblioteca.h"

// Funciones de Autor
void agregarAutor(vector<Autor>& autores, Autor nuevo_autor) {
    autores.push_back(nuevo_autor);
}

void listarAutores(const vector<Autor>& autores) {
    for (const auto& autor : autores) {
        cout << "ID: " << autor.id_autor << " | Nombre: " << autor.nombre << endl;
    }
}

void guardarAutores(const vector<Autor>& autores) {
    ofstream archivo("data/autores.txt");
    for (const auto& autor : autores) {
        archivo << autor.id_autor << "," << autor.nombre << endl;
    }
    archivo.close();
}

void cargarAutores(vector<Autor>& autores) {
    ifstream archivo("data/autores.txt");
    Autor autor;
    while (archivo >> autor.id_autor) {
        archivo.ignore();
        getline(archivo, autor.nombre);
        autores.push_back(autor);
    }
    archivo.close();
}

// Funciones de Libro
void agregarLibro(vector<Libro>& libros, Libro nuevo_libro) {
    libros.push_back(nuevo_libro);
}

void listarLibros(const vector<Libro>& libros) {
    for (const auto& libro : libros) {
        cout << "ID: " << libro.id_libro << " | Titulo: " << libro.titulo << " | Autor ID: "
             << libro.id_autor << " | Estado: " << libro.estado << " | Stock: " << libro.stock_total << endl;
    }
}

void guardarLibros(const vector<Libro>& libros) {
    ofstream archivo("data/libros.txt");
    for (const auto& libro : libros) {
        archivo << libro.id_libro << "," << libro.titulo << "," << libro.anio_publicacion
                << "," << libro.id_autor << "," << libro.estado << "," << libro.stock_total << endl;
    }
    archivo.close();
}

void cargarLibros(vector<Libro>& libros) {
    ifstream archivo("data/libros.txt");
    Libro libro;
    while (archivo >> libro.id_libro) {
        archivo.ignore();
        getline(archivo, libro.titulo, ',');
        archivo >> libro.anio_publicacion;
        archivo.ignore();
        archivo >> libro.id_autor;
        archivo.ignore();
        getline(archivo, libro.estado, ',');
        archivo >> libro.stock_total;
        libros.push_back(libro);
    }
    archivo.close();
}

// Funciones de Estudiante
void agregarEstudiante(vector<Estudiante>& estudiantes, Estudiante nuevo_estudiante) {
    estudiantes.push_back(nuevo_estudiante);
}

void listarEstudiantes(const vector<Estudiante>& estudiantes) {
    for (const auto& estudiante : estudiantes) {
        cout << "ID: " << estudiante.id_estudiante << " | Nombre: " << estudiante.nombre
             << " | Carnet: " << estudiante.carnet << endl;
    }
}

void guardarEstudiantes(const vector<Estudiante>& estudiantes) {
    ofstream archivo("data/estudiantes.txt");
    for (const auto& estudiante : estudiantes) {
        archivo << estudiante.id_estudiante << "," << estudiante.nombre << "," << estudiante.carnet << endl;
    }
    archivo.close();
}

void cargarEstudiantes(vector<Estudiante>& estudiantes) {
    ifstream archivo("data/estudiantes.txt");
    Estudiante estudiante;
    while (archivo >> estudiante.id_estudiante) {
        archivo.ignore();
        getline(archivo, estudiante.nombre, ',');
        getline(archivo, estudiante.carnet, '\n');
        estudiantes.push_back(estudiante);
    }
    archivo.close();
}

// Funciones de Prestamo
void agregarPrestamo(vector<Prestamo>& prestamos, Prestamo nuevo_prestamo) {
    prestamos.push_back(nuevo_prestamo);
}

void listarPrestamos(const vector<Prestamo>& prestamos) {
    for (const auto& prestamo : prestamos) {
        cout << "ID Prestamo: " << prestamo.id_prestamo << " | Libro ID: " << prestamo.id_libro
             << " | Estudiante ID: " << prestamo.id_estudiante << " | Fecha Limite: "
             << prestamo.fecha_limite << " | Fecha Devolucion: " << prestamo.fecha_devolucion << endl;
    }
}

void guardarPrestamos(const vector<Prestamo>& prestamos) {
    ofstream archivo("data/prestamos.txt");
    for (const auto& prestamo : prestamos) {
        archivo << prestamo.id_prestamo << "," << prestamo.id_libro << "," << prestamo.id_estudiante
                << "," << prestamo.fecha_prestamo << "," << prestamo.fecha_limite << "," << prestamo.fecha_devolucion << endl;
    }
    archivo.close();
}

void cargarPrestamos(vector<Prestamo>& prestamos) {
    ifstream archivo("data/prestamos.txt");
    Prestamo prestamo;
    while (archivo >> prestamo.id_prestamo) {
        archivo.ignore();
        archivo >> prestamo.id_libro;
        archivo.ignore();
        archivo >> prestamo.id_estudiante;
        archivo.ignore();
        getline(archivo, prestamo.fecha_prestamo, ',');
        getline(archivo, prestamo.fecha_limite, ',');
        getline(archivo, prestamo.fecha_devolucion, '\n');
        prestamos.push_back(prestamo);
    }
    archivo.close();
}
