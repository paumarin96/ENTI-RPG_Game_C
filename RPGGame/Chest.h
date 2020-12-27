#pragma once
#include "Items.h"
#include "types.h"
#include <time.h>





struct Chest {

	int gold;
	bool isLooted = false;
	Item gear;
	bool containsPotion = false;
	MapPosition pos;
	void InitializeChest() {
		int m = rand() % 21;
		gear = items[m];
		int casas[3] = { 1,2,3 };
		int micasa;
		micasa = casas[2];
		gold = (50 + rand() % 151);
		int num = rand() % 101;
		pos.x = rand() % 5;
		pos.y = rand() % 5;
		if (num <= 25) {
			containsPotion = true;
		}
	}
};