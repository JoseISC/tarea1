#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <sstream>
#include <string>
#include "preguntas.h"

using namespace std;
using namespace preguntas;

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
    int get_max_preguntas();
    int get_cant_preguntas();
};

Prueba::Prueba(int tot_preguntas, float tot_tiempo){
    this->tot_preguntas = tot_preguntas;
    this->tot_tiempo = tot_tiempo;
}
Prueba::~Prueba(){
  //AGREGAR LOGICA DE ELIMINACION DE PREGUNTAS Y LUEGO ELIMINAR PRUEBA  
  for (int i = 0; i < this->preguntas.size(); i++){
    delete this->preguntas[i];
  }
  this->preguntas.clear();
  this->tot_preguntas = 0;
  this->tot_tiempo = 0;
  cout << "Se elimino la prueba" << endl;
}
void Prueba::insertar_pregunta(Pregunta *pregunta){
  this->preguntas.push_back(pregunta);
};
int Prueba::get_cant_preguntas(){
  return this->preguntas.size();
};
int Prueba::get_max_preguntas(){
  return this->tot_preguntas;
}
void Prueba::eliminar_pregunta(int n_pregunta){
  delete this->preguntas[n_pregunta - 1];
}
void Prueba::modificar_pregunta(int n_pregunta){
  int tipo = this->preguntas[n_pregunta - 1] -> get_tipo();
  if (tipo == 1){
    string input;

    cout << "Modificar el enunciado: " << endl;
    cin.ignore();
    getline(cin,input);
    if(!input.empty()){
      this->preguntas[n_pregunta - 1]->set_enunciado(input);
    }

    cout << "Modificar el nivel taxonomico: "<< endl;
    cin.ignore();
    getline(cin,input);
    if(!input.empty()){
      this->preguntas[n_pregunta - 1]->set_niv_tax(input);
    }

    cout << "Modificar el tiempo estimado: "<< endl;
    cin.ignore();
    getline(cin,input);
    if(!input.empty()){
      this->preguntas[n_pregunta - 1]->set_tiempo_est(stoi(input));
    }

    cout << "Modificar la respuesta correcta: "<< endl;   

    this->preguntas[n_pregunta - 1]->set_correct_resp();


    cout << "Modificar la justificacion: "<< endl;
    getline(cin,input);  
    if(!input.empty()){
      ((Verdadero_Falso *)this->preguntas[n_pregunta - 1])->set_justificacion(input);
    }
    cout << "Se modifico la pregunta" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }else{
    string input;
    cout << "Modificar el enunciado: " << endl;
    cin.ignore();
    getline(cin,input);
    if(!input.empty()){
      this->preguntas[n_pregunta - 1]->set_enunciado(input);
    }
    cout << "Modificar el nivel taxonomico: "<< endl;
    cin.ignore();
    getline(cin,input);
    if(!input.empty()){
      this->preguntas[n_pregunta - 1]->set_niv_tax(input);
    }
    cout << "Modificar el tiempo estimado: "<< endl;
    cin.ignore();
    getline(cin,input);
    if(!input.empty()){
      this->preguntas[n_pregunta - 1]->set_tiempo_est(stoi(input));
    }
    cout << "Modificar la respuesta correcta: "<< endl;
    this->preguntas[n_pregunta - 1]->set_correct_resp();
    cout << "Modificar los distractores: "<< endl;
    ((Seleccion_Mult *)this->preguntas[n_pregunta - 1])->set_dists();
    cout << "Se modifico la pregunta" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));    
  }
  }
void Prueba::mostrar_preguntas(){
  for (int i = 0; i < this->preguntas.size(); i++){
    if(preguntas[i]==NULL){
      cout<<"Pregunta eliminada"<<endl;
    }
    else{
      cout << preguntas[i]->get_n_pregunta() << ". " << preguntas[i]->get_enunciado() << endl;
    }
  }
}
