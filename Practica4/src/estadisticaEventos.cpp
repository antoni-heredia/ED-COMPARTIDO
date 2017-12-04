#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char * argv[]){

  if (argc<2){
      cout<<"Error: debe dar al menos los nombres de dos ficheros con cronologías. "<<endl;
      cout<<"[Opcional]: un tercer nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Cronologia c1;
   f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.
   c1.recuentoCronologia(cout);
   return 0;
}
