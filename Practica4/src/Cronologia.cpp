#include "Cronologia.h"
#include <assert.h>
#include <cctype>
using namespace std;

/*################# Constructores #################*/
Cronologia::Cronologia(){}

Cronologia::Cronologia(const char * fichero){
  bool estado = true;
  estado = leerFichero(fichero);
  assert(estado);
}

Cronologia::Cronologia(const Cronologia & original){
  copia(original);
}

void Cronologia::copia(const Cronologia & original){
  cronologia = original.cronologia;
}

/*################# Iteradores #################*/

Cronologia::iterator Cronologia::begin(){
  return cronologia.begin();
}
Cronologia::iterator Cronologia::end(){
  return cronologia.end();
}

Cronologia::const_iterator Cronologia::begin() const{
  return cronologia.cbegin();
}

Cronologia::const_iterator Cronologia::end() const{
  return cronologia.cend();
}

/*################# Funciones Públicas #################*/

Cronologia Cronologia::Union(const Cronologia & c2){
  Cronologia cUnion;
  cUnion = *this;
  for(const_iterator it = c2.begin();it!=c2.end();++it)
    cUnion.aniadirFecha(it->second);

  return cUnion;
}

void Cronologia::ImprimeCronologia (ostream &os){
   Cronologia::const_iterator it;
   for (it = begin(); it!=end();++it){
       os<<it->first<<"#";          //año esta en el key del map
       Fecha_Historica::const_iterator it_ev;
       for (it_ev=(*it).second.begin(); it_ev!=(*it).second.end();++it_ev)
        os<<(*it_ev)<<"#";
   }
}

Cronologia Cronologia::busqueda(int fecha){

  Cronologia resultado;
  for(iterator it=begin();it!=end();++it)
    if(it->first==fecha)
      resultado.aniadirFecha(it->second);
  return resultado;
}

Cronologia Cronologia::busqueda(const std::string cadena){

  Cronologia resultado;
  for(iterator it=begin();it!=end();++it)
    if(it->second.busqueda(cadena).getNumeroAconteciemientos()>0)
      resultado.aniadirFecha(it->second.busqueda(cadena));
  return resultado;
}

Cronologia Cronologia::busqueda(int anio_inicio,int anio_final){
  assert(anio_inicio>anio_final);
  Cronologia resultado;
  for(int i = anio_inicio;i!=anio_final;i++)
    resultado.Union(busqueda(i));
  return resultado;
}

/***************************************************** /

void Cronologia::BorrarFechaHistorica(int anio){
  assert(num_fechas>0);
  assert(anio>0);

  int pos_ano = existeAnio(anio);
  assert(pos_ano != -1);

  for (int i = pos_ano-1 ; i < num_fechas-1; i++)
    vector_cronologico[i] = vector_cronologico[i+1];

  num_fechas = num_fechas-1;
}

Cronologia Cronologia::busqueda(std::string cadena){

  Cronologia c_aux;
  int a_aux;

  for(int i = 0; i < num_fechas; i++){
    Vector_Dinamico< std::string > 	v_aux = vector_cronologico[i].busqueda(cadena);
    if(v_aux.size() > 0){
      Fecha_Historica f_aux;
      a_aux = vector_cronologico[i].getAnio();
      f_aux.cambiarAnio(a_aux);
      for(int x = 0; x<v_aux.size(); x++){
        f_aux.anadirAcontecimiento(v_aux[x]);
      }
      c_aux.aniadirFechaDes(f_aux);
    }
  }

  return c_aux;

}
bool Cronologia::esAscendente(){
  return orden_asc;
}





/***************************************************/
int Cronologia::existeAnio(int anio) const{
  const_iterator it = cronologia.find(anio);
  return it!=end();
}

void Cronologia::aniadirFecha(Fecha_Historica fecha){

   int anio = fecha.getAnio();

   if (cronologia.count(anio) > 0)
     cronologia[anio].unirFechas(fecha);
   else
      cronologia.insert(std::pair<int,Fecha_Historica>(anio,fecha));
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
/*************************************************** /
void Cronologia::ordenarCronologiaAsc(){
  bool cambio = true;
  Fecha_Historica intercambia;
  for (int izda = 0; izda < num_fechas && cambio; izda++){
    cambio = false;
    for (int i = num_fechas-1 ; i > izda ; i--){
      if (vector_cronologico[i].getAnio() < vector_cronologico[i-1].getAnio()){
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
      if (vector_cronologico[i].getAnio() > vector_cronologico[i-1].getAnio()){
        cambio = true;
        intercambia = vector_cronologico[i];
        vector_cronologico[i] = vector_cronologico[i-1];
        vector_cronologico[i-1] = intercambia;
      }
    }
  }
}
*/
std::string Cronologia::to_s() {

  string s = "";
  for(iterator it = begin(); it!=end();++it)
    s += it->second.to_s();

  return s;
}
/*
int Cronologia::getNumeroFechas() const{
  return num_fechas;
}
Vector_Dinamico<Fecha_Historica> Cronologia::getFechas()const{
  return vector_cronologico;
}

ostream& operator<<(ostream& s,const Cronologia& cronologia){
  for (int i = 0; i < cronologia.getNumeroFechas(); i++)
    s << cronologia.getFechas()[i];
  return s;
}
*/
