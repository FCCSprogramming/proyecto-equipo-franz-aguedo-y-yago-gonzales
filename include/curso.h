#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

class Curso {
private:
    string nombre;
    int creditos;

public:
    Curso();
    Curso(string nombre, int creditos);
    Curso(const Curso& otro);

    string getNombre();
    void setNombre(string n);

    int getCreditos();
    void setCreditos(int b);

    void mostrarinformacion();
};

#endif
