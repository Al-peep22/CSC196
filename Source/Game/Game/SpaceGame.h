#pragma once
#include "Framework/Game.h"
//#include "Renderer/Text.h"

class SpaceGame : public viper::Game {
public:
	enum class GameState {
		Initialize,
		Title,
		StartGame,
		Game,
		PlayerDead,
		GameOver,
	}; 
	SpaceGame() = default;

	bool Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

	void Draw() override;

protected:
	//std::unique_ptr<viper::Text> text;
private:
	GameState gameState = GameState::Initialize;
	float enemySpawnTimer = { 0 };
};