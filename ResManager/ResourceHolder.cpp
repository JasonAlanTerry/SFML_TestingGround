#include "ResourceHolder.h"
#include <iostream>

namespace ResCodex {

	// init mem
	ResourceHolder::ResourceHolder() {

	}

	// purge all mem
	ResourceHolder::~ResourceHolder() {

	}

	// TODO-- extract DRY code
	void ResourceHolder::handleStateRequest(State::ResReq req) {

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
	void ResourceHolder::loadTextureResource(std::string path) {

	}

	void ResourceHolder::loadFontResource(std::string path) {

	}

	void ResourceHolder::loadSoundResource(std::string path) {

	}

	// delete res from mem
	void ResourceHolder::purgeTextureResource(TextureID id) {

	}

	void ResourceHolder::purgeFontResource(FontID id) {

	}

	void ResourceHolder::purgeSoundResource(SoundID id) {

	}
}