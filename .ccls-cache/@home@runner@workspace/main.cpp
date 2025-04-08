//Raphaël Maufroy
//José Salazar Cabello

#include <iostream>
#include <vector>
using namespace std;

// CLASE PREGUNTA
class Pregunta{
  private:
    //ATRIBUTOS
    int n_pregunta;
    string enunciado;
    string niv_tax;
    float tiempo_est;
    Pregunta *siguiente;
  public:
    //CONSTRUCTOR - DESTRUCTOR
    Pregunta();
    Pregunta(int n_pregunta, string enunciado, string niv_tax, float tiempo_est);
    ~Pregunta();
    //METODOS
    int get_n_pregunta();
    string get_enunciado();
    string get_niv_tax();
    float get_tiempo_est();
    void set_enunciado(string enunciado);
    void set_niv_tax(string niv_tax);
    void set_tiempo_est(float tiempo_est);
    Pregunta *get_siguiente();
    void set_siguiente(Pregunta *siguiente);
};
//DEFINICION DE CONSTRUCTOR
Pregunta::Pregunta(int n_pregunta, string enunciado, string niv_tax, float tiempo_est){
  this->n_pregunta = n_pregunta;
  this->enunciado = enunciado;
  this->niv_tax = niv_tax;
  this->tiempo_est = tiempo_est;
  this->siguiente = NULL;
}
//DEFINICION DE DESTRUCTOR
Pregunta::~Pregunta(){
  //AGREGAR LOGICA PARA MATAR HIJOS Y LUEGO EL PADRE
}
//DEFINICION DE METODOS DE CLASE PREGUNTA
void Pregunta::set_siguiente(Pregunta *siguiente){
  this->siguiente = siguiente;
};
Pregunta *Pregunta::get_siguiente(){
  return this->siguiente;
}
void Pregunta::set_enunciado(string enunciado){
  this->enunciado = enunciado;
}
string Pregunta::get_enunciado(){
  return this->enunciado;
}
void Pregunta::set_niv_tax(string niv_tax){
  this->niv_tax = niv_tax;
}
string Pregunta::get_niv_tax(){
  return this->niv_tax;
}
void Pregunta::set_tiempo_est(float tiempo_est){
  this->tiempo_est = tiempo_est;
}
float Pregunta::get_tiempo_est(){
  return this->tiempo_est;
}
int Pregunta::get_n_pregunta(){
  return this->n_pregunta;
}


// CLASE PREGUNTA DE VERDADERO O FALSO
class Verdadero_Falso : public Pregunta{
  private:
    //ATRIBUTOS PARTICULARES
    bool correct_resp;
    string justificacion;
  public:
    //CONSTRUCTOR - DESTRUCTOR
    Verdadero_Falso(int n_pregunta);
    Verdadero_Falso(int n_pregunta, string enunciado, string niv_tax, float tiempo_est, bool correct_resp, string justificacion);
    ~Verdadero_Falso();
    //METODOS
    void set_correct_resp(bool correct_resp);
    bool get_correct_resp();
    void set_justificacion(string justificacion);
    string get_justificacion();
};
//DEFINICION DE CONSTRUCTOR
Verdadero_Falso::Verdadero_Falso(int n_pregunta, string enunciado, string niv_tax, float tiempo_est, bool correct_resp, string justificacion) : Pregunta(n_pregunta, enunciado, niv_tax, tiempo_est){
  this->correct_resp = correct_resp;
  this->justificacion = justificacion;
};
//DEFINICION DE DESTRUCTOR
Verdadero_Falso::~Verdadero_Falso(){
  //ESTE SE TIENE QUE MATAR PRIMERO Y LUEGO SE MATA AL PADRE
}
//METODOS DE CLASE VERDADERO O FALSO
void Verdadero_Falso::set_correct_resp(bool correct_resp){
  this->correct_resp = correct_resp;
};
bool Verdadero_Falso::get_correct_resp(){
  return this->correct_resp;
};
void Verdadero_Falso::set_justificacion(string justificacion){
  this->justificacion = justificacion;
};
string Verdadero_Falso::get_justificacion(){
  return this->justificacion;
};

// CLASSE PREGUNTA DE SELECCION MULTIPLE
class Seleccion_Mult : public Pregunta {  
  private :
    //ATRIBUTOS PARTICULARES
    string correct_resp;
    string dist1;
    string dist2;
    string dist3;
    string dist4;
  public:
    //CONSTRUCTOR - DESTRUCTOR
    Seleccion_Mult(string correct_resp, string dist1, string dist2, string dist3, string dist4, int n_pregunta, string enunciado, string niv_tax, float tiempo_est);
    Seleccion_Mult();
    ~Seleccion_Mult();
    //METODOS
    string get_correct_resp();
    string get_dists();
    void set_correct_resp(string correct_resp);
    void set_dist1(string dist1);
    void set_dist2(string dist2);
    void set_dist3(string dist3);
    void set_dist4(string dist4);
};
//DEFINICION DE CONSTRUCTOR
Seleccion_Mult::Seleccion_Mult(string correct_resp, string dist1, string dist2, string dist3, string dist4,int n_pregunta, string enunciado, string niv_tax, float tiempo_est) : Pregunta(n_pregunta, enunciado, niv_tax, tiempo_est) {
  this->correct_resp = correct_resp;
  this->dist1 = dist1;
  this->dist2 = dist2;
  this->dist3 = dist3;
  this->dist4 = dist4;
};
//DEFINICION DE DESTRUCTOR
Seleccion_Mult::~Seleccion_Mult(){
  //ESTE SE TIENE QUE MATAR PRIMERO Y LUEGO SE MATA AL PADRE
}
//METODOS DE CLASE SELECCION MULTIPLE
string Seleccion_Mult::get_correct_resp(){
  return this->correct_resp;
};
string Seleccion_Mult::get_dists(){
  return this->dist1 + "\n" + this->dist2 + "\n" + this->dist3 + "\n" + this->dist4;
};
void Seleccion_Mult::set_correct_resp(string correct_resp){
  this->correct_resp = correct_resp;
};
void Seleccion_Mult::set_dist1(string dist1){
  this->dist1 = dist1;
};
void Seleccion_Mult::set_dist2(string dist2){
  this->dist1 = dist2;
};
void Seleccion_Mult::set_dist3(string dist3){
  this->dist1 = dist3;
};
void Seleccion_Mult::set_dist4(string dist4){
  this->dist1 = dist4;
};


//
class Prueba {
  private:
    int tot_preguntas;
    float tot_tiempo;
    vector <Pregunta *> preguntas;
  public:
    Prueba(int tot_preguntas, float tot_tiempo);
    ~Prueba();
    void insertar_pregunta(Pregunta *pregunta);
    void eliminar_pregunta(int n_pregunta);
    void modificar_pregunta(int n_pregunta);
    void mostrar_preguntas();
    void crear_prueba();
    
};

Prueba::Prueba(int tot_preguntas, float tot_tiempo){
    this->tot_preguntas = tot_preguntas;
    this->tot_tiempo = tot_tiempo;
}
Prueba::~Prueba(){
  //AGREGAR LOGICA DE ELIMINACION DE PREGUNTAS Y LUEGO ELIMINAR PRUEBA
  
}
void Prueba::insertar_pregunta(Pregunta *pregunta){
  this->preguntas.push_back(*pregunta);
};
