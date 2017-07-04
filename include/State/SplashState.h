#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "BaseState.h"

namespace State {

	class SplashState : public BaseState {

	public:

		SplashState(Application& app);
		~SplashState() {}

		void input();
		void update(float dt);
		void draw();

	};

}

