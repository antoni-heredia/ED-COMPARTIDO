#include "Cronologia.h"
using namespace std;
int main(int argc, char *argv[]){

  //La mayoria de cout estan comentados, ya que a ser cosas tan laargas se ve muy feo por pantalla
  //solo hay que descomentarlos para probar que va bien

  cout << "Creamos una cronologia a partir del documento pasado como argumento ordenada de forma ascendente: " << endl;
  Cronologia crono(argv[1], true);

  cout << "Creamos una cronologia a partir del documento pasado como argumento ordenada de forma descendente: " << endl;
  Cronologia cronodes(argv[1], true);
  //cout << cronodes.to_s();

  cout << "Creamos una cronologia a partir de una cronologia existente: " << endl;
  Cronologia copia(crono);
  //cout << copia.to_s();


  cout << "Eliminamos una fecha historia, a partir de un año y la volvemos a ingresar: "<< endl;
  Fecha_Historica fecha;
  fecha = copia.busqueda(2011);
  cout << "La fecha a borrar es: " << fecha.to_s() << endl;
  copia.BorrarFechaHistorica(2011);
  cout << copia.to_s() << endl;
  copia.aniadirFecha(fecha);

  //Para probar el operador << con un objeto cronologia
  //cout << copia << endl;

  Cronologia busqueda;
  cout << "Buscamos la cadena \"London\" en la cronologia: " << endl;
  busqueda = copia.busqueda("London");
  cout << busqueda.to_s() << endl;



  return 0;
}
