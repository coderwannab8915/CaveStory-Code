#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMAATED_SPRITE_H

#include "sprite.h"
#include "globals.h"
#include <map>
#include <string>
#include <vector>

class Graphics; 
//Holds logic for animating sprites

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string & filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

	// Plays the animation provided it isn't already playing
	void playAnimation(std::string animation, bool once = false);

	//Updates the animated sprite
	void update(int elapsedTime);

	void draw(Graphics &graphics, int x, int y);


protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	//Adds on animation to the map of animations for the sprite
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
	
	//Resets all animations associated with the sprite
	void resetAnimations();

	//Stops the current animation
	void stopAnimation();

	//Changes the visibility of the animated sprite
	void setVisible(bool visible);

	//Logic that happens when an animation ends
	virtual void animationDone(std::string currentAnimation) = 0;

	//Required function, sets up all animations for a sprite
	virtual void setupAnimations() = 0;

private:
	std::map < std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed =0;
	bool _visible;
};


#endif  //!ANIMATED_SPRITE_H
