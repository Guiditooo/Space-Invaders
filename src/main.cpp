#include "raylib.h"

int main()
{
	InitWindow(500, 500, "Space Invaders");
	SetTargetFPS(60);
	do
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(200, 200, 10, 10, RED);
		EndDrawing();
	} while (!WindowShouldClose());

	CloseWindow();
	
	return 0;
}