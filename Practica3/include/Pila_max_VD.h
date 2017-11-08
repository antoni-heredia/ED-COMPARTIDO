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
 @brief T.D.A. Pila_max_VD

 El T.D.A. Pila_max_VD permite crear un contenedor de tipo Pila pero con
 una modificación, ofrece al usuario un método para obtener el valor máximo
 que hay almacenado en la pila.

 <tt>\#include Pila_max_VD.h</tt>

 La clase Pila será implementada con un vector dinámico.
 También será implementada como un template.
 */

const int TAM = 10;
template <class T>
class Pila{
  private:

    T *datos;
    int reservados;
    int nelem;
    T *maximo;

  public:

    Pila();
    Pila(const Pila<T> & p);
    ~Pila();

    int getReservados() const;
    int getNumeroElementos() const;
    T* getDatos() const;
    T getElementoMaximo() const;
    int resize(int n);
    bool vacia() const;
    void poner(T c);
    void quitar();
    T tope() const;
    std::string to_s();
    Pila& operator=(const Pila<T> &p);

  private:

    void copiar(const Pila<T> & p);
    void liberar();
  };
template <class T>
std::ostream& operator<< (std::ostream& s, const Pila<T>& pila);
  #include "Pila_max_VD.cpp"
#endif /* Pila_max_VD.h */
