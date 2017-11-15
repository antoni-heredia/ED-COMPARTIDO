/**
 * @file Pila_max_VD.h
 * @brief Fichero cabecera del TDA Pila Máximo Implementado con Vector
 *
 */
#ifndef __PILA_COLA_H__
#define __PILA_COLA_H__

#include <iostream>
#include <cassert>
#include <string>
#include "cola.h"
/**
 @brief T.D.A. Pila_max_VD

 El T.D.A. Pila_max_VD permite crear un contenedor de tipo Pila pero con
 una modificación, ofrece al usuario un método para obtener el valor máximo
 que hay almacenado en la pila.

 <tt>\#include Pila_max_VD.h</tt>

 La clase Pila será implementada con un vector dinámico.
 También será implementada como un template.
 */
template <class T>
class Pila{
  private:

    struct elemento {
      T dato;
      T maximo;
    };

    Cola<elemento> datos;
    int nelem;

  public:

    Pila();
    Pila(const Pila<T> & p);
    int getReservados() const;
    int getNumeroElementos() const;
    T* getDatos() const;
    T getElementoMaximo() const;
    bool vacia() const;
    void poner(const T& c);
    void quitar();
    T tope() const;
    std::string to_s();
    Pila& operator=(const Pila<T> &p);
  private:
    void copiar(const Pila<T> & p);
  };
template <class T>
std::ostream& operator<< (std::ostream& s, const Pila<T>& pila);
  #include "Pila_max_Cola.cpp"
#endif /* Pila_max_VD.h */
