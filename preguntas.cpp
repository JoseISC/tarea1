#include <iostream>
#include <vector>
#include <string>
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
    virtual ~Pregunta();
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
    virtual int get_tipo();
    virtual void set_correct_resp()=0;
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
int Pregunta::get_tipo(){return 0;}

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
    void set_correct_resp();
    bool get_correct_resp();
    void set_justificacion(string justificacion);
    string get_justificacion();
    int get_tipo();
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
void Verdadero_Falso::set_correct_resp(){
  int opcion_resp;
  bool correct_resp;
  cout << "(1. Verdadero) (2. Falso) Ingrese la respuesta correcta: ";
  cin >> opcion_resp;
  if (opcion_resp == 1){
    correct_resp = true;
  } else{
    correct_resp = false;
  }; 
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
int Verdadero_Falso::get_tipo(){
  return 1;
}

// CLASSE PREGUNTA DE SELECCION MULTIPLE
class Seleccion_Mult : public Pregunta {  
  private :
    //ATRIBUTOS PARTICULARES
    string correct_resp;
    vector<string> dists;
  public:
    //CONSTRUCTOR - DESTRUCTOR
    Seleccion_Mult(string correct_resp, int n_pregunta, string enunciado, string niv_tax, float tiempo_est);
    Seleccion_Mult();
    ~Seleccion_Mult();
    //METODOS
    string get_correct_resp();
    string get_dists(int i);
    void set_correct_resp();
    void set_dists();
    int get_tipo();
};
//DEFINICION DE CONSTRUCTOR
void Seleccion_Mult::set_dists(){
  int cant_distractores;
  string distractor;
  cout<<"Ingresa la cantidad de distractores: ";
  cin>>cant_distractores;
  if(cant_distractores>4){
    cout<<"La cantidad de distractores no puede ser mayor que 4"<<endl;
    cout<<"Se establecera la cantidad de distractores en 4"<<endl;
    cant_distractores = 4;
  };
  for(int i = 0; i < cant_distractores; i++){
    cout<<"Ingresa el distractor "<<i+1<<": ";
    cin>>distractor;
    this->dists.push_back(distractor);
    cout<<endl;
  }
};
Seleccion_Mult::Seleccion_Mult(string correct_resp, int n_pregunta, string enunciado, string niv_tax, float tiempo_est) : Pregunta(n_pregunta, enunciado, niv_tax, tiempo_est) {
  this->correct_resp = correct_resp;
  this->set_dists();
};
//DEFINICION DE DESTRUCTOR
Seleccion_Mult::~Seleccion_Mult(){
  //ESTE SE TIENE QUE MATAR PRIMERO Y LUEGO SE MATA AL PADRE
}
//METODOS DE CLASE SELECCION MULTIPLE
string Seleccion_Mult::get_correct_resp(){
  return this->correct_resp;
};
string Seleccion_Mult::get_dists(int i){
  if (i < 0 || i >= this->dists.size()){  
    return this->dists[i];  
  }else{
    return "No existe ese distractor";
  };
};
void Seleccion_Mult::set_correct_resp(){
  string nueva_respuesta;
  cout << "Ingrese la respuesta correcta: ";
  cin.ignore();
  getline(cin, nueva_respuesta);
  if(!nueva_respuesta.empty())
  this->correct_resp = nueva_respuesta;
};
int Seleccion_Mult::get_tipo(){
  return 2;
}

