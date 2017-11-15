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
void Pila<T>::copiar(const Pila<T> & p){
  nelem = p.nelem;
  datos = p.datos;
}

template <class T>
T Pila<T>::getElementoMaximo() const{
  Cola<elemento> aux = datos;
  elemento element = aux.frente();

  while(!aux.vacia()){
    element = aux.frente();
    aux.quitar();
  }

  return element.maximo;
}

template <class T>
void Pila<T>::poner(const T& c){
  elemento e;
  if(!datos.vacia()){
    int maximo = getElementoMaximo();
    if(maximo>= c)
      e.maximo = maximo;
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
/*
template <class T>
elemento Pila<T>::elementoTope() const{

  Cola<elemento> aux = datos;
  elemento element = aux.frente();

  while(!aux.vacia()){
    element = aux.frente();
    aux.quitar();
  }

  return element;
}*/


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
Pila<T>& Pila<T>::operator=(const Pila<T> &p){
  if (this!=&p){
    copiar(p);
  }
  return *this;
}

template <class T>
string Pila<T>::to_s() const{
  assert(nelem>0);
  string valores_cola;
  elemento tope;
  Cola<elemento> copia(datos);

  do{
    tope = copia.frente();
    valores_cola = valores_cola + to_string(tope.dato) ;
    valores_cola = valores_cola + " ";
    valores_cola = valores_cola + to_string(tope.maximo) ;
    valores_cola = valores_cola + "\n";
    copia.quitar();
  }while(!copia.vacia());

  valores_cola += "maximo = ";
  valores_cola += to_string(tope.maximo) + "\n";


  return valores_cola;
}
