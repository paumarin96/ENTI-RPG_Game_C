#pragma once
#include "Dungeon.h"
#include "Enemy.h"
#include "Player.h"
#include "types.h"
#include <stdlib.h>
enum GameState { DUNGEON, BATTLE, CHEST, GAMEOVER, BOSS };

struct MainManager {
	Player player;
	Enemy enemies[3];
	//Chest chests[];
	bool gameOver = false;
	GameState state;

	void Start() { //Executes one time
		//Generate world
		InitializePlayer(player);
	
		state = GameState::DUNGEON;
		Play();
		//Dungeon();
	}

	void Play(); //Executes every frame

	void Dungeon();

	void Battle();
	
	void Chest();

	void GameOver();

	void Boss();

};

