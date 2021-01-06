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

			Boss(radev);
			break;
		case WIN:
			break;
		case TITLE:
			TitleScreen();
			break;
		case STORY:
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
	system("CLS");
	if(deadEnemies == 7 && openChests == 2){
		Boss(radev);
	}
	char userAction = ' ';
	
	bool firstTime;
	printf(R"EOF(
		________                                            
		\______ \  __ __  ____    ____   ____  ____   ____  
		 |    |  \|  |  \/    \  / ___\_/ __ \/  _ \ /    \ 
		 |____`   \  |  /   |  \/ /_/  >  ___(  <_> )   |  \
		/_______  /____/|___|  /\___  / \___  >____/|___|  /
		        \/           \//_____/      \/           \/   

)EOF");
	printf("");
	printf("	____________________________________________________________________\n\n");
	printf("		E -> Enemy    |   P -> Player   |    C -> Chest\n\n");
	printf("				Health: %d / %d\n", player.health, player.maxHealth);
	printf("				Potions: %d / 3\n", player.potions);
	printf("				Moves: %d / %d\n", player.agility, player.maxAgility);
	//printf("Position: %d, %d\n", player.pos.x, player.pos.y);
	if (player.agility == player.maxAgility) {
		firstTime = true;
	}
	else {

		firstTime = false;
	}
	
	//printf("Position: %d, %d \n", player.pos.x, player.pos.y);
	CreateDungeon(player, enemies, chests, firstTime);

	printf("			_______________________________\n\n");
	printf("				W A S D -> Move\n");
	printf("				P -> Potion\n\n");

	userAction = 'g';
	char basura;
	if (actionIsValid == false) {
		printf("Your action was invalid. \n");
	}
		printf("Enter your action: \n\n");
		scanf_s(" %c", &userAction);
		
		if (userAction == 'A' || userAction == 'a' || userAction == 'W' || userAction == 'w' || userAction == 's' || userAction == 'S' || userAction == 'd' || userAction == 'D' || userAction == 'R') {
			actionIsValid = true;
		}
		else {
			actionIsValid = false;
			Dungeon();
		}

		bool canDegradeAgility = false;

		switch (userAction) {
		case 'P':
		case 'p':
			printf("You consume a potion!\n");
			player.ConsumePotion();

			break;
		case 'W':
		case 'w':
			if (player.pos.x - 1 >= 0 && player.pos.x - 1 <= 4) {
				player.pos.x = player.pos.x - 1;
				canDegradeAgility = true;
			}

			break;
		case 'A':
		case 'a':
			if (player.pos.y - 1 >= 0 && player.pos.y - 1 <= 4) {
				player.pos.y = player.pos.y - 1;
				canDegradeAgility = true;
			}
	
			break;
		case 'S':
		case 's':
				if (player.pos.x + 1 >= 0 && player.pos.x + 1 <= 4) {
					player.pos.x = player.pos.x + 1;
					canDegradeAgility = true;
				}
		
			break;
		case 'D':
		case 'd':
				if (player.pos.y + 1 >= 0 && player.pos.y + 1 <= 4) {
					player.pos.y = player.pos.y + 1;
					canDegradeAgility = true;

				}
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
					break;
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
			if (userAction == 'A' || userAction == 'a' || userAction == 'W' || userAction == 'w' || userAction == 's' || userAction == 'S' || userAction == 'd' || userAction == 'D') {
				if(canDegradeAgility)
				DegradeAgility();
			}
		}


	for (int i = 0; i < 2; i++) {
		if (player.pos.x == chests[i].pos.x && player.pos.y == chests[i].pos.y) {

			if (chests[i].isLooted == false) {
			
				chests[i].isLooted = true;
				

				OpenChest(chests[i]);
				break;

			}
		}
	}


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
	printf(R"EOF(
			 __________         __    __  .__          
			\______   \_____ _/  |__/  |_|  |   ____  
			 |    |  _/\__  \\   __\   __\  | _/ __ \ 
			 |    |   \ / __ \|  |  |  | |  |_\  ___/ 
			 |______  /(____  /__|  |__| |____/\___  >
			        \/      \/                     \/ )EOF");
	printf("\n\n");
	printf("					-- Enemy --\n");
	printf(R"EOF(
					   '\\-//`    
					    (o o)     
					ooO--[_]--Ooo)EOF");
	printf("\n\n\n");
	printf("				[");

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
	
	printf("				[");

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
	printf("				---------------------------\n\n");
	printf("					-- Player --\n\n");
	printf("				[");
	
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

	printf("				[");

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
	printf("				Potions %d / 3\n\n", player.potions);

	printf("__________________________________________________________________________\n\n\n");
	printf("A -> Attack\n");
	printf("D -> Defend\n");
	printf("R -> Rest\n");
	printf("P -> Potion\n\n");
	if (actionIsValid == false) {
		printf("Your action was invalid. \n");
	}
	printf("Enter your action: ");


	char userSel;
	int userSeal2; //para hacer feliz a mariona
	char userSeal3;
	char userSeal4;
	scanf_s(" %c", &userSel);
	if (userSel == 'A' || userSel == 'a' || userSel == 'D' || userSel == 'd' || userSel == 'R' || userSel == 'r' || userSel == 'P' || userSel == 'p') {
		actionIsValid = true;
	}
	else {
		actionIsValid = false;
		Battle(enemy);
	}

	switch (userSel) {
	case 'A':
	case 'a':
		if (player.stamina == 0) {
			printf("You can't attack if you have 0 stamina, you little dingus\n");
			printf("Enter a character to update the fight...\n ");
			scanf_s(" %c", &userSeal3);
			Battle(enemy);
			break;
		}
		printf("Enter your attack value (Max %d): \n", player.stamina);

		scanf_s("%d", &userSeal2);	 
		if (userSeal2 > player.stamina) {
			printf("You can't attack with more than your current stamina!");
			printf("\nEnter a character to update the fight... ");
			scanf_s(" %c", &userSeal3);
			Battle(enemy);
			break;
		}
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
				player.stamina = player.maxStamina;
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
	state = GameState::CHEST;
	system("CLS");
	openChests++;
	printf(R"EOF(
			_________ .__                     __   
			\_   ___ \|  |__   ____   _______/  |_ 
			/    \  \/|  |  \_/ __ \ /  ___/\   __\
			\     \___|   Y  \  ___/ \___ \  |  |  
			 \______  /___|  /\___  >____  > |__|  
			        \/     \/     \/     \/        
)EOF");
	printf("\n\n		> You open the chest: \n");
	printf("			> %d gold!\n", chest.gold);
	printf("			> The Chest contains Gear!\n");
	printf("				> %s\n", chest.gear.name);
	if (chest.gear.gold != 0) {
		printf("						- Gold: %d\n", chest.gear.gold);
	}
	if (chest.gear.healthMod != 0) {
		printf("						- HP: %d\n", chest.gear.healthMod);
	}
	if (chest.gear.staminaMod != 0) {
		printf("						- Stamina: %d\n", chest.gear.staminaMod);

	}
	if (chest.gear.agilityMod != 0) {
		printf("						- Agility: %d\n", chest.gear.agilityMod);

	}

	if (chest.containsPotion == true) {
		printf("\n			> The Chest contains a potion!\n");
		if (player.potions == 3) {
			printf("				- You already have max potions\n");
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

	char userSeal3; //Esta variable está maldita. Se bugeaba cuando se llama userSelection y con userSeal3 funciona xD.
	
	printf("_______________________________________________________________________________________\n\n");
	printf("\nEnter a character to go to the dungeon... ");
	scanf_s(" %c", &userSeal3);


	state = GameState::DUNGEON;
	

}

void MainManager::GameOver() {

	system("CLS");
	radevLooseImage();


	printf("\n\n\n		YOU ARE DEAD. NO ONE WILL REMEMBER YOU. RADEV SENDS YOU TO HELL WITH PIPO.\n\n\n");
	printf("					   F in the chat\n\n\n");
	printf("					   Points: %d\n\n\n\n\n\n", player.gold);
	gameOver = true;
	char userSeal68;
	printf("\nEnter a character to exit the game... ");
	scanf_s(" %c", &userSeal68);

}
 
void MainManager::Boss(Enemy &radev) {

	system("CLS");
	radevBossImage();
	printf("\n\n");
	printf(R"EOF(
	 __________.__              .__    __________                     
	\_   _____/|__| ____ _____  |  |   \______   \ ____  ______ ______
	 |    __)  |  |/    \\__  \ |  |    |    |  _//  _ \/  ___//  ___/
	 |     \   |  |   |  \/ __ \|  |__  |    |   (  <_> )___ \ \___ \ 
	 \___  /   |__|___|  (____  /____/  |______  /\____/____  >____  >
	     \/            \/     \/               \/           \/     \/ 
)EOF");

	printf("\n\n");
	printf("			-- RADEV --\n");
	printf("			[");

	if (player.stamina > player.maxStamina) {
		player.stamina = player.maxStamina;
	}

	int enemyMaxHealth = radev.maxHealth;
	int enemyActualHealth = radev.health;
	int barritas;
	barritas = ((enemyActualHealth * 10) / enemyMaxHealth);

	for (int i = 0; i < barritas; i++) {
		printf("=");
	}

	for (int i = 0; i < 10 - barritas; i++) {
		printf(" ");
	}
	printf("] %d/%d HP\n", radev.health, radev.maxHealth);

	printf("			[");

	int enemyMaxStamina = radev.maxStamina;
	int enemyActualStamina = radev.stamina;
	int barritas2;
	barritas2 = ((enemyActualStamina * 10) / enemyMaxStamina);

	for (int i = 0; i < barritas2; i++) {
		printf(">");
	}

	for (int i = 0; i < 10 - barritas2; i++) {
		printf(" ");
	}
	printf("] %d/%d Stamina\n\n", radev.stamina, radev.maxStamina);
	printf("			---------------------------\n\n");
	printf("			-- Player --\n");
	printf("			[");

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

	printf("			[");

	int playerMaxStamina = player.maxStamina;
	int playerActualStamina = player.stamina;
	int barritas2Player;
	barritas2Player = ((playerActualStamina * 10) / playerMaxStamina);

	for (int i = 0; i < barritas2Player; i++) {
		printf(">");
	}

	for (int i = 0; i < 10 - barritas2Player; i++) {
		printf(" ");
	}
	printf("] %d / %d Stamina\n\n", player.stamina, player.maxStamina);
	printf("			Potions %d / 3\n\n", player.potions);
	printf("__________________________________________________________________________\n\n");
	printf("A -> Attack\n");
	printf("D -> Defend\n");
	printf("R -> Rest\n");
	printf("P -> Potion\n\n");

	if (actionIsValid == false) {
		printf("Your action was invalid. \n");
	}
	printf("Enter your action: ");


	char userSel;
	int userSeal2; //para hacer feliz a mariona
	char userSeal3;
	char userSeal4;
	scanf_s(" %c", &userSel);
	if (userSel == 'A' || userSel == 'a' || userSel == 'D' || userSel == 'd' || userSel == 'R' || userSel == 'r' || userSel == 'P' || userSel == 'p') {
		actionIsValid = true;
	}
	else {
		actionIsValid = false;
		Battle(radev);
	}
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
	switch (EnemyAI(radev)) {
	case 'A':
	case 'a':

		attackDamage = Percentage(radev.maxStamina, 20) + Percentage(radev.stamina - Percentage(radev.maxStamina, 20), rand() % 101);

		if (userSel == 'a' || userSel == 'A') {
			if (attackDamage > userSeal2) {
				printf("Radev is more powerful! You recieve %d damage.\n\n", attackDamage);
				player.DamagePlayer(attackDamage);
				player.stamina -= userSeal2;
				radev.stamina -= attackDamage;
			}
			else if (userSeal2 >= attackDamage) {
				printf("In an unexpected turn of events, you strike Radev! He receives %d damage.\n\n", userSeal2);
				radev.health -= userSeal2;
				player.stamina -= userSeal2;
				radev.stamina -= attackDamage;
			}
		}
		else if (userSel == 'd' || userSel == 'D') {
			printf("You defend, but Radev doesn't let you catch a breath so you take %d damage.\n\n", Percentage(attackDamage, 25));
			radev.stamina -= attackDamage;
			player.DamagePlayer(Percentage(attackDamage, 25));
			player.stamina += Percentage(player.maxStamina, 25);

		}
		else if (userSel == 'r' || userSel == 'R') {
			printf("You are sleeping in class when Radev asks you a question, striking for %d damage.\n\n", attackDamage);
			radev.stamina -= attackDamage;
			player.DamagePlayer(attackDamage);
			player.stamina = player.maxStamina;
		}
		break;
	case 'D':
	case 'd':
		if (userSel == 'a' || userSel == 'A') {
			printf("You strike Radev! But Edu comes and protects him, striking for %d damage.\n\n", Percentage(userSeal2, 25));
			radev.health -= Percentage(userSeal2, 25);
			radev.stamina += Percentage(radev.maxStamina, 25);
			player.stamina -= userSeal2;
		}
		else if (userSel == 'd' || userSel == 'D') {
			printf("Both you and Radev defend. Nobody gets hurt :c\n\n");
			radev.stamina += Percentage(radev.maxStamina, 25);
			player.stamina += Percentage(player.maxStamina, 25);
		}
		else if (userSel == 'r' || userSel == 'R') {
			printf("You sleep in class while Edu is defending Radev.\n\n");
			radev.stamina += Percentage(radev.maxStamina, 25);
			player.stamina += player.maxStamina;
		}
		break;
	case 'R':
	case 'r':
		if (userSel == 'a' || userSel == 'A') {
			printf("You strike Radev while he plays his PS5, striking for %d damage.\n\n", userSeal2);
			radev.health -= userSeal2;
			radev.stamina = radev.maxStamina;
			player.stamina -= userSeal2;
		}
		else if (userSel == 'd' || userSel == 'D') {
			printf("You defend while Radev is playing Demon Souls! It seems ready to strike!\n\n");
			radev.stamina = radev.maxStamina;
			player.stamina += Percentage(player.maxStamina, 25);
		}
		else if (userSel == 'r' || userSel == 'R') {
			printf("Both of you rest a little bit and play Valorant together!\n\n");
			player.stamina = player.maxStamina;
			radev.stamina = radev.maxStamina;
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
	if (radev.health <= 0) {
		system("CLS");
		printf("You have defeated Radev! That didn't seem possible to be honest.\n");
		
		state = GameState::WIN;
		Win();

	}
}


void MainManager::Win() {
	
	system("CLS");
	printf("\n\n\n		You have defeated Radev! That didn't seem possible to be honest.\n\n\n");
	printf("					Points: %d\n\n\n\n\n\n", player.gold);
	char userSeal69;
	printf("\nEnter a character to exit the game... ");
	scanf_s(" %c", &userSeal69);
	gameOver = true;
}


void MainManager::TitleScreen() {

		printf(R"EOF(
	 ____    ____  ___      ___ __ __  __  _____     _____  __ __  ____   __ __ 
	|    \  /    ||   \    /  _]  |  ||  |/ ___/    |     ||  |  ||    \ |  |  |
	|  D  )|  o  ||    \  /  [_|  |  ||_ (   \_     |   __||  |  ||  D  )|  |  |
	|    / |     ||  D  ||    _]  |  |  \|\__  |    |  |_  |  |  ||    / |  ~  |
	|    \ |  _  ||     ||   [_|  :  |    /  \ |    |   _] |  :  ||    \ |___, |
	|  .  \|  |  ||     ||     |\   /     \    |    |  |   |     ||  .  \|     |
	|__|\_||__|__||_____||_____| \_/       \___|    |__|    \__,_||__|\_||____/ 
																				)EOF");
	char userSeal0;
	printf("\n\n\n				      Welcome to Radev's Fury.\n");
	printf("\n			     Adjust the screen for the best experience.");
	printf("\n\n				Made by: Pau Marin & Mariona Barranco");
	printf("\n					   ENTI: CDI 2021");
	printf("\n\n\n				     Enter a character to start.\n");
	scanf_s(" %c", &userSeal0);
	state = GameState::DUNGEON;
	Dungeon();
}

void MainManager::Story() {

}

int Percentage(int percentage, int number) {
	int result = (int)(((float)number * (float)percentage)/100.f);
	return result;
}