#include <iostream>
#include <string>
using namespace std;

struct EstrucNotas{
    float* nota;
    int cantidadNotas;
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

struct Inscripcion{
    int indEstudiante;
    int indCurso;
};

struct RegistroNotas{
    int indInscripcion;
    float* notas;
    int cantidadNota;
};

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
  string getNombre() const{
      return nombre;
  }
  void setNombre(string n){
      nombre=n;
  }
  int getEdad() const{
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
  virtual void calculardesempenio()const{
      cout<<"Desempeño general de la persona.\n"  <<endl;
  }
  virtual ~Persona(){}
};

class Estudiante:public Persona{
    private:
    double promedio;
    public:
    Estudiante():Persona(),promedio(0.0){}
    Estudiante(string n, int e,double p):Persona(n,e),promedio(p){}
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
        cout<<"Edad: "<< getEdad() <<endl;
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
        cout<<"Nombre del curso: "<< getNombre() <<endl;
        cout<<"Creditos: "<< getCreditos() <<endl;
    }
};

class Sistema{
    private:
    Estudiante* estudiantes;
    int cantidadEstudiantes;
    Curso* cursos;
    int cantidadCursos;
    Inscripcion* inscripciones;
    int cantdiadInscripciones;
    RegistroNotas* registroNotas;
    int cantidadRegistroNotas;
    public:
    Sistema():estudiantes(nullptr),cantidadEstudiantes(0),cursos(nullptr),cantidadCursos(0),inscripciones(nullptr),cantdiadInscripciones(0),registroNotas(nullptr),cantidadRegistroNotas(0){}

    ~Sistema(){
        for(int i =0;i<cantidadRegistroNotas;i++){
            delete[] registroNotas[i].notas;
        }
        delete[] estudiantes;
        delete[] cursos;
        delete[] inscripciones;
        delete[] registroNotas;
    }

    void registrarEstudiantes(){
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

    void listarEstudiantes() const{
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

    void registrarCursos(){
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

    void listarCurso() const{
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
    void listarEstudiantesconInd() const{
        for(int i =0;i<cantidadEstudiantes;i++){
            cout <<i<<"."<<estudiantes[i].getNombre()<<endl;
        }
    }
    void listarCursosconInd() const{
        for(int i = 0;i<cantidadCursos;i++){
            cout<<i<<"."<<cursos[i].getNombre()<<endl;
        }
    }

    void InscribirEstudiantes(){
        if(cantidadEstudiantes == 0||cantidadCursos == 0){
            cout <<"Debe haber estudiantes y cursos registrados."<<endl;
            return;
        }

        cout<<"-------- Estudiante ---------"<<endl;
        listarEstudiantesconInd();

        int e;
        cout<<"Seleccione indice del estudiante: ";
        cin>>e;

        if(e<0 || e >= cantidadEstudiantes){
            cout <<"Estudiante invalido"<<endl;
            return;
        }

        cout<<"--------- Cursos -----------"<<endl;
        listarCursosconInd();

        int c;
        cout<<"Seleccione indice del curso: ";
        cin>>c;

        if(c<0||c>=cantidadCursos){
            cout <<"Curso invalido"<<endl;
            cin>>c;
        }

        Inscripcion* nuevo = new Inscripcion[cantdiadInscripciones+1];

        for(int i=0;i<cantdiadInscripciones;i++){
            nuevo[i] = inscripciones[i];
        }

        nuevo[cantdiadInscripciones].indCurso = c;
        nuevo[cantdiadInscripciones].indEstudiante = e;

        delete[] inscripciones;
        inscripciones = nuevo;
        cantdiadInscripciones++;

        cout<<"Inscripcion realizada correctamente."<<endl;
    }

    void listarInscripciones() const{
        if(cantdiadInscripciones == 0){
            cout <<"No hay inscripciones"<<endl;
            return;
        }

        for(int i = 0;i<cantdiadInscripciones;i++){
            cout << "Estudiante: "
            << estudiantes[inscripciones[i].indEstudiante].getNombre()
            << " | Curso: "
            << cursos[inscripciones[i].indCurso].getNombre()
            << endl;
        }
    }

    void registrarNotas(){
        if(cantdiadInscripciones == 0){
            cout <<"No hay inscripciones registradas"<<endl;
            return;
        }

        cout <<"----------- Inscripciones ------------"<<endl;
        listarInscripciones();

        int idx;
        cout<<"Seleccione indice de inscripcion: ";
        cin>>idx;

        if(idx<0||idx>=cantdiadInscripciones){
            cout<<"Indice Invalido"<<endl;
            return;
        }

        int n;
        cout<<"Cantidad de notas a registrar: ";
        cin>>n;
        if(n<=0){
            cout<<"Cantidad invalida"<<endl;
            return;
        }

        RegistroNotas reg;
        reg.indInscripcion = idx;
        reg.cantidadNota =n;
        reg.notas = new float[n];

        for(int i = 0;i<n;i++){
            cout<<"Nota "<<i+1<<": ";
            cin>>reg.notas[i];
        }

        RegistroNotas* nuevo = new RegistroNotas{cantidadRegistroNotas + 1};

        for(int i = 0;i<cantidadRegistroNotas;i++){
            nuevo[i] = registroNotas[i];
        }

        nuevo[cantidadRegistroNotas] = reg;

        delete[] registroNotas;
        registroNotas = nuevo;
        cantidadRegistroNotas++;

        cout<<"Notas registrada correctamente"<<endl;
    }
    
    float calcularPromedio(const RegistroNotas& r) const{
        float suma = 0;
        for(int i = 0;i<r.cantidadNota;i++){
            suma += r.notas[i];
        }
        return suma/r.cantidadNota;
    }

    
};
int main() {

    return 0;
}
