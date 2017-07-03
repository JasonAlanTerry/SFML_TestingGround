#include "Application.h"
#include <sstream>
#include <iostream>
#include <vector>

Application::Application() {

	display.init();
	
}

int Application::runMainLoop() {


	sf::Clock c;

	sf::Font font;
	if (!font.loadFromFile("res/Monaco.ttf")) {
		std::cout << "We fucked up" << std::endl;
	}
	else {
		std::cout << "Loading font" << std::endl;
	}


	sf::Text lft;
	sf::Text fps;	

	lft.setFont(font);
	lft.setCharacterSize(22);
	lft.setFillColor(sf::Color(0, 255, 0, 125));
	fps.setFont(font);
	fps.setCharacterSize(22);
	fps.setFillColor(sf::Color(0, 255, 0, 125));
	

	lft.setPosition(0.0f, 0.0f);
	fps.setPosition(0.0f, 25.0f);

	while (display.isOpen()) {

		auto dt = c.restart().asSeconds();

		// clear
		display.clear();

		// input
		// update
		// draw

		std::stringstream ss;
		ss << "[ LF:" << dt << "ms ]";
		std::string lftstr = ss.str();
		std::cout << lftstr << std::endl;
		lft.setString(lftstr);
		ss.str(std::string());

		ss << "[ FPS:" << 0.0f << "]";
		std::string fpsstr = ss.str();		
		std::cout << fpsstr << std::endl;
		fps.setString(fpsstr);
		ss.str(std::string());
				
		display.draw(lft);
		display.draw(fps);

		// display
		display.render();
		display.pollEvents();
	}

	return 0;
}
