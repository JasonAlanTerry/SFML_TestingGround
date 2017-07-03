#pragma once

#include <cstdint>
#include <SFML\Graphics.hpp>

class Display {
	
private:
	const uint16_t WIDTH	= 1280;
	const uint16_t HEIGHT	= 720;	

	void handleEvent(const sf::Event& e);

public:

	Display() {};

	sf::RenderWindow window;

	// init the window
	void init(const std::string& name = "Window");

	void update();
	void clear(const sf::Color& colour = { 0, 0, 0 });
	void draw(const sf::Drawable& drawable);

	bool isOpen();
	void pollEvents();
};

