#ifndef _DISPLAY
#define _DISPLAY

#include <cstdint>
#include <SFML\Graphics.hpp>

#include "State\BaseState.h"

class Display {

private:
	const uint16_t WIDTH = 1280;
	const uint16_t HEIGHT = 720;

	sf::RenderWindow window;

	void handleEvent(const sf::Event& e);

public:

	Display() {};

	// init the window
	void init(const std::string& name = "Window");

	void clear();
	void draw(const State::Scene& scene);
	void draw(const sf::Drawable& drawable);
	void render();

	bool isOpen();
	void pollEvents(State::BaseState& gameState);
};


#endif