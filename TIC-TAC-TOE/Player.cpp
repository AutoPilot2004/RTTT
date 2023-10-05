#include "Player.h"
#include "Utils.h"

#include <iostream>

Player::Player(std::string color)
{
	m_color = color;
}

void Player::getPlayerInfo(Player *prevPlayer)
{
	static int numPlayer = 1;

	std::string playerName;
	char playerSymbol;

	std::cout << "Enter the name of player " << numPlayer++ << ": ";
	std::cin >> playerName;

	do {
		std::cout << "Enter symbol for " << playerName << ": ";
		std::cin >> playerSymbol;
		std::cin.ignore(1000, '\n');
	} while ((playerSymbol >= '0' && playerSymbol <= '9') || (prevPlayer != nullptr && playerSymbol == prevPlayer->getPlayer().begin()->second));

	m_player[m_color + playerName + PLAYER_COLOR_END] = playerSymbol;

	std::cout << std::endl;
}