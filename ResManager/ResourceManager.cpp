#include "ResourceManager.h"
#include <iostream>
#include <string.h>

namespace ResCodex {

	// init mem
	ResourceManager::ResourceManager() {

	}

	// purge all mem
	ResourceManager::~ResourceManager() {

	}

	// TODO-- extract DRY code
	void ResourceManager::handleStateRequest(ResReq req) {

		sf::Clock c;
		float dt = 0.0;

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
	void ResourceManager::loadTextureResource(std::string& path) {
		std::vector<std::string> tokens;
		tokenizePath(path, tokens);

		std::string key = tokens[1] + "_" + tokens[tokens.size() - 2];

		sf::Texture t;
		t.loadFromFile(path);
		textures.insert(std::make_pair(key, t));
	}

	void ResourceManager::loadFontResource(std::string& path) {
		std::vector<std::string> tokens;
		tokenizePath(path, tokens);

		std::string key = tokens[1] + "_" + tokens[tokens.size() - 2];

		sf::Font f;
		f.loadFromFile(path);
		fonts.insert(std::make_pair(key, f));
	}

	// todo --
	void ResourceManager::loadSoundResource(std::string& path) {
		
	}

	// delete res from mem
	void ResourceManager::purgeTextureResource(std::string& id) {

	}

	void ResourceManager::purgeFontResource(std::string& id) {

	}

	void ResourceManager::purgeSoundResource(std::string& id) {

	}

	// getters
	const sf::Texture& ResourceManager::getTextureResource(const std::string& id) {
		auto search = textures.find(id);
		if (search != textures.end()) {
			std::cout << "Found " << search->first << "\n" << std::endl;
			return textures.at(id);
		}
		else {
			std::cout << "Not found\n";
		}
		return textures.at(id);
	}

	const sf::Font& ResourceManager::getFontResource(const std::string& id) {
		auto search = fonts.find(id);
		if (search != fonts.end()) {
			std::cout << "Found " << search->first << " " << search->second.getInfo().family << '\n';
			return fonts.at(id);
		}
		else {
			std::cout << "Not found\n";
		}
		return fonts.at(id);
	}

	sf::Sound ResourceManager::getSoundResource(std::string id) {
		return sounds.at(id);
	}

	void ResourceManager::tokenizePath(const std::string& path, std::vector<std::string>& tokens) {

		std::string delimiters = "/_.";

		// Skip delimiters at beginning.
		std::string::size_type lastPos = path.find_first_not_of(delimiters, 0);
		// Find first "non-delimiter".
		std::string::size_type pos = path.find_first_of(delimiters, lastPos);

		while (std::string::npos != pos || std::string::npos != lastPos)
		{
			// Found a token, add it to the vector.
			tokens.push_back(path.substr(lastPos, pos - lastPos));
			// Skip delimiters.  Note the "not_of"
			lastPos = path.find_first_not_of(delimiters, pos);
			// Find next "non-delimiter"
			pos = path.find_first_of(delimiters, lastPos);
		}
	}
}