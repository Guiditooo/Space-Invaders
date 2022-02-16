#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "General/Extern/Extern.h"

namespace game
{

	void GeneralInit();
	void GeneralUpdate();
	void GeneralDraw();
	void GeneralDeinit();

	void Update();
	void Draw();

	void CheckNextScene();

}

#endif // !SCENEMANAGER_H