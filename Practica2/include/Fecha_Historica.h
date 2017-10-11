#ifndef FECHA_HISTORICA_H
#define FECHA_HISTORICA_H
#include "adicional.h"
#include <fstream>
class Fecha_Historica{
  private:
    Vector_Dinamico<std::string> vector;
    int anio;
  public:
    Fecha_Historica();
    Fecha_Historica(int nuevo);
    int getAnio();
    void getAcontecimientos();
    void cambiarAnio(int nuevo);
    void anadirAcontecimiento(std::string cadena);
    Vector_Dinamico<std::string> busqueda(std::string cadena);

    bool Leer(const char* fichero);


};
#endif
