#pragma once
#include <string>

#include "Player.h"
#include "Board.h"
#include "Utils.h"

class GameSystem
{
public:
	GameSystem();
	~GameSystem();

	void playGame();

private:
	Player* m_player1 = new Player(PLAYER_1_COLOR_START);
	Player* m_player2 = new Player(PLAYER_2_COLOR_START);

	Board m_board;

	int m_sizeOfBoard = 0;
};

