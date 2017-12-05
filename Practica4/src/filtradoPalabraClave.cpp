#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char * argv[]){

  if (argc<2 ){
      cout<<"Error: debe dar al menos el nombre de un fichero con cronología. "<<endl;
	  cout<<"[Opcional]: una segunda palabra para buscar."<<endl;
      cout<<"[Opcional]: un tercer nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia c1, c2, cBusqueda;
   f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.
   if(argc > 2)
      cBusqueda = c1.busqueda(argv[2]);
   else{
		cout << "Por favor introduzca la palabra a buscar: ";
		string palabra;
		cin >> palabra;
		cBusqueda = c1.busqueda(palabra);
   }

   if (argc!=4)   //No se dio fichero de salida, imprimimos en cout
      cBusqueda.ImprimeCronologia(cout);
   else{
     ofstream fout(argv[3]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
      cBusqueda.ImprimeCronologia(fout);

   }
   return 0;
}
