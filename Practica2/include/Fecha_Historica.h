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
    const static char DELIMITADOR = '#';
    int anio;/**< Entero que reseprensenta la fecha de los acontecimientos.*/
    int num_acont;/**< Contiene el número de acontecimientos ocurridos en el año (anio).*/
    Vector_Dinamico<std::string> vector;/**< Vector que contendrá todos los sucesos del año.*/
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
    /*!Método Privado Auxiliar: copia
        Función que nos hace la copia de una Fecha_Historica pasada por argumento.
        * \param Fecha_Historica Objeto que vamos a utilizar para copiar.
      */
    void copia(const Fecha_Historica & f);
    /*!Método Privado Auxiliar: censurarString
          Función privada que permite al usuario de la clase censurar palabras dentro de un acontecimiento de un objeto Fecha_Historica. Por defecto cambia la palabra censurada por ****.
          * \param censurado Palabra que va a ser censurada.
		      * \param cadena Cadena donde va a ser censurada la palabra escogida.
      */
    void censurarString(std::string &censurado, const std::string &cadena);
    /*!Método Privado Auxiliar: mostrarErrorFormatoFecha
            Función privada que muestra por pantalla el error que puede ocurrir con un string de formato Fecha_Historica.
          */
    void mostrarErrorFormatoFecha() const;


  public:

    /*!Construtor: Sin parámetros
        Constructor sin parámetros de la clase Fecha_Historica. Por defecto: año = 0 y num_acontecimientos = 0.
      */
    Fecha_Historica();
    /*!Construtor: Año nuevo
          Constructor que asigna el año pasado por parámetro al objeto Fecha_Historica. Por defecto: num_acontecimientos = 0.
		      * \param nuevo Año con el que se creará la nueva Fecha_Historica.
      */
    Fecha_Historica(int nuevo);
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
    /*!Método: get
          Función que devuelve el número de acontecimientos de la Fecha_Historica.
		      * \return Devuelve el año.
      */
    int getNumeroAconteciemientos() const;
    /*!Método: get
          Función que devuelve un vector con todos los acontecimientos de la Fecha_Historica.
		      * \return Devuelve un vector dinámico que contiene todos los acontecimientos.
      */
    Vector_Dinamico<std::string>  getAcontecimientos() const;
    /*!Método: set
          Función permite asignar un año nuevo a nuestro objeto Fecha_Historica.
	        * \param nuevo Año nuevo para la Fecha_Historica. Se permiten años negativos (A.C.).
      */
    void cambiarAnio(int nuevo);
    /*!Método: set
          Función que permite añadir un nuevo acontecimiento a la Fecha_Historica.
	        * \param cadena Cadena que contiene el nuevo acontecimiento.
      */
    void anadirAcontecimiento(std::string cadena);
    /*!Método: eliminarAcontecimiento
          Función que borra el acontecimiento que usar la posición indicada por el usuario. Acontecimiento 1 = posicion 1,...
          * \param posicion Entero que indica la posición a borrar.
      */
    void eliminarAcontecimiento(int posicion);
    void eliminarAcontecimientos(const std::string cadena);

    /*!Método: toString
          Devuelve un string con un formato más legible para el usuario.
	        * \return String que contiene la Fecha_Historica con un formato legible.
      */
    std::string to_s() const;
    /*!Método: busqueda
          Permite buscar una cadena dentro de todos los acontecimientos.
	        * \param Cadena que queremos buscar dentro de los acontecimientos.
		      * \return Vector que contiene los resultados de la búsqueda.
      */
    Vector_Dinamico<std::string> busqueda(const std::string &cadena) const;
    /*!Método: Sobrecarga del operador =
          Permite asignar un objeto Fecha_Historica a otra.
		      * \param original Fecha_Historica que queremos copiar en nuestro objeto.
	        * \return Devuelve una referencia al objeto this para poder concatenar (1=2=3...).
      */
    Fecha_Historica& operator=(const Fecha_Historica & original);
    /*!Método: Sobrecarga del operador >
          Permite comparar un objeto Fecha_Historica con el operador >.
		      * \param otra Objeto que va a ser comparado.
	        * \return Devuelve true si la fecha es mayor.
      */
    bool operator > (const Fecha_Historica & otra);
    /*!Método: Sobrecarga del operador <
          Permite comparar un objeto Fecha_Historica con el operador <.
          * \param otra Objeto que va a ser comparado.
          * \return Devuelve true si la fecha es menor.
      */
    bool operator < (const Fecha_Historica & otra);
    /*!Método: Sobrecarga del operador >=
          Permite comparar un objeto Fecha_Historica con el operador >=.
		      * \param otra Objeto que va a ser comparado.
	        * \return Devuelve true si la fecha es mayor o igual.
      */
    bool operator >= (const Fecha_Historica & otra);
    /*!Método: Sobrecarga del operador >
          Permite comparar un objeto Fecha_Historica con el operador <=.
		      * \param otra Objeto que va a ser comparado.
	        * \return Devuelve true si la fecha es menor o igual.
      */
    bool operator <= (const Fecha_Historica & otra);

    /*!Método: Sobrecarga del operador ==
            Permite comparar dos objetos Fecha_Historica.
  		      * \param otra Fecha_Historica con la que queremos comparar.
  		      * \return Devuelve true si las Fecha_Historicas son iguales.
          */
    bool operator == (const Fecha_Historica & otra);
    /*!Método: Sobrecarga del operador !=
          Permite comparar dos objetos Fecha_Historica.
		      * \param otra Fecha_Historica con la que queremos comparar.
	        * \return Devuelve false si las Fecha_Historicas son iguales.
      */
    bool operator != (const Fecha_Historica & otra);
    /*!Método: Sobrecarga del operador [] lectura
          Permite acceder a las posiciones de los acontecimientos dados.
		      * \param i Indice que representa al acontecimiento i.
	        * \return Devuelve el acontecimiento que ocupa la posición i.
      */
    std::string& operator[](int i);
    /*!Método: Sobrecarga del operador [] escritura
          Permite asignar un nuevo valor al acontecimiento dado.
		      * \param i Indice que representa al acontecimiento i.
	        * \return Devuelve el acontecimiento que ocupa la posición i.
      */
    const std::string& operator[] (int i) const;
    /*!Método: Sobrecarga del operador +=
          Permite añadir un nuevo acontecimiento. Si la cadena esta separada (acont#acont2#...) añade varios acontecimientos a la vez.
		      * \param acontecimiento Cadena que contiene el acontecimiento o los acontecimientos (separados por #) que vamos a añadir al objeto.
	        * \return Devuelve al propio objeto Fecha_Historica.
      */
    Fecha_Historica& operator+=(const std::string& acontecimiento);

    Fecha_Historica& operator-=(const std::string& acontecimiento);
    /*!Método: Sobrecarga del operador --
              Quita el último acontecimiento que ha sido añadido.
    		      * \return Devuelve al propio objeto Fecha_Historica.
          */
    Fecha_Historica& operator--();
    Fecha_Historica operator--(int);
    char getDelimitador() const;
    void censurarCadena(const std::string& Cadena);
    

};
/*!Método: Sobrecarga del operador de flujo <<
    Almacena el objeto Fecha_Historica con formato fichero (anio#acont1#acont2...)
*/
std::ostream& operator<< (std::ostream& s, const Fecha_Historica& fecha);
/*!Método: Sobrecarga del operador de flujo <<
    Introduce en el objeto Fecha_Historica un acontecimiento nuevo.
*/
std::istream& operator>> (std::istream& s, const Fecha_Historica& fecha);
#endif
