#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"
#define MAP_SIZE 5

//Here the map gets randomly generated.
void CreateDungeon(Player pl, Enemy enemies[7], Chest chests[2], bool firstTime);

//The map gets rendered.
void RenderDungeon(Player pl, char theMap[][MAP_SIZE]);
