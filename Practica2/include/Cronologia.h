#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

#include "adicional2.h"
#include <fstream>
#include <string>
#include <iostream>

class Cronologia{
  private:
    Vector_Dinamico<Fecha_Historica> vector_cronologico;
    bool orden_asc;

  public:

    Cronologia();
    Cronologia(const char* fichero);
    Cronologia(const char* fichero, bool orden_asc);
    Cronologia(const Fecha_Historica &fecha);
    Cronologia(const Cronologia& original);
    void ordenarCronologiaAsc();
    void ordenarCronologiaDesc();
    void unirCronologia();
    bool esAscendente();
    Fecha_Historica busqueda(int fecha);
    Vector_Dinamico<std::string> busqueda(int fecha,const std::string cadena);
    Vector_Dinamico<Cronologia> busqueda(std::string cadena);
    void AnadirFechaHistorica();
    void BorrarFechaHistorica();

};

std::istream& operator>>(std::istream& flujo,Cronologia& cronologia);
std::ostream& operator<<(std::ostream& flujo,const Cronologia& cronologia);

#endif
