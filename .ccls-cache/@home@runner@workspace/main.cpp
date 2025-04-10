// Raphaël Maufroy
// José Salazar Cabello

#include "utils.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <thread>
#include <vector>
using namespace std;

#define SLEEP 1

void limpiar_pantalla() {
  int dummy = system("clear");
  (void)dummy;
}

// CLASE PREGUNTA
class Pregunta {
private:
  // ATRIBUTOS
  int n_pregunta;
  string enunciado;
  string niv_tax;
  float tiempo_est;
  Pregunta *siguiente;

public:
  // CONSTRUCTOR - DESTRUCTOR
  Pregunta();
  Pregunta(int n_pregunta, string enunciado, string niv_tax, float tiempo_est);
  virtual ~Pregunta();
  // METODOS
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
  virtual void set_correct_resp() = 0;
};
// DEFINICION DE CONSTRUCTOR
Pregunta::Pregunta(int n_pregunta, string enunciado, string niv_tax,
                   float tiempo_est) {
  this->n_pregunta = n_pregunta;
  this->enunciado = enunciado;
  this->niv_tax = niv_tax;
  this->tiempo_est = tiempo_est;
  this->siguiente = NULL;
}
// DEFINICION DE DESTRUCTOR
Pregunta::~Pregunta() {
  // AGREGAR LOGICA PARA MATAR HIJOS Y LUEGO EL PADRE
}
// DEFINICION DE METODOS DE CLASE PREGUNTA
void Pregunta::set_siguiente(Pregunta *siguiente) {
  this->siguiente = siguiente;
};
Pregunta *Pregunta::get_siguiente() { return this->siguiente; }
void Pregunta::set_enunciado(string enunciado) { this->enunciado = enunciado; }
string Pregunta::get_enunciado() { return this->enunciado; }
void Pregunta::set_niv_tax(string niv_tax) { this->niv_tax = niv_tax; }
string Pregunta::get_niv_tax() { return this->niv_tax; }
void Pregunta::set_tiempo_est(float tiempo_est) {
  this->tiempo_est = tiempo_est;
}
float Pregunta::get_tiempo_est() { return this->tiempo_est; }
int Pregunta::get_n_pregunta() { return this->n_pregunta; }
int Pregunta::get_tipo() { return 0; }

// CLASE PREGUNTA DE VERDADERO O FALSO
class Verdadero_Falso : public Pregunta {
private:
  // ATRIBUTOS PARTICULARES
  bool correct_resp;
  string justificacion;

public:
  // CONSTRUCTOR - DESTRUCTOR
  Verdadero_Falso(int n_pregunta);
  Verdadero_Falso(int n_pregunta, string enunciado, string niv_tax,
                  float tiempo_est, bool correct_resp, string justificacion);
  ~Verdadero_Falso();
  // METODOS
  void set_correct_resp();
  bool get_correct_resp();
  void set_justificacion(string justificacion);
  string get_justificacion();
  int get_tipo();
};
// DEFINICION DE CONSTRUCTOR
Verdadero_Falso::Verdadero_Falso(int n_pregunta, string enunciado,
                                 string niv_tax, float tiempo_est,
                                 bool correct_resp, string justificacion)
    : Pregunta(n_pregunta, enunciado, niv_tax, tiempo_est) {
  this->correct_resp = correct_resp;
  this->justificacion = justificacion;
};
// DEFINICION DE DESTRUCTOR
Verdadero_Falso::~Verdadero_Falso() {
  // ESTE SE TIENE QUE MATAR PRIMERO Y LUEGO SE MATA AL PADRE
}
// METODOS DE CLASE VERDADERO O FALSO
void Verdadero_Falso::set_correct_resp() {
  int opcion_resp;
  bool correct_resp;
  cout << "(1. Verdadero) (2. Falso) Ingrese la respuesta correcta: ";
  cin >> opcion_resp;
  if (opcion_resp == 1) {
    correct_resp = true;
  } else {
    correct_resp = false;
  };
  this->correct_resp = correct_resp;
};
bool Verdadero_Falso::get_correct_resp() { return this->correct_resp; };
void Verdadero_Falso::set_justificacion(string justificacion) {
  this->justificacion = justificacion;
};
string Verdadero_Falso::get_justificacion() { return this->justificacion; };
int Verdadero_Falso::get_tipo() { return 1; }

