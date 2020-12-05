#include "Enemy.h"

void InitializeEnemy(Enemy& enemy) {
	
	enemy.stamina = 60 + rand() % 30;
	enemy.health = 60 + rand() % 30;
}