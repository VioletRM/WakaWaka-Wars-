#include "../include/juego.h"
#include <fstream>
#include <iostream>

Juego::Juego() : window(sf::VideoMode(800, 600), "Wakawaka Wars"), score(0) {
    // Constructor
    // Inicializamos el mapa con ceros, que indica bloques vacíos
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 20; ++j) {
            mapa[i][j] = 0;  // Todos los bloques vacíos inicialmente
        }
    }
}

void Juego::ejecutar() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Wakawaka Wars");

    // Verifica si la ventana se abrió correctamente
    if (!window.isOpen()) {
        std::cerr << "Error al crear la ventana" << std::endl;
        return;
    } else {
        std::cout << "Ventana creada correctamente" << std::endl;
    }

    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("assets/images/background.png")) {
        std::cerr << "Error al cargar la textura de fondo" << std::endl;
        return;
    } else {
        std::cout << "Textura de fondo cargada correctamente" << std::endl;
    }

    sf::Sprite fondo(fondoTexture);
    fondo.setScale(640.0f / fondoTexture.getSize().x, 480.0f / fondoTexture.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fondo);
        pacman.draw(window);
        ghost.draw(window);
        window.display();
    }
}

void Juego::cargarMapa(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de mapa!" << std::endl;
        return;
    }

    std::string linea;
    for (int i = 0; i < 15 && getline(archivo, linea); ++i) {
        for (size_t j = 0; j < 20 && j < linea.size(); ++j) {
            mapa[i][j] = (linea[j] == '1') ? 1 : 0;  // '1' representa un bloque, '0' vacío
        }
    }
}

bool Juego::esBloqueLibre(float x, float y) {
    const int tileSize = 32;
    int fil = static_cast<int>(y) / tileSize;
    int col = static_cast<int>(x) / tileSize;
    return mapa[fil][col] != 1;  // Verifica si el bloque está libre (no es un muro)
}
