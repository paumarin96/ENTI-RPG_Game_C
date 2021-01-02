#pragma once
#include "Dungeon.h"
#include "Enemy.h"
#include "Player.h"
#include <stdlib.h>
#include "Chest.h"
enum GameState { DUNGEON, BATTLE, CHEST, GAMEOVER, BOSS };

struct MainManager {
	Player player;
	
	Enemy enemies[7];
	int deadEnemies; 
	Chest chests[2];
	
	//spawnear enemigos muertos

	//Chest chests[];
	bool gameOver = false;
	GameState state;

	void AddEnemies() {

		int j = 0;
		do {
			Enemy generatedEnemy;
			generatedEnemy = GenerateEnemy();
			bool enemyExists = false;
			for (int i = 0; i < 7; i++) {
				if (enemies[i].pos.x == generatedEnemy.pos.x && enemies[i].pos.y == generatedEnemy.pos.y || player.pos.x == generatedEnemy.pos.x && player.pos.y == generatedEnemy.pos.y) {
					enemyExists = true;
				}
			}
			for (int l = 0; l < 2; l++) {
				if (chests[l].pos.x == generatedEnemy.pos.x && chests[l].pos.y == generatedEnemy.pos.y) {
					enemyExists = true;
				}
			}
			if (!enemyExists) {
				enemies[j] = generatedEnemy;
				j++;
			}
		} while (j < 7);
	}

	void AddChest() {

		int i = 0;
		do {
			Chest generatedChest;
			generatedChest = generateChest();
			bool chestExists = false;
			for (int l = 0; l < 2; l++) {
				if (chests[l].pos.x == generatedChest.pos.x && chests[l].pos.y == generatedChest.pos.y || player.pos.x == generatedChest.pos.x && player.pos.y == generatedChest.pos.y) {
					chestExists = true;
				}
			}
			if (!chestExists) {
				chests[i] = generatedChest;
				i++;
			}
		} while (i < 2);
	}

	void Start() { //Executes one time
		//Generate world
		InitializePlayer(player);
		int a = rand() % 3;
		deadEnemies = a;
		AddChest();
		AddEnemies(); 
	
		for (int i = 0; i <= a; i++) {
			if (i == 0) {
				continue;
			}
			enemies[i].isDead = true;
		}
		state = GameState::DUNGEON;
		Play();
	
	}

	void Play(); //Executes every frame

	void DegradeAgility();

	void Dungeon();

	void Battle(Enemy &enemy);
	
	void OpenChest(Chest chest);

	void GameOver();

	void Boss();
	
	
};

