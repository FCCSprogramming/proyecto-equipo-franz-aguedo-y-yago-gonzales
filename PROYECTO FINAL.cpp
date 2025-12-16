#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Inscripcion{
    int indEstudiante;
    int indCurso;
};

struct RegistroNotas{
    int indInscripcion;
    float* notas;
    int cantidadNota;
};

struct IndiceEstudiante {
    long posicion;
};

void escribirString(ofstream& archivo,const string& texto){
    int tam = texto.size();
    archivo.write((char*)&tam,sizeof(int));
    archivo.write(texto.c_str(),tam);
}

string leerString(ifstream& archivo){
    int tam;
    archivo.read((char*)&tam,sizeof(int));

    char* buffer = new char[tam + 1];
    archivo.read(buffer,tam);
    buffer[tam] = '\0';

    string texto(buffer);
    delete[] buffer;
    return texto;  
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
  virtual ~Persona() {}
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
            cout<<"Desempenio: BUENO"<<endl;
        }
        else if(promedio>=11){
            cout<<"Desempenio: REGULAR"<<endl;
        }else{
            cout<<"Desempenio: DEFICIENTE"<<endl;
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
    void mostrarReporte() const {
        if (cantidadRegistroNotas == 0) {
            cout << "No hay notas registradas."<<endl;
            return;
        }

        for (int i = 0; i < cantidadRegistroNotas; i++) {
            int ins = registroNotas[i].indInscripcion;

            int e = inscripciones[ins].indEstudiante;
            int c = inscripciones[ins].indCurso;
            cout<<endl;
            cout << "Estudiante: " << estudiantes[e].getNombre() << endl;
            cout << "Curso: " << cursos[c].getNombre() << endl;

            cout << "Notas: ";
            for (int j = 0; j < registroNotas[i].cantidadNota; j++) {
                cout << registroNotas[i].notas[j] << " ";
            }
            cout<<endl;
            float prom = calcularPromedio(registroNotas[i]);
            cout << "Promedio: " << prom << endl;
            cout << "---------------------------"<<endl;
        }
    }

    void crearAprobadosTXT() const {
        ofstream archivo("aprobados.txt");

        if (!archivo) {
            cout << "Error al crear el archivo."<<endl;
            return;
        }

        bool hayAprobados = false;

        for (int i = 0; i < cantidadRegistroNotas; i++) {
            float promedio = calcularPromedio(registroNotas[i]);

            if (promedio >= 11) {
                int idxIns = registroNotas[i].indInscripcion;
                int idxEst = inscripciones[idxIns].indEstudiante;
                int idxCur = inscripciones[idxIns].indCurso;

                archivo << estudiantes[idxEst].getNombre() << " | "
                        << cursos[idxCur].getNombre() << " | "
                        << promedio << endl;

                hayAprobados = true;
            }
        }

        archivo.close();

        if (hayAprobados) {
            cout << "Archivo 'aprobados.txt' generado correctamente."<<endl;
        } else {
            cout << "No hay estudiantes aprobados para exportar."<<endl;
        }
    }

    void guardarBinario() const{
        ofstream archivo("sistema.dat",ios::binary);

        if(!archivo){
            cout<<"Error al guardar el archivo."<<endl;
            return;
        }

        archivo.write((char*)&cantidadEstudiantes, sizeof(int));

        IndiceEstudiante* indice = new IndiceEstudiante[cantidadEstudiantes];

        long inicioIndice = archivo.tellp();
        archivo.seekp(sizeof(IndiceEstudiante) * cantidadEstudiantes, ios::cur);

        for (int i = 0; i < cantidadEstudiantes; i++) {
            indice[i].posicion = archivo.tellp();

            escribirString(archivo, estudiantes[i].getNombre());
            int edad = estudiantes[i].getEdad();
            double prom = estudiantes[i].getPromedio();
            archivo.write((char*)&edad, sizeof(int));
            archivo.write((char*)&prom, sizeof(double));
        }

        long finEstudiantes = archivo.tellp();
        archivo.seekp(inicioIndice, ios::beg);
        archivo.write((char*)indice, sizeof(IndiceEstudiante) * cantidadEstudiantes);

        archivo.seekp(finEstudiantes, ios::beg);
        delete[] indice;

        archivo.write((char*)&cantidadCursos,sizeof(int));
        for(int i = 0;i<cantidadCursos;i++){
            escribirString(archivo,cursos[i].getNombre());
            int creditos = cursos[i].getCreditos();
            archivo.write((char*)&creditos,sizeof(int));
        }

        archivo.write((char*)&cantdiadInscripciones,sizeof(int));
        for(int i=0;i<cantdiadInscripciones;i++){
            archivo.write((char*)&inscripciones[i],sizeof(Estudiante));
        }

        archivo.write((char*)&cantidadRegistroNotas,sizeof(int));
        for(int i = 0;i<cantidadRegistroNotas;i++){
            archivo.write((char*)&registroNotas[i].indInscripcion,sizeof(int));
            archivo.write((char*)&registroNotas[i].cantidadNota,sizeof(int));
            archivo.write((char*)&registroNotas[i].notas,sizeof(float)*registroNotas[i].cantidadNota);
        }

        archivo.close();
        cout << "Sistema guardado correctamente"<<endl;
    }
    void buscarEstudianteDirecto() const {
        ifstream archivo("sistema.dat", ios::binary);

        if (!archivo) {
            cout << "No existe archivo binario.\n";
            return;
        }

        int cant;
        archivo.read((char*)&cant, sizeof(int));

        IndiceEstudiante* indice = new IndiceEstudiante[cant];
        archivo.read((char*)indice, sizeof(IndiceEstudiante) * cant);

        int pos;
        cout << "Ingrese indice del estudiante (0 - " << cant - 1 << "): ";
        cin >> pos;

        if (pos < 0 || pos >= cant) {
            cout << "Indice invalido.\n";
            delete[] indice;
            archivo.close();
            return;
        }

        archivo.seekg(indice[pos].posicion, ios::beg);

        string nombre = leerString(archivo);
        int edad;
        double prom;
        archivo.read((char*)&edad, sizeof(int));
        archivo.read((char*)&prom, sizeof(double));

        cout << "--- ESTUDIANTE (ACCESO DIRECTO) ---"<<endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Promedio: " << prom << endl;

        delete[] indice;
        archivo.close();
    }


    void leerBinario() const{
        ifstream archivo("Sistema.dat",ios::binary);
        if(!archivo){
            cout <<"No existe el archivo."<<endl;
            return;
        }

        delete[] estudiantes;
        delete[] cursos;
        delete[] inscripciones;
        for(int i = 0;i < cantidadRegistroNotas;i++){
            delete[] registroNotas[i].notas;
        }
        delete[] registroNotas;

        archivo.read((char*)&cantidadEstudiantes,sizeof(int));

        for(int i=0;i<cantidadEstudiantes;i++){
            string nombre = leerString(archivo);
            int edad;
            double prom;
            archivo.read((char*)&edad,sizeof(int));
            archivo.read((char*)&prom,sizeof(double));
            estudiantes[i] = Estudiante(nombre,edad,prom);
        }

        archivo.read((char*)&cantidadCursos,sizeof(int));
        
        for(int i = 0;i<cantidadCursos;i++){
            string nombre = leerString(archivo);
            int cred;
            archivo.read((char*)&cred,sizeof(int));
            cursos[i] = Curso(nombre,cred);
        }

        archivo.read((char*)&cantdiadInscripciones,sizeof(int));
        
        for(int i = 0;i<cantdiadInscripciones;i++){
            archivo.read((char*)&inscripciones[i],sizeof(Inscripcion));
        }

        archivo.read((char*)&cantidadRegistroNotas,sizeof(int));
        

        for(int i=0;i<cantdiadInscripciones;i++){
            archivo.read((char*)&registroNotas[i].indInscripcion,sizeof(int));
            archivo.read((char*)&registroNotas[i].cantidadNota,sizeof(int));
            registroNotas[i].notas = new float[registroNotas[i].cantidadNota];
            archivo.read((char*)&registroNotas[i].notas,sizeof(float)*registroNotas[i].cantidadNota);
        }

        archivo.close();
        cout<<"Sistema cagado correctamente."<<endl;
    }



    void menu() {
        int opcion;

        do {
            cout << "===== SISTEMA DE GESTION ACADEMICA ====="<<endl;
            cout << "1. Registrar estudiante"<<endl;
            cout << "2. Listar estudiantes"<<endl;
            cout << "3. Registrar curso"<<endl;
            cout << "4. Listar cursos"<<endl;
            cout << "5. Inscribir estudiante a curso"<<endl;
            cout << "6. Listar inscripciones"<<endl;
            cout << "7. Registrar notas"<<endl;
            cout << "8. Mostrar reporte academico"<<endl;
            cout << "9. Crear archivo .txt con alumnos aprobados"<<endl;
            cout << "10. Guardar datos en archivo binario"<<endl;
            cout << "11. Leer datos del archivo binario"<<endl;
            cout << "12. Buscar Estudiante (Mediante acceso directo)"<<endl;
            cout << "0. Salir"<<endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    registrarEstudiantes();
                    break;
                case 2:
                    listarEstudiantes();
                    break;
                case 3:
                    registrarCursos();
                    break;
                case 4:
                    listarCurso();
                    break;
                case 5:
                    InscribirEstudiantes();
                    break;
                case 6:
                    listarInscripciones();
                    break;
                case 7:
                    registrarNotas();
                    break;
                case 8:
                    mostrarReporte();
                    break;
                case 9:
                    crearAprobadosTXT();
                    break;
                case 10:
                    guardarBinario();\
                    break;
                case 11:
                    leerBinario();
                    break;
                case 12:
                    buscarEstudianteDirecto();
                    break;
                case 0:
                    cout << "Saliendo del sistema..."<<endl;
                    break;
                default:
                    cout << "Opcion invalida."<<endl;
            }

        } while (opcion != 0);
    }
};


int main() {

    Sistema sistema;
    sistema.menu();

    return 0;
}