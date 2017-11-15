using namespace std;

template <class T>
Pila<T>::Pila(){
  nelem = 0;
}

template <class T>
Pila<T>::Pila(const Pila<T> & p){
  copiar(p);
}
template <class T>
void copiar(const Pila<T> & p){
  nelem = p.nelem;
  datos = p.datos;
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
bool Pila<T>::vacia() const{
  return nelem == 0;
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
  nelem--;
}

template <class T>
Pila& Pila<T>::operator=(const Pila<T> &p){
  if (this!=&p){
    copiar(p);
  }
  return *this;
}