#include "Display.h"
#include "State/BaseState.h"

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

void Display::render() {
	window.display();
}

void Display::clear() {
	window.clear(sf::Color::Black);
}

void Display::draw(const State::Scene& scene) {
	for (auto i : scene.sprites) {
		window.draw(i);
	}
	for (auto i : scene.text) {
		window.draw(i);
	}
}

void Display::draw(const sf::Drawable& drawable) {
	window.draw(drawable);
}

void Display::pollEvents(State::BaseState& gameState) {
	sf::Event e;
	while (window.pollEvent(e))
	{
		handleEvent(e);
		gameState.input(e);
	}
}
