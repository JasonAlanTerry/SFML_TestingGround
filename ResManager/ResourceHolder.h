#ifndef _RES_HOLDER
#define _RES_HOLDER

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

#include "..\State\BaseState.h"

#include <memory>
#include <unordered_map>

namespace ResCodex {	

	enum class TextureID {
		TileWall,
		TileFloor,
		EntityBase
	};

	enum class FontID {
		Debug,
		Title,
		Script
	};

	enum class SoundID {
		Test
	};

	class ResourceHolder {
	private:

		const std::string texturePath = "res/tex/";
		const std::string audioPath = "res/snd/";
		const std::string fontPath = "res/font/";

		std::unordered_map<ResCodex::TextureID, sf::Texture> textures;
		std::unordered_map<ResCodex::FontID, sf::Font> fonts;
		std::unordered_map<ResCodex::SoundID, sf::Sound> sounds;

	public:

		ResourceHolder();
		~ResourceHolder();

		// todo extact to manager?
		void handleStateRequest(State::ResReq req);

		// loaders
		void loadTextureResource(std::string path);
		void loadFontResource(std::string path);
		void loadSoundResource(std::string path);

		// deleters
		void purgeTextureResource(TextureID id);
		void purgeFontResource(FontID id);
		void purgeSoundResource(SoundID id);

	};

}
#endif

