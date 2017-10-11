#include <iostream>
//#include "adicional.h"
#include "Fecha_Historica.h"

using namespace std;
Fecha_Historica::Fecha_Historica(){
  anio=0;
  vector=0;
}
Fecha_Historica::Fecha_Historica(int nuevo){
  anio=nuevo;
  vector=0;
}

int Fecha_Historica::getAnio(){
  return anio;
}

void Fecha_Historica::getAcontecimientos(){
  if(vector.size()!=0)
    for(int i=0;i<vector.size();i++){
      cout<<"----------Acontecimientos del año "<<Fecha_Historica::getAnio()<<"----------"<<endl;
      cout<<vector[i]<<endl;
    }
  else cout<<"No hay acontecimientos asociados a este año."<<endl;
}
void Fecha_Historica::cambiarAnio(int nuevo){
  anio=nuevo;
}
void Fecha_Historica::anadirAcontecimiento(string cadena){
  vector.resize(vector.size()+1);
  vector[vector.size()-1]=cadena;
}
bool Fecha_Historica::Leer(const char* fichero){
  int anno;
	string cadena;

  // Abrir archivo
	ifstream archi;
  archi.open(fichero);

	if (!archi) {
		cerr << "No se pudo abrir el archivo " << fichero<<".\n";
		return false;
	}
  //Leer año

  getline(archi,cadena,'#');
  anno=stoi(cadena);
  //Leer acontecimientos
  while (getline(archi, cadena, '#')){
      anadirAcontecimiento(cadena);
  }
	if(archi.fail()){
		cerr << "Formato de archivo de lectura no válido.\n";
		return false;
	}
  anio=anno;
	return true;
}
int main(int argc, char *argv[]){
  cout<<"HOLA";
  Fecha_Historica prueba;
  prueba.Leer(argv[1]);
  cout<<prueba.getAnio();
  //cout<<prueba.getAcontecimientos();
}
