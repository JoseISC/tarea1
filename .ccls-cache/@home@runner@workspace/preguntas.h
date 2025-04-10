#include <string>
#include <vector>
using namespace std;
namespace preguntas{
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
  // CLASE PREGUNTA DE SELECCION MULTIPLE
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
}