#include "Fecha_Historica.h"
using namespace std;
int main(int argc, char *argv[]){
  cout << "--Constructores de la clase Fecha--" << endl;

  cout << "Constructor por defecto" << endl;
  Fecha_Historica por_defecto;
  cout << por_defecto.to_s() << endl;

  cout << "Constructor por fichero" << endl;
  Fecha_Historica por_fichero(argv[1]);
  cout << por_fichero.to_s() << endl;

  cout << "Constructor Mediante string" << endl;
  string cadena = "1900#Paso algo importante#Terminamos el proyecto de ED";
  Fecha_Historica por_string(cadena);
  cout << por_string.to_s() << endl;

  cout <<"--Operadores--" << endl;

  cout <<"Operador =" << endl;
  Fecha_Historica operador_igual;
  operador_igual = por_string;
  cout << operador_igual.to_s() << endl;

  cout <<"Operador <<" << endl;
  cout << operador_igual << endl;

  cout <<"Operador []" << endl;
  cout << operador_igual[1] << endl;
  




  return 0;
}
