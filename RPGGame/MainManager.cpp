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

void MainManager::Dungeon() {
	char userAction;

	printf("  ------ DUNGEON ------\n\n");
	printf("E -> Enemy    |   P -> Player   |    C -> Chest\n\n");
	printf("Health: %d / %d\n", player.health, player.maxHealth);
	printf("Potions: %d / 3\n", player.potions);
	printf("Moves: %d / 3\n", player.agility);
	RenderDungeon();

	printf("__________________________\n\n");
	printf("W A S D -> Move\n");
	printf("P -> Potion\n\n");
	printf("Enter your action: \n\n");
	scanf_s(" %c", &userAction);
	system("CLS");
	switch (userAction) {
	case 'P':
		player.ConsumePotion();
		break;
	case 'W':
		player.ConsumePotion();
		break;
	case 'A':
		player.ConsumePotion();
		break;
	case 'S':
		player.ConsumePotion();
		break;
	case 'D':
		player.ConsumePotion();
		break;


	default:
		break;
	}
	

}

void MainManager::Battle() {

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