#include "Biblioteca.h"
#include <stdexcept>  // Para try-catch en stoi

// Chequea si ID autor ya esta
bool idDuplicado(const vector<Autor>& autores, int id) {
    for (const auto& a : autores) {
        if (a.id_autor == id) return true;
    }
    return false;
}

// Chequea si ID libro ya esta
bool idDuplicado(const vector<Libro>& libros, int id) {
    for (const auto& l : libros) {
        if (l.id_libro == id) return true;
    }
    return false;
}

// Chequea si ID estudiante ya esta
bool idDuplicado(const vector<Estudiante>& estudiantes, int id) {
    for (const auto& e : estudiantes) {
        if (e.id_estudiante == id) return true;
    }
    return false;
}

// Chequea si ID prestamo ya esta
bool idDuplicado(const vector<Prestamo>& prestamos, int id) {
    for (const auto& p : prestamos) {
        if (p.id_prestamo == id) return true;
    }
    return false;
}

// Chequea si autor existe por ID
bool existeAutor(const vector<Autor>& autores, int id_autor) {
    for (const auto& a : autores) {
        if (a.id_autor == id_autor) return true;
    }
    return false;
}

// Chequea si libro existe por ID
bool existeLibro(const vector<Libro>& libros, int id_libro) {
    for (const auto& l : libros) {
        if (l.id_libro == id_libro) return true;
    }
    return false;
}

// Chequea si estudiante existe por ID
bool existeEstudiante(const vector<Estudiante>& estudiantes, int id_estudiante) {
    for (const auto& e : estudiantes) {
        if (e.id_estudiante == id_estudiante) return true;
    }
    return false;
}

// Agrega autor, valida ID duplicado
void agregarAutor(vector<Autor>& autores, Autor nuevo_autor) {
    if (idDuplicado(autores, nuevo_autor.id_autor)) {
        cout << "Error: ID de autor duplicado.\n";
        return;
    }
    autores.push_back(nuevo_autor);
}

// Edita nombre de autor por ID
void editarAutor(vector<Autor>& autores, int id_autor) {
    for (auto& autor : autores) {
        if (autor.id_autor == id_autor) {
            cout << "Editando Autor ID: " << id_autor << endl;
            cout << "Nuevo Nombre (actual: " << autor.nombre << "): ";
            getline(cin, autor.nombre);
            guardarAutores(autores);
            cout << "Autor actualizado.\n";
            return;
        }
    }
    cout << "Autor no encontrado.\n";
}

// Muestra todos los autores, o mensaje si vacio
void listarAutores(const vector<Autor>& autores) {
    if (autores.empty()) {
        cout << "No hay autores registrados.\n";
        return;
    }
    for (const auto& autor : autores) {
        cout << "ID: " << autor.id_autor << " | Nombre: " << autor.nombre << endl;
    }
}

// Guarda autores en archivo txt
void guardarAutores(const vector<Autor>& autores) {
    ofstream archivo("autores.txt");
    for (const auto& autor : autores) {
        archivo << autor.id_autor << "," << autor.nombre << endl;
    }
    archivo.close();
}

// Carga autores desde archivo txt, con chequeos
void cargarAutores(vector<Autor>& autores) {
    ifstream archivo("autores.txt");
    if (!archivo.is_open()) {
        cout << "Archivo autores.txt no encontrado, vector vacio.\n";  // Debug temporal
        return;
    }
    string linea;
    autores.clear();  // Limpia vector antes de cargar
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;  // Salta lineas vacias
        stringstream ss(linea);
        Autor autor;
        string temp;
        try {
            getline(ss, temp, ',');
            autor.id_autor = stoi(temp);
            getline(ss, autor.nombre);
            autores.push_back(autor);
        } catch (const exception& e) {
            cout << "Error en linea: " << linea << " - Formato invalido.\n";  // Manejo error
        }
    }
    archivo.close();
    cout << "Cargados " << autores.size() << " autores.\n";  // Debug temporal
}

// Borra autor si no tiene libros
void eliminarAutor(vector<Autor>& autores, vector<Libro>& libros, int id_autor) {
    for (auto it = autores.begin(); it != autores.end(); ++it) {
        if (it->id_autor == id_autor) {
            for (const auto& libro : libros) {
                if (libro.id_autor == id_autor) {
                    cout << "No se puede eliminar: El autor tiene libros asociados.\n";
                    return;
                }
            }
            autores.erase(it);
            guardarAutores(autores);
            cout << "Autor eliminado.\n";
            return;
        }
    }
    cout << "Autor no encontrado.\n";
}

// Agrega libro, valida ID duplicado
void agregarLibro(vector<Libro>& libros, Libro nuevo_libro) {
    if (idDuplicado(libros, nuevo_libro.id_libro)) {
        cout << "Error: ID de libro duplicado.\n";
        return;
    }
    libros.push_back(nuevo_libro);
}

