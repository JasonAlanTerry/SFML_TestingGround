#ifndef _SPLASHSTATE
#define _SPLASHSTATE


#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "BaseState.h"

namespace State {

	class SplashState : public BaseState {

	public:

		SplashState(Application& app);
		~SplashState() {}

		void input(const sf::Event& e);
		void input();
		void update(float dt);
		void draw();

	};

}

#endif