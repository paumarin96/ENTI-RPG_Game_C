#include "Dungeon.h"
#define MAP_SIZE 5



void CreateDungeon(Player pl, Enemy enemies[7], Chest chests[2], bool firstTime) {
	char map[MAP_SIZE][MAP_SIZE] = { {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '},
									   {' ', ' ', ' ',' ',' '}, };
	map[pl.pos.y][pl.pos.x] = 'P';

	for (int i = 0; i < 7; i++)	{
		//printf(" %d: Enemy inicial Pos: %d, %d\n", i, enemies[i].pos.x, enemies[i].pos.y);
		if (enemies[i].isDead == false) {
			if (map[enemies[i].pos.x][enemies[i].pos.y] == ' ') {
				map[enemies[i].pos.x][enemies[i].pos.y] = 'E';
			//printf(" %d: Enemy Pos: %d, %d\n", i, enemies[i].pos.x, enemies[i].pos.y);

			} 
			else if (firstTime){
				while (true) {
					enemies[i].pos.x = rand() % 5;
					enemies[i].pos.y = rand() % 5;
					if (map[enemies[i].pos.x][enemies[i].pos.y] == ' ') {
						map[enemies[i].pos.x][enemies[i].pos.y] = 'E';
						//printf(" %d: 2Enemy Pos: %d, %d\n", i, enemies[i].pos.x, enemies[i].pos.y);
				
						break;
					}
				}
			}
	
		}
	
	}
	for (int i = 0; i < 2; i++) {
		if (map[chests[i].pos.x][chests[i].pos.y] == ' ') {
			map[chests[i].pos.x][chests[i].pos.y] = 'C';
			//printf(" %d: Enemy Pos: %d, %d\n", i, enemies[i].pos.x, enemies[i].pos.y);
		}
		else if(firstTime) {
			while (true) {
				chests[i].pos.x = rand() % 5;
				chests[i].pos.y = rand() % 5;
				if (map[chests[i].pos.x][chests[i].pos.y] == ' ') {
					map[chests[i].pos.x][chests[i].pos.y] = 'C';
					//printf(" %d: 2Enemy Pos: %d, %d\n", i, enemies[i].pos.x, enemies[i].pos.y);

					break;
				}
			}
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