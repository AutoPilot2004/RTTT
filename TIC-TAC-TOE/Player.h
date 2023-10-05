#pragma once
#include <string>
#include <map>

class Player
{
public:
	Player(std::string color);

	void getPlayerInfo(Player *prevPlayer = nullptr);

	//Getters
	std::map<std::string, char> getPlayer() { return m_player; }
	int getScore() { return m_score; }
	std::string getColor() { return m_color; }

	//Setters
	void addScore(int addScore) { m_score += addScore; }

private:
	std::map<std::string, char> m_player;

	std::string m_color;

	int m_sizeOfBoard = 0;

	int m_score = 0;
};

