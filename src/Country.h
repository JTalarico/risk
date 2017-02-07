#ifndef Country_H
#define Country_H

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Country {

	private:

		int soldiers;
		string name;
		string continent;
		Player owner;

	public:
		// Constructors
		Country ();
		Country (string, string, Player, int);
		Country(string);
		Country(string, string);

		// Get Functions
		string getName();
		string getContinent();
		Player getOwner();
		int getSoldiers();

		// Mutators
		void addSoldiers(int);	
		void removeSoldiers(int);
		void setOwner(Player newOwner);

		// Other
		bool operator==(const Country &);
		void print();
};	

#endif

