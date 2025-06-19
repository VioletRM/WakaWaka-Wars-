#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>  // Para std::ifstream

// Incluir los archivos de cabecera de Pacman y Ghost
#include "pacman.h"
#include "ghost.h"

class Juego {
private:
    sf::RenderWindow window;
    Pacman pacman;  // Ahora tiene la definición completa
    Ghost ghost;    // Ahora tiene la definición completa
    sf::Text textoScore;
    
    // Mapa del juego representado como una matriz
    int mapa[15][20];  // Definir el mapa como una matriz de enteros
    int score = 0;

public:
    Juego();
    void ejecutar();
    void cargarMapa(const std::string& ruta);
    bool esBloqueLibre(float x, float y);
};


