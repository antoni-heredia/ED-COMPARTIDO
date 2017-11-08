INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11
AR = ar rvs
AR_MACOS = libtool -static -o
all : $(BIN)/usopilaS

$(BIN)/usopilas : pruebasPilaVD.cpp
	g++ -std=c++11 -I$(INCLUDE) -o $(BIN)/pruebas.exe $(SRC)/pruebasPilaVD.cpp 
