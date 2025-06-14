# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include
ASSETS_DIR = assets

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SOURCES))

# Ejecutable
EXECUTABLE = waka_waka_wars

# Regla principal
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -rf $(BIN_DIR)/*.o $(EXECUTABLE)

# Ejecutar el juego
run: $(EXECUTABLE)
	./$(EXECUTABLE).exe