#include "Application.h"

#include "Util\Random.h"

#include "State\SplashState.h"

#include <sstream>


sf::Clock Application::timer;
sf::Clock Application::printTimer;

Application::Application() {

	display.init();
	Random::init();

	// set init state
	pushState(std::make_unique<State::SplashState>(*this));

}

int Application::runMainLoop() {

	sf::Clock c;

	sf::Font font;
	if (!font.loadFromFile("res/font/Monaco.ttf")) {
		// error
	}

	// todo-- Move to debug-class
	sf::Text debugLFT;
	sf::Text debugFPS;

	debugLFT.setFont(font);
	debugLFT.setCharacterSize(12);
	debugLFT.setFillColor(sf::Color(0, 255, 0, 125));
	debugFPS.setFont(font);
	debugFPS.setCharacterSize(12);
	debugFPS.setFillColor(sf::Color(0, 255, 0, 125));

	debugLFT.setPosition(0.0f, 0.0f);
	debugFPS.setPosition(0.0f, 12.0f);

	while (display.isOpen()) {

		auto dt = c.restart().asSeconds();
		calculateFPS();

		display.clear();

		m_states.top()->input();
		m_states.top()->update(dt);
		m_states.top()->draw();
		
		// draw debug
		debugLFT.setString(getLastFrameTime(dt));
		debugFPS.setString(getFPS());

		display.draw(debugLFT);
		display.draw(debugFPS);

		// display
		display.render();
		display.pollEvents(*m_states.top());
	}

	return 0;
}

void Application::pushState(std::unique_ptr<State::BaseState> state) {
	m_states.push(std::move(state));
}

void Application::popState() {
	m_states.pop();
}

// debug bs

void Application::calculateFPS()
{
	totalFrames++;
	if (printTimer.getElapsedTime().asSeconds() >= 1.0f)
	{
		fps = (float)totalFrames / timer.getElapsedTime().asSeconds();
		printTimer.restart();
		totalFrames = 0;
		timer.restart();
	}
}

std::string Application::getFPS()
{
	std::stringstream ss;
	ss << "FPS:" << fps;
	std::string fpsstr = ss.str();
	return fpsstr;

}

std::string Application::getLastFrameTime(float dt)
{
	std::stringstream ss;
	ss << "LFT:" << dt << "ms";
	std::string lftstr = ss.str();
	return lftstr;
}
