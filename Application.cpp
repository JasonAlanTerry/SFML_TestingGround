#include "Application.h"
#include <iostream>

Application::Application() {

	display.init();
	
}

int Application::runMainLoop() {
	
	sf::Clock c;
	
	sf::Font font;
	if (!font.loadFromFile("res/Akashi.ttf")) {
		std::cout << "We fucked up" << std::endl;
	}
	else {
		std::cout << "Loading font" << std::endl;
	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Black);
	text.setPosition(0 , 0);
	text.setFont(font);

	while (display.isOpen()) {

		auto dt = c.restart().asSeconds();

		// clear
		display.clear();

		// input
		// update
		// draw

		text.setString("Test");
		display.draw(text);
		printf("test\n");

		// display
		display.pollEvents();
	}
	
	
	return 0;
}
