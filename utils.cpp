#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <sstream>
#include <string>
#include "prueba.h"
#include "preguntas.h"

using namespace std;
using namespace preguntas;
using namespace prueba;

void limpiar_pantalla() {
    int dummy = system("clear");
    (void)dummy;
}

namespace menu {
  class Menu {
    private:
      int opcion;
      vector <Prueba *> pruebas;
    public:
      void mostrar_menu();
      void ejecutar_opcion_1();
      void ejecutar_opcion_2();
      void ejecutar_opcion_3();
      void ejecutar_opcion_4();
      void ejecutar_opcion_5();
      void ejecutar_opcion_6();
  };
}
void menu::Menu::ejecutar_opcion_1(){  
  int tot_preguntas;
  float tot_tiempo;
  limpiar_pantalla();
  cout << "Crear prueba" << endl;
  cout << "Ingrese el numero de preguntas: ";
  cin >> tot_preguntas;
  cout << "Ingrese el tiempo total estimado para la prueba (default 3 minutos por pregunta): ";
  cin >> tot_tiempo;
  if (tot_preguntas > 0){
    if (tot_tiempo > 0){
      Prueba *prueba = new Prueba(tot_preguntas, tot_tiempo);
      this->pruebas.push_back(prueba);
    } else {
      cout << tot_preguntas * 3 <<" minutos" << endl;
      Prueba *prueba = new Prueba(tot_preguntas, tot_preguntas * 3);
      this->pruebas.push_back(prueba);
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }
  }  
};
void menu::Menu::ejecutar_opcion_2(){
  int id_prueba;
  limpiar_pantalla();
  cout << "Insertar pregunta" << endl;
  cout << "Ingrese el numero de la prueba: ";
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()){
      while(true){
        if (this->pruebas[id_prueba - 1]->get_cant_preguntas() < this->pruebas[id_prueba - 1]->get_max_preguntas()){
          int tipo_pregunta;
          limpiar_pantalla();
          cout << "Insertar pregunta" << endl;
          cout << "1.\tPregunta de Verdadero o Falso"<<endl;
          cout<<"2.\tSeleccion Multiple"<< endl;
          cout<<"3.\tSalir"<<endl;
          cout << "Ingrese una opcion: ";
          cin>>tipo_pregunta;
          if (tipo_pregunta == 1){
            int n_pregunta = this->pruebas[id_prueba - 1]->get_cant_preguntas() + 1;
            string enunciado;
            string niv_tax;
            float tiempo_est = 3;
            int opcion_resp;
            bool correct_resp;
            string justificacion;
            cin.ignore();
            cout << "Ingrese el enunciado: ";
            getline(cin, enunciado);
            cout << "Ingrese el nivel taxonomico: ";
            cin >> niv_tax;
            cout << "Ingrese el tiempo estimado: ";
            cin >> tiempo_est;
            cout << "(1. Verdadero) (2. Falso) Ingrese la respuesta correcta: ";
            cin >> opcion_resp;
            if (opcion_resp == 1)
              correct_resp = true;
            else
              correct_resp = false;
            cin.ignore();
            cout << "Ingrese la justificacion: ";
            getline(cin,justificacion);
            Pregunta *pregunta = new Verdadero_Falso(n_pregunta, enunciado, niv_tax, tiempo_est, correct_resp, justificacion);
            pruebas[id_prueba - 1]->insertar_pregunta(pregunta);
            cout << "Se inserto la pregunta" << endl;
            this_thread::sleep_for(chrono::seconds(SLEEP));
          } 
          else if (tipo_pregunta == 2){
            int n_pregunta = this->pruebas[id_prueba - 1]->get_cant_preguntas() + 1;
            string enunciado;
            string niv_tax;
            float tiempo_est = 3;
            string correct_resp;
            cout << "Ingrese el enunciado: ";
            getline(cin, enunciado);
            cout << "Ingrese el nivel taxonomico: ";
            cin >> niv_tax;
            cout << "Ingrese el tiempo estimado: ";
            cin >> tiempo_est;
            cin.ignore();
            cout << "Ingrese la respuesta correcta: ";
            getline(cin, correct_resp);
            Pregunta *pregunta = new Seleccion_Mult(correct_resp, n_pregunta, enunciado, niv_tax, tiempo_est);
            pruebas[id_prueba - 1]->insertar_pregunta(pregunta);
            cout << "Se inserto la pregunta" << endl;
            this_thread::sleep_for(chrono::seconds(SLEEP));
          } 
          else if(tipo_pregunta==3){
            break;
          } 
          else {
            cout << "Opcion invalida" << endl;
            this_thread::sleep_for(chrono::seconds(SLEEP));
          }
        } else {
          cout << "No se puede insertar mas preguntas" << endl;
          this_thread::sleep_for(chrono::seconds(SLEEP));
          break;
        }
      }
    } else {
      cout << "No existe esa prueba" << endl;
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }
}
void menu::Menu::ejecutar_opcion_3(){
  int id_prueba;
  int id_pregunta;
  limpiar_pantalla();
  cout << "Eliminar pregunta" << endl;    
  cout << "Ingrese el numero de la prueba: " << endl;  
  cin >> id_prueba;  
  if(id_prueba > 0 && id_prueba <= this->pruebas.size()){
    pruebas[id_prueba-1]->mostrar_preguntas();
    cout << "Ingrese el numero de la pregunta: " << endl;
    cin >> id_pregunta;
    if (id_pregunta > 0 && id_pregunta <= this->pruebas[id_prueba-1]->get_cant_preguntas()){
        pruebas[id_prueba-1]->eliminar_pregunta(id_pregunta);
        cout << "Se elimina la pregunta" << endl;
        this_thread::sleep_for(chrono::seconds(SLEEP));
    }    

  } else{
    cout << "No existe esa prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
};

void menu::Menu::ejecutar_opcion_4(){
  int id_prueba;
  int id_pregunta;
  limpiar_pantalla();
  cout << "Modificar pregunta" << endl;
  cout << "Ingrese el numero de la prueba: " << endl;  
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()){
    cout << "Aqui estan las preguntas: " << endl;
    pruebas[id_prueba-1]->mostrar_preguntas();
    cout << "Ingrese el numero de la pregunta: " << endl;
    cin >> id_pregunta;
    if (id_pregunta > 0 && id_pregunta <= this->pruebas[id_prueba-1]->get_cant_preguntas()){
        pruebas[id_prueba-1]->modificar_pregunta(id_pregunta);
        cout << "Se modifico la pregunta" << endl;
        this_thread::sleep_for(chrono::seconds(SLEEP));
    }    
  } else {
    cout << "No existe esa prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
}

void menu::Menu::ejecutar_opcion_5(){
  int id_prueba;
  limpiar_pantalla();
  cout << "Mostrar preguntas" << endl;
  cout << "Ingrese el numero de la prueba: " << endl;
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()){
    pruebas[id_prueba-1]->mostrar_preguntas();
    cout<<"Presione una tecla para continuar..."<<endl;
    cin.get();
    this_thread::sleep_for(chrono::seconds(SLEEP));  
    this_thread::sleep_for(chrono::seconds(SLEEP));  
    this_thread::sleep_for(chrono::seconds(SLEEP));  
    this_thread::sleep_for(chrono::seconds(SLEEP));  
  }
  else{
    cout << "No existe esa prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));    
  }
}

void menu::Menu::ejecutar_opcion_6(){
  int id_prueba;
  cout << "Ingrese el numero de la prueba: " << endl;
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()){
    delete this->pruebas[id_prueba-1];
    cout<<"Se elimino la prueba"<<endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
}

void menu::Menu::mostrar_menu(){
  while (true){
    limpiar_pantalla();
    cout << "1. Crear prueba" << endl;
    cout << "2. Insertar pregunta" << endl;
    cout << "3. Eliminar pregunta" << endl;
    cout << "4. Modificar pregunta" << endl;
    cout << "5. Mostrar pregunta" << endl;
    cout << "6. Eliminar prueba" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> this->opcion;
    if (this->opcion == 7){
      break;
    } else if (this->opcion == 1){
      ejecutar_opcion_1();
    } else if (this -> opcion == 2){
      ejecutar_opcion_2();
    } else if (this->opcion == 3){
      ejecutar_opcion_3();
    } else if (this->opcion == 4){
      ejecutar_opcion_4();
    } else if (this->opcion == 5){
      ejecutar_opcion_5();
    } else if (this->opcion == 6){
      ejecutar_opcion_6();
    } else {
      cout << "Opcion invalida" << endl;
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }
  }
}