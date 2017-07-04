#include "ResourceHolder.h"

namespace ResCodex {

	// init mem
	ResourceHolder::ResourceHolder() {

	}

	// purge all mem
	ResourceHolder::~ResourceHolder() {

	}

	void ResourceHolder::handleStateRequest(State::ResReq req) {

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