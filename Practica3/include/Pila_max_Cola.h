/**
 * @file Pila_max_Cola.h
 * @brief Fichero cabecera del TDA Pila Máximo Implementado con Cola
 *
 */
#ifndef __PILA_COLA_H__
#define __PILA_COLA_H__

#include <iostream>
#include <cassert>
#include <string>
#include "cola.h"
/**
 * @brief T.D.A. Pila_max_Cola
 *
 * El T.D.A. Pila_max_Cola permite crear un contenedor de tipo Pila pero con
 * una modificación, ofrece al usuario un método para obtener el valor máximo
 * que hay almacenado en la pila.
 *
 * <tt>\#include Pila_max_Cola.h</tt>
 *
 * La clase Pila será implementada con una cola.
 * También será implementada como un template.
 *
 * @author Heredia Castillo, Antonio Jesus
 * @author Hinojosa Castro, Miguel Angel
 * @author Perez Lendinez, Jose Manuel
 *
 * @date Noviembre 2017
 */

template <class T>
class Pila{
  private:

    struct elemento {
      T dato; ///< Elemento almacenado en la pila
      T maximo; ///< Elemento maximo almacenado en la pila
    };

    Cola<elemento> datos; ///< Cola que controla el funcionamiento de la pila
    int nelem;///< Numero de lementos almacenados en la pila

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
    // --------------- Otras funciones ---------------
    /**
     * @brief Devuelve el numero de elementos de la pila
     */
    int getNumeroElementos() const;
    /**
     * @brief Devuelve el elemento maximo de la pila
     */
    T getElementoMaximo() const;
    /**
     * @brief Comprueba si la Pila esta vacia.
     */
    bool vacia() const;
    /**
     * @brief Añade un elemento al principio de la pila
     * @param c Elemento que se va a añadir.
     */
    void poner(const T& c);
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
    std::string to_s() const;
    /**
     * @brief Operador de asignacion
     * @param p La Pila que se va a asignar.
     */
    Pila<T>& operator=(const Pila<T> &p);
  private:
    // --------------- Funciones auxiliares ---------------
    /**
     * @brief Copia la pila pasada como argumento
     * @param p La pila que se va a copiar.
     */
    void copiar(const Pila<T> & p);
  //  elemento elementoTope() const;
  };
#include "Pila_max_Cola.cpp"
#endif /* Pila_max_VD.h */
