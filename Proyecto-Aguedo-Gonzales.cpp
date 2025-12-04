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

class Persona{
  private: 
  string nombre;
  int edad;
  public:
  Persona():nombre("Sin nomrbre"),edad(0){}
  Persona(string nombre,int edad){
      this->nombre=nombre;
      this->edad=edad;
  }
  Persona(const Persona& otro){
      this->nombre=otro.nombre;
      this->edad=otro.edad;
  }
  strign getNombre(){
      return nombre;
  }
  void setNombre(string n){
      nombre=n;
  }
  int getEdad(){
      return edad;
  }
  void setEdad(int n){
      edad=n;
  }
  void actualizardatos(string nombre,int edad){
      this->nombre=nombre;
      this->edad=edad;
  }
  virtual void mostrarinformacion()const=0;
  virtual float calculardesempenio()const{
      cout<<"Desempeño general de la persona.\n"  <<endl;
  }
};

class Estudiante:public Persona{
    private:
    double promedio;
    public:
    Estudiante():Persona(),promedio(0.0){}
    Estudiante(string n, int e,double p):Persona(n,e),promedio(promedio){}
    Estudiante(const Estudiante& otro):Persona(otro){
        this->promedio=otro.promedio;
    }
    double getPromedio()const{
        return promedio;
    }
    void setPromedio(double p){
        if(p>=0 && p<=20){
        this->promedio=p;
        }
    }
    
    void mostrarinformacion()const override{
        cout<<"Nombre: "<<getNombre()<<endl;
        cout<<"Edad: "<<getEdad()<<endl;
        cout<<"Promedio: "<<promedio<<endl;
    }
    
    void calculardesempenio()const override{
        if(promedio>=14){
            cout<<"Desempeño: BUENO"<<endl;
        }
        else if(promedio>=11){
            cout<<"Desempeño: REGULAR"<<endl;
        }else{
            cout<<"Desempeño: DEFICIENTE"<<endl;
        }
    }
};

class Curso{
    private:
    string nombre;
    int creditos;
    public:
    Curso():nombre("Sin nombre"),creditos(0){}
    Curso(string nombre,int creditos){
        this->nombre=nombre;
        this->creditos=creditos;
    }
    Curso(const Curso& otro){
        this->nombre=otro.nombre;
        this->creditos=otro.creditos;
    }
    string getNombre(){
        return nombre;
    }
    void setNombre(string n){
        nombre=n;
    }
    int getCreditos(){
        return creditos;
    }
    void setCreditos(int b){
        creditos=b;
    }
    void mostrarinformacion(){
        cout<<"Nombre del curso: "<<getNombre<<endl;
        cout<<"Creditos: "<<getCreditos<<endl;
    }
};

class Sistema
int main() {

    return 0;
}
