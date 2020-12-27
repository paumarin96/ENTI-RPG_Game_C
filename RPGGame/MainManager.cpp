#include "MainManager.h"

void MainManager::Play() {

	while (!MainManager::gameOver) {
	
		 
		switch (state) {
		case DUNGEON:
			Dungeon();
			break;

		case BATTLE:
			Battle();
			break;

		case CHEST:
			Chest();
			break;

		case GAMEOVER:
			GameOver();
			break;

		case BOSS:
			Boss();
			break;
		}
		
	
	}

}

void MainManager::DegradeAgility() {
	player.agility--;
	if (player.agility <= 0) {
		player.agility = 3;
		//RandomizeDungeon();
	}
}

void MainManager::Dungeon() {
	char userAction;
	bool firstTime;
	printf("  ------ DUNGEON ------\n\n");
	printf("E -> Enemy    |   P -> Player   |    C -> Chest\n\n");
	printf("Health: %d / %d\n", player.health, player.maxHealth);
	printf("Potions: %d / 3\n", player.potions);
	printf("Moves: %d / 3\n", player.agility);

	if (player.agility == 3) {
		firstTime = true;
	}
	else {
		firstTime = false;
	}

	//printf("Position: %d, %d \n", player.pos.x, player.pos.y);
	CreateDungeon(player, enemies, chests, firstTime);

	printf("__________________________\n\n");
	printf("W A S D -> Move\n");
	printf("P -> Potion\n\n");
	printf("Enter your action: \n\n");
	scanf_s(" %c", &userAction);

	switch (userAction) {
	case 'P':
	case 'p':
		player.ConsumePotion();
		break;
	case 'W':
	case 'w':
		if (player.position(player.pos.x - 1, player.pos.y)) 
			DegradeAgility();
		break;
	case 'A':
	case 'a':
		if(player.position(player.pos.x, player.pos.y - 1))
			DegradeAgility();
		break;
	case 'S':
	case 's':
		if(player.position(player.pos.x + 1, player.pos.y))
			DegradeAgility();
		break;
	case 'D':
	case 'd':
		if(player.position(player.pos.x, player.pos.y + 1))
			DegradeAgility();
		break;
	}
	for (int i = 0; i < 7; i++) {
		if (player.pos.x == enemies[i].pos.x && player.pos.y == enemies[i].pos.y) {
			//printf("Comienza batalla: %d, %d, %d", i, enemies[i].pos.x, enemies[i].pos.y);
			if (enemies[i].isDead == false) {
				printf("Aqui hay un enemigo no muerto\n");
				//state = GameState::BATTLE;
				//Battle();
			}
			else {
				printf("Aqui hay un enemigo muerto\n");
			}
		}
	}
	//system("CLS");

}

void MainManager::Battle() {
	printf("OH NO OH NOO OH NONONONONONONONONO, BATALLA\n");
	char userSel;
	scanf_s(" &c", &userSel);

	if (player.health <= 0) {
		state = GameState::GAMEOVER;
		gameOver = true;
		GameOver();
	}
}

void MainManager::Chest() {

}

void MainManager::GameOver() {
	printf("\n\n\nYOU ARE DEAD. NO ONE WILL REMEMBER YOU. YOU WILL GO TO HELL WITH PIPO.\n\n\n");
}
 
void MainManager::Boss() {

}

