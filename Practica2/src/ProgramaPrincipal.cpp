#include "Cronologia.h"
using namespace std;
int main(int argc, char *argv[]){

  cout << "Creamos una cronologia a partir del documento pasado como argumento: " << endl;
  Cronologia crono(argv[1], true);
  cout << crono.to_s();

  cout << "Creamos una cronologia a partir de una cronologia existente: " << endl;
  Cronologia copia(crono);
  cout << copia.to_s();

  cout << "Buscamos una cadena de texto en la cronologia: " << endl;
  Cronologia busqueda;
  busqueda = copia.busqueda("London");
  cout << busqueda.to_s();
  Fecha_Historica fecha;
  fecha = copia.busqueda(2011);
  cout << fecha.to_s();
  return 0;
}
