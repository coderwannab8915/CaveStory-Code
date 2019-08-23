#pragma once
#ifndef ANIMATED_TILE_H
#define ANIMATED_TILE_H

#include "tile.h"
#include <vector>

class AnimatedTile : public Tile {
public:
	AnimatedTile(std::vector<Vector2> tilePositions, int duration, SDL_Texture* tileset, Vector2 size, Vector2 position);
	void update(int elapsedTime);
	void draw(Graphics &graphics);

protected:
	int _amountOfTime = 0;
	int _notDone = false;

private:
	std::vector<Vector2> _tilesetPositions;
	int _tileToDraw;
	int _duration;
};

struct AnimatedTileInfo {
public:
	int TilesetsFirstGid;
	int StartTileId;
	std::vector<int> TileIds;
	int Duration;
};
#endif // !ANIMATED_TILE_H
