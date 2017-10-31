#include "Cronologia.h"
#include <assert.h>
using namespace std;


Cronologia::Cronologia(){
  orden_asc = true;
}

Cronologia::Cronologia(const char *  fichero) {
  bool estado = true;
  num_fechas = 0;
  estado = leerFichero(fichero);

  orden_asc = true;

  assert(estado);
}

/*
Cronologia::Cronologia(const * char fichero,bool orden_asc) : vector_cronologico= new Fecha_Historica(fichero){

}
*/

void Cronologia::aniadirFecha(Fecha_Historica fecha){
  //Usamos esta comparacion para evitar realizar el resize de uno en uno
  //lo hago porcetualmente(con un factor de 0.2)
  if(num_fechas == vector_cronologico.size())
    vector_cronologico.resize((vector_cronologico.size()*1.2)+1);

  //añadimos la cadena y sumamos 1 al numero de acontecientos
  vector_cronologico[num_fechas]=fecha;
  num_fechas++;

}


bool Cronologia::leerFichero(const char * direccion_fichero){
  bool estado = true;

  string linea;
  ifstream fichero;
  fichero.open(direccion_fichero);

  if(fichero){
    getline(fichero,linea);
    aniadirFecha(Fecha_Historica(linea));

    while(!fichero.eof()){
      getline(fichero,linea);
      aniadirFecha(Fecha_Historica(linea));
    }

    fichero.close();
  }else{
    cerr << "¡¡Error al acceder al fichero "<< direccion_fichero << "!!" << endl;
    estado = false;
  }
  return estado;

}
int main(int argc, char *argv[]){
  Cronologia crono(argv[1]);
  return 0;
}
