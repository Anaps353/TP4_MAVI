#include <SFML/Graphics.hpp>

using namespace sf;

Texture crosshair;
Sprite sprite;

int main() {

	RenderWindow app(VideoMode(800, 600), "Crosshair");

	crosshair.loadFromFile("crosshair.png");
	sprite.setTexture(crosshair);

	FloatRect crosshairBounds = sprite.getLocalBounds();

	sprite.setOrigin(crosshairBounds.width / 2, crosshairBounds.height / 2);
	sprite.setPosition(app.getSize().x / 2, app.getSize().y / 2);

	while (app.isOpen())
	{
		Event event;
		while (app.pollEvent(event)) {
			if (event.type == Event::Closed)
				app.close();
		}

		app.clear();
		app.draw(sprite);
		app.display();
	}

	return 0;

}