#include <vector>
#include <cstdlib>
#include <sstream>
#include "prueba.h"
#include "preguntas.h"

using namespace std;
using namespace preguntas;
using namespace prueba;

namespace menu{
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