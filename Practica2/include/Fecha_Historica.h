/**
  * Clase Fecha_Historica. Representa los acontecimientos ocurridos en una fecha especificada.
  */
#ifndef FECHA_HISTORICA_H
#define FECHA_HISTORICA_H
#include "adicional.h"
#include <fstream>
#include <string>
#include <iostream>
class Fecha_Historica{
  private:

    int anio;/**< Entero que reseprensenta la fecha de los acontecimientos.*/
    int num_acont;/**< Contiene el número de acontecimientos ocurridos en el año (anio).*/
    Vector_Dinamico<std::string> vector;/**< Vector que contendrá todos los sucesos del año.*/
    //!Método Privado Auxiliar: leerString
      /*!
        leerString permite procesar un string dado. Separa la cadena pasada por el delimitador (por defecto #) y utiliza las cadenas procesadas crear el objeto Fecha_Historica.
        * \param cadena Cadena que va a ser procesada por la función.
      */
    bool leerString(std::string cadena);
    bool leerFichero(const char* fichero);
    void copia(const Fecha_Historica & f);
    void censurarString(std::string &censurado, const std::string &cadena);
    void mostrarErrorFormatoFecha() const;


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
