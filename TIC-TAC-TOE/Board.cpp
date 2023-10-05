#include "Board.h"
#include "Utils.h"

#include <iostream>
#include <string>

Board::Board()
{
	//empty
}

int Board::initBoard(std::string player)
{
	bool isValid = false;

	while (!isValid) {
		std::cout << "Enter size of board: ";
		if (!(std::cin >> m_sizeOfBoard)) {
			std::cout << "Invalid input, try again!\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else if (m_sizeOfBoard < 2) {
			std::cout << "Too small, try again!\n";
		}
		else if (m_sizeOfBoard >= 10) {
			std::cout << "Too big, try again!\n";
		}
		else {
			isValid = true;
		}
	}

	m_board.resize(m_sizeOfBoard);

	for (int i = 0; i < m_board.size(); i++) {
		m_board[i].resize(m_sizeOfBoard);
	}

	for (int i = 0; i < m_sizeOfBoard; i++) {
		for (int j = 0; j < m_sizeOfBoard; j++) {
			m_board[i][j] =	std::to_string((i * m_sizeOfBoard) + (j % m_sizeOfBoard) + 1);
			//m_board[i][j] = ((i * sizeOfBoard) + (j % sizeOfBoard)) + 1 < 10 ? (std::to_string(((i * sizeOfBoard) + (j % sizeOfBoard)) + 1)).c_str()[0] : (std::to_string(((i * sizeOfBoard) + (j % sizeOfBoard)) + 1)).c_str()[1];
		}
	}

	m_currentPlayer = player;

	return m_sizeOfBoard;
}

void Board::printScores(std::string player1, int score1, std::string player2, int score2)
{
	printf("%s: %d, %s: %d\n\n", player1.c_str(), score1, player2.c_str(), score2);
}

void Board::printBoard()
{
	printf("   ");

	for (int i = 0; i < m_sizeOfBoard; i++) {
		printf(" | %d%d", 0, i + 1);
	}

	for (int i = 0; i < m_sizeOfBoard; i++) {

		printf("\n%s\n", std::string((m_sizeOfBoard * 5) + 4, '-').c_str());

		printf(" %d%d", 0,i + 1);

		for (int j = 0; j < m_sizeOfBoard; j++) {
			if (m_board[i][j] <= std::to_string(pow(m_sizeOfBoard, 2)) && m_board[i][j] >= "1") {
				printf(" | %2s", m_board[i][j].c_str());
			}
			else {
				printf(" |  %s", m_board[i][j].c_str());
			}
		}
	}

	printf("\n\n");
}

int Board::getMove(const std::map<std::string, char> &player)
{
	int cell;

	bool validInput;

	do {
		std::cout << player.begin()->first << " choose a cell: ";
		if (!(std::cin >> cell)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			validInput = false;
		}
		else validInput = true;
	} while (!validInput || !isEmpty(cell));

	return cell;
}

void Board::updateBoard(const std::map<std::string, char> &player1, const std::map<std::string, char> &player2)
{
	int cell;

	if (m_currentPlayer == player1.begin()->first) {
		cell = getMove(player1);
		m_board[(cell - 1) / m_sizeOfBoard][(cell - 1) % m_sizeOfBoard] = PLAYER_1_COLOR_START + player1.begin()->second + PLAYER_COLOR_END;
	}
	else if (m_currentPlayer == player2.begin()->first) {
		cell = getMove(player2);
		m_board[(cell - 1) / m_sizeOfBoard][(cell - 1) % m_sizeOfBoard] = PLAYER_2_COLOR_START + player2.begin()->second + PLAYER_COLOR_END;
	}
	else {
		m_currentPlayer = player1.begin()->first;
		cell = getMove(player1);
		m_board[(cell - 1) / m_sizeOfBoard][(cell - 1) % m_sizeOfBoard] = PLAYER_1_COLOR_START + player1.begin()->second + PLAYER_COLOR_END;
	}
}

bool Board::isEmpty(int cell)
{

	if (cell < 1 || cell > pow(m_sizeOfBoard, 2)) {
		return false;
	}

	std::string m_cell = m_board[(cell - 1) / m_sizeOfBoard][(cell - 1) % m_sizeOfBoard];

	if (m_cell < "1" || m_cell > "9") {
		return false;
	}

	return true;
}

bool Board::hasWon(const std::map<std::string, char> &player1, const std::map<std::string, char> &player2)
{
	for (int i = 0; i < m_sizeOfBoard; i++) {
		for (int j = 0; j < m_sizeOfBoard - 1; j++) {
			if (!(m_board[i][j] == m_board[i][j + 1])) {
				break;
			}

			if (j == m_sizeOfBoard - 2) {
				return true;
			}
		}

		for (int j = 0; j < m_sizeOfBoard - 1; j++) {
			if (!(m_board[j][i] == m_board[j + 1][i])) {
				break;
			}

			if (j == m_sizeOfBoard - 2) {
				return true;
			}
		}
	}

	for (int i = 0; i < m_sizeOfBoard - 1; i++) {
		if (!(m_board[i][i] == m_board[i + 1][i + 1])) {
			break;
		}

		if (i == m_sizeOfBoard - 2) {
			return true;
		}
	}

	int j = m_sizeOfBoard - 1;

	for (int i = 0; i < m_sizeOfBoard - 1; i++) {
		if (!(m_board[i][j] == m_board[i + 1][j - 1])) {
			break;
		}

		j--;
		
		if (i == m_sizeOfBoard - 2) {
			return true;
		}
	}

	if (m_currentPlayer == player1.begin()->first) {
		m_currentPlayer = player2.begin()->first;
	}
	else {
		m_currentPlayer = player1.begin()->first;
	}

	return false;
}