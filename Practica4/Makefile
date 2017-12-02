# ************ Variable utilizadas ************


INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11
AR = ar rvs
AR_MACOS = libtool -static -o


# ************ Generación de código ************
all : $(BIN)/pruebaMijel
$(BIN)/pruebaMijel : $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o $(OBJ)/pruebaMijel.o
	$(CXX) -o $(BIN)/pruebaMijel $(OBJ)/Cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/pruebaMijel.o -I$(INCLUDE)

$(OBJ)/pruebaMijel.o : $(SRC)/pruebaMijel.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebaMijel.o $(SRC)/pruebaMijel.cpp -I$(INCLUDE)

$(OBJ)/Fecha_Historica.o : $(SRC)/Fecha_Historica.cpp $(INCLUDE)/Fecha_Historica.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Fecha_Historica.o $(SRC)/Fecha_Historica.cpp -I$(INCLUDE)

$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp $(INCLUDE)/Cronologia.h $(OBJ)/Fecha_Historica.o
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp -I$(INCLUDE)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
