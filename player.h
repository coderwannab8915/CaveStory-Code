#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"
#include "slope.h"
#include "door.h"
#include "level.h"
#include "enemy.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, Vector2 spawnPoint);
	void draw(Graphics &graphics);
	void update(float elapsedTime);;

	//moves the player left by -dx
	void moveLeft();
	//moves the player right by dx
	void moveRight();
	//stop moving the player
	void stopMoving();
	void lookUp();
	void stopLookingUp();
	void lookDown();
	void stopLookingDown();
	void jump();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle> &others);
	void handleSlopeCollisions(std::vector<Slope> &others);
	void handleDoorCollision(std::vector<Door> &others, Level &level, Graphics &graphics);
	void handleEnemyCollisions(std::vector<Enemy*> &others);

	const float getX() const;
	const float getY() const;

	const inline int getMaxHealth() const { return this->_maxHealth; }
	const inline int getCurrentHealth() const { return this->_currentHealth;  }

	void gainHealth(int amount);

private:
	float _dx, _dy;

	Direction _facing;

	bool _grounded;
	bool _lookingUp = false;
	bool _lookingDown = false;

	int _maxHealth;
	int _currentHealth;
};
#endif PLAYER_H
