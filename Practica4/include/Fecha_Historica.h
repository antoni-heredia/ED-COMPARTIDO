/**
  * Clase Fecha_Historica. Representa los acontecimientos ocurridos en una fecha especificada.
  @author     Heredia Castillo, Antonio Jesus
  @author     Hinojosa Castro, Miguel Angel
  @ author    Perez Lendinez, Jose Manuel
  */
#ifndef FECHA_HISTORICA_H
#define FECHA_HISTORICA_H
//#include <fstream>
#include <string>
#include <iostream>
#include <utility>
#include <set>
#include <assert.h>


class Fecha_Historica{
  private:
    const static char DELIMITADOR = '#';
    std::pair< int,std::set<std::string> > fecha;

    /*!Método Privado Auxiliar: mostrarErrorFormatoFecha
            Función privada que muestra por pantalla el error que puede ocurrir con un string de formato Fecha_Historica.
          */
    void mostrarErrorFormatoFecha() const;

    //!Método Privado Auxiliar: leerString
      /*!
        leerString permite procesar un string dado. Separa la cadena pasada por el delimitador (por defecto #) y utiliza las cadenas procesadas crear el objeto Fecha_Historica.
        * \param cadena Cadena que va a ser procesada por la función.
      */
    bool leerString(std::string cadena);
    /*!Método Privado Auxiliar: leerFichero
          leerFichero lee y procesa un fichero. Hace uso de la función leeString para el procesado del fichero.
          * \param fichero Fichero que va a ser usado por la función.
		      * \return Retorna un booleano que nos indica si ha habido un error al leer el fichero (false) o si por el contrario, todo ha ido bien (true).
      */
    bool leerFichero(const char* fichero);

  public:

    typedef std::set<std::string>::iterator iterator;
    typedef typename std::set<std::string>::const_iterator const_iterator;

    Fecha_Historica();
    /*!Construtor: Año nuevo
          Constructor que asigna el año pasado por parámetro al objeto Fecha_Historica. Por defecto: num_acontecimientos = 0.
		      * \param nuevo Año con el que se creará la nueva Fecha_Historica.
      */
      Fecha_Historica(int anio);
    /*!Construtor: Lectura de String
          Constructor que lee el String pasado por parámetro y lo procesa para crear un objeto de tipo Fecha_Historica.
          * \param cadena String que contiene la cadena con el formato específico para crear una Fecha_Historica. Por defecto el formato es : año#acontecimiento1#...
      */
    Fecha_Historica(const std::string &cadena);
    /*!Construtor: Lectura de fichero
          Constructor que lee el fichero pasado por parámetro y lo procesa para crear un objeto de tipo Fecha_Historica.
		      * \param direccion_fichero Direccion del fichero que contiene la información necesaria para crear un objeto tipo Fecha_Historica. Por defecto el formato es : año#acontecimiento1#...
      */
    Fecha_Historica(const char* direccion_fichero);

    /*!Construtor: Constructor de Copia
          Constructor de copia de la clase Fecha_Historica. Crea un objeto Fecha_Historica a partir de otro objeto Fecha_Historica.
		      * \param Fecha_Historica Objeto que va a ser copiado por la función.
      */
    Fecha_Historica(const Fecha_Historica & f);
    /*!Método: get
        Función que devuelve el año de la Fecha_Historica.
      */
    int getAnio() const;
    /*!Método: set
          Función permite asignar un año nuevo a nuestro objeto Fecha_Historica.
	        * \param nuevo Año nuevo para la Fecha_Historica. Se permiten años negativos (A.C.).
      */
    void cambiarAnio(int nuevo);
    /*!Método: set
          Función que permite añadir un nuevo acontecimiento a la Fecha_Historica.
	        * \param cadena Cadena que contiene el nuevo acontecimiento.
      */
    void anadirAcontecimiento(const std::string& cadena);
    /*!Método: eliminarAcontecimiento
          Función que borra el acontecimiento que usar la posición indicada por el usuario. Acontecimiento 1 = posicion 1,...
          * \param posicion Entero que indica la posición a borrar.
      */
    void eliminarAcontecimiento(int posicion);
    /*!Método: eliminarAcontecimiento por string
          Función que borra todas las ocurrencias con la cadena pasada por parámetro.
          * \param cadena Cadena que se quiere borrar.
      */
    void eliminarAcontecimientos(const std::string& cadena);
    /*!Método: get
          Función que devuelve el número de acontecimientos de la Fecha_Historica.
		      * \return numero de acontecimientos
      */
    int getNumeroAconteciemientos() const;
    /*!Método: toString
          Devuelve un string con un formato más legible para el usuario.
	        * \return String que contiene la Fecha_Historica con un formato legible.
      */
    std::string to_s() const;
    /*!Método: busqueda
          Permite buscar una cadena dentro de todos los acontecimientos.
	        * \param Cadena que queremos buscar dentro de los acontecimientos.
		      * \return Set que contiene los resultados de la búsqueda.
      */
    //set<std::string> busqueda(const std::string &cadena) const;
    /*!Método: get
              Devuelve el delimitador usado.
    		      * \return Devuelve el delimitador que es usado en los archivos. Por defecto #.
          */
    //char getDelimitador() const;

    /*!Método: Unir fechas
      Función  que permite al usuario la unión de dos fechas si estas son del mismo año.
      * \param anadida Fecha historica que se añade a la que invoca la funcion.
    */
    bool unirFechas(const Fecha_Historica& anadida);

    /*!Método: busqueda
          Permite buscar una cadena dentro de todos los acontecimientos.
	        * \param Cadena que queremos buscar dentro de los acontecimientos.
		      * \return Fecha_Historica que contiene los resultados de la búsqueda.
      */
    Fecha_Historica busqueda(const std::string& cadena) const;
    
    

    iterator begin();
    iterator end();
    
    const_iterator begin() const;
    const_iterator end() const;
    
    


};

#endif
