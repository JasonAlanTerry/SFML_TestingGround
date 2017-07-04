#ifndef _RES_HOLDER
#define _RES_HOLDER

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

#include <memory>
#include <unordered_map>

namespace ResourceCodex {

	

	enum class TextureResource {
		Wall,
		Floor,
		Entity
	};

	enum class FontResource {
		Debug,
		Title,
		Script
	};

	enum class SoundResource {

	};

	class ResourceHolder
	{
	public:
		ResourceHolder();
		~ResourceHolder();

		// storage for res

	};

}
#endif

