#pragma once
#include <vector>
#include <string>
#include <map>

class Board
{
public:
	Board();

	int initBoard(std::string player);

	void printScores(std::string player1, int score1, std::string player2, int score2);

	void printBoard();
	void updateBoard(const std::map<std::string, char> &player1, const std::map<std::string, char> &player2);

	bool isEmpty(int cell);

	bool hasWon(const std::map<std::string, char> &player1, const std::map<std::string, char> &player2);

	//Getters
	std::string getCurrentPlayer() { return m_currentPlayer; }

private:
	int getMove(const std::map<std::string, char> &player);

	std::vector<std::vector<std::string> > m_board;

	//Maybe have "previous player" to keep track to display the name when won
	std::string m_currentPlayer;

	int m_sizeOfBoard = 0;
};

