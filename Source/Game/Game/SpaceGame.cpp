#include "SpaceGame.h"

#include "Core/Random.h"
#include "Framework/Scene.h"
#include "Math/Vector2.h"
#include "Player.h"
//#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
//#include "Renderer/Text.h"
#include "Engine.h"
#include "Input/InputSystem.h"

#include <vector>
#include "Enemy.h"
#include "GameData.h"
#include "Renderer/ParticleSystem.h"

bool SpaceGame::Initialize() {
    scene = std::make_unique<viper::Scene>(this);

	titleFont = std::make_shared<viper::Font>();
	titleFont->Load(GameData::gameFont, 128);

	uiFont = std::make_shared<viper::Font>();
	uiFont->Load(GameData::gameFont, 48);

	titleText = std::make_unique<viper::Text>(titleFont);
	scoreText = std::make_unique<viper::Text>(uiFont);
	livesText = std::make_unique<viper::Text>(uiFont);

    // SHIP POINTS
    /*std::vector<viper::vec2> ship_points{
            { 6, 0 },
            { -2, -4 },
            { -2, -6 },
            { -4, -6 },
            { -4, -2 },
            { 4, 0 },
            { -4, 2 },
            { -4, 6 },
            { -2, 6 },
            { -2, 3 },
            { 6, 0 },
            { -3, 0 },
            { -2, -4 },
            { -3, 0 },
            { -2, 3 }
    };*/

	// CREATE PLAYER
    /*
    //viper::Model ship_Model{ ship_points, viper::vec3{ 255, 255, 255} };
    std::shared_ptr<viper::Model> ship_model = std::make_shared<viper::Model>(GameData::ship_points, viper::vec3{ 96, 255, 41 });

    viper::Transform transform{ viper::vec2{ viper::GetEngine().GetRenderer().GetWidth() * 0.5f , viper::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 2 };
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, ship_model);

    player->speed = 500.0f;
    player->rotationRate = 180.0f;
    player->damping = 0.5f;
	player->name = "player";
	player->tag = "player";

	scene->AddActor(std::move(player));*/

    //CREATE ENEMIES
    /*
    std::shared_ptr<viper::Model> enemy_model = std::make_shared<viper::Model>(GameData::enemy_points, viper::vec3{ 255, 46, 46 });
	for (int i = 0; i < 10; i++) {
		viper::Transform enemy_transform{ viper::vec2{ viper::random::getRandomFloat() * viper::GetEngine().GetRenderer().GetWidth(), viper::random::getRandomFloat() * viper::GetEngine().GetRenderer().GetHeight() }, 0, 2 };
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(enemy_transform, enemy_model);
		enemy->speed = viper::random::getRandomFloat() * 500;
		enemy->damping = 1.5f;
        //enemy->name = "enemy";
		//enemy->tag = "enemy";
		scene->AddActor(std::move(enemy));
	}
    */

    // SAVING CODE FOR ENEMY CODE
    /*for (int i = 0; i < 10; i++) {
        viper::Transform transform{ viper::vec2{viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1024}, 0, 2 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        scene->AddActor(std::move(player));
    }*/

    // FONT CREATION
    /*std::unique_ptr<viper::Font> font = std::make_unique<viper::Font>();
    font->Load("ArcadeClassic.ttf", 20);*/

    // TEXT CREATION
    /*_text = std::make_unique<viper::Text>(font);
    _text->Create(viper::GetEngine().GetRenderer(), "Hello World", viper::vec3{ 1, 1, 1 });*/

    return true;
}

void SpaceGame::Update(float dt) {

    switch (gameState) {
    case SpaceGame::GameState::Initialize:
        gameState = GameState::Title;
		break;
	case SpaceGame::GameState::Title:
		if (viper::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {
		    gameState = GameState::StartGame;
		}        
		break;
	case SpaceGame::GameState::StartGame:
        score = 0;
        lives = 3;
		gameState = GameState::StartRound;
        break;
    case SpaceGame::GameState::StartRound:
    {
        scene->RemoveAllActors();
        // CREATE PLAYER
        std::shared_ptr<viper::Model> ship_model = std::make_shared<viper::Model>(GameData::ship_points, viper::vec3{ 0.37f, 1, 0.16f });
        viper::Transform transform{ viper::vec2{ viper::GetEngine().GetRenderer().GetWidth() * 0.5f , viper::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 2 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, ship_model);

        player->speed = 500.0f;
        player->rotationRate = 180.0f;
        player->damping = 0.5f;
        player->name = "player";
        player->tag = "player"; 

        scene->AddActor(std::move(player));

        gameState = GameState::Game;
        break;
    }
	case SpaceGame::GameState::Game:
        enemySpawnTimer -= dt;
        if (enemySpawnTimer <= 0) {
            enemySpawnTimer = 2;
            // CREATE ENEMY
            std::shared_ptr<viper::Model> enemy_model = std::make_shared<viper::Model>(GameData::enemy_points, viper::vec3{ 1, 0.18f, 0.18f });
            viper::Transform enemy_transform{ viper::vec2{ viper::random::getRandomFloat() * viper::GetEngine().GetRenderer().GetWidth(), viper::random::getRandomFloat() * viper::GetEngine().GetRenderer().GetHeight() }, 0, 5 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(enemy_transform, enemy_model);

            enemy->speed = (viper::random::getReal() * 100) + 100;
            enemy->damping = 0.2f;
			enemy->fireTime = 3;
			enemy->fireTimer = 5;
            enemy->name = "enemy";
            enemy->tag = "enemy";

            scene->AddActor(std::move(enemy));
        }
        break;
	case SpaceGame::GameState::PlayerDead:
        stateTimer -= dt;
        if (stateTimer <= 0) {
            lives--;
            if (lives == 0) { gameState = GameState::GameOver; stateTimer = 3; }
            else { gameState = GameState::StartRound; }
        }
		break;
	case SpaceGame::GameState::GameOver:
        stateTimer -= dt;
        if (stateTimer <= 0) {
            gameState = GameState::Title;
        }
        break;
    }
    scene->Update(viper::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw(viper::Renderer& renderer) {

    if (gameState == GameState::Title) {
        titleText->Create(renderer, "PIT VIPER", viper::vec3{ 1,0,0 });
        titleText->Draw(renderer, 250, 400);
    }

    if (gameState == GameState::GameOver) {
        titleText->Create(renderer, "GAME OVER", viper::vec3{ 1,0,0 });
        titleText->Draw(renderer, 250, 400);
    }

    if (gameState != GameState::GameOver && gameState != GameState::Title) {
        scoreText->Create(renderer, "SCORE  "+std::to_string(score), {1,1,1});
	    scoreText->Draw(renderer, 20.0f, 20.0f);

        livesText->Create(renderer, "LIVES  " + std::to_string(lives), { 1,1,1 });
        livesText->Draw(renderer, (float)renderer.GetWidth() - 300, 20.0f);
    }

    scene->Draw(renderer);

	viper::GetEngine().GetParticleSystem().Draw(renderer);

    // DRAW TEXT
    //_text->Draw(viper::GetEngine().GetRenderer(), 40.0f, 40.0f);
	//viper::GetEngine()GetParticalSystem().Draw(renderer);
}

void SpaceGame::OnPlayerDead()
{
	gameState = GameState::PlayerDead;
    stateTimer = 2;
}

void SpaceGame::Shutdown() {

}