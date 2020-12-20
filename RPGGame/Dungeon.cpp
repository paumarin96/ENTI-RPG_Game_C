#include "Dungeon.h"
#define MAP_SIZE 5



void CreateDungeon() {


}

void RenderDungeon() {

	char map[MAP_SIZE][MAP_SIZE] = { {' ', ' ', ' ',' ',' '},
								   {' ', ' ', ' ',' ',' '},
								   {' ', ' ', ' ',' ',' '},
								   {' ', ' ', ' ',' ',' '},
								   {' ', ' ', ' ',' ',' '}, };


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
			printf("| %c |", map[i][j]);
		}
		printf("\n");

		for (int j = 0; j < MAP_SIZE; j++) {
			printf("|___|");
		}
		printf("\n");
	}
	

	

}