// CLASSE PREGUNTA DE SELECCION MULTIPLE
class Seleccion_Mult : public Pregunta {
private:
  // ATRIBUTOS PARTICULARES
  string correct_resp;
  vector<string> dists;

public:
  // CONSTRUCTOR - DESTRUCTOR
  Seleccion_Mult(string correct_resp, int n_pregunta, string enunciado,
                 string niv_tax, float tiempo_est);
  Seleccion_Mult();
  ~Seleccion_Mult();
  // METODOS
  string get_correct_resp();
  string get_dists(int i);
  void set_correct_resp();
  void set_dists();
  int get_tipo();
};
// DEFINICION DE CONSTRUCTOR
void Seleccion_Mult::set_dists() {
  int cant_distractores;
  string distractor;
  cout << "Ingresa la cantidad de distractores: ";
  cin >> cant_distractores;
  if (cant_distractores > 4) {
    cout << "La cantidad de distractores no puede ser mayor que 4" << endl;
    cout << "Se establecera la cantidad de distractores en 4" << endl;
    cant_distractores = 4;
  };
  for (int i = 0; i < cant_distractores; i++) {
    cout << "Ingresa el distractor " << i + 1 << ": ";
    cin >> distractor;
    this->dists.push_back(distractor);
    cout << endl;
  }
};
Seleccion_Mult::Seleccion_Mult(string correct_resp, int n_pregunta,
                               string enunciado, string niv_tax,
                               float tiempo_est)
    : Pregunta(n_pregunta, enunciado, niv_tax, tiempo_est) {
  this->correct_resp = correct_resp;
  this->set_dists();
};
// DEFINICION DE DESTRUCTOR
Seleccion_Mult::~Seleccion_Mult() {
  // ESTE SE TIENE QUE MATAR PRIMERO Y LUEGO SE MATA AL PADRE
}
// METODOS DE CLASE SELECCION MULTIPLE
string Seleccion_Mult::get_correct_resp() { return this->correct_resp; };
string Seleccion_Mult::get_dists(int i) {
  if (i < 0 || i >= this->dists.size()) {
    return this->dists[i];
  } else {
    return "No existe ese distractor";
  };
};
void Seleccion_Mult::set_correct_resp() {
  string nueva_respuesta;
  cout << "Ingrese la respuesta correcta: ";
  cin.ignore();
  getline(cin, nueva_respuesta);
  if (!nueva_respuesta.empty())
    this->correct_resp = nueva_respuesta;
};
int Seleccion_Mult::get_tipo() { return 2; }

//
class Prueba {
private:
  int tot_preguntas;
  float tot_tiempo;
  vector<Pregunta *> preguntas;

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

Prueba::Prueba(int tot_preguntas, float tot_tiempo) {
  this->tot_preguntas = tot_preguntas;
  this->tot_tiempo = tot_tiempo;
}
Prueba::~Prueba() {
  // AGREGAR LOGICA DE ELIMINACION DE PREGUNTAS Y LUEGO ELIMINAR PRUEBA
  for (int i = 0; i < this->preguntas.size(); i++) {
    delete this->preguntas[i];
  }
  this->preguntas.clear();
  this->tot_preguntas = 0;
  this->tot_tiempo = 0;
  cout << "Se elimino la prueba" << endl;
}
void Prueba::insertar_pregunta(Pregunta *pregunta) {
  this->preguntas.push_back(pregunta);
};
int Prueba::get_cant_preguntas() { return this->preguntas.size(); };
int Prueba::get_max_preguntas() { return this->tot_preguntas; }
void Prueba::eliminar_pregunta(int n_pregunta) {
  delete this->preguntas[n_pregunta - 1];
}
void Prueba::modificar_pregunta(int n_pregunta) {
  int tipo = this->preguntas[n_pregunta - 1]->get_tipo();
  if (tipo == 1) {
    string input;

    cout << "Modificar el enunciado: " << endl;
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
      this->preguntas[n_pregunta - 1]->set_enunciado(input);
    }

    cout << "Modificar el nivel taxonomico: " << endl;
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
      this->preguntas[n_pregunta - 1]->set_niv_tax(input);
    }

