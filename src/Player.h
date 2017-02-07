#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player {

	private:
		string player_name;
	public:
		Player ();
		Player (string);
		string getName();
		bool operator==(const Player &);

};

#endif
