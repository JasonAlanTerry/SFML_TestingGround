#ifndef _APP
#define _APP

#include <memory>
#include <stack>


#include "Display.h"
#include "State\BaseState.h"


class Application {

private:

	Display display;

	// debug preformance
	static sf::Clock m_timer;
	static sf::Clock m_printTimer;

	uint32_t m_fps			= 0;
	float m_dt				= 0;
	long int m_totalFrames	= 0;

	void calculateFPS();
	std::string getFPS();
	std::string getLastFrameTime();
	std::string getActiveStateInfo();
	std::string debugOutput();

public:

	Application();

	int runMainLoop();

	void pushState(std::unique_ptr<State::BaseState> state);
	void popState();

	std::stack<std::unique_ptr<State::BaseState>> m_states;

};

#endif