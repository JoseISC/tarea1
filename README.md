# Sistema de Gestión de Preguntas y Pruebas

## Descripción
Este proyecto implementa un sistema de gestión de preguntas y pruebas en C++, diseñado para crear y administrar diferentes tipos de preguntas educativas utilizando la Taxonomía de Bloom como referencia principal. El sistema utiliza programación orientada a objetos y permite manejar preguntas de selección múltiple y verdadero/falso.

## Autores
- Raphaël Maufroy
- José Salazar Cabello

## Objetivos del Proyecto
- Implementar un sistema de gestión de pruebas escritas basado en la Taxonomía de Bloom
- Aplicar conceptos fundamentales de programación orientada a objetos
- Desarrollar una solución modular y estructurada
- Demostrar el uso práctico de herencia y polimorfismo
- Implementar manejo eficiente de memoria dinámica

## Estructura del Proyecto
```
tarea1/
├── main.cpp           # Punto de entrada del programa
├── utils.h/cpp        # Utilidades y clase Menu
├── preguntas.h/cpp    # Definición de las clases de preguntas
├── prueba.h/cpp       # Manejo de pruebas
└── Makefile          # Archivo de compilación
```

## Diseño de Clases

### Clase Base: Pregunta
```cpp
class Pregunta {
private:
    int n_pregunta;      // Identificador único
    string enunciado;    // Texto de la pregunta
    string niv_tax;      // Nivel taxonómico
    float tiempo_est;    // Tiempo estimado
    Pregunta *siguiente; // Siguiente pregunta en la lista
public:
    virtual void set_correct_resp()=0; // Método abstracto
};
```

### Clase Seleccion_Mult
```cpp
class Seleccion_Mult : public Pregunta {  
private:
    string correct_resp;    // Respuesta correcta
    vector<string> dists;   // Distractores
};
```

### Clase Verdadero_Falso
```cpp
class Verdadero_Falso : public Pregunta {
private:
    bool correct_resp;      // Respuesta correcta
    string justificacion;   // Justificación de la respuesta
};
```

### Clase Prueba
```cpp
class Prueba {
private:
    int tot_preguntas;     // Total de preguntas
    float tot_tiempo;      // Tiempo total
    vector<Pregunta *> preguntas; // Colección de preguntas
};
```

## Características Técnicas
- **Herencia**: Implementación de jerarquía de clases para diferentes tipos de preguntas
- **Polimorfismo**: Uso de métodos virtuales para manejo uniforme de preguntas
- **Memoria Dinámica**: Gestión de preguntas mediante punteros y vectores
- **Modularidad**: Separación clara de responsabilidades entre clases
- **Encapsulamiento**: Protección de datos mediante miembros privados y métodos públicos

## Funcionalidades del Sistema

### 1. Gestión de Pruebas
- Crear nuevas pruebas
- Especificar cantidad de preguntas
- Definir tiempo total estimado
- Eliminar pruebas existentes

### 2. Gestión de Preguntas
- **Tipos de Preguntas**:
  - Selección Múltiple (con distractores)
  - Verdadero/Falso (con justificación)
- **Atributos por Pregunta**:
  - Número identificador
  - Enunciado
  - Nivel taxonómico según Bloom
  - Tiempo estimado de respuesta

### 3. Operaciones del Menú
1. **Crear Prueba**
   - Configuración inicial de parámetros
   - Validación de entrada

2. **Insertar Pregunta**
   - Selección de tipo de pregunta
   - Ingreso de datos específicos
   - Validación de límites

3. **Eliminar Pregunta**
   - Selección de prueba
   - Visualización de preguntas disponibles
   - Eliminación segura

4. **Modificar Pregunta**
   - Edición de campos existentes
   - Preservación de integridad

5. **Mostrar Preguntas**
   - Visualización detallada
   - Formato estructurado

6. **Eliminar Prueba**
   - Liberación de memoria
   - Actualización de referencias

## Aspectos de Implementación
- Manejo de excepciones para entradas inválidas
- Liberación adecuada de memoria
- Validación de datos de entrada
- Interfaz de usuario por consola
- Estructura de lista enlazada para preguntas

## Compilación y Ejecución

### Requisitos
- Compilador C++ (g++)
- Make

### Instrucciones
```bash
make        # Compilar el proyecto
./main      # Ejecutar el programa
```

## Notas de Desarrollo
- Implementación basada en programación orientada a objetos
- Uso extensivo de características de C++ moderno
- Código documentado y estructurado
- Diseño pensado en la extensibilidad 