#include "Player.h"

Player::Player (string s) {
	player_name = s;
}

Player::Player () {
	player_name = "Default Jim";
}

string Player::getName() {return player_name;}

bool Player::operator== (const Player & p) {
	return (player_name.compare(p.player_name) == 0);
}

