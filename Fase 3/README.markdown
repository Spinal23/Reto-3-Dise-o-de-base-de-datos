# Reto 3: Diseño de Bases de Datos

## Descripcion
Sistema en C++ para gestionar autores, libros, estudiantes y prestamos. Usa structs, vectores y menu para CRUD. Guarda datos en archivos txt automaticamente. Valida IDs, stock y busquedas. Incluye diagrama ER, normalizacion e informe.

## Estructura
- `src/`: `Biblioteca.h`, `Biblioteca.cpp`, `main.cpp`
- `docs/`: `Diagrama_ER.png`, `Normalizacion.pdf`, `Informe.pdf`
- `README.md`

## Requisitos
- g++ (C++17)
- Windows, Linux o macOS

## Compilar y Ejecutar
1. Clona repo:
   ```bash
   git clone <URL>
   cd <REPO>
   ```
2. Compila:
   ```bash
   g++ -std=c++17 -o biblioteca src/main.cpp src/Biblioteca.cpp
   ```
3. Ejecuta:
   ```bash
   ./biblioteca
   ```
   Windows: `biblioteca.exe`

## Uso
Menu con 16 opciones: agregar/listar/editar/borrar autores, libros, estudiantes, prestamos; buscar prestamos por estudiante; salir (0). IDs son enteros no negativos, fechas en DD/MM/YYYY. Datos se guardan en archivos txt.

## Notas
- Archivos txt se crean solos al guardar datos.
- Normalizacion evita duplicados 
- Codigo valida IDs, stock y relaciones.