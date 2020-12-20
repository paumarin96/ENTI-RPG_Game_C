#pragma once

struct MapPosition {
	int x;
	int y;
};

struct Item {
	char name[20];
	int gold;
	int healthMod;
	int staminaMod;
	int agilityMod;
};

struct Chest {
	int gold;
	bool isLooted;
	Item gear;
	bool containsPotion;
};