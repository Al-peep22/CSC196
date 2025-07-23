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

#include <vector>
#include "Enemy.h"

bool SpaceGame::Initialize() {
    scene = std::make_unique<viper::Scene>();

    std::vector<viper::vec2> ship_points{
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
    };

    //viper::Model ship_Model{ ship_points, viper::vec3{ 255, 255, 255} };
    std::shared_ptr<viper::Model> ship_model = std::make_shared<viper::Model>(ship_points, viper::vec3{ 96, 255, 41 });

    viper::Transform transform{ viper::vec2{ viper::GetEngine().GetRenderer().GetWidth() * 0.5f , viper::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 2 };
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, ship_model);

    player->speed = 500.0f;
    player->rotationRate = 180.0f;
    player->damping = 0.5f;
	player->name = "player";

	scene->AddActor(std::move(player));

    std::shared_ptr<viper::Model> enemy_model = std::make_shared<viper::Model>(ship_points, viper::vec3{ 255, 46, 46 });


    //create enemies
	for (int i = 0; i < 10; i++) {
		viper::Transform enemy_transform{ viper::vec2{ viper::random::getRandomFloat() * viper::GetEngine().GetRenderer().GetWidth(), viper::random::getRandomFloat() * viper::GetEngine().GetRenderer().GetHeight() }, 0, 2 };
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(enemy_transform, enemy_model);
		enemy->speed = viper::random::getRandomFloat() * 500;
		enemy->damping = 1.5f;
		scene->AddActor(std::move(enemy));
	}

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

void SpaceGame::Update() {
    scene->Update(viper::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw() {
    scene->Draw(viper::GetEngine().GetRenderer());

    //// DRAW TEXT
    //_text->Draw(viper::GetEngine().GetRenderer(), 40.0f, 40.0f);
}

void SpaceGame::Shutdown() {

}