#pragma once
#include "Items.h"
#include "types.h"
#include <time.h>
#include <stdlib.h>
#include "Items.h"
struct Chest {
	int gold;
	bool isLooted = false;
	Item gear;
	bool containsPotion = false;
	MapPosition pos;
};

Chest generateChest();