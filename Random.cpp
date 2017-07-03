#include "Random.h"

#include <random>

namespace Random {

	std::minstd_rand gen;

	void init() {
		gen.seed(std::random_device{}());
	}

	int integer(int min, int max) {
		std::uniform_int_distribution<int> dist(min, max);
		return dist(gen);
	}

	float decimal(float min, float max) {
		std::uniform_real_distribution<float> dist(min, max);
		return dist(gen);
	}



}
