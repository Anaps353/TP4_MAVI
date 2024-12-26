/*#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Texture texturaCuadrado, texturaCirculo;
Sprite sprite;

// Función para configurar el sprite con la textura dada
void configurarSprite(Sprite& sprite, const Texture& textura) {
    sprite.setTexture(textura);
    // Escala el sprite a un tamaño de 50x50 píxeles
    sprite.setScale(50.f / textura.getSize().x, 50.f / textura.getSize().y);
}

int main() {
    // Crear la ventana
    RenderWindow ventana(VideoMode(800, 600), "Atrapado");

    // Cargar texturas
    Texture texturaCuadrado, texturaCirculo;
    if (!texturaCuadrado.loadFromFile("cuad_yellow.png") ||
        !texturaCirculo.loadFromFile("rcircleg.png")) {
        // Manejar error de carga de textura
        return 1;
    }

    Sprite sprite;
    bool esCirculo = false;
    bool espacioPresionado = false;

    // Configurar el sprite inicial como cuadrado
    configurarSprite(sprite, texturaCuadrado);

    while (ventana.isOpen()) {
        Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana.close();
            }
            else if (evento.type == Event::KeyReleased &&
                evento.key.code == Keyboard::Space) {
                espacioPresionado = false; // Liberar tecla espacio
            }
        }

        // Movimiento del sprite
        if (Keyboard::isKeyPressed(Keyboard::Left))  sprite.move(-0.5f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sprite.move(0.5f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Up))    sprite.move(0.f, -0.5f);
        if (Keyboard::isKeyPressed(Keyboard::Down))  sprite.move(0.f, 0.5f);

        // Cambiar entre círculo y cuadrado con la tecla espacio
        if (Keyboard::isKeyPressed(Keyboard::Space) && !espacioPresionado) {
            esCirculo = !esCirculo;
            configurarSprite(sprite, esCirculo ? texturaCirculo : texturaCuadrado);
            espacioPresionado = true;
        }

        // Mantener el sprite dentro de los límites de la ventana
        FloatRect limitesSprite = sprite.getGlobalBounds();
        if (limitesSprite.left < 0) {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        else if ((limitesSprite.left + limitesSprite.width) > ventana.getSize().x) {
            sprite.setPosition(ventana.getSize().x - limitesSprite.width, sprite.getPosition().y);
        }
        if (limitesSprite.top < 0) {
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        else if ((limitesSprite.top + limitesSprite.height) > ventana.getSize().y) {
            sprite.setPosition(sprite.getPosition().x, ventana.getSize().y - limitesSprite.height);
        }

        ventana.clear();
        ventana.draw(sprite);
        ventana.display();
    }

    return 0;
}*/

#include <SFML/Graphics.hpp>

using namespace sf;

// Función para configurar el sprite con la textura dada y escalarlo a 50x50 píxeles
void configurarSprite(Sprite& sprite, const Texture& textura) {
    sprite.setTexture(textura);
    sprite.setScale(50.f / textura.getSize().x, 50.f / textura.getSize().y);
}

int main() {
    // Crear la ventana
    RenderWindow ventana(VideoMode(800, 600), "Cuadrado y Círculo");

    // Cargar texturas
    Texture texturaCuadrado, texturaCirculo;
    if (!texturaCuadrado.loadFromFile("cuad_yellow.png") ||
        !texturaCirculo.loadFromFile("rcircleg.png")) {
        // Manejar error de carga de textura (mostrar mensaje o salir del programa)
        return 1;
    }

    // Crear el sprite inicial (cuadrado)
    Sprite sprite;
    configurarSprite(sprite, texturaCuadrado);

    // Variable para controlar la forma actual (cuadrado o círculo)
    bool esCirculo = false;

    while (ventana.isOpen()) {
        Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana.close();
            }
        }

        // Movimiento del sprite
        if (Keyboard::isKeyPressed(Keyboard::Left))  sprite.move(-0.5f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sprite.move(0.5f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Up))    sprite.move(0.f, -0.5f);
        if (Keyboard::isKeyPressed(Keyboard::Down))  sprite.move(0.f, 0.5f);

        // Cambiar entre cuadrado y círculo con la barra espaciadora
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            esCirculo = !esCirculo;
            configurarSprite(sprite, esCirculo ? texturaCirculo : texturaCuadrado);
        }

        // Mantener el sprite dentro de los límites de la ventana
        FloatRect limitesSprite = sprite.getGlobalBounds();
        if (limitesSprite.left < 0) {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        else if ((limitesSprite.left + limitesSprite.width) > ventana.getSize().x) {
            sprite.setPosition(ventana.getSize().x - limitesSprite.width, sprite.getPosition().y);
        }
        if (limitesSprite.top < 0) {
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        else if ((limitesSprite.top + limitesSprite.height) > ventana.getSize().y) {
            sprite.setPosition(sprite.getPosition().x, ventana.getSize().y - limitesSprite.height);
        }

        ventana.clear();
        ventana.draw(sprite);
        ventana.display();
    }

    return 0;
}