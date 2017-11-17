#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "Pila_max_VD.h"
using namespace std;


int main(){
  Pila <int> nueva;

  for(int i = 0; i < 15; i++){
    nueva.poner(rand() % 100);
  }
  cout << "Mostrando pila 1 \n" << nueva.to_s();

  cout << "Copiando la pila anterior....." << endl;
  Pila<int> copia(nueva);
  cout << "Se le quitan dos elementos a la pila copiada...." << endl;
  copia.quitar();
  copia.quitar();
  cout << "Mostrando pila copia \n" << copia.to_s();
  cout << "Se la añade el elemento 155 a la pila." << endl;
  copia.poner(155);
  cout << "Mostrando pila copia \n" << copia.to_s();


}
