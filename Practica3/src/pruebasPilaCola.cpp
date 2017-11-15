#include <iostream>
#include "Pila_max_Cola.h"
using namespace std;


int main(){
  Pila <int> nueva;
  nueva.poner(7);
  nueva.poner(5);
  cout << "hola" << endl;

  //nueva.quitar();
  nueva.poner(23);
  nueva.poner(4);
  nueva.quitar();
  cout << nueva.tope() << endl;

}
