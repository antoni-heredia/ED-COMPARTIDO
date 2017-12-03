#include "Cronologia.h"
using namespace std;

void ImprimeCronologia (const Cronologia &c, ostream &os){
   Cronologia::const_iterator it;
   for (it=c.begin(); it!=c.end();++it){
       os<<(*it).first<<"#";          //año esta en el key del map
       Fecha_Historica::const_iterator it_ev;
       for (it_ev=(*it).second.begin(); it_ev!=(*it).second.end();++it_ev)
        os<<(*it_ev)<<"#";
   }
}
int main(int argc,char* argv[]){
  Cronologia falete(argv[1]);
  Cronologia pantoja(argv[2]);
  Cronologia recuento(argv[3]);

  cout<<falete.to_s();
  cout<<pantoja.to_s();
  cout<<"Union de falete y pantoja"<<endl;
  Cronologia flamencoFusion = falete.Union(pantoja);
  cout<<flamencoFusion.to_s();
  cout<<"Buscamos la fecha 1900."<<endl;
  Cronologia busqueda = flamencoFusion.busqueda(1900);
  cout<<busqueda.to_s();
  cout<<"Buscamos la palabra prueba."<<endl;
  Cronologia busquedaTwo = flamencoFusion.busqueda("prueba");
  cout<<busquedaTwo.to_s();

  cout << "Recuento de prueba." << endl;
  cout << recuento.to_s();
  recuento.recuentoCronologia(cout);
}
