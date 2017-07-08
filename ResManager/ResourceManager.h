#ifndef _RES_HOLDER
#define _RES_HOLDER

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

#include <memory>
#include <map>

namespace ResCodex {	
	
	struct ResReq {
		std::vector<std::string> textures;
		std::vector<std::string> fonts;
		std::vector<std::string> sounds;
	};

	class ResourceManager {
	private:

		const std::string texturePath = "res/tex/";
		const std::string audioPath = "res/snd/";
		const std::string fontPath = "res/font/";

		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;
		std::map<std::string, sf::Sound> sounds;

	public:

		ResourceManager();
		~ResourceManager();

		// todo extact to manager?
		void handleStateRequest(ResReq req);
		void tokenizePath(const std::string& path, std::vector<std::string>& tokens);

		// loaders
		void loadTextureResource(std::string& path);
		void loadFontResource(std::string& path);
		void loadSoundResource(std::string& path);

		// deleters
		void purgeTextureResource(std::string& id);
		void purgeFontResource(std::string& id);
		void purgeSoundResource(std::string& id);

		// getters
		const sf::Texture& getTextureResource(const std::string& id);
		const sf::Font& getFontResource(const std::string& id);
		sf::Sound getSoundResource(std::string id);

	};

}
#endif

