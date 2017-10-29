#ifndef FECHA_HISTORICA_H
#define FECHA_HISTORICA_H
#include "adicional.h"
#include <fstream>
#include <string>
#include <iostream>
class Fecha_Historica{
  private:

    int anio;
    int num_acont;
    Vector_Dinamico<std::string> vector;
    bool leerString(std::string cadena);
    bool leerFichero(const char* fichero);
    void copia(const Fecha_Historica & f);

  public:

    Fecha_Historica();
    Fecha_Historica(int nuevo);
    Fecha_Historica(const std::string &cadena);
    Fecha_Historica(const char* direccion_fichero);
    Fecha_Historica(const Fecha_Historica & f);
    int getAnio() const;
    int getNumeroAconteciemientos() const;
    Vector_Dinamico<std::string>  getAcontecimientos() const;
    void cambiarAnio(int nuevo);
    void anadirAcontecimiento(std::string cadena);
    void eliminarAcontecimiento(int posicion);
    std::string to_s() const;
    Vector_Dinamico<std::string> busqueda(const std::string &cadena) const;
    Fecha_Historica& operator=(const Fecha_Historica & original);




};
std::ostream& operator<< (std::ostream& s, const Fecha_Historica& fecha);

#endif
