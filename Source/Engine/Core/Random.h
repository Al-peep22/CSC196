#pragma once
#include <stdlib.h>
namespace viper {
	namespace random {
		int getRandomInt() { return rand(); }

		//<summary>
		//Generates a random integer in the range [0,max)
		int getRandomInt(int max) { return rand() % max; }

		//<summary>
		//Generates a random integer in the range [min,max]
		int getRandomInt(int min, int max) { return min + getRandomInt(max - min + 1); }

		inline float getRandomFloat() { return rand() / (float)RAND_MAX; }
	}
}