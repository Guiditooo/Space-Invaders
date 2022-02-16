#include "Button.h"

namespace game
{
	Button::Button()
	{
		SetActive();
		type = EntityType::BUTTON;
		hovered = false;
		clicked = false;
	}

	Button::Button(float newWidth, float newHeight, float newX, float newY, Text newTx)
	{
		SetActive();

		width = newWidth;
		height = newHeight;
		pos.x = newX;
		pos.y = newY;
		text = newTx;

		hovered = false;
		clicked = false;
	}

	Button::~Button()
	{
	}
	void Button::Draw()
	{
		if (IsActive())
		{
			if (texture != nullptr)
			{
				DrawTexture(*texture, static_cast<int>(pos.x), static_cast<int>(pos.y), color);
			}
			else
			{
				DrawRectangle(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width), static_cast<int>(height), color);
			}
			if (border.texture != nullptr)
			{
				DrawTexture(*border.texture, static_cast<int>(pos.x), static_cast<int>(pos.y), border.color);
			}
			if (&font == nullptr)
			{
				DrawText(&text.tx[0], static_cast<int>(text.pos.x), static_cast<int>(text.pos.y), static_cast<int>(text.size), text.color);
			}
			else
			{
				DrawTextEx(font,&text.tx[0], text.pos.ToVector2(), text.size, TEXT_SPACING, text.color);
			}
		}
	}
	void Button::Update()
	{
	}
	void Button::SetTextAlignement(txt::Alignement newAlignement)
	{
		text.alignement = newAlignement;
		switch (newAlignement)
		{
		case game::txt::Alignement::LEFT_TOP:
			text.pos.x = this->pos.x;
			text.pos.y = this->pos.y;
			break;
		case game::txt::Alignement::LEFT_MID:
			text.pos.x = this->pos.x;
			text.pos.y = this->pos.y + this->height /2 - MeasureTextEx(font,&text.tx[0],text.size,TEXT_SPACING).y/2;
			break;
		case game::txt::Alignement::LEFT_BOT:
			text.pos.x = this->pos.x;
			text.pos.y = this->pos.y + this->height - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).y;
			break;
		case game::txt::Alignement::CENTER_TOP:
			text.pos.x = this->pos.x + this->width / 2 - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).x / 2;
			text.pos.y = this->pos.y;
			break;
		case game::txt::Alignement::CENTER_MID:
			text.pos.x = this->pos.x + this->width / 2 - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).x / 2;
			text.pos.y = this->pos.y + this->height / 2 - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).y / 2;
			break;
		case game::txt::Alignement::CENTER_BOT:
			text.pos.x = this->pos.x + this->width / 2 - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).x / 2;
			text.pos.y = this->pos.y + this->height - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).y;
			break;
		case game::txt::Alignement::RIGHT_TOP:
			text.pos.x = this->pos.x + this->width - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).x;
			text.pos.y = this->pos.y;
			break;
		case game::txt::Alignement::RIGHT_MID:
			text.pos.x = this->pos.x + this->width - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).x;
			text.pos.y = this->pos.y + this->height / 2 - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).y / 2;
			break;
		case game::txt::Alignement::RIGHT_BOT:
			text.pos.x = this->pos.x + this->width - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).x;
			text.pos.y = this->pos.y + this->height - MeasureTextEx(font, &text.tx[0], text.size, TEXT_SPACING).y;
			break;
		default:
			break;
		}
	}
	void Button::SetText(Text newText)
	{
		text = newText;
	}
	void Button::SetTextText(std::string newTextText)
	{
		text.tx = newTextText;
	}
	void Button::SetFontSize(float newfontSize)
	{
		text.size = newfontSize;
	}
	void Button::SetTextColor(Color newTextColor)
	{
		text.color = newTextColor;
	}
	void Button::SetTextPosition(Vec2 newPos)
	{
		text.pos = newPos;
	}
	void Button::SetTextPosition(float x, float y)
	{
		text.pos = Vec2(x, y);
	}
	void Button::SetBorderTexture(Texture2D* newBorderTexture)
	{
		border.texture = newBorderTexture;
	}
	void Button::SetBorderColor(Color newBorderColor)
	{
		border.color = newBorderColor;
	}
	Text Button::GetText()
	{
		return text;
	}

	Texture2D* Button::GetBorderTexture()
	{
		return border.texture;
	}
}