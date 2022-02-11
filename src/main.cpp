#include "General/Starter/GameStarter.h"

#include "Scenes/Gameplay/Gameplay.h"

using namespace game;

int main()
{

	starter::StartWindow();

	gameplay::Init();

	do
	{
		BeginDrawing();
		ClearBackground(BLACK); 
		gameplay::Update();
		gameplay::Draw();
		EndDrawing();

	} while (!WindowShouldClose());

	
	starter::EndWindow();
	
	return 0;
}