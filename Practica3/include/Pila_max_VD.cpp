using namespace std;

template <class T>
Pila<T>::Pila(){
  datos = 0;
  maximo = 0;
  reservados = 0;
  nelem = 0;
}

template <class T>
Pila<T>::Pila(const Pila<T> & p){
  datos = 0;
  maximo = 0;
  reservados = 0;
  nelem = 0;  
  copiar(p);
}

template <class T>
Pila<T>::~Pila(){
  liberar();
}

template <class T>
int Pila<T>::getReservados() const{
  return reservados;
};

template <class T>
int Pila<T>::getNumeroElementos() const{
  return nelem;
};

template <class T>
void Pila<T>::liberar(){
  if(datos != 0){
    delete [] datos;
    delete [] maximo;
    datos = 0;
    maximo = 0;
    nelem = 0;
    reservados = 0;
  }
 
}

template <class T>
T* Pila<T>::getDatos() const{
  return datos;
}

template <class T>
T Pila<T>::getElementoMaximo() const{
  assert(nelem>0);
  return maximo[nelem-1];
}

template <class T>
bool Pila<T>::vacia() const{
  return(nelem==0);
}

template <class T>
void Pila<T>::copiar(const Pila<T> & p){
  nelem = p.nelem;
  resize(p.reservados);
  for (int i = 0; i < reservados-1;i++){
    datos[i] = p.datos[i];
    maximo[i] = p.maximo[i];
  }

}

template <class T>
void Pila<T>::poner(T c){
  if (nelem==reservados)
    resize(2+2*reservados);
  datos[nelem] = c;

  if(nelem==0)
    maximo[nelem] = c;
  else if (c>maximo[nelem-1])
    maximo[nelem] = c;
  else
    maximo[nelem] = maximo[nelem-1];

  nelem++;
}

template <class T>
void Pila<T>::quitar(){
  assert(nelem>0);
  nelem--;
  if(nelem<reservados/4)
    resize(reservados/2);
}

template <class T>
T Pila<T>::tope() const{
  assert(nelem>0);
  return datos[nelem-1];
}

template <class T>
int Pila<T>::resize(int n){
    int i, min;
    /* Si piden el mismo tamaño que tiene: no hacer nada */

    
    if (reservados == n)
      return 0;

    
    /* Reserva nuevo espacio */
    T* q = new T [n];
    T* p = new T [n];
    if (p == 0)
      return 1;

    /* Copiar los componentes que se mantienen */
    min = (reservados < n ? reservados : n);
    for (i = 0; i < min; i++){
      p[i] = datos[i];
      q[i] = maximo[i];
    }
    if(datos != 0)
      delete [] datos;
    if(maximo != 0)  
      delete [] maximo;

    datos = p;
    maximo = q;
    reservados = n;
    return 0;
}

template <class T>
string Pila<T>::to_s(){
  string s;
  s +=  "Número de reservados: " + to_string(reservados) + "\n";
  s +=  "Número de elementos: " + to_string(nelem) + "\n";
 s +=  "Elemento máximo de la pila: " + to_string(getElementoMaximo()) + "\n";
  for (int i = 0; i < nelem; i++ )
    s += "Elemento " + to_string(i) + ": " + to_string(datos[i]) + "\n";
  return s;
}

template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> &p){
  if (this!=&p){
    liberar();
    copiar(p);
  }
  return *this;
}

template <class T>
ostream& operator<< (ostream& s, const Pila<T>& pila){
  s << "Tamaño reservado: " << pila.getReservados() << endl;
  s << "Número de elementos en la pila: " << pila.getNumeroElementos() << endl;
  s << "Elemento máximo de la pila: " << pila.getElementoMaximo() << endl;
  for (int i = 0; i < pila.getNumeroElementos(); i++)
    s << "Elemento "<<i<<": "<<pila.getDatos()[i] << endl;
  return s;
}
