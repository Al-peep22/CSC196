#pragma once
#include <algorithm>

namespace viper {
	namespace math {
		const float pi = 3.14;
		const float twoPi = 2 * pi;
		const float halfPi = pi / 2;

		const float radToDeg(float rad) { return rad * (180 / pi); }
		const float degToRad(float deg) { return deg * (pi / 180); }

		using std::min;
		using std::max;
		//using std::clamp;
		/*template <typename T>
		T min(T a, T b) {
			return std::min(a, b);

			return (a < b) ? a : b;

			if (a < b) { return a; }
			else { return b; }
		}*/
	}
}