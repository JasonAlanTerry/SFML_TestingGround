#ifndef _APP
#define _APP

#include <memory>
#include <stack>


#include "Display.h"
#include "include\State\BaseState.h"


class Application {

private:

	Display display;

	// debug preformance
	static sf::Clock timer;
	static sf::Clock printTimer;

	uint32_t fps			= 0;
	long int totalFrames	= 0;

	void calculateFPS();
	std::string getFPS();
	std::string getLastFrameTime(float dt);

public:

	Application();

	int runMainLoop();

	void pushState(std::unique_ptr<State::BaseState> state);
	void popState();

	std::stack<std::unique_ptr<State::BaseState>> m_states;

};

#endif