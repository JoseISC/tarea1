#include "preguntas.h"
#include <vector>
using namespace preguntas;

namespace prueba{
  class Prueba {
    private:
      int tot_preguntas;
      float tot_tiempo;
      vector <Pregunta *> preguntas;
      void recalcular_tiempo_total();
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
      float get_tiempo_total() const { return tot_tiempo; }
  };  
}
