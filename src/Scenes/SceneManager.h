#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "General/Extern/Extern.h"

namespace game
{
	extern SceneList actualScene;
	extern SceneList nextScene;

	void Init();
	void Update();
	void Draw();
	void Deinit();

}

#endif // !SCENEMANAGER_H