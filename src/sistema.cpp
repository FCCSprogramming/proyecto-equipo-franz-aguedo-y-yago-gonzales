#include "sistema.h"
#include <iostream>
#include <fstream>
using namespace std;

Sistema::Sistema()
    : estudiantes(nullptr), cantidadEstudiantes(0), cursos(nullptr), cantidadCursos(0) {}

Sistema::~Sistema() {
    delete[] estudiantes;
    delete[] cursos;
}

void Sistema::registrarEstudiantes() {
    string nombre;
        int edad;
        double promedio;

        cout << "Nombre del estudiante: ";
        cin.ignore();
        getline(cin,nombre);
        cout << "Edad: ";
        cin >> edad;
        cout << "Promedio: ";
        cin >> promedio;
        Estudiante* nuevo = new Estudiante[cantidadEstudiantes + 1];
        for(int i = 0;i <cantidadEstudiantes;i++){
            nuevo[i] = estudiantes[i];
        }
        nuevo[cantidadEstudiantes]= Estudiante(nombre, edad , promedio);

        delete[] estudiantes;
        estudiantes = nuevo;
        cantidadEstudiantes++;

        cout<<"Estudiante Registrado"<<endl;
}

void Sistema::listarEstudiantes() const {
    if(cantidadEstudiantes == 0){
            cout<<"No hay ningun estudiante registrado"<<endl;
            return;
        }
        for(int i=0;i<cantidadEstudiantes;i++){
            estudiantes[i].mostrarinformacion();
            estudiantes[i].calculardesempenio();
            cout<<"-----------------------------------------"<<endl;
        }
}

// Aquí va el resto de tu código para el Sistema.
void Sistema::menu() {
    int opcion;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar estudiantes\n";
        cout << "2. Listar estudiantes\n";
        cout << "3. Registrar cursos\n";
        cout << "4. Listar cursos\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarEstudiantes(); break;
            case 2: listarEstudiantes(); break;
            case 3: registrarCursos(); break;
            case 4: listarCurso(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (opcion != 0);
}
void Sistema::registrarCursos() {
     string nombre;
        int creditos;
        cout<<"Nombre del curso: ";
        cin.ignore();
        getline(cin,nombre);
        cout<<"Creditos: ";
        cin>>creditos;

        Curso* nuevo = new Curso[cantidadCursos + 1];
        for(int i =0 ; i< cantidadCursos;i++){
            nuevo[i] = cursos[i];
        }

        nuevo[cantidadCursos] = Curso(nombre,creditos);

        delete[] cursos;
        cursos = nuevo;
        cantidadCursos++;

        cout<<"Curso registrado correctamente"<<endl;
    
}

void Sistema::listarCurso() const {
    if(cantidadCursos == 0){
            cout<<"No hay un curso registrado"<<endl;
            return;
        }
        for(int i =0;i<cantidadCursos;i++){
            cout<<"curso: "<<cursos[i].getNombre()<<endl;
            cout<<"Creditos: "<<cursos[i].getCreditos()<<endl;
            cout <<"-----------------------------------------"<<endl;
        }
    
}

