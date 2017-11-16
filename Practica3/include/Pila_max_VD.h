/**
 * @file Pila_max_VD.h
 * @brief Fichero cabecera del TDA Pila Máximo Implementado con Vector
 *
 */
#ifndef __PILA_H__
#define __PILA_H__

#include <iostream>
#include <cassert>
#include <string>
/**
 * @brief T.D.A. Pila_max_VD
 *
 * El T.D.A. Pila_max_VD permite crear un contenedor de tipo Pila pero con
 * una modificación, ofrece al usuario un método para obtener el valor máximo
 * que hay almacenado en la pila.
 *
 * <tt>\#include Pila_max_VD.h</tt>
 *
 * La clase Pila será implementada con un vector dinámico.
 * También será implementada como un template.
 *
 * @author Heredia Castillo, Antonio Jesus
 * @author Hinojosa Castro, Miguel Angel
 * @author Perez Lendinez, Jose Manuel
 *
 * @date Noviembre 2017
 */

const int TAM = 10;
template <class T>
class Pila{
  private:

    T *datos; ///< Vector que controla los datos de la pila.
    int reservados; ///< Entero que indica el espacio reservado de la pila.
    int nelem; ///< Numero elementos de la pila.
    T *maximo; ///< Vector que controla el valor maximo de la pila.

  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila();
    /**
     * @brief Constructor de copia
     * @param p La pila de la que se hara la copia.
     */
    Pila(const Pila<T> & p);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila();
    // --------------- Otras funciones ---------------
    /**
     * @brief Devuelve el numero de elementos reservados en la pila
     */
    int getReservados() const;
    /**
     * @brief Devuelve el numero de elementos de la pila
     */
    int getNumeroElementos() const;
    /**
     * @brief Devuelve la posicion donde se encuentra el vector que controla los datos
     */
    T* getDatos() const;
    /**
     * @brief Devuelve el elemento maximo de la pila
     */
    T getElementoMaximo() const;
    int resize(int n);
    /**
     * @brief Comprueba si la Pila esta vacia.
     */
    bool vacia() const;
    /**
     * @brief Añade un elemento al principio de la pila
     * @param c Elemento que se va a añadir.
     */
    void poner(T c);
    /**
     * @brief Quita el elemento del tope de la pila.
     */
    void quitar();
    /**
     * @brief Devuelve el elemento del tope de la pila.
     */
    T tope() const;
    /**
     * @brief Devuelve un string con informacion sobre la pila.
     */
    std::string to_s();
    /**
     * @brief Operador de asignacion
     * @param p La Pila que se va a asignar.
     */
    Pila& operator=(const Pila<T> &p);

  private:
    // --------------- Funciones auxiliares ---------------
    /**
     * @brief Copia la pila pasada como argumento
     * @param p La pila que se va a copiar.
     */
    void copiar(const Pila<T> & p);
    /**
     * @brief Libera la memoria de los vectores usados
     */
    void liberar();
  };
template <class T>
/**
 * @brief Operador de salida de flujo
 */
std::ostream& operator<< (std::ostream& s, const Pila<T>& pila);
  #include "Pila_max_VD.cpp"
#endif /* Pila_max_VD.h */
