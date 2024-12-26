#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

Texture redTexture;
Texture blueTexture;
Sprite redCircle;
Sprite blueCircle;

int main() {

    redTexture.loadFromFile("rcircle.png");
    blueTexture.loadFromFile("bcircle.png");

    redCircle.setTexture(redTexture);
    blueCircle.setTexture(blueTexture);

    RenderWindow app(VideoMode(800, 600), "circulos");

    std::vector<Sprite> circles;

    while (app.isOpen()) {

        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed) {
                app.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                Vector2f
                    mousePos = app.mapPixelToCoords(Mouse::getPosition(app));

                if (event.mouseButton.button == Mouse::Left) {
                    circles.push_back(redCircle);
                }
                else if (event.mouseButton.button == Mouse::Right) {
                    circles.push_back(blueCircle);
                }
                circles.back().setPosition(mousePos); 
            }
        }

        app.clear();

        for (const auto& circle : circles) {
            app.draw(circle);
        }

        app.display();
    }

    return 0;
}