#pragma once
#include <stdlib.h>
#include "types.h"
#include <time.h>
struct Player {
	MapPosition pos;
	int gold = 0;
	int health;
	int stamina;
	int agility = 3;
	int potions = 3;
	void position(int x, int y) {
		pos.x = x;
		pos.y = y;
	}
	int enemiesKilled = 0; 
};

void InitializePlayer(Player& p);
