#include "Enemy.h"


Enemy GenerateEnemy() {
	Enemy enemy;
	enemy.maxStamina = 60 + rand() % 31;
	enemy.maxHealth = 60 + rand() % 31;
	enemy.health = enemy.maxHealth;
	enemy.stamina = enemy.maxStamina;
	enemy.position(rand() % 5, rand() % 5);
	return enemy;
}