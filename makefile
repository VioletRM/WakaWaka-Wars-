# === CONFIGURACIÓN ===
CXX = g++
SRC = src
BIN = bin
ASSETS = assets
INCLUDES = -IC:/SFML/include
LIBS = -LC:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS = -Wall -std=c++17

# === ARCHIVOS ===
SRCS = $(SRC)/main.cpp $(SRC)/Juego.cpp
OUT = $(BIN)/wakawaka.exe

# === REGLAS ===

all: $(OUT)

$(OUT): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

run: all
	./$(OUT)

clean:
	del /Q $(BIN)\*.exe
