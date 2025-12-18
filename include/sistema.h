#ifndef SISTEMA_H
#define SISTEMA_H

#include "estudiante.h"
#include "curso.h"
#include <fstream>

struct Inscripcion {
    int indEstudiante;
    int indCurso;
};

struct RegistroNotas {
    int indInscripcion;
    float* notas;
    int cantidadNota;
};

struct IndiceEstudiante {
    long posicion;
};

class Sistema {
private:
    Estudiante* estudiantes;
    int cantidadEstudiantes;
    Curso* cursos;
    int cantidadCursos;
    Inscripcion* inscripciones;
    int cantdiadInscripciones;
    RegistroNotas* registroNotas;
    int cantidadRegistroNotas;

public:
    Sistema();
    ~Sistema();

    void registrarEstudiantes();
    void listarEstudiantes() const;
    void registrarCursos();
    void listarCurso() const;
    void listarEstudiantesconInd() const;
    void listarCursosconInd() const;
    void InscribirEstudiantes();
    void listarInscripciones() const;
    void registrarNotas();
    float calcularPromedio(const RegistroNotas& r) const;
    void mostrarReporte() const;
    void crearAprobadosTXT() const;
    void guardarBinario() const;
    void leerBinario() const;
    void buscarEstudianteDirecto() const;
    void menu();
};

#endif
