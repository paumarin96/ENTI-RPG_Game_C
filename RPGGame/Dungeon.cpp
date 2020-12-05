#include "Dungeon.h"
#define MAP_SIZE 5;


void CreateDungeon() {


}

void RenderDungeon(char map[][5]) {
	for (int i = 0; i < 5; i++) {
		printf(" ____ ");

		for (int j = 0; j < 5; j++) {
			
			printf("|    | ");
			printf("| %c  |", map[i][j]);
			printf("|____|");
			//printf("%c", map[i][j]);

		}
		printf("\n");
	}
	

}