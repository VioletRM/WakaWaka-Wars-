#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>

class Juego {
private:
    sf::RenderWindow window;
    sf::Texture pacmanTexture, ghostTexture;
    sf::Sprite pacman, ghost;
    float speed;

public:
    Juego();
    void ejecutar();
};

#endif
