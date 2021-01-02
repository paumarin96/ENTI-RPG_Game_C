#pragma once
#include "types.h"
#include <time.h>
#include <stdlib.h>
struct Enemy {
	MapPosition pos;
	int health;
	int maxHealth;
	int stamina;
	int maxStamina;
	bool isDead = false;
	void position(int x, int y) {
		pos.x = x;
		pos.y = y;
	}
};

Enemy GenerateEnemy();