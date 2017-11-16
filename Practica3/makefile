INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11
AR = ar rvs
AR_MACOS = libtool -static -o

all : $(BIN)/usopilas

 $(BIN)/usopilas : $(SRC)/pruebasPilaCola.cpp $(INCLUDE)/Pila_max_Cola.h $(INCLUDE)/Pila_max_Cola.cpp
	g++ -std=c++11 -I$(INCLUDE) -o $(BIN)/pruebas.exe $(SRC)/pruebasPilaCola.cpp

#************ Generación de documentación ******************
documentacion_VD:
	doxygen doc/doxys/Doxyfile
documentacion_Cola:
	doxygen doc/doxys/Doxyfile2


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/Cola/html/* doc/VD/html/*
