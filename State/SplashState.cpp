#include "SplashState.h"
#include "../Display.h"
#include "../Application.h"



namespace State {
	
	SplashState::SplashState(Application& app)
		: BaseState(app)
	{

	}

	void SplashState::setup() {

		Scene splash;

		// let's list all the resources we plan to use in this state
		req.textures.push_back("tex_splsfml.png");
		req.fonts.push_back("font_Akashi.ttf");

		resManager.handleStateRequest(req);

		// list all the game objects here
		// todo -- Game objects should be abstracted a bit more
		sf::Sprite logo;
		sf::Text title;

		title.setFont(resManager.getFontResource("font_Akashi"));
		title.setCharacterSize(64);
		title.setFillColor(sf::Color(0, 255, 0, 125));
		title.setOrigin(0.5f, 0.5f);
		title.setPosition(1280 / 2, 720 - 65);
		title.setString("Game Engine Test");

		logo.setTexture(resManager.getTextureResource("tex_splsfml"));
		logo.setColor(sf::Color(255, 255, 255, m_fade));
		logo.scale(0.75f, 0.75f);
		logo.setOrigin(logo.getTexture()->getSize().x/2, logo.getTexture()->getSize().y / 2);
		logo.setPosition(1280 / 2, 720 / 2);

		splash.sprites.push_back(logo);
		splash.text.push_back(title);

		newScene(splash);
	}

	void SplashState::kill() {
	}

	void SplashState::newScene(Scene s) {
		this->sceneStack.push(s);
	}

	Scene SplashState::activeScene() {
		return sceneStack.top();
	}

	void SplashState::killScene() {

	}

	void SplashState::input(const sf::Event& e) {

	}

	void SplashState::input() {
	
	}

	void SplashState::update(float dt) {
			
	}

	std::string SplashState::stateInfo() {
		return "Splash State";
	}

}