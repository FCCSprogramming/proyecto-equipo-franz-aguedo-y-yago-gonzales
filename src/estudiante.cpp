#include "estudiante.h"
#include <iostream>

Estudiante::Estudiante():Persona(),promedio(0.0){}
Estudiante::Estudiante(string n,int e,double p):Persona(n,e),promedio(p){}
Estudiante::Estudiante(const Estudiante& otro):Persona(otro){ promedio=otro.promedio; }

double Estudiante::getPromedio() const { return promedio; }

void Estudiante::setPromedio(double p){
    if(p>=0 && p<=20) promedio=p;
}

void Estudiante::mostrarinformacion() const{
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Edad: "<<getEdad()<<endl;
    cout<<"Promedio: "<<promedio<<endl;
}

void Estudiante::calculardesempenio() const{
    if(promedio>=14) cout<<"Desempenio: BUENO"<<endl;
    else if(promedio>=11) cout<<"Desempenio: REGULAR"<<endl;
    else cout<<"Desempenio: DEFICIENTE"<<endl;
}
