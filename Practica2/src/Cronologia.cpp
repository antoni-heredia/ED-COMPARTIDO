#include "Cronologia.h"
#include <assert.h>
#include <cctype>
using namespace std;


Cronologia::Cronologia(){
  orden_asc = true;
}

Cronologia::Cronologia(const char *  fichero) {
  bool estado = true;
  num_fechas = 0;
  estado = leerFichero(fichero);

  ordenarCronologiaAsc();
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
    getline(fichero,linea,'\n');
    cout << linea << endl;

    aniadirFecha(Fecha_Historica(linea));
    int c = fichero.peek();
    while(c != EOF){
      getline(fichero,linea,'\n');
      aniadirFecha(Fecha_Historica(linea));
      cout << linea << endl;
      c = fichero.peek();
    }

    fichero.close();
  }else{
    cerr << "¡¡Error al acceder al fichero "<< direccion_fichero << "!!" << endl;
    estado = false;
  }
  return estado;

}

void Cronologia::ordenarCronologiaAsc(){
  Fecha_Historica temp;
  for (int i=1; i<num_fechas; i++)
    for(int j=0 ; j<  num_fechas - 1; j++)
      if (vector_cronologico[j] > vector_cronologico[j+1]){
        temp = vector_cronologico[j];
        vector_cronologico[j] = vector_cronologico[j+1];
        vector_cronologico[j+1] = temp;
      }

}

std::string Cronologia::to_s()const {

  string s = "";
  for(int i = 0; i < num_fechas; i++)
    s += vector_cronologico[i].to_s();
  return s;
}

int main(int argc, char *argv[]){
  Cronologia crono(argv[1]);
  cout << crono.to_s();
  return 0;
}
