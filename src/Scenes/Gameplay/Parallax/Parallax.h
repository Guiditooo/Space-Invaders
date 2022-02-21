#ifndef PARALLAX_H
#define PARALLAX_H

#include "General/Extern/Extern.h"

namespace game
{
	namespace gameplay
	{

		using namespace parallax;

		extern Texture2D parallaxTx[PARALLAX_COUNT];
		extern TextureInfo parallaxTI[PARALLAX_COUNT][PARALLEL_IMAGES];

		void InitParallax();
		void UpdateParallax();
		void DrawParallax();
		void DeinitParallax();

	}
}

#endif // !GAMEOVER_H
