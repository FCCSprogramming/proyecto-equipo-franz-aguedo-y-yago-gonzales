#include "persona.h"
#include <iostream>
#include <string>

Persona::Persona():nombre("Sin nombre"),edad(0){}
Persona::Persona(string nombre,int edad){ this->nombre=nombre; this->edad=edad; }
Persona::Persona(const Persona& otro){ nombre=otro.nombre; edad=otro.edad; }

string Persona::getNombre() const { return nombre; }
void Persona::setNombre(string n){ nombre=n; }
int Persona::getEdad() const { return edad; }
void Persona::setEdad(int n){ edad=n; }

void Persona::actualizardatos(string nombre,int edad){
    this->nombre=nombre;
    this->edad=edad;
}

void Persona::calculardesempenio() const{
    cout<<"Desempeño general de la persona.\n"<<endl;
}

Persona::~Persona(){}
