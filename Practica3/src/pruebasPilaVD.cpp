#include <iostream>
#include "Pila_max_VD.h"
using namespace std;


int main(){
  Pila <int> nueva,copia;
  //
  Pila <int> as(nueva);
  string resultado;
  nueva.poner(7);
  copia = nueva;
  nueva.poner(5);
  nueva.poner(23);
  //Pila <int> copia2(nueva);
  nueva.poner(4);
  //cout<<copia2;
  cout<<copia;
  //asigna = nueva;
  //cout<<asigna;
}
