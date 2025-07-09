#pragma once
#include <algorithm>
#include <cmath>

namespace viper {
	namespace math {
		const float pi = 3.14;
		const float twoPi = 2 * pi;
		const float halfPi = pi / 2;

		/// <summary>
		/// Converts an angle from randians to degrees;
		/// </summary>
		/// <param name="rad">The anagle in randians to converts.</param>
		/// <returnsThe equivalent angle in degrees. </returns>
		constexpr float radToDeg(float rad) { return rad * (180 / pi); }
		
		/// <summary>
		/// Converts an angle from degrees to radians;
		/// </summary>
		/// <param name="deg">The anagle in degrees to converts.</param>
		/// <returnsThe angle in radians. </returns>
		constexpr float degToRad(float deg) { return deg * (pi / 180); }

		using std::min;
		using std::max;
		using std::sqrt;
		using std::sqrtf;
		using std::sin;
		using std::sinf;
		using std::cos;
		using std::cosf;

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