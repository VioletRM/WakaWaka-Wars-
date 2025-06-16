#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>

class Juego {
private:
    sf::RenderWindow window;
    sf::Texture pacmanTexture, ghostTexture;
    sf::Sprite pacman, ghost;
    sf::Font fuente;
    sf::Text textoScore;
    sf::RectangleShape bloque;

    std::vector<std::string> mapa;
    int score = 0;
    float speed;

    bool esBloqueLibre(float x, float y);  // <-- Declaramos aquí como método privado

public:
    Juego();
    void ejecutar();
    void cargarMapa(const std::string& ruta);
};

#endif
