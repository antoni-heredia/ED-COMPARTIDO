#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>

QuienEsQuien::QuienEsQuien(){}
void QuienEsQuien::copiar(const QuienEsQuien &otra){
	personajes = otra.personajes;
	atributos = otra.atributos;
	tablero = otra.tablero;
	arbol = otra.arbol;
	jugada_actual = otra.jugada_actual;
}
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	copiar(quienEsQuien);
}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	if(this != &quienEsQuien){
		this->limpiar();
		copiar(quienEsQuien);
	}
	return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	tablero.clear();
	arbol.clear();
	//jugada_actual.clear();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();

  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");

    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}

    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;

	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));

	    		assert(valor == "0" || valor == "1");

	    		bool valor_atributo = valor == "1";

	    		atributos_personaje.push_back(valor_atributo);

	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}

			string nombre_personaje = linea;

	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}

	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n
  *      con el n�mero de elementos especificado por @e digitos.

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

string QuienEsQuien::resolver_juego(const int numero_atributos){
	int i,j;
	int coincidencias;
	bool encontrado = false;
	for( i = 0; i < tablero.size() && !encontrado; i++ ){
		coincidencias=0;
		for( j = 0; j < numero_atributos; j++ )
			if( tablero[i][j] )
				coincidencias++;
		if( coincidencias == numero_atributos)
			encontrado = true;
	}
	return personajes[i];
}
void QuienEsQuien::crear_arbol_recursivo(bintree<Pregunta>::node pregunta, int atributo, vector<bool> eliminados){
	//se comprueba que tiene no es un nodo hoja.
	if((*pregunta).obtener_num_personajes() > 1){
		//eliminados_si alamacena los personajes que cumplan la pregunta que corresponda.
		//eliminados_no alamacena los personajes que no cumplan la pregunta que corresponda.
		vector<bool> eliminados_si, eliminados_no;
		//los iniciamos los dos con los datos que nos pasaron en eliminados.
		eliminados_si = eliminados_no = eliminados;
		//cumplen almacena el numero de personajes que cumplen la pregunta
		//no_cumplen almacena el numero de personajes que no cumplen la pregunta
		int cumplen = 0, no_cumplen = 0;
		//el for corrige los datos de los personajes de la pregunta anterior eliminar
		//con la pregunta correspondiente de esta pasada
		for(int i = 0 ; i < eliminados.size(); i++)
			//si eliminado es falso quiere decir que ese personaje aun puede ser elegido
			//asi que pasamos a ver si se cumple esta pregunta
			if(!eliminados[i]){
				//Se comprueba que se cumpla la condicion del atributo anterior
				if(tablero[i][atributo - 1]){
					//si es verdad se elimina ese personaje de las posibles elecciones que no cumplen
					// la pregunta y se suma uno al contador que nos muestra el numero de personajes
					//que pueden ser
					cumplen++;
					eliminados_no[i] = true;
				}else{
					//si no es verdad se elimina ese personaje de las posibles elecciones que si cumplen
					// la pregunta y se suma uno al contador que nos muestra el numero de personajes
					//que no pueden ser
					no_cumplen++;
					eliminados_si[i] = true;
				}

			}
		int nuevo_atributo;
		nuevo_atributo = anadir_nuevo_nodo(pregunta,atributo,eliminados_si,cumplen,1);
		nuevo_atributo = anadir_nuevo_nodo(pregunta,atributo,eliminados_no,no_cumplen,0);
		if(atributo == nuevo_atributo)
			atributo++;
		else
			atributo = nuevo_atributo;

		if(cumplen > 0 && cumplen < (*pregunta).obtener_num_personajes()){
			crear_arbol_recursivo(pregunta.left(), atributo, eliminados_si);
			crear_arbol_recursivo(pregunta.right(), atributo, eliminados_no);
		}else{

			crear_arbol_recursivo(pregunta, atributo, eliminados);
		}
	}

}
int QuienEsQuien::anadir_nuevo_nodo(bintree<Pregunta>::node pregunta, int atributo, vector<bool> eliminados, int num_elecciones, bool esIzquierda){

	cout << num_elecciones << " " << (*pregunta).obtener_num_personajes() << " " << atributos[atributo] << endl;
	if(num_elecciones > 1 && (*pregunta).obtener_num_personajes() > num_elecciones){
		int cumplen = 0;
		for(int i = 0 ; i < eliminados.size(); i++)

			if(!eliminados[i]){
				if(esIzquierda)
					if(tablero[i][atributo])
						cumplen++;


				else
				if(tablero[i][atributo])
					cumplen++;
			}

		if(cumplen != num_elecciones )
			atributo++;
		if(esIzquierda){
			arbol.insert_left(pregunta, Pregunta(atributos[atributo], num_elecciones));

		}else
			arbol.insert_right(pregunta, Pregunta(atributos[atributo], num_elecciones));
	}else if(num_elecciones == 1){
		int i = 0;

		while (eliminados[i])
			i++;
		if (esIzquierda)
			arbol.insert_left(pregunta, Pregunta(personajes[i], num_elecciones));
		else
			arbol.insert_right(pregunta, Pregunta(personajes[i], num_elecciones));
	}

	return atributo;
}

