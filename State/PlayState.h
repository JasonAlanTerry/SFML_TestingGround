#ifndef _PLAYSTATE
#define _PLAYSTATE


#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "BaseState.h"

namespace State {

	class PlayState : public BaseState {

	public:

		PlayState(Application& app);
		~PlayState() {}

		void input(const sf::Event& e);
		void input();
		void update(float dt);
		void draw();

	};

}

#endif
