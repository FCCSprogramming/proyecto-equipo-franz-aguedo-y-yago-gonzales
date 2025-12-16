#include "curso.h"
#include <iostream>
#include <string>

using namespace std;

Curso::Curso():nombre("Sin nombre"),creditos(0){}

Curso::Curso(string nombre,int creditos){
    this->nombre=nombre;
    this->creditos=creditos;
}

Curso::Curso(const Curso& otro){
    this->nombre=otro.nombre;
    this->creditos=otro.creditos;
}

string Curso::getNombre(){
    return nombre;
}

void Curso::setNombre(string n){
    nombre=n;
}

int Curso::getCreditos(){
    return creditos;
}

void Curso::setCreditos(int b){
    creditos=b;
}

void Curso::mostrarinformacion(){
    cout<<"Nombre del curso: "<< getNombre() <<endl;
    cout<<"Creditos: "<< getCreditos() <<endl;
}
