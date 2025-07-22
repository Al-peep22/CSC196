#pragma once
#include <SDL3/SDL.h>
#include <iostream>

namespace viper {
	class Renderer {
	public:
		Renderer() = default;

		bool Initialize();
		void ShutDown();
		bool CreateWindow(const std::string& name, int width, int height);

		void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void Clear();

		void Present();
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x, float y);

		int GetWidth() const { return width; }
		int GetHeight() const { return height; }

	private:
		//friend class Text;

		int width{ 0 };
		int height{ 0 };

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
	};
}