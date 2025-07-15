#include "Model.h"
#include "Renderer.h"

namespace viper {
	/// <summary>
	///  Draws the model by rendering lines
	/// </summary>
	/// <param name="renderer"></param>
	void Model::Draw(Renderer& renderer, const vec2& position, float rotation, float scale)
	{
		// check if points are empty, if so return
		if (points.empty()) { return; }

		renderer.SetColor(color.x, color.y, color.z);

		// iterate through all points, draw line
		for (int i = 0; i < points.size()-1; i++) {
			vec2 p1 = (points[i].Rotate(rotation) * scale) + position;
			vec2 p2 = (points[i + 1].Rotate(rotation) * scale) + position;

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}