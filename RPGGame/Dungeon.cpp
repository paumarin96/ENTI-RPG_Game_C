#include "Dungeon.h"
#define MAP_SIZE 5



void CreateDungeon(Player pl, Enemy enemies[], Chest chests[], bool firstTime) {
	char map[MAP_SIZE][MAP_SIZE] = { {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '}, };
	map[pl.pos.x][pl.pos.y] = 'P';

	for (int i = 0; i < 7; i++)	{
		if (enemies[i].isDead == false) {
			if (map[enemies[i].pos.x][enemies[i].pos.y] == ' ') {
				map[enemies[i].pos.x][enemies[i].pos.y] = 'E';
			} 
		}
	}

	for (int i = 0; i < 2; i++) {
	
		if (map[chests[i].pos.x][chests[i].pos.y] == ' ' && chests[i].isLooted == false) {
			map[chests[i].pos.x][chests[i].pos.y] = 'C';
		}
	}
	
	RenderDungeon(pl, map);
}

void RenderDungeon(Player pl, char theMap[][MAP_SIZE]) {

	for (int i = 0; i < MAP_SIZE; i++) {
		printf(" ___ ");
	}
	printf("\n");

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			printf("|   |");
		}
		printf("\n");

		for (int j = 0; j < MAP_SIZE; j++) {
			printf("| %c |", theMap[i][j]);
		}
		printf("\n");

		for (int j = 0; j < MAP_SIZE; j++) {
			printf("|___|");
		}
		printf("\n");
	}
	

	

}