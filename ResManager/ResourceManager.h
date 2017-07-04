#ifndef _RES_HOLDER
#define _RES_HOLDER

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

#include "..\State\BaseState.h"

#include <memory>
#include <unordered_map>

namespace ResCodex {	

	class ResourceManager {
	private:

		const std::string texturePath = "res/tex/";
		const std::string audioPath = "res/snd/";
		const std::string fontPath = "res/font/";

		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, sf::Font> fonts;
		std::unordered_map<std::string, sf::Sound> sounds;

	public:

		ResourceManager();
		~ResourceManager();

		// todo extact to manager?
		void handleStateRequest(State::ResReq req);

		// loaders
		void loadTextureResource(std::string path);
		void loadFontResource(std::string path);
		void loadSoundResource(std::string path);

		// deleters
		void purgeTextureResource(std::string id);
		void purgeFontResource(std::string id);
		void purgeSoundResource(std::string id);

		// getters
		sf::Texture getTextureResource(std::string id);
		sf::Font getFontResource(std::string id);
		sf::Sound getSoundResource(std::string id);

	};

}
#endif

