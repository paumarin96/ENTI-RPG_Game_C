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

	Chest chests[2];
	
	//spawnear enemigos muertos

	//Chest chests[];
	bool gameOver = false;
	GameState state;

	void Start() { //Executes one time
		//Generate world
		InitializePlayer(player);
		int a = rand() % 3;
		for (int i = 0; i < 7; i++) {
			InitializeEnemy(enemies[i]);
			
		}
		for (int i = 0; i <= a; i++) {
			if (i == 0) {
				continue;
			}
			enemies[i].isDead = true;
		}
		for (int i = 0; i < 2; i++) {
			chests[i].InitializeChest();
		}
		state = GameState::DUNGEON;
		Play();
	
	}

	void Play(); //Executes every frame

	void DegradeAgility();

	void Dungeon();

	void Battle();
	
	void Chest();

	void GameOver();

	void Boss();
	
	
};

