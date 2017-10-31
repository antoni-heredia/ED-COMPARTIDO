/**
  * Clase Cronologia. Representa un conjunto de Fechas Historicas ordenadas.
  */
#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

#include "adicional2.h"
#include <fstream>
#include <string>
#include <iostream>

class Cronologia{
  private:
    Vector_Dinamico<Fecha_Historica> vector_cronologico;/**< Vector que guarda las fechas históricas de la Cronología.*/
    int num_fechas;/**< Número de fechas diferentes que hay en la Cronología.*/
    bool orden_asc;/**< Indica si la Cronología está ordenada de forma ascendente (true) o descendente (false). Por defecto este valor está a true.*/
    //!Método Privado Auxiliar: leerFichero
      /*!
          leerFichero permite leer un ficheor con el formato adecuado y procesarlo para crear una Cronología ordenada.
		      El formato por defecto del fichero debe ser:
			         Año#Acontecimiento1#Acontecimiento2#...
			         Año2#...#...
			         .
			         .
			         .
          * \param direccion_fichero Indica el fichero que va a ser leido por la función.
		      * \return Retorna un booleano: true si no hay ningún fallo y el fichero ha sido leido correctamente.
      */
    bool leerFichero(const char * direccion_fichero);
    //!Método Privado Auxiliar: existe Año
      /*!
          Función auxiliar que devuelve un entero si existe el año pasado por argumento o un -1 si no existe.
          * \param anio Entero que representa el año que queremos comprobar si existe.
		      * \return Retorna -1 si el año no existe.
      */
    int existeAnio(int anio) const ;
    //!Método Privado Auxiliar: copia
      /*!
          Función que copia una Cronología a partir de otro objeto Cronología.
          * \param original Objeto Cronología que va a ser copiado.
      */
    void copia(const Cronologia & original);

    /*!Método: set
        Añade una Fecha_Historica a el objeto Cronología en la ultima posicion.
		    * \param fecha Objeto de tipo Fecha_Historica que va a ser introducido en la Cronología.
		    * \return Retorna un vector con la información de la búsqueda (acontecimientos generados por la búsqueda).
    */
    void aniadirFechaDes(Fecha_Historica fecha);
  public:
    /*!Construtor: Sin parámetros
        Constructor sin parámetros de la clase Cronología. Por defecto: orden_asc = true.
      */
    Cronologia();
    /*!Construtor: Leer Fichero
        Constructor que utiliza un fichero con el formato adecuado para procesarlo y crear un objeto Cronologia con los datos.
  		  * \param fichero Fichero que se utilizará para crear el objeto Cronología.
    */
    Cronologia(const char* fichero);
    /*!Construtor: Leer Fichero indicando el orden deseado
        Constructor que utiliza un fichero con el formato adecuado para procesarlo y crear un objeto Cronologia con los datos. Se puede indicar el orden que queremos (asc o desc).
		    * \param fichero Fichero que se utilizará para crear el objeto Cronología.
		    * \param orden_asc True si queremos el orden normal (asc) o false para el orden desc.
      */
    Cronologia(const char* fichero, bool orden_asc);
    /*!Construtor: A partir de una Fecha_Historica
        Constructor que utiliza un objeto de Fecha_Historica para crear una Cronología a partir del mismo.
		    * \param fecha Objeto Fecha_Historica usado para crear la Cronología.
      */
    Cronologia(const Fecha_Historica &fecha);
    /*!Construtor: Constructor de Copia
        Constructor que utiliza un objeto Cronología ya creado para crear un nuevo objeto Cronología.
		    * \param original Objeto Cronología que va a ser copiado.
      */
    Cronologia(const Cronologia& original);
    /*!Método: Ordenación asc
        Ordena de forma ascendente las Fechas Historicas contenidas en el objeto Cronología.
      */
    void ordenarCronologiaAsc();
    /*!Método: Ordenación desc
            Ordena de forma descendente las Fechas Historicas contenidas en el objeto Cronología.
          */
    void ordenarCronologiaDesc();
    /*!Método: Unión de Cronologías
       Une los datos de otro objeto Cronología. Para la unión deben de coincidir al menos un año dentro de las Cronologías.
      */
    void unirCronologia();
    /*!Método: get
        Indica si la Cronología está ordenada ascendentemente (true).
		    * \return Devuelve true si la Cronología está ordenada de formas ascendente.
      */
    bool esAscendente();
    /*!Método: Búsqueda de fecha
        Permite buscar un año dentro del objeto Cronología.
		    * \param fecha Año que será buscado en la Cronología.
		    * \return Retorna los acontecimientos de la fecha buscada.
      */
    Fecha_Historica busqueda(int fecha);
    /*!Método: Búsqueda de fecha y acontecimiento dentro de esa fecha
        Permite buscar un año dentro del objeto Cronología.
		    * \param fecha Año que será buscado en la Cronología.
		    * \param cadena Acontecimiento\s que se quieren buscar en la Cronología.
		     * \return Retorna un vector con la información de la búsqueda (acontecimientos generados por la búsqueda).
      */
    Vector_Dinamico<std::string> busqueda(int fecha,const std::string cadena);
    /*!Método: Búsqueda de acontecimientos
        Permite buscar uno o varios acontecimientos dentro de la Cronología.
    		* \param cadena Cadena que va a ser buscada en el Cronología.
    		* \return Retorna una Cronología con las fechas históricas buscadas.
    */
    Cronologia busqueda(std::string cadena);

    /*!Método: Borrar Fecha_Historica
          Borra un año y los acontecimientos de un objeto Cronología.
		      * \param anio Año que va ser borrado de Cronología.
      */
    void BorrarFechaHistorica(int anio);
    /*!Método: toString
        Devuelve un string con un formato más legible para el usuario.
		    * \return String que contiene la Fecha_Historica con un formato legible.
      */
    std::string to_s() const;

    /*!Método: set
        Añade una Fecha_Historica a el objeto Cronología de forma ordenada.
        * \param fecha Objeto de tipo Fecha_Historica que va a ser introducido en la Cronología.
        * \return Retorna un vector con la información de la búsqueda (acontecimientos generados por la búsqueda).
    */
    void aniadirFecha(Fecha_Historica fecha);

    int getNumeroFechas() const;
    Vector_Dinamico<Fecha_Historica> getFechas() const;


};

/*!Método: Sobrecarga del operador de flujo <<
    Introduce en el objeto Fecha_Historica un acontecimiento nuevo.
*/
std::ostream& operator<<(std::ostream& flujo,const Cronologia& cronologia);
#endif
