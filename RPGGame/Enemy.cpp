#include "Enemy.h"

void InitializeEnemy(Enemy& enemy) {
	
	enemy.stamina = 60 + rand() % 31;
	enemy.health = 60 + rand() % 31;

	enemy.position(rand() % 5, rand() % 5);
}