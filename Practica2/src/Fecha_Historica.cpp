//#include "adicional.h"
#include "Fecha_Historica.h"
#include <assert.h>

using namespace std;
Fecha_Historica::Fecha_Historica(){
  anio=0;
  //vector=0;
}
Fecha_Historica::Fecha_Historica(int nuevo){
  anio=nuevo;
  //vector=0;
}
Fecha_Historica::Fecha_Historica(const string &cadena){
  bool creacion_de_clase = leerString(cadena);
  assert(creacion_de_clase);
}
Fecha_Historica::Fecha_Historica(const char* direccion_fichero){
  bool creacion_de_clase = leerFichero(direccion_fichero);
  assert(creacion_de_clase);
}


int Fecha_Historica::getAnio() const{
  return anio;
}

Vector_Dinamico<std::string> Fecha_Historica::getAcontecimientos() const{
  return vector;
}

void Fecha_Historica::cambiarAnio(int nuevo){
  anio=nuevo;
}

void Fecha_Historica::anadirAcontecimiento(string cadena){
  vector.resize(vector.size()+1);
  vector[vector.size()-1]=cadena;
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
    cerr << "Error al acceder al fichero." << endl;
    estado = false;
  }

  return estado;
}


bool Fecha_Historica::leerString(string cadena){

  bool estado = true;
  char delimitador = '#';
  string token;
  //buscamos la primerea posocion donde se encuentra el delimitador
  size_t posicion = cadena.find(delimitador);
  //se mira que almenos se contenga el delimitador una vez
  if(posicion != cadena.npos ){

    try
    {
      //nos quedamos con la primera parte delimitada del string y se alamacena
      //anio
      anio = stoi(cadena.substr(0,posicion));

      //se borra del string la parte que corresponde con el anio que es el primer
      // token
      cadena.erase(0,posicion+1);

      //Se actualiza la nueva posocion del delimitador y se comprueba que no sea
      //el final del string.
      while( (posicion = cadena.find(delimitador)) != cadena.npos){

        //se añade el acontecimiento hasta llegar al sigiente delimitador
        anadirAcontecimiento(cadena.substr(0,posicion));

        //se borra este aconteciento del string
        cadena.erase(0,posicion+1);

      }
      //se añade el ultimo
      anadirAcontecimiento(cadena.substr(0,posicion));

    //excepcion generica cuando se da un error como por ejempos desbordamiento
    //en el entero anio salta y pone el estado a false
    }catch(...){
        cerr << "Error en el formato de la fecha historica"<< endl;
        estado = false;
    }
  }else{
    cerr << "Error en el formato de la fecha historica"<< endl;
    estado = false;
  }

  return estado;
}

Vector_Dinamico<std::string> Fecha_Historica::busqueda(const string &cadena) const{
//no lo inico con valor mayor que 0 para que si no se encontra ninguna coincidencia
//tengamos un vector con size()=0 (Nose si seria mejor hacerlo devolviendo
//un booleano y pasando el vector donde guardar las coincidencias por parametro)
  Vector_Dinamico<std::string> encontrados;
  int acontecimientos_encontrados = 0;
//nose si seria mejor hacerlos aumentando de 1 en 1 porque la clase vector tiene
//solo la variable del tamaño del vector y no una con numero de elementos utilizados
  for(int i = 0; i < vector.size(); i++){
    //se mira si el string de la posicion i contiene la cadena buscada.
    if(vector[i].find(cadena) != vector[i].npos){
      //Si el vector de encontrados tiene el mimso tamaño que los aconteciemtos
      //encontrados hay que aumentarlo
      if(encontrados.size() == acontecimientos_encontrados){
        //si es la primera vez que se encuntra una conincidencia se aumenta a 1
        if(acontecimientos_encontrados == 0){
          encontrados.resize(1);
        }else{
          //En el caso de que ya se encontraran ya mas de una se aumenta el tamaño
          //al doble
          encontrados.resize(acontecimientos_encontrados * 2);
        }
      }

      encontrados[acontecimientos_encontrados] = vector[i];
      acontecimientos_encontrados++;
    }
  }
  //Al tener el problema de que la clase vector no tiene el elemento de numero
  // de usuados y solo tener el tamaño tendriamos que redimensionar para quitar
  //los que sobran
  if(acontecimientos_encontrados != encontrados.size())
    encontrados.resize(acontecimientos_encontrados);

  return encontrados;
}

ostream& operator<<(ostream& s, const Fecha_Historica& fecha){
  s << fecha.getAnio();
  Vector_Dinamico<string> vector = fecha.getAcontecimientos();
  for (int i = 0; i < vector.size(); i++)
    s << "#" << vector[i];
  s <<endl;
  return s;

}


int main(int argc, char *argv[]){

  Fecha_Historica prueba(argv[1]);

  Vector_Dinamico<string> vector=prueba.busqueda("hola");
  cout << prueba;
  for (int i = 0; i < vector.size(); i++)
    cout << vector[i] << endl;
  cout << vector.size() << endl;


}