    cout << "Modificar el tiempo estimado: " << endl;
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
      this->preguntas[n_pregunta - 1]->set_tiempo_est(stoi(input));
    }

    cout << "Modificar la respuesta correcta: " << endl;

    this->preguntas[n_pregunta - 1]->set_correct_resp();

    cout << "Modificar la justificacion: " << endl;
    getline(cin, input);
    if (!input.empty()) {
      ((Verdadero_Falso *)this->preguntas[n_pregunta - 1])
          ->set_justificacion(input);
    }
    cout << "Se modifico la pregunta" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  } else {
    string input;
    cout << "Modificar el enunciado: " << endl;
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
      this->preguntas[n_pregunta - 1]->set_enunciado(input);
    }
    cout << "Modificar el nivel taxonomico: " << endl;
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
      this->preguntas[n_pregunta - 1]->set_niv_tax(input);
    }
    cout << "Modificar el tiempo estimado: " << endl;
    cin.ignore();
    getline(cin, input);
    if (!input.empty()) {
      this->preguntas[n_pregunta - 1]->set_tiempo_est(stoi(input));
    }
    cout << "Modificar la respuesta correcta: " << endl;
    this->preguntas[n_pregunta - 1]->set_correct_resp();
    cout << "Modificar los distractores: " << endl;
    ((Seleccion_Mult *)this->preguntas[n_pregunta - 1])->set_dists();
    cout << "Se modifico la pregunta" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
}
void Prueba::mostrar_preguntas() {
  for (int i = 0; i < this->preguntas.size(); i++) {
    if (preguntas[i] == NULL) {
      cout << "Pregunta eliminada" << endl;
    } else {
      cout << preguntas[i]->get_n_pregunta() << ". "
           << preguntas[i]->get_enunciado() << endl;
    }
  }
}

