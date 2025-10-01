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

void eliminarAutor(vector<Autor>& autores, vector<Libro>& libros, int id_autor) {
    for (auto it = autores.begin(); it != autores.end(); ++it) {
        if (it->id_autor == id_autor) {
            // Comprobamos si el autor tiene libros asociados
            for (const auto& libro : libros) {
                if (libro.id_autor == id_autor) {
                    cout << "No se puede eliminar: El autor tiene libros asociados.\n";
                    return;
                }
            }
            autores.erase(it);  // Eliminamos el autor
            guardarAutores(autores);
            cout << "Autor eliminado.\n";
            return;
        }
    }
    cout << "Autor no encontrado.\n";
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

void eliminarLibro(vector<Libro>& libros, vector<Prestamo>& prestamos, int id_libro) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->id_libro == id_libro) {
            // Comprobamos si el libro tiene préstamos activos
            for (const auto& prestamo : prestamos) {
                if (prestamo.id_libro == id_libro && prestamo.fecha_devolucion.empty()) {
                    cout << "No se puede eliminar el libro, tiene préstamos activos.\n";
                    return;
                }
            }
            libros.erase(it);  // Eliminamos el libro
            guardarLibros(libros);
            cout << "Libro eliminado.\n";
            return;
        }
    }
    cout << "Libro no encontrado.\n";
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
        archivo.ignore(); // Limpiar el buffer de entrada
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

void registrarDevolucion(vector<Prestamo>& prestamos, vector<Libro>& libros, int id_prestamo, const string& fecha_devolucion) {
    for (auto it = prestamos.begin(); it != prestamos.end(); ++it) {
        if (it->id_prestamo == id_prestamo) {
            it->fecha_devolucion = fecha_devolucion;  // Establecemos la fecha de devolución
            // Actualizamos el stock del libro
            for (auto& libro : libros) {
                if (libro.id_libro == it->id_libro) {
                    libro.stock_total++;  // Aumentamos el stock disponible
                    guardarLibros(libros);
                    break;
                }
            }
            // Eliminamos el préstamo completado
            prestamos.erase(it);
            guardarPrestamos(prestamos);
            cout << "Préstamo devuelto correctamente.\n";
            return;
        }
    }
    cout << "Préstamo no encontrado.\n";
}

void eliminarPrestamosCompletados(vector<Prestamo>& prestamos) {
    for (auto it = prestamos.begin(); it != prestamos.end(); ) {
        if (!it->fecha_devolucion.empty()) {
            it = prestamos.erase(it);  // Eliminamos los préstamos completados
        } else {
            ++it;
        }
    }
    guardarPrestamos(prestamos);
}
