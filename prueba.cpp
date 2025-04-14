#include "prueba.h"
#include <iostream>
#include <chrono>
#include <thread>
#define SLEEP 1

using namespace std;
using namespace prueba;

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

void Prueba::recalcular_tiempo_total() {
    float nuevo_tiempo = 0;
    for (Pregunta* pregunta : preguntas) {
        nuevo_tiempo += pregunta->get_tiempo_est();
    }
    this->tot_tiempo = nuevo_tiempo;
}

void Prueba::insertar_pregunta(Pregunta *pregunta){
    this->preguntas.push_back(pregunta);
    this->recalcular_tiempo_total();
}

int Prueba::get_cant_preguntas(){
  return this->preguntas.size();
}

int Prueba::get_max_preguntas(){
  return this->tot_preguntas;
}

void Prueba::eliminar_pregunta(int n_pregunta){
    this->preguntas.erase(this->preguntas.begin() + n_pregunta - 1);
    this->recalcular_tiempo_total();
}

void Prueba::modificar_pregunta(int n_pregunta){
    int tipo = this->preguntas[n_pregunta - 1]->get_tipo();
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
            this->preguntas[n_pregunta - 1]->set_tiempo_est(stof(input));
            this->recalcular_tiempo_total();
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
            this->preguntas[n_pregunta - 1]->set_tiempo_est(stof(input));
            this->recalcular_tiempo_total();
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
  if(this->preguntas.size() == 0){
    cout << "No hay preguntas que mostrar" << endl;
  } else {
  for (int i = 0; i < this->preguntas.size(); i++){
    if(preguntas[i]==NULL){
      cout<<"Pregunta eliminada"<<endl;
    }
    else{
      cout << preguntas[i]->get_n_pregunta() << ". " << preguntas[i]->get_enunciado() << endl;
    }
    }
  }
}