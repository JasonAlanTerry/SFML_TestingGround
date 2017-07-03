#include "Display.h"

void Display::handleEvent(const sf::Event& e) {
	if (e.type == sf::Event::Closed) {
		window.close();
	}
}

void Display::init(const std::string& name) {
	window.create({ WIDTH, HEIGHT }, name, sf::Style::Close);
}

bool Display::isOpen() {
	return window.isOpen();
}

void Display::update() {
	window.display();
}

void Display::clear(const sf::Color& colour) {
	window.clear(colour);
}


void Display::draw(const sf::Drawable& drawable) {
	window.draw(drawable);
}

void Display::pollEvents() {
	sf::Event e;
	while (window.pollEvent(e))
	{
		handleEvent(e);
	}
}
