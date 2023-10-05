#pragma once
#include <string>

#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

const std::string PLAYER_1_COLOR_START = MAG;
const std::string PLAYER_2_COLOR_START = CYN;

const std::string PLAYER_COLOR_END = "\033[0m";