class Menu {
private:
  int opcion;
  vector<Prueba *> pruebas;

public:
  void mostrar_menu();
  void ejecutar_opcion_1();
  void ejecutar_opcion_2();
  void ejecutar_opcion_3();
  void ejecutar_opcion_4();
  void ejecutar_opcion_5();
  void ejecutar_opcion_6();
};
void Menu::ejecutar_opcion_1() {
  int tot_preguntas;
  float tot_tiempo;
  limpiar_pantalla();
  cout << "Crear prueba" << endl;
  cout << "Ingrese el numero de preguntas: ";
  cin >> tot_preguntas;
  cout << "Ingrese el tiempo total estimado para la prueba (default 3 minutos "
          "por pregunta): ";
  cin >> tot_tiempo;
  if (tot_preguntas > 0) {
    if (tot_tiempo > 0) {
      Prueba *prueba = new Prueba(tot_preguntas, tot_tiempo);
      this->pruebas.push_back(prueba);
    } else {
      cout << tot_preguntas * 3 << " minutos" << endl;
      Prueba *prueba = new Prueba(tot_preguntas, tot_preguntas * 3);
      this->pruebas.push_back(prueba);
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }
  }
};
void Menu::ejecutar_opcion_2() {
  int id_prueba;
  limpiar_pantalla();
  cout << "Insertar pregunta" << endl;
  cout << "Ingrese el numero de la prueba: ";
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()) {
    while (true) {
      if (this->pruebas[id_prueba - 1]->get_cant_preguntas() <
          this->pruebas[id_prueba - 1]->get_max_preguntas()) {
        int tipo_pregunta;
        limpiar_pantalla();
        cout << "Insertar pregunta" << endl;
        cout << "1.\tPregunta de Verdadero o Falso" << endl;
        cout << "2.\tSeleccion Multiple" << endl;
        cout << "3.\tSalir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> tipo_pregunta;
        if (tipo_pregunta == 1) {
          int n_pregunta =
              this->pruebas[id_prueba - 1]->get_cant_preguntas() + 1;
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
          getline(cin, justificacion);
          Pregunta *pregunta =
              new Verdadero_Falso(n_pregunta, enunciado, niv_tax, tiempo_est,
                                  correct_resp, justificacion);
          pruebas[id_prueba - 1]->insertar_pregunta(pregunta);
          cout << "Se inserto la pregunta" << endl;
          this_thread::sleep_for(chrono::seconds(SLEEP));
        } else if (tipo_pregunta == 2) {
          int n_pregunta =
              this->pruebas[id_prueba - 1]->get_cant_preguntas() + 1;
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
          Pregunta *pregunta = new Seleccion_Mult(
              correct_resp, n_pregunta, enunciado, niv_tax, tiempo_est);
          pruebas[id_prueba - 1]->insertar_pregunta(pregunta);
          cout << "Se inserto la pregunta" << endl;
          this_thread::sleep_for(chrono::seconds(SLEEP));
        } else if (tipo_pregunta == 3) {
          break;
        } else {
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
void Menu::ejecutar_opcion_3() {
  int id_prueba;
  int id_pregunta;
  limpiar_pantalla();
  cout << "Eliminar pregunta" << endl;
  cout << "Ingrese el numero de la prueba: " << endl;
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()) {
    pruebas[id_prueba - 1]->mostrar_preguntas();
    cout << "Ingrese el numero de la pregunta: " << endl;
    cin >> id_pregunta;
    if (id_pregunta > 0 &&
        id_pregunta <= this->pruebas[id_prueba - 1]->get_cant_preguntas()) {
      pruebas[id_prueba - 1]->eliminar_pregunta(id_pregunta);
      cout << "Se elimina la pregunta" << endl;
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }

  } else {
    cout << "No existe esa prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
};

void Menu::ejecutar_opcion_4() {
  int id_prueba;
  int id_pregunta;
  limpiar_pantalla();
  cout << "Modificar pregunta" << endl;
  cout << "Ingrese el numero de la prueba: " << endl;
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()) {
    cout << "Aqui estan las preguntas: " << endl;
    pruebas[id_prueba - 1]->mostrar_preguntas();
    cout << "Ingrese el numero de la pregunta: " << endl;
    cin >> id_pregunta;
    if (id_pregunta > 0 &&
        id_pregunta <= this->pruebas[id_prueba - 1]->get_cant_preguntas()) {
      pruebas[id_prueba - 1]->modificar_pregunta(id_pregunta);
      cout << "Se modifico la pregunta" << endl;
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }
  } else {
    cout << "No existe esa prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
}

void Menu::ejecutar_opcion_5() {
  int id_prueba;
  limpiar_pantalla();
  cout << "Mostrar preguntas" << endl;
  cout << "Ingrese el numero de la prueba: " << endl;
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()) {
    pruebas[id_prueba - 1]->mostrar_preguntas();
    cout << "Presione una tecla para continuar..." << endl;
    cin.get();
    this_thread::sleep_for(chrono::seconds(SLEEP));
    this_thread::sleep_for(chrono::seconds(SLEEP));
    this_thread::sleep_for(chrono::seconds(SLEEP));
    this_thread::sleep_for(chrono::seconds(SLEEP));
  } else {
    cout << "No existe esa prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
}

void Menu::ejecutar_opcion_6() {
  int id_prueba;
  cout << "Ingrese el numero de la prueba: " << endl;
  cin >> id_prueba;
  if (id_prueba > 0 && id_prueba <= this->pruebas.size()) {
    delete this->pruebas[id_prueba - 1];
    cout << "Se elimino la prueba" << endl;
    this_thread::sleep_for(chrono::seconds(SLEEP));
  }
}

void Menu::mostrar_menu() {
  while (true) {
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
    if (this->opcion == 7) {
      break;
    } else if (this->opcion == 1) {
      ejecutar_opcion_1();
    } else if (this->opcion == 2) {
      ejecutar_opcion_2();
    } else if (this->opcion == 3) {
      ejecutar_opcion_3();
    } else if (this->opcion == 4) {
      ejecutar_opcion_4();
    } else if (this->opcion == 5) {
      ejecutar_opcion_5();
    } else if (this->opcion == 6) {
      ejecutar_opcion_6();
    } else {
      cout << "Opcion invalida" << endl;
      this_thread::sleep_for(chrono::seconds(SLEEP));
    }
  }
}

int main() {
  Menu menu;
  menu.mostrar_menu();
  return 0;
};