// Edita datos de libro por ID
void editarLibro(vector<Libro>& libros, int id_libro) {
    for (auto& libro : libros) {
        if (libro.id_libro == id_libro) {
            cout << "Editando Libro ID: " << id_libro << endl;
            cout << "Nuevo Titulo (actual: " << libro.titulo << "): ";
            getline(cin, libro.titulo);
            cout << "Nuevo Anio (actual: " << libro.anio_publicacion << "): ";
            cin >> libro.anio_publicacion;
            cin.ignore();
            cout << "Nuevo Estado (actual: " << libro.estado << "): ";
            getline(cin, libro.estado);
            cout << "Nuevo Stock (actual: " << libro.stock_total << "): ";
            cin >> libro.stock_total;
            cin.ignore();
            guardarLibros(libros);
            cout << "Libro actualizado.\n";
            return;
        }
    }
    cout << "Libro no encontrado.\n";
}

// Muestra todos los libros
void listarLibros(const vector<Libro>& libros) {
    if (libros.empty()) {
        cout << "No hay libros registrados.\n";
        return;
    }
    for (const auto& libro : libros) {
        cout << "ID: " << libro.id_libro << " | Titulo: " << libro.titulo << " | Autor ID: "
             << libro.id_autor << " | Estado: " << libro.estado << " | Stock: " << libro.stock_total << endl;
    }
}

// Guarda libros en archivo txt
void guardarLibros(const vector<Libro>& libros) {
    ofstream archivo("libros.txt");
    for (const auto& libro : libros) {
        archivo << libro.id_libro << "," << libro.titulo << "," << libro.anio_publicacion
                << "," << libro.id_autor << "," << libro.estado << "," << libro.stock_total << endl;
    }
    archivo.close();
}

// Carga libros desde archivo txt
void cargarLibros(vector<Libro>& libros) {
    ifstream archivo("libros.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Libro libro;
        string temp;
        getline(ss, temp, ',');
        libro.id_libro = stoi(temp);
        getline(ss, libro.titulo, ',');
        getline(ss, temp, ',');
        libro.anio_publicacion = stoi(temp);
        getline(ss, temp, ',');
        libro.id_autor = stoi(temp);
        getline(ss, libro.estado, ',');
        getline(ss, temp);
        libro.stock_total = stoi(temp);
        libros.push_back(libro);
    }
    archivo.close();
}

// Borra libro si no tiene prestamos
void eliminarLibro(vector<Libro>& libros, vector<Prestamo>& prestamos, int id_libro) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->id_libro == id_libro) {
            for (const auto& prestamo : prestamos) {
                if (prestamo.id_libro == id_libro && prestamo.fecha_devolucion.empty()) {
                    cout << "No se puede eliminar el libro, tiene prestamos activos.\n";
                    return;
                }
            }
            libros.erase(it);
            guardarLibros(libros);
            cout << "Libro eliminado.\n";
            return;
        }
    }
    cout << "Libro no encontrado.\n";
}

// Agrega estudiante, valida ID duplicado
void agregarEstudiante(vector<Estudiante>& estudiantes, Estudiante nuevo_estudiante) {
    if (idDuplicado(estudiantes, nuevo_estudiante.id_estudiante)) {
        cout << "Error: ID de estudiante duplicado.\n";
        return;
    }
    estudiantes.push_back(nuevo_estudiante);
}

// Edita datos de estudiante por ID
void editarEstudiante(vector<Estudiante>& estudiantes, int id_estudiante) {
    for (auto& est : estudiantes) {
        if (est.id_estudiante == id_estudiante) {
            cout << "Editando Estudiante ID: " << id_estudiante << endl;
            cout << "Nuevo Nombre (actual: " << est.nombre << "): ";
            getline(cin, est.nombre);
            cout << "Nuevo Carnet (actual: " << est.carnet << "): ";
            getline(cin, est.carnet);
            guardarEstudiantes(estudiantes);
            cout << "Estudiante actualizado.\n";
            return;
        }
    }
    cout << "Estudiante no encontrado.\n";
}

// Muestra todos los estudiantes
void listarEstudiantes(const vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    for (const auto& estudiante : estudiantes) {
        cout << "ID: " << estudiante.id_estudiante << " | Nombre: " << estudiante.nombre
             << " | Carnet: " << estudiante.carnet << endl;
    }
}

// Guarda estudiantes en archivo txt
void guardarEstudiantes(const vector<Estudiante>& estudiantes) {
    ofstream archivo("estudiantes.txt");
    for (const auto& estudiante : estudiantes) {
        archivo << estudiante.id_estudiante << "," << estudiante.nombre << "," << estudiante.carnet << endl;
    }
    archivo.close();
}

// Carga estudiantes desde archivo txt
void cargarEstudiantes(vector<Estudiante>& estudiantes) {
    ifstream archivo("estudiantes.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Estudiante est;
        string temp;
        getline(ss, temp, ',');
        est.id_estudiante = stoi(temp);
        getline(ss, est.nombre, ',');
        getline(ss, est.carnet);
        estudiantes.push_back(est);
    }
    archivo.close();
}

