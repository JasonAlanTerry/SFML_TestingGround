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

	public:

		SplashState(Application& app);
		~SplashState() {}

		// build any drawables here
		void setup();
		void kill();

		virtual void newScene(Scene s);
		virtual void killScene();

		void input(const sf::Event& e);
		void input();
		void update(float dt);
		void draw();

	};

}

#endif
