#include "BaseState.h"


namespace State {

	BaseState::BaseState(Application& app)
		: m_p_application(&app)
	{

	}

	static ResCodex::ResourceManager resManager;

}