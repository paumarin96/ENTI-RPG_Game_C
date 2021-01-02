#include "MainManager.h"

void MainManager::Play() {

	while (!MainManager::gameOver) {
	
		 
		switch (state) {
		case DUNGEON:
			Dungeon();
			break;

		case BATTLE:
			for (int i = 0; i < 7; i++) {
				if (player.pos.x == enemies[i].pos.x && player.pos.y == enemies[i].pos.y) {

					if (enemies[i].isDead == false) {
						//system("CLS");
						state = GameState::BATTLE;
						Battle(enemies[i]);

					}
				}
			}
		
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
		player.agility = player.maxAgility;
		//RandomizeDungeon();
		AddEnemies();
		for (int i = 0; i <= deadEnemies; i++) {
			if (i == 0) {
				continue;
			}
			enemies[i].isDead = true;
		}
	}
}

void MainManager::Dungeon() {
	char userAction;
	bool firstTime;
	printf("  ------ DUNGEON ------\n\n");
	printf("E -> Enemy    |   P -> Player   |    C -> Chest\n\n");
	printf("Health: %d / %d\n", player.health, player.maxHealth);
	printf("Potions: %d / 3\n", player.potions);
	printf("Moves: %d / %d\n", player.agility, player.maxAgility);

	if (player.agility == player.maxAgility) {
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
			
			if (enemies[i].isDead == false) {
				system("CLS");
				state = GameState::BATTLE;
				Battle(enemies[i]);

			}
		}
	}
	for (int i = 0; i < 2; i++) {
		if (player.pos.x == chests[i].pos.x && player.pos.y == chests[i].pos.y) {

			if (chests[i].isLooted == false) {
				system("CLS");
				state = GameState::CHEST;
				chests[i].isLooted = true;
				OpenChest(chests[i]);

			}
		}
	}
	system("CLS");

}

void MainManager::Battle(Enemy &enemy) {
	system("CLS");
	printf("------ COMBAT ------\n\n");
	printf("-- Enemy --\n");
	printf("[");

	int enemyMaxHealth = enemy.maxHealth;
	int enemyActualHealth = enemy.health;
	int barritas;
	barritas = ((enemyActualHealth * 10) / enemyMaxHealth);
	
	for (int i = 0; i < barritas; i++) {
		printf("=");
	}

	for (int i = 0; i < 10 - barritas; i++) {
		printf(" ");
	}
	printf("] ? HP\n");

	printf("[");

	int enemyMaxStamina = enemy.maxStamina;
	int enemyActualStamina = enemy.stamina;
	int barritas2;
	barritas2 = ((enemyActualStamina * 10) / enemyMaxStamina);

	for (int i = 0; i < barritas2; i++) {
		printf(">");
	}

	for (int i = 0; i < 10 - barritas2; i++) {
		printf(" ");
	}
	printf("] ? Stamina\n\n");
	printf("---------------------------\n\n");
	printf("-- Player --\n");
	printf("[");
	
	int playerMaxHealth = player.maxHealth;
	int playerActualHealth = player.health;
	int barritasPlayer;
	barritasPlayer = ((playerActualHealth * 10) / playerMaxHealth);

	for (int i = 0; i < barritasPlayer; i++) {
		printf("=");
	}

	for (int i = 0; i < 10 - barritas; i++) {
		printf(" ");
	}
	printf("] %d / %d HP\n", player.health, player.maxHealth);

	printf("[");

	int playerMaxStamina = player.maxStamina;
	int playerActualStamina = player.stamina;
	int barritas2Player;
	barritas2Player = ((playerActualStamina * 10) /playerMaxStamina);

	for (int i = 0; i < barritas2Player; i++) {
		printf(">");
	}

	for (int i = 0; i < 10 - barritas2Player; i++) {
		printf(" ");
	}
	printf("] %d / %d Stamina\n\n", player.stamina, player.maxStamina);
	printf("Potions %d / 3\n\n", player.potions);
	printf("__________________________________________________________________________\n\n");
	printf("A -> Attack\n");
	printf("D -> Defend\n");
	printf("R -> Rest\n");
	printf("P -> Potion\n\n");
	printf("Enter your action:");


	char userSel;
	int userSeal2;
	//printf("Cuanto damage le quieres quitar\n");
	scanf_s(" %c", &userSel);
	printf("\n\n");

	switch (userSel) {
	case 'A':
	case 'a':
		printf("Enter your attack value (Max %d)", player.stamina);
		 //para hacer feliz a mariona
		scanf_s("%d", &userSeal2);
		printf("You strike the enemy with more force! The enemy receives %d damage\n\n", userSeal2);
		printf("Enter a character to update the fight... ");
		
		//IF (ENEMIGO MUERTO) --> The minion is no more :c 
		//scanf_s("%c", &nom);
		break;
	case 'D':
	case 'd':

		break;
	case 'R':
	case 'r':

		break;
	case 'P':
	case 'p':

		break;

	}

	if (player.health <= 0) {
		state = GameState::GAMEOVER;
		gameOver = true;
		GameOver();
	}
}

void MainManager::OpenChest(Chest chest) {
	printf("------ CHEST ------\n\n");
	printf(" > You open the chest: \n");
	printf("	> %d gold!\n", chest.gold);
	printf("	> The Chest contains Gear!\n");
	printf("			> %s\n", chest.gear.name);
	printf("				- Gold: %d\n", chest.gear.gold);
	printf("				- HP: %d\n", chest.gear.healthMod);
	printf("				- Stamina: %d\n", chest.gear.staminaMod);
	printf("				- Agility: %d\n", chest.gear.agilityMod);
	if (chest.containsPotion == true) {
		printf("	> The Chest contains a potion!\n");
		if (player.potions == 3) {
			printf("		- You already have max potions\n");
		}
		else {
			player.potions++;
		}
	}

	player.maxHealth += chest.gear.healthMod;
	if (player.health > player.maxHealth) {
		player.health = player.maxHealth;
	}

	player.maxStamina += chest.gear.staminaMod;
	if (player.stamina > player.maxStamina) {
		player.stamina = player.maxStamina;
	}

	player.maxAgility += chest.gear.agilityMod;
	if (player.agility > player.maxAgility) {
		player.agility = player.maxAgility;
	}

	char userSel;
	printf("____________________________________________________\n\n");
	printf(" > Enter a character to continue...\n");
	scanf_s(" &c", &userSel);
	state = GameState::DUNGEON;
	Dungeon();

}

void MainManager::GameOver() {
	printf("\n\n\nYOU ARE DEAD. NO ONE WILL REMEMBER YOU. YOU WILL GO TO HELL WITH PIPO.\n\n\n");
}
 
void MainManager::Boss() {

}

