#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "types.h"

#include "Player.h"
#include "Dungeon.h"
#include "Enemy.h"

#include "MainManager.h"



int main() {
	

	srand(time(NULL));
	
	MainManager mm;
	mm.Start();

	return 0;

}