#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;


class Graphics {
public:
	Graphics();
	~Graphics();

	//loading image from sprite sheet into _spriteSheets if it isn't already there. Every image only ever loaded once. Return that img from the map, not from file.
	SDL_Surface* loadImage(const std::string &filePath);

	//Overlap texture pulled from sprite sheet onto a particular part of the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	//Push the renderer to the screen
	void flip();

	//clears the screen
	void clear();

	//Returns the renderer
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};


#endif // !GRAPHICS_H