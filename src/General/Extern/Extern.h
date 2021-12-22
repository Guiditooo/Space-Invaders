#ifndef EXTERN_H
#define EXTERN_H

namespace game
{
	namespace screen
	{
		extern int width;
		extern int height;
	}

	enum class SceneList
	{
		MENU,
		CREDITS,
		OPTIONS,
		GAME,
		NONE
	};

}

#endif // !EXTERN_H