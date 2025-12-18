#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona();
    Persona(string nombre, int edad);
    Persona(const Persona& otro);

    string getNombre() const;
    void setNombre(string n);

    int getEdad() const;
    void setEdad(int n);

    void actualizardatos(string nombre, int edad);

    virtual void mostrarinformacion() const = 0;
    virtual void calculardesempenio() const;
    virtual ~Persona();
};

#endif
