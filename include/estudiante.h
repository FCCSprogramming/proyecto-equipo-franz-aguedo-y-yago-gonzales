#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"

class Estudiante : public Persona {
private:
    double promedio;

public:
    Estudiante();
    Estudiante(string n, int e, double p);
    Estudiante(const Estudiante& otro);

    double getPromedio() const;
    void setPromedio(double p);

    void mostrarinformacion() const override;
    void calculardesempenio() const override;
};

#endif