int QuienEsQuien::mejor_atributo(vector<bool> & atributos_usados, vector<bool> & personajes_tumbados, int &num_personajes_con_atributo){
	int posicion = -1, contador_ant = 0, contador = 0, i;
	contador_ant = 0;
	for (i = 0; i < atributos.size(); i++){ //Recorremos todos los atributos.
		if( !atributos_usados[i] ) {//Si no se esta usando el atributo..
			contador = contar_personajes_con_atributo(i);
			if( contador > contador_ant ){
				posicion = i;
				contador_ant = contador;
				num_personajes_con_atributo = contador;
			}
		}
	}
	actualizar_personajes_tumbados(posicion,personajes_tumbados);
	return posicion;
}
void QuienEsQuien::actualizar_personajes_tumbados(int atributo,vector<bool> & personajes_tumbados){
	for(int i=0;i < personajes.size();i++)
		if(tablero[i][atributo] )
			personajes_tumbados[i] = true;
}
int QuienEsQuien::contar_personajes_con_atributo(int posicion_atributo){
	int i, contador = 0;
	for ( i = 0; i < personajes.size(); i++ ) //Recorremos todos los personajes.
		if( tablero[i][posicion_atributo] ) // Contamos los personajes en juego
			contador++;																														// que tienen el atributo dado.
	return contador;
}

bintree<Pregunta> QuienEsQuien::crear_arbol(){

	arbol = bintree<Pregunta>(Pregunta(atributos[0], personajes.size()));
	vector<bool> eliminados;
	for(int i = 0; i < personajes.size(); i++)
		eliminados.push_back(false);

	crear_arbol_recursivo(arbol.root(), 1, eliminados);

	return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	string respuesta_usuario;

	bintree<Pregunta>::node pregunta = arbol.root();
	while( (*pregunta).obtener_num_personajes() > 1 ){
		do{
			set<string> personajes_levantados =  informacion_jugada(pregunta);
			cout << "Los personajes que quedan son: " << endl;
			for( set<string>::iterator iter = personajes_levantados.begin() ; iter != personajes_levantados.end() ; ++iter ) 
				cout << "\t" << *iter << endl ;

			cout<<"¿Es "<<(*pregunta).obtener_pregunta()<<" ?"<<endl;
			getline(cin,respuesta_usuario);
			//Convierte el string pasado a mayus.
			transform(respuesta_usuario.begin(), respuesta_usuario.end(),respuesta_usuario.begin(), ::toupper);
		}while ( respuesta_usuario.compare("SI") && respuesta_usuario.compare("NO"));

		if ( respuesta_usuario.compare("SI") )
			pregunta = pregunta.right();
		else
			pregunta = pregunta.left();
	}
	cout<< "Respuesta: "<<(*pregunta).obtener_personaje()<<endl;
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){

	set<string> personajes_levantados;
	cuales_quedan(jugada_actual, personajes_levantados);
	return personajes_levantados;
}

void QuienEsQuien::cuales_quedan(bintree<Pregunta>::node n, set<string> & personajes_levantados){

	if((*n).obtener_num_personajes()==1)		
		personajes_levantados.insert((*n).obtener_personaje());
	else{
		if(!n.left().null() || !n.right().null()){
			cuales_quedan(n.left(), personajes_levantados);
			cuales_quedan(n.right(), personajes_levantados);
		}
			
	}
}



void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a,
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	// Este metodo no ha sido añadido debido a que ya los teniamos en cuenta antes de añadirlos
}

float QuienEsQuien::profundidad_promedio_hojas(){
	int cantidad = 0;
	int profundidad = 0;
	ver_profundidad(this->arbol.root(),profundidad, cantidad);
	return cantidad/(personajes.size()*1.0);
}

void QuienEsQuien::ver_profundidad(bintree<Pregunta>::node n, int & profundidad, int & cantidad){
	if (n.null()){

	} else {
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			profundidad++;
	    	ver_profundidad(n.right(),profundidad, cantidad);
			ver_profundidad(n.left(),profundidad, cantidad);
			profundidad--;

		}else{
			cantidad += profundidad;

		}
  	}
}
/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
