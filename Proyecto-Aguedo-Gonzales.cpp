#include <iostream>
#include <string>
using namespace std;

struct EstrucNotas{
    float* nota;
    string curso;
    string estudiante;
};

void liberarMemoria(EstrucNotas* notas, int cantidadNotas) {
    for (int i = 0; i < cantidadNotas; ++i) {
        delete[] notas[i].nota;
    }
    delete[] notas; 
}

struct ListaDimEstudiantes{
    char** nombresEstudiantes;
    int cantidadEstudiantes;
    char** cursos;
    int cantidadCursos;
}; 

void liberarMemoriaEstudiantes(ListaDimEstudiantes* lista) {
    for (int i = 0; i < lista->cantidadEstudiantes; ++i) {
        delete[] lista->nombresEstudiantes[i];
    }
    delete[] lista->nombresEstudiantes;

    for (int j = 0; j < lista->cantidadCursos; ++j) {
        delete[] lista->cursos[j];
    }
    delete[] lista->cursos;

    delete lista;
}


int main() {

    return 0;
}