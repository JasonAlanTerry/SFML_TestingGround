#include "ResourceManager.h"
#include <iostream>

namespace ResCodex {

	// init mem
	ResourceManager::ResourceManager() {

	}

	// purge all mem
	ResourceManager::~ResourceManager() {

	}

	// TODO-- extract DRY code
	void ResourceManager::handleStateRequest(State::ResReq req) {

		sf::Clock c;
		float dt;

		std::clog << "Loading Textures" << std::endl;
		for (auto i : req.textures) {
			loadTextureResource(texturePath + i);
		}

		dt = c.restart().asSeconds();
		std::clog << "Loading Textures done | Time Elapsed: " << dt << "ms" << std::endl;
		std::clog << "Loading Fonts" << std::endl;

		for (auto i : req.fonts) {
			loadFontResource(fontPath + i);
		}

		dt = c.restart().asSeconds();
		std::clog << "Loading fonts done | Time Elapsed: " << dt << "ms" << std::endl;
		std::clog << "Loading Sounds" << std::endl;

		for (auto i : req.sounds) {
			loadSoundResource(audioPath + i);
		}

		dt = c.restart().asSeconds();
		std::clog << "Loading sounds done | Time Elapsed: " << dt << "ms" << std::endl;

	}

	// load res to mem
	void ResourceManager::loadTextureResource(std::string path) {

	}

	void ResourceManager::loadFontResource(std::string path) {

	}

	void ResourceManager::loadSoundResource(std::string path) {

	}

	// delete res from mem
	void ResourceManager::purgeTextureResource(std::string id) {

	}

	void ResourceManager::purgeFontResource(std::string id) {

	}

	void ResourceManager::purgeSoundResource(std::string id) {

	}

	// getters
	sf::Texture ResourceManager::getTextureResource(std::string id) {

	}

	sf::Font ResourceManager::getFontResource(std::string id) {
	
	}

	sf::Sound ResourceManager::getSoundResource(std::string id) {

	}
}