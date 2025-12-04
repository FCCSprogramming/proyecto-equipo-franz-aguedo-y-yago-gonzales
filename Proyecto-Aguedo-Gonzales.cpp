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


int main() {

    return 0;
}