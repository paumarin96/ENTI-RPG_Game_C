#include "Player.h"


void InitializePlayer(Player& p) {
	
	p.position(3,2);
	p.stamina = 90 + rand() % 21;
	p.health = 90 + rand() % 21;
	p.maxHealth = p.health;
	p.maxStamina = p.stamina;

	
}

void Player::ConsumePotion() {
	
	if (potions > 0) {
		potions--;
		health += ((40 * maxHealth) / 100);

		if (health > maxHealth) {
			health = maxHealth;
		}
	}
	
}



void Player::DamagePlayer(int damage) {

	health -= damage;
	//codifo si mueres
	
}