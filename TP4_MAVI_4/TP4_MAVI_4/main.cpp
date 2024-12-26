#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Texture texturaCuadrado, texturaCirculo;
Sprite sprite;


void configurarSprite(Sprite& sprite, const Texture& textura) {
    sprite.setTexture(textura);

    sprite.setScale(50.f / textura.getSize().x, 50.f / textura.getSize().y);
}

int main() {

    RenderWindow ventana(VideoMode(800, 600), "Atrapado");


    texturaCuadrado.loadFromFile("cuad_yellow.png");
    texturaCirculo.loadFromFile("rcircleg.png");

    Sprite sprite;
    bool esCirculo = false;
    bool espacioPresionado = false;


    configurarSprite(sprite, texturaCuadrado);

    while (ventana.isOpen()) {
        Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana.close();
            }
            else if (evento.type == Event::KeyReleased &&
                evento.key.code == Keyboard::Space) {
                espacioPresionado = false; 
            }
        }

   
        if (Keyboard::isKeyPressed(Keyboard::Left))  sprite.move(-0.5f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sprite.move(0.5f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Up))    sprite.move(0.f, -0.5f);
        if (Keyboard::isKeyPressed(Keyboard::Down))  sprite.move(0.f, 0.5f);


        if (Keyboard::isKeyPressed(Keyboard::Space) && !espacioPresionado) {
            esCirculo = !esCirculo;
            configurarSprite(sprite, esCirculo ? texturaCirculo : texturaCuadrado);
            espacioPresionado = true;
        }

    
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
