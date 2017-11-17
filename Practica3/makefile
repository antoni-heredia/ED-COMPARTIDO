INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11
AR = ar rvs
AR_MACOS = libtool -static -o

all : $(BIN)/pruebasPilaCola.exe $(BIN)/pruebasPilaVD.exe

 $(BIN)/pruebasPilaCola.exe : $(SRC)/pruebasPilaCola.cpp $(INCLUDE)/Pila_max_Cola.h $(INCLUDE)/Pila_max_Cola.cpp
	g++ -std=c++11 -I$(INCLUDE) -o $(BIN)/pruebasPilaCola.exe $(SRC)/pruebasPilaCola.cpp

$(BIN)/pruebasPilaVD.exe : $(SRC)/pruebasPilaVD.cpp $(INCLUDE)/Pila_max_VD.h $(INCLUDE)/Pila_max_VD.cpp
	g++ -std=c++11 -I$(INCLUDE) -o $(BIN)/pruebasPilaVD.exe $(SRC)/pruebasPilaVD.cpp

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
