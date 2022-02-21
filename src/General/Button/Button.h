#ifndef BUTTON_H
#define BUTTON_H

#include "General/Enitity/Entity.h"

namespace game
{

	class Button : public Entity
	{
	private:
		Text text;
		TextureInfo border;
		bool hovered;
		bool clicked;
		scene::SceneList sceneToCharge;
		/*const*/ float NORMAL_MULTIPLIER = 1.0f;
		/*const*/ float HOVERED_MULTIPLIER = 1.15f;
		/*const*/ Color HOVERED_COLOR = GREEN;
		/*const*/ Color CLICKED_COLOR = RED;

		void CheckHover();
		void CheckClick();

	public:
		Button();
		~Button();

		void Draw() override;
		void Update() override;
		void SetPosition(float x, float y) override;
		void SetPosition(Vec2 newPos) override;

		void SetTextAlignement(txt::Alignement newAlignement);
		void SetText(Text newText);
		void SetTextText(std::string newTextText);
		void SetTextSize(float newfontSize);
		void SetTextColor(Color newTextColor);
		void SetEntityWidth(float newWidth) override;
		void SetEntityHeight(float newHeight) override;
		void SetSceneToCharge(scene::SceneList newSceneToCharge);

		void SetBorderTexture(Texture2D* newBorderTexture);
		void SetBorderColor(Color newBorderColor);

		Text GetText();

		Texture2D* GetBorderTexture();

		bool IsBeingClicked();

	};

	

}

#endif // !BUTTON_H
