#ifndef _BASESTATE
#define _BASESTATE

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "..\ResManager\ResourceManager.h"

#include <vector>
#include <stack>

class Application;

namespace State {

	enum class Status {
		Init,
		Active,
		Hold,
		Exit
	};

	struct Scene {
		std::vector<sf::Sprite> sprites;
		std::vector<sf::Text> text;
	};

	class BaseState
	{

	public:
		BaseState(Application& app);
		virtual ~BaseState() {}

		virtual void setup()					= 0;
		virtual void kill()						= 0;

		virtual void newScene(Scene s)			= 0;
		virtual Scene activeScene()				= 0;
		virtual void killScene()				= 0;

		virtual void input(const sf::Event& e)	= 0;
		virtual void input()					= 0;
		virtual void update(float dt)			= 0;

		virtual std::string stateInfo()			= 0;
		

	protected:
		ResCodex::ResourceManager resManager;
		std::stack<Scene> sceneStack;
		Application* m_p_application;
	};

}

#endif