// Borra estudiante si no tiene prestamos
void eliminarEstudiante(vector<Estudiante>& estudiantes, vector<Prestamo>& prestamos, int id_estudiante) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (it->id_estudiante == id_estudiante) {
            for (const auto& prestamo : prestamos) {
                if (prestamo.id_estudiante == id_estudiante && prestamo.fecha_devolucion.empty()) {
                    cout << "No se puede eliminar: El estudiante tiene prestamos activos.\n";
                    return;
                }
            }
            estudiantes.erase(it);
            guardarEstudiantes(estudiantes);
            cout << "Estudiante eliminado.\n";
            return;
        }
    }
    cout << "Estudiante no encontrado.\n";
}

// Agrega prestamo, valida IDs y stock
void agregarPrestamo(vector<Prestamo>& prestamos, vector<Libro>& libros, vector<Estudiante>& estudiantes, Prestamo nuevo_prestamo) {
    if (idDuplicado(prestamos, nuevo_prestamo.id_prestamo)) {
        cout << "Error: ID de prestamo duplicado.\n";
        return;
    }
    if (!existeLibro(libros, nuevo_prestamo.id_libro)) {
        cout << "Error: Libro no existe.\n";
        return;
    }
    if (!existeEstudiante(estudiantes, nuevo_prestamo.id_estudiante)) {
        cout << "Error: Estudiante no existe.\n";
        return;
    }
    bool stock_actualizado = false;
    for (auto& libro : libros) {
        if (libro.id_libro == nuevo_prestamo.id_libro) {
            if (libro.stock_total <= 0) {
                cout << "Error: Libro no disponible (stock 0).\n";
                return;
            }
            libro.stock_total--;
            stock_actualizado = true;
            break;
        }
    }
    if (stock_actualizado) {
        prestamos.push_back(nuevo_prestamo);
        guardarLibros(libros);
    }
}

// Muestra todos los prestamos
void listarPrestamos(const vector<Prestamo>& prestamos) {
    if (prestamos.empty()) {
        cout << "No hay prestamos registrados.\n";
        return;
    }
    for (const auto& prestamo : prestamos) {
        cout << "ID Prestamo: " << prestamo.id_prestamo << " | Libro ID: " << prestamo.id_libro
             << " | Estudiante ID: " << prestamo.id_estudiante << " | Fecha Limite: "
             << prestamo.fecha_limite << " | Fecha Devolucion: " << prestamo.fecha_devolucion << endl;
    }
}

// Guarda prestamos en archivo txt
void guardarPrestamos(const vector<Prestamo>& prestamos) {
    ofstream archivo("prestamos.txt");
    for (const auto& prestamo : prestamos) {
        archivo << prestamo.id_prestamo << "," << prestamo.id_libro << "," << prestamo.id_estudiante
                << "," << prestamo.fecha_prestamo << "," << prestamo.fecha_limite << "," << prestamo.fecha_devolucion << endl;
    }
    archivo.close();
}

// Carga prestamos desde archivo txt
void cargarPrestamos(vector<Prestamo>& prestamos) {
    ifstream archivo("prestamos.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Prestamo prestamo;
        string temp;
        getline(ss, temp, ',');
        prestamo.id_prestamo = stoi(temp);
        getline(ss, temp, ',');
        prestamo.id_libro = stoi(temp);
        getline(ss, temp, ',');
        prestamo.id_estudiante = stoi(temp);
        getline(ss, prestamo.fecha_prestamo, ',');
        getline(ss, prestamo.fecha_limite, ',');
        getline(ss, prestamo.fecha_devolucion);
        prestamos.push_back(prestamo);
    }
    archivo.close();
}

// Marca prestamo como devuelto y suma stock
void registrarDevolucion(vector<Prestamo>& prestamos, vector<Libro>& libros, int id_prestamo, const string& fecha_devolucion) {
    for (auto it = prestamos.begin(); it != prestamos.end(); ++it) {
        if (it->id_prestamo == id_prestamo) {
            it->fecha_devolucion = fecha_devolucion;
            for (auto& libro : libros) {
                if (libro.id_libro == it->id_libro) {
                    libro.stock_total++;
                    guardarLibros(libros);
                    break;
                }
            }
            prestamos.erase(it);
            guardarPrestamos(prestamos);
            cout << "Prestamo devuelto correctamente.\n";
            return;
        }
    }
    cout << "Prestamo no encontrado.\n";
}

// Borra prestamos ya devueltos
void eliminarPrestamosCompletados(vector<Prestamo>& prestamos) {
    for (auto it = prestamos.begin(); it != prestamos.end(); ) {
        if (!it->fecha_devolucion.empty()) {
            it = prestamos.erase(it);
        } else {
            ++it;
        }
    }
    guardarPrestamos(prestamos);
}

// Busca prestamos de un estudiante
void buscarPrestamosPorEstudiante(const vector<Prestamo>& prestamos, int id_estudiante) {
    bool encontrado = false;
    cout << "Prestamos para Estudiante ID: " << id_estudiante << endl;
    for (const auto& prestamo : prestamos) {
        if (prestamo.id_estudiante == id_estudiante) {
            cout << "ID Prestamo: " << prestamo.id_prestamo << " | Libro ID: " << prestamo.id_libro
                 << " | Fecha Limite: " << prestamo.fecha_limite << " | Fecha Devolucion: " << prestamo.fecha_devolucion << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron prestamos para este estudiante.\n";
    }
}