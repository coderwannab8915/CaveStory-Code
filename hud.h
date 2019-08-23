#pragma once
#ifndef HUD_H
#define HUD_H

#include "sprite.h"
#include "player.h"

class Graphics;

class HUD {
public:
	HUD();
	HUD(Graphics &graphics, Player &player);
	void update(int elapsedTime, Player &player);
	void draw(Graphics &graphics);

private:
	Player _player;

	//Health sprites
	Sprite _healthBarSprite;
	Sprite _healthNumber1;
	Sprite _currentHealthBar;

	//EXP sprites
	Sprite _lvWord;
	Sprite _lvNumber;
	Sprite _expBar;

	//Weapons Stuff
	Sprite _slash;
	Sprite _dashes;
};







#endif // !HUD_H
