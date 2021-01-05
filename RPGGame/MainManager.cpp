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
	bool actionIsValid = false;
	
		printf("Enter your action: \n\n");
		scanf_s(" %c", &userAction);

		switch (userAction) {
		case 'P':
		case 'p':
			printf("You consume a potion!\n");
			player.ConsumePotion();

			break;
		case 'W':
		case 'w':
			if (player.position(player.pos.x - 1, player.pos.y))
			

			break;
		case 'A':
		case 'a':
			if (player.position(player.pos.x, player.pos.y - 1))

	
			break;
		case 'S':
		case 's':
			if (player.position(player.pos.x + 1, player.pos.y))
	
		
			break;
		case 'D':
		case 'd':
			if (player.position(player.pos.x, player.pos.y + 1))
	
		
			break;

		}
		bool isThereEnemy = false;
		for (int i = 0; i < 7; i++) {
			if (player.pos.x == enemies[i].pos.x && player.pos.y == enemies[i].pos.y) {

				if (enemies[i].isDead == false) {
					isThereEnemy = true;
					system("CLS");
					state = GameState::BATTLE;
					Battle(enemies[i]);
				
				}
				else {
				
					isThereEnemy = false;
				}
			}
			else {
			
				isThereEnemy = false;
			}

		}
		if (!isThereEnemy) {
			DegradeAgility();
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

char EnemyAI(Enemy enemy) {

	if (enemy.health < Percentage(enemy.maxHealth, 30) && enemy.stamina < Percentage(enemy.maxStamina, 30)) {
		return 'D';
	}
	else if (enemy.stamina < Percentage(enemy.maxStamina, 20)) {
		return 'R';
	}
	else {
		return 'A';
	}
}
void MainManager::Battle(Enemy &enemy) {
	system("CLS");
	printf("------ COMBAT ------\n\n");
	printf("-- Enemy --\n");
	printf("[");
	
	if (player.stamina > player.maxStamina) {
		player.stamina = player.maxStamina;
	}

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

	for (int i = 0; i < 10 - barritasPlayer; i++) {
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
	printf("Enter your action: ");


	char userSel;
	int userSeal2; //para hacer feliz a mariona
	char userSeal3;
	char userSeal4;
	scanf_s(" %c", &userSel);
	printf("\n\n");

	switch (userSel) {
	case 'A':
	case 'a':
		printf("Enter your attack value (Max %d): \n", player.stamina);
		scanf_s("%d", &userSeal2);	 
		break;
	case 'D':
	case 'd':
		break;
	case 'R':
	case 'r':
		break;
	case 'P':
	case 'p':
		printf("You consume a potion!\n");
		player.ConsumePotion();
		break;

	}
	int attackDamage;
	switch (EnemyAI(enemy)) {
		case 'A':
		case 'a': 

			attackDamage = Percentage(enemy.maxStamina, 20) + Percentage(enemy.stamina - Percentage(enemy.maxStamina, 20), rand() % 101);

			if (userSel == 'a' || userSel == 'A') {
				if (attackDamage > userSeal2) {
					printf("The enemy strikes harder! You recieve %d damage.\n\n", attackDamage);
					player.DamagePlayer(attackDamage);
					player.stamina -= userSeal2;
					enemy.stamina -= attackDamage;
				}
				else if (userSeal2 >= attackDamage) {
					printf("You strike the enemy with more force! The enemy receives %d damage.\n\n", userSeal2);
					enemy.health -= userSeal2;
					player.stamina -= userSeal2;
					enemy.stamina -= attackDamage; 
				}
			}
			else if (userSel == 'd' || userSel == 'D') {
				printf("You defend the enemy blow, but receive %d damage.\n\n", Percentage(attackDamage,25));
				enemy.stamina -= attackDamage;
				player.DamagePlayer(Percentage(attackDamage, 25));
				player.stamina += Percentage(player.maxStamina, 25);

			}
			else if (userSel == 'r' || userSel == 'R') {
				printf("You rest when the enemy hits you, striking for %d damage.\n\n", attackDamage);
				enemy.stamina -= attackDamage;
				player.DamagePlayer(attackDamage);
				player.stamina = player.maxStamina;
			}
			break;
		case 'D':
		case 'd':
			if (userSel == 'a' || userSel == 'A') {
				printf("You strike the enemy! The enemy defends but receives %d damage.\n\n", Percentage(userSeal2, 25));
				enemy.health -= Percentage(userSeal2, 25);
				enemy.stamina += Percentage(enemy.maxStamina, 25);
				player.stamina -= userSeal2;
			}
			else if (userSel == 'd' || userSel == 'D') {
				printf("You and the enemy defend. Nobody gets hurt :c\n\n");
				enemy.stamina += Percentage(enemy.maxStamina, 25);
				player.stamina += Percentage(player.maxStamina, 25);
			}
			else if (userSel == 'r' || userSel == 'R') {
				printf("You rest while the enemy defends.\n\n");
				enemy.stamina += Percentage(enemy.maxStamina, 25);
				player.stamina += player.maxStamina;
			}
			break;
		case 'R':
		case 'r':
			if (userSel == 'a' || userSel == 'A') {
				printf("You strike the enemy! The enemy receives %d damage.\n\n", userSeal2);
				enemy.health -= userSeal2;
				enemy.stamina = enemy.maxStamina;
				player.stamina -= userSeal2;
			}
			else if (userSel == 'd' || userSel == 'D') {
				printf("You defend while the enemy catches a breath! It seems ready to strike!\n\n");
				enemy.stamina = enemy.maxStamina;
				player.stamina += Percentage(player.maxStamina, 25);
			}
			else if (userSel == 'r' || userSel == 'R') {
				printf("You rest while the enemy catches a breath! It seems ready to strike!\n\n");
				player.stamina += player.maxStamina;
				enemy.stamina = enemy.maxStamina;
			}
			break;
	}
	printf("\nEnter a character to update the fight... ");
	scanf_s(" %c", &userSeal3);

	if (player.health <= 0) {
		state = GameState::GAMEOVER;
		gameOver = true;
		GameOver();
	}
	if (enemy.health <= 0) {
		printf("You have defeated the enemy!\n");
		printf("\nEnter a character to go to the dungeon... ");

		enemy.isDead = true;
		deadEnemies++;
		scanf_s(" %c", &userSeal4);
		DegradeAgility();
		state = GameState::DUNGEON;
		Dungeon();
	}
}



void MainManager::OpenChest(Chest chest) {
	printf("------ CHEST ------\n\n");
	printf(" > You open the chest: \n");
	printf("	> %d gold!\n", chest.gold);
	printf("	> The Chest contains Gear!\n");
	printf("			> %s\n", chest.gear.name);
	if (chest.gear.gold != 0) {
		printf("				- Gold: %d\n", chest.gear.gold);
	}
	if (chest.gear.healthMod != 0) {
		printf("				- HP: %d\n", chest.gear.healthMod);
	}
	if (chest.gear.staminaMod != 0) {
		printf("				- Stamina: %d\n", chest.gear.staminaMod);

	}
	if (chest.gear.agilityMod != 0) {
		printf("				- Agility: %d\n", chest.gear.agilityMod);

	}

	if (chest.containsPotion == true) {
		printf("\n	> The Chest contains a potion!\n");
		if (player.potions == 3) {
			printf("		- You already have max potions\n");
		}
		else {
			player.potions++;
		}
	}
	player.gold += chest.gold + chest.gear.gold;
	if (player.gold <= 0) {
		player.gold = 0;
	}
	player.maxHealth += chest.gear.healthMod;
	if (player.health > player.maxHealth) {
		player.health = player.maxHealth;
	}
	if (player.health <= 0) {
		player.health = 0;
		state = GameState::GAMEOVER;
		GameOver();
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
	system("CLS");
	printf("\n\n\nYOU ARE DEAD. NO ONE WILL REMEMBER YOU. YOU WILL GO TO HELL WITH PIPO.\n\n\n");
	printf("						Points: %d\n", player.gold);
}
 
void MainManager::Boss() {

}


int Percentage(int percentage, int number) {
	int result = (int)(((float)number * (float)percentage)/100.f);
	return result;
}