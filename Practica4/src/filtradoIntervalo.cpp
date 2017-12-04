#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char * argv[]){

  if (argc<4 ){
      cout<<"Error: debe dar al menos el nombre de un fichero con cronología. "<<endl;
      cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia c1, cIntervalo;
   f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.

   cIntervalo = c1.busqueda(stoi(argv[2]),stoi(argv[3]));
   if (argc==4)   //No se dio fichero de salida, imprimimos en cout
      cIntervalo.ImprimeCronologia(cout);
   else{
     ofstream fout(argv[3]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
      cIntervalo.ImprimeCronologia(fout);

   }
   return 0;
}
