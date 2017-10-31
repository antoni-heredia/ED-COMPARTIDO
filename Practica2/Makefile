INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11
AR = ar rvs
AR_MACOS = libtool -static -o
all : $(BIN)/ProgramaPrincipal
$(BIN)/ProgramaPrincipal : $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o $(OBJ)/ProgramaPrincipal.o
	$(CXX) -o $(BIN)/ProgramaPrincipal $(OBJ)/Cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/ProgramaPrincipal.o -I$(INCLUDE)

$(OBJ)/ProgramaPrincipal.o : $(SRC)/ProgramaPrincipal.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ProgramaPrincipal.o $(SRC)/ProgramaPrincipal.cpp -I$(INCLUDE)

$(OBJ)/Fecha_Historica.o : $(SRC)/Fecha_Historica.cpp $(INCLUDE)/Fecha_Historica.h $(INCLUDE)/adicional.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Fecha_Historica.o $(SRC)/Fecha_Historica.cpp -I$(INCLUDE)


$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp $(INCLUDE)/Cronologia.h $(OBJ)/Fecha_Historica.o $(INCLUDE)/adicional2.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp -I$(INCLUDE)

# Nótese que como vector_dinamico es una clase genérica (template), no la hemos compilado explícitamente ni enlazado con ejemplo_vector_dinamico.o
# Como hemos incluido el código de vector_dinamico.tpp en el fichero de cabeceras vector_dinamico.h, cuando hagamos #include "Vector_Dinamico.h" desde otro fichero de código (por ejemplo, desde ejemplo_vector_dinamico.cpp)
# tanto la definición como la implementación de vector_dinamico están disponibles al compilador, con lo que puede generar el código objeto ejemplo_vector_dinamico.o.
# La desventaja es que renunciamos al principio de ocultamiento de información (el fichero de cabeceras incluye la implementación de los métodos)


#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
