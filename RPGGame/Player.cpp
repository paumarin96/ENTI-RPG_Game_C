#include "Player.h"


void InitializePlayer(Player& p) {
	
	p.position(2,3);
	p.stamina = 90 + rand() % 20;
	p.health = 90 + rand() % 20;
	p.maxHealth = p.health;
	
}

void Player::ConsumePotion() {
	potions--;
	health += ((40 * maxHealth) / 100);
	if (health > maxHealth) {
		health = maxHealth;
	}
}

void Player::DamagePlayer(int damage) {
	//Au duele
	//igual pipo muere.

	health -= damage;
	
}