#include "Button.h"

namespace game
{
	void Button::CheckHover()
	{
		hovered = CheckCollisionPointRec(fix::mousePos, GetRectangle());
	}
	void Button::CheckClick()
	{
		if (hovered)
		{
			if (IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
			{
				scene::nextScene = sceneToCharge;
			}
		}
			
	}
	Button::Button()
	{
		SetActive();
		type = EntityType::BUTTON;
		hovered = false;
		clicked = false;
		SetTexture(&button::buttonTexture);
		sceneToCharge = scene::SceneList::NONE;
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
			//if (border.texture != nullptr)
			//{
			//	DrawTexture(*border.texture, static_cast<int>(pos.x), static_cast<int>(pos.y), border.color);
			//}
			if (&font == nullptr)
			{
				DrawText(&text.tx[0], static_cast<int>(text.pos.x), static_cast<int>(text.pos.y), static_cast<int>(text.size), text.color);
			}
			else
			{
				if(!hovered)
				DrawTextEx(font,&text.tx[0], text.pos.ToVector2(), text.size, TEXT_SPACING, text.color);
				else
					DrawTextEx(font, &text.tx[0], text.pos.ToVector2(), text.size, TEXT_SPACING, HOVERED_COLOR);
			}
		}
	}
	void Button::Update()
	{
		CheckHover();
		CheckClick();
	}
	void Button::SetPosition(float x, float y)
	{
		pos.x = x;
		pos.y = y;
		SetTextAlignement(text.alignement);
	}
	void Button::SetPosition(Vec2 newPos)
	{
		pos = newPos;
		SetTextAlignement(text.alignement);
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
		SetTextAlignement(newText.alignement);
	}
	void Button::SetTextText(std::string newTextText)
	{
		text.tx = newTextText;
		SetTextAlignement(text.alignement);
	}
	void Button::SetTextSize(float newfontSize)
	{
		text.size = newfontSize;
		SetTextAlignement(text.alignement);
	}
	void Button::SetTextColor(Color newTextColor)
	{
		text.color = newTextColor;
	}
	void Button::SetEntityWidth(float newWidth)
	{
		this->width = newWidth;
		this->texture->width = static_cast<int>(newWidth);
		SetTextAlignement(text.alignement);
	}
	void Button::SetEntityHeight(float newHeight)
	{
		this->height = newHeight;
		this->texture->height = static_cast<int>(newHeight);
		SetTextAlignement(text.alignement);
	}
	void Button::SetSceneToCharge(scene::SceneList newSceneToCharge)
	{
		sceneToCharge = newSceneToCharge;
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