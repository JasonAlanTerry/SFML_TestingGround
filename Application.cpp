#include "Application.h"

#include "Util\Random.h"

#include "State\SplashState.h"

#include <sstream>
#include <cmath>


sf::Clock Application::m_timer;
sf::Clock Application::m_printTimer;

Application::Application() {

	display.init();
	Random::init();

}

int Application::runMainLoop() {

	pushState(std::make_unique<State::SplashState>(*this));

	sf::Clock c;
	sf::Font font;
	if (!font.loadFromFile("res/font/font_Monaco.ttf")) {
		// error
	}

	// todo-- Move to debug-class
	sf::Text debug;

	debug.setFont(font);
	debug.setCharacterSize(12);
	debug.setFillColor(sf::Color(0, 255, 0, 125));

	debug.setPosition(0.0f, 0.0f);

	while (display.isOpen()) {

		m_dt = c.restart().asSeconds();
		calculateFPS();

		display.clear();		
		
		m_states.top()->input();
		m_states.top()->update(m_dt);
		display.draw(m_states.top()->activeScene());
		display.draw(debug);
		

		// draw debug
		debug.setString(debugOutput());

		// display scene
		display.render();
		display.pollEvents(*m_states.top());
	}

	return 0;
}

void Application::pushState(std::unique_ptr<State::BaseState> state) {
	m_states.push(std::move(state));
	m_states.top()->setup();
}

void Application::popState() {
	m_states.top()->kill();
	m_states.pop();
}

// debug bs
void Application::calculateFPS() {
	m_totalFrames++;
	if (m_printTimer.getElapsedTime().asSeconds() >= 1.0f) {
		m_fps = std::floor(m_totalFrames) / m_timer.getElapsedTime().asSeconds();
		m_printTimer.restart();
		m_totalFrames = 0;
		m_timer.restart();
	}
}

std::string Application::getFPS() {
	std::stringstream ss;
	ss << "FPS:" << m_fps << "\n";
	std::string str = ss.str();
	return str;

}

std::string Application::getLastFrameTime() {
	std::stringstream ss;
	ss << "LFT:" << m_dt << "ms \n";
	std::string str = ss.str();
	return str;
}

std::string Application::getActiveStateInfo() {
	std::stringstream ss;
	ss << "STATE:" << m_states.top()->stateInfo() << "\n";
	std::string str = ss.str();
	return str;
}

std::string Application::debugOutput() {
	std::stringstream ss;
	ss << getActiveStateInfo() << getFPS() << getLastFrameTime();
	std::string str = ss.str();
	return str;
}
