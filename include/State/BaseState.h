#pragma once

#include <SFML\Graphics.hpp>

class Application;

namespace State {

	class BaseState
	{
	public:
		BaseState(Application& app);
		virtual ~BaseState() {}

		virtual void input(const sf::Event& e)	= 0;
		virtual void update(float dt)			= 0;
		virtual void update()					= 0;
		virtual void draw()						= 0;




	protected:
		Application* m_p_application;
	};

}