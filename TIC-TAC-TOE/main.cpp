#include <iostream>
#include <conio.h>

#include "GameSystem.h"
#include "Player.h"

int main()
{
	GameSystem game;

	game.playGame();

	printf("\n\nPress any key to quit: ");
	char g = _getch();

	return 0;
}