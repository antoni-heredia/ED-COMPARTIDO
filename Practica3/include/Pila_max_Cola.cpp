using namespace std;

template <class T>
Pila<T>::Pila(){
  reservados = 0;
  nelem = 0;
}

/*template <class T>
Pila<T>::~Pila(){
  liberar();
}*/

template <class T>
void Pila<T>::liberar(){
  if(datos != 0)
    delete [] datos;
  datos = 0;
  nelem = 0;
  reservados = 0;
}

template <class T>
void Pila<T>::poner(const T& c){
  elemento e;
  if(!datos.vacia()){

    if(datos.frente().maximo >= c)
      e.maximo = datos.frente().maximo;
    else
      e.maximo = c;

  }else{
    e.maximo = c;
  }

  e.dato = c;
  nelem++;
  datos.poner(e);
}

template <class T>
T Pila<T>::tope() const{

  Cola<elemento> aux = datos;
  elemento element = aux.frente();

  while(!aux.vacia()){
    element = aux.frente();
    aux.quitar();
  }

  return element.dato;

}

template <class T>
void Pila<T>::quitar(){

  assert(nelem>0);
  Cola<elemento> aux;
  elemento elemento;

  do{
    aux.poner(datos.frente());
    datos.quitar();
  //  aux2
}while(datos.num_elementos() > 1);



  datos = aux;
  /*Cola<elemento> aux(datos);

  elemento element;
  do{
    element = aux.frente();
    aux.quitar();
  }while(!aux.vacia());*/

  nelem--;
}
