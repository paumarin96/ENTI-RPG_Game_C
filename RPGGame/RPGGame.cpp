#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "types.h"

#include "Player.h"
#include "Dungeon.h"
#define MAP_SIZE 5;



int main() {
	

	srand(time(NULL));
	char map[][5] = { {'1', '2', '3','4','5'},
					   {'1', '2', '3','4','5'},
					   {'1', '2', '3','4','5'},
					   {'1', '2', '3','4','5'},
					   {'1', '2', '3','4','5'}, };

	const char *map2[][5][5] = { {" ____ ",  " ____ ",  " ____ ", " ____ ", " ____ "},
							  {"|    | ", "|    | ", "|    | ","|    | ","|    | "},
							  {"|    | ", "|    | ", "|    | ","|    | ","|    | "},
							  {"|    | ", "|    | ", "|    | ","|    | ","|    | "},
							  {"|____|",  "|____|",  "|____|", "|____|", "|____|"}, };
	Player player;
	InitializePlayer(player);

	bool gameRunning = true;
	printf("%s", map2); //hacer for para imprimir y provar, no funciona
	//RenderDungeon(map2);
	//while (gameRunning) {
	//	player.agility = 3;
	//	CreateDungeon(); //We create the map
	//	if (player.enemiesKilled >= 10) {
	//		//Radev boss battle
	//	}
	//	else {
	//		while (player.agility != 0) {
	//			RenderDungeon(map); //We render the map every step. 
	//			
	//				player.agility--;
	//		}
	//	}
	//	gameRunning = false;
	//}

	return 0;


}