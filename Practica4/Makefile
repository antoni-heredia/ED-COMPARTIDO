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
all :  $(BIN)/union_cronologia $(BIN)/filtradoPalabraClave $(BIN)/filtradoIntervalo $(BIN)/estadisticaEventos
$(BIN)/union_cronologia : $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o $(OBJ)/union_cronologia.o
	$(CXX) -o $(BIN)/union_cronologia $(OBJ)/Cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/union_cronologia.o -I$(INCLUDE)

$(BIN)/filtradoPalabraClave : $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o $(OBJ)/filtradoPalabraClave.o
	$(CXX) -o $(BIN)/filtradoPalabraClave $(OBJ)/Cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/filtradoPalabraClave.o -I$(INCLUDE)

$(BIN)/filtradoIntervalo : $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o $(OBJ)/filtradoIntervalo.o
	$(CXX) -o $(BIN)/filtradoIntervalo $(OBJ)/Cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/filtradoIntervalo.o -I$(INCLUDE)

$(BIN)/estadisticaEventos : $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o $(OBJ)/estadisticaEventos.o
	$(CXX) -o $(BIN)/estadisticaEventos $(OBJ)/Cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/estadisticaEventos.o -I$(INCLUDE)


$(OBJ)/union_cronologia.o : $(SRC)/union_cronologia.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/union_cronologia.o $(SRC)/union_cronologia.cpp -I$(INCLUDE)

$(OBJ)/filtradoPalabraClave.o : $(SRC)/filtradoPalabraClave.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/filtradoPalabraClave.o $(SRC)/filtradoPalabraClave.cpp -I$(INCLUDE)

$(OBJ)/filtradoIntervalo.o : $(SRC)/filtradoIntervalo.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/filtradoIntervalo.o $(SRC)/filtradoIntervalo.cpp -I$(INCLUDE)

$(OBJ)/estadisticaEventos.o : $(SRC)/estadisticaEventos.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/estadisticaEventos.o $(SRC)/estadisticaEventos.cpp -I$(INCLUDE)

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
