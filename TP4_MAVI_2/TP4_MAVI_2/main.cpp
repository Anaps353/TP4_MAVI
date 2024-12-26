#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture;
Sprite sprite1, sprite2, sprite3, sprite4;

int main() {
    texture.loadFromFile("rcircle.png");
    sprite1.setTexture(texture);
    sprite2.setTexture(texture);
    sprite3.setTexture(texture);
    sprite4.setTexture(texture);

    RenderWindow app(VideoMode(800, 600), "Sniper^4 ");

    sprite1.setPosition(0, 0);
    sprite2.setPosition(app.getSize().x - texture.getSize().x, 0);
    sprite3.setPosition(0, app.getSize().y - texture.getSize().y);
    sprite4.setPosition(app.getSize().x - texture.getSize().x, app.getSize().y - texture.getSize().y);

    bool isDragging = false;
    Sprite* selectedSprite = nullptr;

    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2f mousePos = app.mapPixelToCoords(Mouse::getPosition(app));
                    if (sprite1.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &sprite1;
                    }
                    else if (sprite2.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &sprite2;
                    }
                    else if (sprite3.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &sprite3;
                    }
                    else if (sprite4.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &sprite4;
                    }
                }
            }

            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    isDragging = false;
                    selectedSprite = nullptr;
                }
            }

            if (event.type == Event::MouseMoved && isDragging) {
                Vector2f mousePos = app.mapPixelToCoords(Mouse::getPosition(app));
                selectedSprite->setPosition(mousePos);
            }
        }

        app.clear();
        app.draw(sprite1);
        app.draw(sprite2);
        app.draw(sprite3);
        app.draw(sprite4);
        app.display();
    }

    return 0;
}