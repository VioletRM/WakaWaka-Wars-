#include "Juego.h"

Juego::Juego() : window(sf::VideoMode(800, 600), "Pac-Man Multijugador"), speed(3.0f) {
    pacmanTexture.loadFromFile("assets/pacman.png");
    ghostTexture.loadFromFile("assets/ghost.png");

    pacman.setTexture(pacmanTexture);
    ghost.setTexture(ghostTexture);

    pacman.setPosition(100, 100);
    ghost.setPosition(400, 300);
}

void Juego::ejecutar() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimiento Pac-Man
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) pacman.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) pacman.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) pacman.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) pacman.move(speed, 0);

        // Movimiento Fantasma
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ghost.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ghost.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ghost.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ghost.move(speed, 0);

        // Colisión
        if (pacman.getGlobalBounds().intersects(ghost.getGlobalBounds())) {
            window.close(); // El juego termina
        }

        // Dibujar
        window.clear();
        window.draw(pacman);
        window.draw(ghost);
        window.display();
    }
}
