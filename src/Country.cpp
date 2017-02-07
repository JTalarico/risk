#include "Country.h"

////////////////////////////////////
//////////  Constructors  //////////
////////////////////////////////////

// Unspecific constructor
Country::Country() {			// This should never happen.
	name = "WhatDidYouDo-land";	
}

// Specify Name
Country::Country(string cn) {
	name = cn;	
	continent = "NONE";
	soldiers = 0;
}

// Specify Name and Continent
Country::Country(string cn, string c) {
	name = cn;	
	continent = c;
	soldiers = 0;
}

// Specific constructor
Country::Country(string cn, string c, Player o, int s) {
	name = cn;	
	continent = c;
	owner = o;
	soldiers = s;
}

//////////////////////////////////////////
//////////  Constructors (END)  //////////
//////////////////////////////////////////

/////////////////////////////////////
//////////  Get Functions  //////////
/////////////////////////////////////

string Country::Country::getName() {return name;}
string Country::getContinent() {return continent;}
Player Country::getOwner() {return owner;}
int Country::getSoldiers() {return soldiers;}

///////////////////////////////////////////
//////////  Get Functions (END)  //////////
///////////////////////////////////////////

////////////////////////////////////
//////////  Mutators  //////////////
////////////////////////////////////

// Add a number of soldiers to the Country
void Country::addSoldiers(int n) {
	soldiers += n;
}

// Add a number of soldiers to the Country
void Country::removeSoldiers(int n) {
	if (soldiers <= 0) {
		cout << "There are no soldiers to remove!" << endl;
	}
	else {
		soldiers -= n;
	}
}

// Set a new owner for the Country
void Country::setOwner(Player newOwner) {
	owner = newOwner;	
}

//////////////////////////////////////////
//////////  Mutators (END)  //////////////
//////////////////////////////////////////

// Compares each element of two countries.
bool Country::operator==(const Country & c) {
	bool sameName = name.compare(c.name) == 0;
	bool sameSoldiers = soldiers == c.soldiers;
	bool sameContinent = continent.compare(c.continent) == 0;
	bool sameOwner = owner == c.owner;
	return sameName && sameSoldiers && sameContinent && sameOwner;
}

// Print stuff about the Country. Mostly for debugging.
void Country::print() {
	cout << "### " << name << " ###\nContinent: " << continent
	<< "\nOwner: " << owner.getName() << "\nSoldier Count: " << soldiers 
	<< endl;
}
