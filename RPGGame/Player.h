#pragma once
#include <stdlib.h>
#include <stdio.h>
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

	int enemiesKilled = 0; 

	void ConsumePotion();
	
	void DamagePlayer(int damage);
};

void InitializePlayer(Player& p);
