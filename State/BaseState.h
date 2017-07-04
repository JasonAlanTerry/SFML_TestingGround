#ifndef _BASESTATE
#define _BASESTATE

#include <SFML\Graphics.hpp>

class Application;

namespace State {

	enum class Status {
		Init,
		Active,
		Hold,
		Exit
	};

	class BaseState
	{
	public:
		BaseState(Application& app);
		virtual ~BaseState() {}

		virtual void input(const sf::Event& e)	= 0;
		virtual void input()					= 0;
		virtual void update(float dt)			= 0;
		virtual void draw()						= 0;




	protected:
		Application* m_p_application;
	};

}

#endif