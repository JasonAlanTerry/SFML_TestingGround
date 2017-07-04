#ifndef _BASESTATE
#define _BASESTATE

#include <SFML\Graphics.hpp>

#include <vector>

class Application;

namespace State {

	enum class Status {
		Init,
		Active,
		Hold,
		Exit
	};

	struct ResReq {
		std::vector<std::string> textures;
		std::vector<std::string> fonts;
		std::vector<std::string> sounds;
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