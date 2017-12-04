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
             os << "falete";

  /*for (it = begin(); it!=end();++it){
       os<<it->first<<"#";          //año esta en el key del map
       Fecha_Historica::const_iterator it_ev;
       for (it_ev=(*it).second.begin(); it_ev!=(*it).second.end();++it_ev)
        os<<(*it_ev)<<"#";
   }*/

   os << *this;
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

void Cronologia::recuentoCronologia(std::ostream& os){
  if(getNumeroFechas() > 0){
    iterator it = begin();
    int anio_max = it->second.getAnio();
    int numero_eventos_max = it->second.getNumeroAconteciemientos();
    int numero_eventos = numero_eventos_max , numero_anios = getNumeroFechas();

    ++it;
    while (it != end()){
      int nuevo_evento = it->second.getNumeroAconteciemientos();
      if(nuevo_evento > numero_eventos_max){
        anio_max = it->second.getAnio();
        numero_eventos_max = nuevo_evento;
      }
      numero_eventos += nuevo_evento;
      ++it;
    }

    os << "Numero de fechas historicas: " << numero_anios << endl;
    os << "Numero total de acontecimeintos en la cronoliga: " << numero_eventos << endl;
    os << "Numero medio de acontecimientos por año: " << numero_eventos / numero_anios << endl;
    os << anio_max << " es el año con mas acontecimientos ("<< numero_eventos_max <<" acontecimientos)" << endl;
  }else{
    os << "No tiene fechas historicas dentro de la cronologia" << endl;
  }


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

int Cronologia::getNumeroFechas() const{
  return static_cast<int>(cronologia.size());
}
/*
Vector_Dinamico<Fecha_Historica> Cronologia::getFechas()const{
  return vector_cronologico;
}


*/
ostream& operator<<(ostream& os,const Cronologia& cronologia){
  for (Cronologia::const_iterator it = cronologia.begin(); it != cronologia.end(); ++it)
    os << it->second;
  return os;
}

istream& operator>>(istream& is,Cronologia& cronologia){
  string linea;
  getline(is,linea,'\n');

  cronologia.aniadirFecha(Fecha_Historica(linea));
  int c = is.peek();
  while(c != EOF){
    getline(is,linea,'\n');
    cronologia.aniadirFecha(Fecha_Historica(linea));
    c = is.peek();
  }

  return is;
}
