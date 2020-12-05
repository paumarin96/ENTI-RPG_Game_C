#include "Player.h"


void InitializePlayer(Player& p) {
	
	p.position(3,4);
	p.stamina = 90 + rand() % 20;
	p.health = 90 + rand() % 20;
	
}