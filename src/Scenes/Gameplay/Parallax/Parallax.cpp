#include "Parallax.h"



namespace game
{
	namespace gameplay
	{

		Texture2D parallaxTx[PARALLAX_COUNT];
		TextureInfo parallaxTI[PARALLAX_COUNT][PARALLEL_IMAGES];

		void InitParallax()
		{
			for (short i = 0; i < PARALLAX_COUNT; i++)
			{
				 std::string path = "res/assets/backgrounds/Parallax" + std::to_string(i) + ".png";
				 parallaxTx[i] = LoadTexture(&path[0]);

				 switch (static_cast<ParallaxDirection>(i))
				 {
				 case ParallaxDirection::P_UP:
					 for (short j = 0; j < PARALLEL_IMAGES; j++)
					 {
						 parallaxTI[i][j].texture = &parallaxTx[i];
						 parallaxTI[i][j].position.x = static_cast<float>(screen::width) / 2 - static_cast<float>(parallaxTI[i][j].texture->width) / 2;
						 parallaxTI[i][j].position.y = static_cast<float>(j * parallaxTI[i][j].texture->height);
						 int aux = 100 + ((PARALLAX_COUNT - i - 1) * 35);
						 parallaxTI[i][j].color.r = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.g = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.b = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.a = static_cast<unsigned char>(aux);
					 }
					 break;
				 case ParallaxDirection::P_DOWN:
					 for (short j = 0; j < PARALLEL_IMAGES; j++)
					 {
						 parallaxTI[i][j].texture = &parallaxTx[i];
						 parallaxTI[i][j].position.x = static_cast<float>(screen::width) / 2 - static_cast<float>(parallaxTI[i][j].texture->width) / 2;
						 parallaxTI[i][j].position.y = static_cast<float>(screen::height) - static_cast<float>((j+1) * parallaxTI[i][j].texture->height);
						 int aux = 100 + ((PARALLAX_COUNT - i - 1) * 35);
						 parallaxTI[i][j].color.r = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.g = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.b = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.a = static_cast<unsigned char>(aux);
					 }
					 break;
				 case ParallaxDirection::P_LEFT:
					 for (short j = 0; j < PARALLEL_IMAGES; j++)
					 {
						 parallaxTI[i][j].texture = &parallaxTx[i];
						 parallaxTI[i][j].position.x = j * static_cast<float>(parallaxTI[i][j].texture->width);
						 parallaxTI[i][j].position.y = static_cast<float>(screen::height)/2 - static_cast<float>(parallaxTI[i][j].texture->height)/2;
						 int aux = 100 + ((PARALLAX_COUNT - i - 1) * 35);
						 parallaxTI[i][j].color.r = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.g = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.b = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.a = static_cast<unsigned char>(aux);
					 }
					 break;
				 case ParallaxDirection::P_RIGHT:
					 for (short j = 0; j < PARALLEL_IMAGES; j++)
					 {
						 parallaxTI[i][j].texture = &parallaxTx[i];
						 parallaxTI[i][j].position.x = static_cast<float>(screen::width) - (j+1) * static_cast<float>(parallaxTI[i][j].texture->width);
						 parallaxTI[i][j].position.y = static_cast<float>(screen::height) / 2 - static_cast<float>(parallaxTI[i][j].texture->height) / 2;
						 int aux = 100 + ((PARALLAX_COUNT - i - 1) * 35);
						 parallaxTI[i][j].color.r = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.g = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.b = static_cast<unsigned char>(aux);
						 parallaxTI[i][j].color.a = static_cast<unsigned char>(aux);
					 }
					 break;
				 default:
					 break;
				 }

				 

			}
			int a = 0;
			a++;
		}

		void UpdateParallax()
		{
			for (short i = 0; i < PARALLAX_COUNT; i++)
			{

				switch (static_cast<ParallaxDirection>(i))
				{
				case ParallaxDirection::P_UP:
					for (short j = 0; j < PARALLEL_IMAGES; j++)
					{
						parallaxTI[i][j].position.y -= PARALLAX_SPEED_UP * fix::frameTime;
						
						if (parallaxTI[i][j].position.y < -parallaxTI[i][j].texture->height)
						{
							parallaxTI[i][j].position.y += PARALLEL_IMAGES * parallaxTI[i][j].texture->height;
						}

					}
					break;
				case ParallaxDirection::P_DOWN:
					for (short j = 0; j < PARALLEL_IMAGES; j++)
					{
						parallaxTI[i][j].position.y += PARALLAX_SPEED_DOWN * fix::frameTime;

						if (parallaxTI[i][j].position.y > screen::height)
						{
							parallaxTI[i][j].position.y -= PARALLEL_IMAGES * parallaxTI[i][j].texture->height;
						}
					}
					break;
				case ParallaxDirection::P_LEFT:
					for (short j = 0; j < PARALLEL_IMAGES; j++)
					{
						parallaxTI[i][j].position.x -= PARALLAX_SPEED_LEFT * fix::frameTime;

						if (parallaxTI[i][j].position.x < -parallaxTI[i][j].texture->width)
						{
							parallaxTI[i][j].position.x += PARALLEL_IMAGES * parallaxTI[i][j].texture->width;
						}
					}
					break;
				case ParallaxDirection::P_RIGHT:
					for (short j = 0; j < PARALLEL_IMAGES; j++)
					{
						parallaxTI[i][j].position.x += PARALLAX_SPEED_RIGHT * fix::frameTime;

						if (parallaxTI[i][j].position.x > screen::width)
						{
							parallaxTI[i][j].position.x -= PARALLEL_IMAGES * parallaxTI[i][j].texture->width;
						}
					}
					break;
				default:
					break;
				}



			}
		}

		void DrawParallax()
		{
			//DrawTexture(*parallaxTI[0][0].texture, static_cast<int>(parallaxTI[0][0].position.x), static_cast<int>(parallaxTI[0][0].position.y), parallaxTI[0][0].color);
			
			for (short i = 0; i < PARALLAX_COUNT; i++)
			{
				for (short j = 0; j < PARALLEL_IMAGES; j++)
				{
					DrawTexture(*parallaxTI[i][j].texture, static_cast<int>(parallaxTI[i][j].position.x), static_cast<int>(parallaxTI[i][j].position.y), parallaxTI[i][j].color);
				}
			}
			
		}

		void DeinitParallax()
		{
			for (short i = 0; i < PARALLAX_COUNT; i++)
			{
				UnloadTexture(parallaxTx[i]);
			}
		}

	}
}