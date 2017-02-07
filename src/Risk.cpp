#include "Risk.h"

int main() {

// Create 3 players
	vector <Player> players;
	players.push_back(Player ("Bob Bobly"));
	players.push_back(Player ("Tim Timly"));	
	players.push_back(Player ("Jim Jimly"));

	// Create 6 countries

	// 3 in continent A
	Country *A1 = new Country ("A1", "A", players[0], 0);
	Country *A2 = new Country ("A2", "A", players[1], 10);
	Country *A3 = new Country ("A3", "A", players[2], 100);

	vector <Country*> countriesA (3);
	countriesA[0] = A1;
	countriesA[1] = A2;
	countriesA[2] = A3;

	// 3 in continent B
	Country *B1 = new Country ("B1", "B", players[0], 0);
	Country *B2 = new Country ("B2", "B", players[1], 10);
	Country *B3 = new Country ("B3", "B", players[2], 100);
	
	vector <Country*> countriesB (3);
	countriesB[0] = B1;
	countriesB[1] = B2;
	countriesB[2] = B3;
////////////////////////////
	// Create borders

	// Create borders in A.
	Border *A1A2 = new Border (A1,A2);
	Border *A2A3 = new Border (A2,A3);
	Border *A3B1 = new Border (A3,B1);

	vector <Border *> bordersA (3);
	bordersA[0] = A1A2;
	bordersA[1] = A2A3;
	bordersA[2] = A3B1;

	// Create borders in B.
	Border *B1B2 = new Border (B1,B2);
	Border *B2B3 = new Border (B2,B3);

	vector <Border *> bordersB (3);
	bordersB[0] = B1B2;
	bordersB[1] = B2B3;
	bordersB[2] = A3B1;

//////////////////////////////////////////
	// Make two continents using two different constructors
	Map continentA (countriesA,bordersA);

	Map continentB;
	continentB.addCountries(countriesB);
	continentB.addBorders(bordersB);

	vector <Map> continents;
	continents.push_back(continentA);
	continents.push_back(continentB);
	
	// Make the world map
	Map world = continents[0] + continents[1];
	MapView worldView (&world);

///////////////////////////////////////////

	// Test stuff
	
	// Make player 1 conquer all of continent A.
	vector <Country> countryList = continentA.getCountries();
	int n = countryList.size();

	// For every country in this continent:
	// Set owner to player 1.
	for (int i = 0; i < n; i++) {
		cout << "###### Iteration " << i << " ######" << endl;
		world.setOwner(countryList[i],players[0]);
		cout << "**************************************\n"
		     << "**************************************\n";
		     
	}

// Notice how the map is updated 3 times. Once for each time
// Player 1 (Bob Bobly) conquers a country in continent A.

// The adjaceny matrix does NOT change since no knew edges are added.

// Lets say we decide to add a new Border 
// This souldn't really be possible at this point in the game
// but it's more of a proof of concept.

// Lets say we create a country and its border.

	Country *B4 = new Country ("B4", "B", players[2], 1000);
	Border *B4A1 = new Border (B4,A1);

	cout << "########### Add a Border ##########\n"
	     << "**************************************\n"
	     << "**************************************\n";

	world.addBorders(B4A1); 
// After this command, the adjaceny matrix still does not have B4.
// This is because the country is not in the country list yet.
// However, A1 knows that it is connected to something, since it prints:
/*

### A1 ###
Continent: A
Owner: Bob Bobly
Soldier Count: 0
Borders: A2, B4
###########

*/
cout << "########### Add a Country ##########\n"
     << "**************************************\n"
     << "**************************************\n";
	world.addCountries(B4); 
// Now the adjaceny matrix has changed.
// We cannot add the country first since that would make an unconnected graph.

	return 0;
}

