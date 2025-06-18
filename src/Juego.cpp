#include <Juego.h>

Juego::Juego() : window(sf::VideoMode(800, 600), "Pac-Man Multijugador"), speed(3.0f) {
   
    cargarMapa("assets/Laberinto.txt");
    pacmanTexture.loadFromFile("assets/pacman.png");
    ghostTexture.loadFromFile("assets/ghost.png");


    pacman.setTexture(pacmanTexture);
    ghost.setTexture(ghostTexture);

    pacman.setPosition(100, 100);
    ghost.setPosition(400, 300);


    // Fuente y texto del score
    fuente.loadFromFile("assets/arial.ttf"); // ← Puedes usar cualquier fuente TTF aquí
    textoScore.setFont(fuente);
    textoScore.setCharacterSize(24);
    textoScore.setFillColor(sf::Color::White);
    textoScore.setPosition(10, 10);
    textoScore.setString("Score: 0");

}

void Juego::ejecutar() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimiento Pac-Man
    sf::Vector2f posPac = pacman.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && esBloqueLibre(posPac.x, posPac.y - speed)) pacman.move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && esBloqueLibre(posPac.x, posPac.y + speed)) pacman.move(0, speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && esBloqueLibre(posPac.x - speed, posPac.y)) pacman.move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && esBloqueLibre(posPac.x + speed, posPac.y)) pacman.move(speed, 0);

    // Comer puntos
    int col = pacman.getPosition().x / 40;
    int fil = pacman.getPosition().y / 40;

    if (mapa[fil][col] == '.') {
        mapa[fil][col] = ' '; // Borra el punto
        score++;
        textoScore.setString("Score: " + std::to_string(score));
    }

        // Movimiento Fantasma
    sf::Vector2f posGhost = ghost.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && esBloqueLibre(posGhost.x, posGhost.y - speed)) ghost.move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && esBloqueLibre(posGhost.x, posGhost.y + speed)) ghost.move(0, speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && esBloqueLibre(posGhost.x - speed, posGhost.y)) ghost.move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && esBloqueLibre(posGhost.x + speed, posGhost.y)) ghost.move(speed, 0);


        // Colisión
        if (pacman.getGlobalBounds().intersects(ghost.getGlobalBounds())) {
            window.close(); // El juego termina
        }

        // Dibujar
        window.clear();
        
        for (size_t i = 0; i < mapa.size(); ++i) {
    for (size_t j = 0; j < mapa[i].length(); ++j) {
        if (mapa[i][j] == '#') {
            bloque.setPosition(j * 40, i * 40);
            window.draw(bloque);
        }
        else if (mapa[i][j] == '.') {
            sf::CircleShape punto(5);
            punto.setFillColor(sf::Color::Yellow);
            punto.setPosition(j * 40 + 15, i * 40 + 15); // centrado en el bloque
            window.draw(punto);
        }
    }
}
        window.draw(pacman);
        window.draw(ghost);
        window.draw(textoScore);   
        window.display();
    }
}

void Juego::cargarMapa(const std::string& ruta) {
    std::ifstream archivo(ruta);
    std::string linea;
    while (std::getline(archivo, linea)) {
        mapa.push_back(linea);
    }

    bloque.setSize(sf::Vector2f(40, 40)); // Tamaño de bloque
    bloque.setFillColor(sf::Color::Blue); // Color de pared
}

bool esBloqueLibre(float x, float y) {
    int col = x / 40;
    int fil = y / 40;

    // Verifica que esté dentro del mapa
    if (fil < 0 || fil >= (int)mapa.size() || col < 0 || col >= (int)mapa[fil].size()) {
        return false;
    }

    return mapa[fil][col] != '#';
}
