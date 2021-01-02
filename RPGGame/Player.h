#pragma once
#include <stdlib.h>
#include "types.h"
#include <time.h>

struct Player {
	MapPosition pos;
	int gold = 0;

	int health;
	int maxHealth;

	int stamina;
	int maxStamina;

	int agility = 3;
	int maxAgility = 3;
	

	int potions = 3;

	bool position(int x, int y) {

		if (x > 4 || x < 0) {
			
			return false;
		} 
		if (y > 4 || y < 0) {
			
			return false;
		}

		pos.y = y;
		pos.x = x;
		return true;
	}

	int enemiesKilled = 0; 

	void ConsumePotion();
	
	void DamagePlayer(int damage);
};

void InitializePlayer(Player& p);
