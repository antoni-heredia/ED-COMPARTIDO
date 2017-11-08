using namespace std;

template <class T>
Pila<T>::Pila(){
  reservados = 0;
  nelem = 0;
  datos = 0;
}

template <class T>
Pila<T>::~Pila(){
  liberar();
}

template <class T>
void Pila<T>::liberar(){
  if(datos != 0)
    delete [] datos;
  datos = 0;
  nelem = 0;
  reservados = 0;
}

template <class T>
void Pila<T>::poner(T c){

  if(nelem == reservados)
    resize(reservados*2);
  
  elemento e;
  
  if(datos.frente().maximo >= c)
    e.maximo = datos.frente().maximo;
  else
    e.maximo = c;
  
  e.dato = c;

  datos.poner(c);
}

template <class T>
T Pila<T>::tope() const{

  Cola<elemento> *aux;
  for(int i = 0; i < nelem-1; i++){
    aux.poner(datos.frente());
    datos.quitar();    
  }

  elemento = datos.frente();
  datos.quitar();

  datos = aux;

  return elemento;

}


template <class T>
int Pila<T>::resize(int n){
    int i, min;
    /* Si piden el mismo tamaño que tiene: no hacer nada */
    if (reservados == n)
      return 0;
    /* Reserva nuevo espacio */
    Cola<elemento> * q = new Cola<elemento> [n];

    if (q == 0)
      return 1;

    /* Copiar los componentes que se mantienen */
    min = (nelem < n ? nelem : n);
    for (i = 0; i < min; i++){
      q[i] = datos[i];
    }

    delete [] datos;
    datos = q;
    reservados = n;
    nelem = min;
    
    return 0;
}

