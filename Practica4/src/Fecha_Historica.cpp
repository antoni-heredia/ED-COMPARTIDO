//Constructores
#include "Fecha_Historica.h"
#include <string>
#include <iostream>
#include <utility>
#include <set>
#include <fstream>


using namespace std;

//Constructores
Fecha_Historica::Fecha_Historica(){
  fecha.first = 0;
}
Fecha_Historica::Fecha_Historica(int anio){
  fecha.first = anio;
}

Fecha_Historica::Fecha_Historica(const string &cadena){
  bool creacion_de_clase = leerString(cadena);
  assert(creacion_de_clase);
}

Fecha_Historica::Fecha_Historica(const char* direccion_fichero){
  bool creacion_de_clase = leerFichero(direccion_fichero);
  assert(creacion_de_clase);
}

Fecha_Historica::Fecha_Historica(const Fecha_Historica & f):fecha(f.fecha){
}
//operadores

//Funciones privadas

void Fecha_Historica::mostrarErrorFormatoFecha() const{
  cerr << "¡¡Error en el formato de la fecha historica!!"<< endl;
}

bool Fecha_Historica::leerString(string cadena){

  bool estado = true;
  //buscamos la primerea posocion donde se encuentra el delimitador
  size_t posicion = cadena.find(DELIMITADOR);
  //se mira que almenos se contenga el delimitador una vez
  if(posicion != cadena.npos ){

    try
    {
      //nos quedamos con la primera parte delimitada del string y se alamacena
      //anio
      fecha.first = stoi(cadena.substr(0,posicion));

      if(to_string(fecha.first) == cadena.substr(0,posicion)){
        assert(to_string(fecha.first) == cadena.substr(0,posicion));
        //se borra del string la parte que corresponde con el anio que es el primer
        // token
        cadena.erase(0,posicion+1);

        //Se actualiza la nueva posocion del delimitador y se comprueba que no sea
        //el final del string.
        while( (posicion = cadena.find(DELIMITADOR)) != cadena.npos){

          //se añade el acontecimiento hasta llegar al sigiente delimitador
          anadirAcontecimiento(cadena.substr(0,posicion));

          //se borra este aconteciento del string
          cadena.erase(0,posicion+1);

        }
        //se añade el ultimo
        anadirAcontecimiento(cadena.substr(0,posicion));
    }else{
      mostrarErrorFormatoFecha();
      estado = false;
    }
    //excepcion generica cuando se da un error como por ejempos desbordamiento
    //en el entero anio salta y pone el estado a false
    }catch(...){
        mostrarErrorFormatoFecha();
        estado = false;
    }
  }else{
    mostrarErrorFormatoFecha();
    estado = false;
  }

  return estado;
}

bool Fecha_Historica::leerFichero(const char* direccion_fichero){
  bool estado = true;

  string linea;

  ifstream fichero;
  fichero.open(direccion_fichero);

  if(fichero){

    getline(fichero,linea);
    estado = leerString(linea);
    fichero.close();

  }else{
    cerr << "¡¡Error al acceder al fichero "<< direccion_fichero << "!!" << endl;
    estado = false;
  }

  return estado;
}

//Publicas
int Fecha_Historica::getAnio() const {
  return fecha.first;
}

void Fecha_Historica::anadirAcontecimiento(const string& cadena){
  fecha.second.insert(cadena);
}

void Fecha_Historica::cambiarAnio(int nuevo){
  fecha.first = nuevo;
}

void Fecha_Historica::eliminarAcontecimiento(int posicion){
    assert(posicion < static_cast<int>(fecha.second.size()) && posicion >= 0);
    set<string>::iterator it = fecha.second.begin();
    for(int i = 0; i < posicion; i++)
      ++it;

    fecha.second.erase(it);
}

void Fecha_Historica::eliminarAcontecimientos(const string& cadena){
  set<string>::iterator it = fecha.second.begin();
  while(it != fecha.second.end()){
    if( it->find(cadena) != std::string::npos)
      it = fecha.second.erase(it);
    else
      ++it;

  }
}

int Fecha_Historica::getNumeroAconteciemientos() const{
  return static_cast<int>(fecha.second.size());
}

std::string Fecha_Historica::to_s() const{
  string s;
  s += "Año: " + to_string(fecha.first) + "\n";
  int contador_acontecimientos = 0;

  for (set<string>::iterator it = fecha.second.begin() ; it != fecha.second.end(); ++it){
    s += "Acontecimiento " + to_string(contador_acontecimientos) + ": " + *it + "\n";
    contador_acontecimientos++;
  }

  s += "\n";
  return s;
}

bool Fecha_Historica::unirFechas(const Fecha_Historica& anadida){
  bool estado = false;
  if(fecha.first == anadida.getAnio()){
    estado = true;
    fecha.second.insert(anadida.begin(),anadida.end());
  }
  return estado;
}

Fecha_Historica Fecha_Historica::busqueda(const string& cadena) const{
//no lo inico con valor mayor que 0 para que si no se encontra ninguna coincidencia
//tengamos un vector con size()=0 (Nose si seria mejor hacerlo devolviendo
//un booleano y pasando el vector donde guardar las coincidencias por parametro)
  Fecha_Historica encontrados(fecha.first);

//nose si seria mejor hacerlos aumentando de 1 en 1 porque la clase vector tiene
//solo la variable del tamaño del vector y no una con numero de elementos utilizados

  for(set<string>::iterator it = fecha.second.begin(); it != fecha.second.end(); ++it){

    //se mira si el string de la posicion i contiene la cadena buscada
    if(it->find(cadena) != it->npos)
      encontrados.anadirAcontecimiento(*it);

  }

  return encontrados;
}

Fecha_Historica::iterator Fecha_Historica::begin(){
  return fecha.second.begin();
}
Fecha_Historica::iterator Fecha_Historica::end(){
  return fecha.second.end();
}

Fecha_Historica::const_iterator Fecha_Historica::begin() const{
  return fecha.second.begin();
}

Fecha_Historica::const_iterator Fecha_Historica::end() const{
  return fecha.second.end();
}
