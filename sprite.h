#pragma once
#ifndef SPRITE_H
#define SPRITE_H

class Graphics; 

#include "rectangle.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

//Sprite class holds all the information for individual sprites

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);

	const Rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(Rectangle &other) const;

	const inline float getX() const { return this->_x; }
	const inline float getY() const { return this->_y; }

	void setSourceRectX(int value);
	void setSourceRectY(int value);

	void setSourceRectW(int value);
	void setSourceRectH(int value);

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	Rectangle _boundingBox;

	float _x, _y;

private:
	
};




#endif
