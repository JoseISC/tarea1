// HEADER DE LA CLASE PREGUNTA
#include <string>
#include <vector>
using namespace std;
namespace preguntas{
  const vector<string> NIVELES_TAXONOMICOS = {
    "Conocimiento",
    "Comprension",
    "Aplicacion",
    "Analisis",
    "Sintesis",
    "Evaluacion"
  };

  bool es_nivel_taxonomico_valido(const string& nivel) {
    for (const auto& n : NIVELES_TAXONOMICOS) {
      if (n == nivel) return true;
    }
    return false;
  }

  // CLASE PREGUNTA BASE
  class Pregunta{
    private:
      //ATRIBUTOS
      int n_pregunta;
      string enunciado;
      string niv_tax;
      float tiempo_est;
      //Pregunta *siguiente;  // Atributo no utilizado - implementación de lista enlazada descartada
    public:
      //CONSTRUCTOR - DESTRUCTOR
      // Constructor por defecto no utilizado - todas las preguntas se crean con parámetros
      //Pregunta();
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
      //Pregunta *get_siguiente();  // Método no utilizado - implementación de lista enlazada descartada
      //void set_siguiente(Pregunta *siguiente);  // Método no utilizado - implementación de lista enlazada descartada
      virtual int get_tipo();
      virtual void set_correct_resp()=0;
  };
  // CLASE PREGUNTA DE SELECCION MULTIPLE
  class Seleccion_Mult : public Pregunta {  
    private :
      //ATRIBUTOS PARTICULARES
      string correct_resp;
      vector<string> dists;
    public:
      //CONSTRUCTOR - DESTRUCTOR
      Seleccion_Mult(string correct_resp, int n_pregunta, string enunciado, string niv_tax, float tiempo_est);
      // Constructor por defecto no utilizado - todas las preguntas de selección múltiple se crean con parámetros
      //Seleccion_Mult();
      ~Seleccion_Mult();
      //METODOS
      string get_correct_resp();
      string get_dists(int i);
      void set_correct_resp();
      void set_dists();
      int get_tipo();
  };
  // CLASE PREGUNTA DE VERDADERO O FALSO
  class Verdadero_Falso : public Pregunta{
    private:
      //ATRIBUTOS PARTICULARES
      bool correct_resp;
      string justificacion;
    public:
      //CONSTRUCTOR - DESTRUCTOR
      // Constructor no utilizado - todas las preguntas V/F requieren más información que solo el número
      //Verdadero_Falso(int n_pregunta);
      Verdadero_Falso(int n_pregunta, string enunciado, string niv_tax, float tiempo_est, bool correct_resp, string justificacion);
      ~Verdadero_Falso();
      //METODOS
      void set_correct_resp();
      bool get_correct_resp();
      void set_justificacion(string justificacion);
      string get_justificacion();
      int get_tipo();
  };
}