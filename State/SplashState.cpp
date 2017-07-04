#include "SplashState.h"
#include "../Display.h"
#include "../Application.h"

namespace State {



	SplashState::SplashState(Application& app)
		: BaseState(app)
	{
		req.textures.push_back("spl/tex_splsfml.png");
		req.fonts.push_back("fnt_Akashi.ttf");
	}

	void SplashState::input(const sf::Event& e) {

	}

	void SplashState::input() {
	
	}

	void SplashState::update(float dt) {

	}

	void SplashState::draw() {
	
	}

}