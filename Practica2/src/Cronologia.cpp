#include "Cronologia.h"
#include <assert.h>
#include <cctype>
using namespace std;


Cronologia::Cronologia(){
  orden_asc = true;
}

Cronologia::Cronologia(const char *  fichero) {
  *this = Cronologia(fichero, true);
}


Cronologia::Cronologia(const char * fichero,bool orden_asc){
  bool estado = true;
  num_fechas = 0;
  estado = leerFichero(fichero);
  orden_asc = orden_asc;

  if(!orden_asc)
    ordenarCronologiaDesc();
  else
    ordenarCronologiaAsc();

  assert(estado);
}

Cronologia::Cronologia(const Cronologia & original){
  copia(original);
}

void Cronologia::copia(const Cronologia & original){

  num_fechas = original.num_fechas;
  orden_asc = original.orden_asc;
  vector_cronologico.resize(original.vector_cronologico.size());

  for(int i = 0; i < num_fechas; i++)
    vector_cronologico[i] = original.vector_cronologico[i];

}

Fecha_Historica Cronologia::busqueda(int fecha){

  int pos_ano = existeAnio(fecha);
  assert(pos_ano != -1);

  return vector_cronologico[pos_ano];
}

Vector_Dinamico<std::string> Cronologia::busqueda(int fecha,const std::string cadena){

  int pos_ano = existeAnio(fecha);
  assert(pos_ano != -1);

  return vector_cronologico[pos_ano].busqueda(cadena);
}

void Cronologia::BorrarFechaHistorica(int anio){
  assert(num_fechas>0);
  assert(anio<num_fechas+1);
  assert(anio>0);

  int pos_ano = existeAnio(anio);
  assert(pos_ano != -1);

  for (int i = pos_ano-1 ; i < num_fechas-1; i++)
    vector_cronologico[i] = vector_cronologico[i+1];

  num_fechas = num_fechas-1;
}
/*
Cronologia Cronologia::busqueda(std::string cadena){

  Cronologia c_aux;
  int a_aux;

  for(int i = 0; i < num_fechas; i++){
    Vector_Dinamico< std::string > 	v_aux;
    if(v_aux == 0){
      Fecha_Historica f_aux;
      v_aux = vector_cronologico[i].busqueda(cadena);
      a_aux = vector_cronologico[i].getAnio();
      f_aux.cambiarAnio(a_aux);
      for(int i = 0; i<v_aux.size(); i++)
        f_aux.anadirAcontecimiento(v_aux[i]);

      c_aux.aniadirFecha(f_aux);
    }
  }

  return c_aux;
}
*/
void Cronologia::aniadirFecha(Fecha_Historica fecha){
  int pos_ano = existeAnio(fecha.getAnio());

  if(pos_ano == -1){
    //Usamos esta comparacion para evitar realizar el resize de uno en uno
    //lo hago porcetualmente(con un factor de 0.2)
    if(num_fechas == vector_cronologico.size())
      vector_cronologico.resize((vector_cronologico.size()*1.2)+1);

    //añadimos la cadena y sumamos 1 al numero de acontecientos
    vector_cronologico[num_fechas]=fecha;
    num_fechas++;
  }else{
    for(int i = 0; i < fecha.getNumeroAconteciemientos(); i++)
      vector_cronologico[pos_ano].anadirAcontecimiento(fecha[i]);
  }
}

int Cronologia::existeAnio(int anio) const{
  bool existe = false;
  int i;

  for(i = 0; i < num_fechas && !existe; i++)
    if(vector_cronologico[i].getAnio() == anio)
      existe = true;

  if(!existe)
    i = -1;

  return i;
}

bool Cronologia::leerFichero(const char * direccion_fichero){
  bool estado = true;

  string linea;
  ifstream fichero;
  fichero.open(direccion_fichero);

  if(fichero){
    getline(fichero,linea,'\n');

    aniadirFecha(Fecha_Historica(linea));
    int c = fichero.peek();
    while(c != EOF){
      getline(fichero,linea,'\n');
      aniadirFecha(Fecha_Historica(linea));
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
  bool cambio = true;
  Fecha_Historica intercambia;
  for (int izda = 0; izda < num_fechas && cambio; izda++){
    cambio = false;
    for (int i = num_fechas-1 ; i > izda ; i--){
      if (vector_cronologico[i] < vector_cronologico[i-1]){
        cambio = true;
        intercambia = vector_cronologico[i];
        vector_cronologico[i] = vector_cronologico[i-1];
        vector_cronologico[i-1] = intercambia;
      }
    }
  }
}

void Cronologia::ordenarCronologiaDesc(){
  bool cambio = true;
  Fecha_Historica intercambia;
  for (int izda = 0; izda < num_fechas && cambio; izda++){
    cambio = false;
    for (int i = num_fechas-1 ; i > izda ; i--){
      if (vector_cronologico[i] > vector_cronologico[i-1]){
        cambio = true;
        intercambia = vector_cronologico[i];
        vector_cronologico[i] = vector_cronologico[i-1];
        vector_cronologico[i-1] = intercambia;
      }
    }
  }
}

std::string Cronologia::to_s()const {

  string s = "";
  for(int i = 0; i < num_fechas; i++)
    s += vector_cronologico[i].to_s();
  return s;
}
