#include "Chest.h"





const Item RichardsHatred{
	/*Item name:*/ "Richard’s Hatred",
	/*Gold:*/ 200,
	/*HP*/ -20,
	/*Stamina*/ 40,
	/*Agility*/ -1
};

const Item SwiftBoots{
	/*Item name:*/ "Swift Boots",
	/*Gold:*/ 10,
	/*HP*/ -10,
	/*Stamina*/ -5,
	/*Agility*/ 1
};

const Item WhitePowder{
	/*Item name:*/ "White Powder",
	/*Gold:*/ 150,
	/*HP*/ -20,
	/*Stamina*/ 20,
	/*Agility*/ 1
};

const Item RadevMug{
	/*Item name:*/ "Radev’s Mug",
	/*Gold:*/ -300,
	/*HP*/ -20,
	/*Stamina*/ -40,
	/*Agility*/ -1
};

const Item RavenFeather{
	/*Item name:*/ "Raven Feather",
	/*Gold:*/ 50,
	/*HP*/ -10,
	/*Stamina*/ 0,
	/*Agility*/ 2
};

const Item RedMushroom{
	/*Item name:*/ "Red Mushroom",
	/*Gold:*/ 170,
	/*HP*/ 30,
	/*Stamina*/ 0,
	/*Agility*/ 0
};

const Item UglyFacemask{
	/*Item name:*/ "Ugly Facemask",
	/*Gold:*/ 10,
	/*HP*/ 5,
	/*Stamina*/ 0,
	/*Agility*/ 0
};

const Item BrokenShield{
	/*Item name:*/ "Broken Shield",
	/*Gold:*/ 25,
	/*HP*/ 10,
	/*Stamina*/ 0,
	/*Agility*/ 0
};

const Item GreenMushroom{
	/*Item name:*/ "Green Mushroom",
	/*Gold:*/ -50,
	/*HP*/ 0,
	/*Stamina*/ -10,
	/*Agility*/ 0
};

const Item NaughtyBook{
	/*Item name:*/ "Naughty Book",
	/*Gold:*/ 69,
	/*HP*/ 0,
	/*Stamina*/ 7,
	/*Agility*/ 0
};

const Item IceCube{
	/*Item name:*/ "Ice Cube",
	/*Gold:*/ 10,
	/*HP*/ 21,
	/*Stamina*/ 2,
	/*Agility*/ -1
};

const Item Candy{
	/*Item name:*/ "Candy",
	/*Gold:*/ -25,
	/*HP*/ -5,
	/*Stamina*/ 5,
	/*Agility*/ 0
};

const Item EnergyDrink{
	/*Item name:*/ "Energy Drink",
	/*Gold:*/ -8,
	/*HP*/ 5,
	/*Stamina*/ 15,
	/*Agility*/ 1
};

const Item Horchata{
	/*Item name:*/ "Horchata",
	/*Gold:*/ 40,
	/*HP*/ 10,
	/*Stamina*/ 2,
	/*Agility*/ -1
};

const Item CupCake{
	/*Item name:*/ "Cup Cake",
	/*Gold:*/ 10,
	/*HP*/ 15,
	/*Stamina*/ 9,
	/*Agility*/ -1
};

const Item Yogurt{
	/*Item name:*/ "Yogurt",
	/*Gold:*/ 8,
	/*HP*/ 33,
	/*Stamina*/ 21,
	/*Agility*/ 2
};



const Item Ensaimada{
	/*Item name:*/ "Ensaimada",
	/*Gold:*/ -12,
	/*HP*/ -5,
	/*Stamina*/ 0,
	/*Agility*/ -1
};

const Item HappySeal{
	/*Item name:*/ "Happy Seal",
	/*Gold:*/ 300,
	/*HP*/ 80,
	/*Stamina*/ 40,
	/*Agility*/ 2
};

const Item MoonStone{
	/*Item name:*/ "Moon Stone",
	/*Gold:*/ 13,
	/*HP*/ -5,
	/*Stamina*/ 18,
	/*Agility*/ -1
};


Item items[19] = { RichardsHatred, SwiftBoots, WhitePowder, RadevMug, RavenFeather, RedMushroom, UglyFacemask, BrokenShield, GreenMushroom, NaughtyBook, IceCube, Candy, EnergyDrink, Horchata, CupCake, Yogurt, Ensaimada, HappySeal, MoonStone };

Chest generateChest() {
	Chest chest;
	int m = rand() % 20;
	chest.gear = items[m];
	chest.gold = (50 + rand() % 151);
	int num = rand() % 101;
	chest.pos.x = rand() % 5;
	chest.pos.y = rand() % 5;
	if (num <= 25) {
		chest.containsPotion = true;
	}

	return chest;
}