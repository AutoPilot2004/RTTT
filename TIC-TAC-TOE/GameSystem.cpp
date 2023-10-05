#include "GameSystem.h"
#include <iostream>

GameSystem::GameSystem()
{
	//empty
}

GameSystem::~GameSystem()
{
	delete m_player1;
	delete m_player2;
}

void GameSystem::playGame()
{
	std::cout << "*** WELCOME TO TIC-TAC-TOE ***\n\n";

	m_player1->getPlayerInfo();
	m_player2->getPlayerInfo(m_player1);

	bool isDone;
	bool exit = false;

	int count;

	while (!exit) {
		isDone = false;
		count = 0;

		m_sizeOfBoard = m_board.initBoard(m_player1->getPlayer().begin()->first);

		while (!isDone && count < pow(m_sizeOfBoard, 2)) {
			system("CLS");
			m_board.printScores(m_player1->getPlayer().begin()->first, m_player1->getScore(), m_player2->getPlayer().begin()->first, m_player2->getScore());
			m_board.printBoard();
			m_board.updateBoard(m_player1->getPlayer(), m_player2->getPlayer());
			isDone = m_board.hasWon(m_player1->getPlayer(), m_player2->getPlayer());
			count++;
		}

		if (m_board.getCurrentPlayer() == m_player1->getPlayer().begin()->first && isDone)
			m_player1->addScore(1);
		else if (m_board.getCurrentPlayer() == m_player2->getPlayer().begin()->first && isDone)
			m_player2->addScore(1);

		system("CLS");
		m_board.printScores(m_player1->getPlayer().begin()->first, m_player1->getScore(), m_player2->getPlayer().begin()->first, m_player2->getScore());
		m_board.printBoard();

		if (isDone) {
			std::cout << m_board.getCurrentPlayer() << " has won!\n\n";
		}
		else {
			std::cout << "It's a tie!\n\n";
		}

		char tmp;

		do {
			std::cout << "Do you want to player again? (y/n): ";
			std::cin >> tmp;
		} while (tmp != 'n' && tmp != 'y' && tmp != 'N' && tmp != 'Y');

		if (tmp == 'n' || tmp == 'N') exit = true;
	}
}