#ifndef _SPLASHSTATE
#define _SPLASHSTATE


#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "BaseState.h"

namespace State {

	class SplashState : public BaseState {

	private:
		Status currentStatus;
		ResCodex::ResReq req;
		int m_fade = 255;

	public:

		SplashState(Application& app);
		~SplashState() {}

		// build any drawables here
		void setup();
		void kill();

		void newScene(Scene s);
		Scene activeScene();		
		void killScene();

		void input(const sf::Event& e);
		void input();
		void update(float dt);

		std::string stateInfo();

	};

}

#endif
