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

		float NORMAL_MULTIPLIER = 1.0f;
		float HOVERED_MULTIPLIER = 1.15f;
		Color HOVERED_COLOR = GREEN;
		Color CLICKED_COLOR = RED;

	public:
		Button();
		Button(float newWidth, float newHeight, float newX, float newY, Text newTx);
		~Button();

		void Draw() override;
		void Update() override;

		void SetTextAlignement(txt::Alignement newAlignement);
		void SetText(Text newText);
		void SetTextText(std::string newTextText);
		void SetFontSize(float newfontSize);
		void SetTextColor(Color newTextColor);
		void SetTextPosition(Vec2 newPos);
		void SetTextPosition(float x, float y);

		void SetBorderTexture(Texture2D* newBorderTexture);
		void SetBorderColor(Color newBorderColor);

		Text GetText();

		Texture2D* GetBorderTexture();

	};

	

}

#endif // !BUTTON_H
