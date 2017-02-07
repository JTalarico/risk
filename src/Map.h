#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip> 

#include "Country.h"
#include "Border.h"
#include "Subject.h"

using namespace std;

class Map: public Subject {

	private:
		vector <Border *> borders;
		vector <Country *> countries;
	public:
		//Constructors
		Map();
		Map(vector <Country *>, vector <Border *>);
		Map(const Map&);
		
		// Get functions
		vector <Country> getCountries();
		vector <Border> getBorders();
		vector <Country> getAdjacentCountries(Country);

		// Mutators
		void setOwner(Country, Player);
		void addSoldiers(Country, int);
		void removeSoldiers(Country, int);

		void addCountries (vector <Country *>);
		void addCountries(Country *);
		void addBorders (vector <Border *>);
		void addBorders (Border *);
		void addSubgraph (const Map &);
		Map operator+ (const Map &) const;

		// Print functions
		void printCountries();
		void printBorders();

		void printSimple();
		void printDetailed();

		void printAdjacencyMatrix();
};

// Helper Functions
int findPosition (Country, vector <Country*>);
template <typename T> 
bool exists (T element, vector <T> v );
template <typename T> 
bool exists (T element, vector <T*> v );
vector <Country *> catCountries (vector <Country *>, vector <Country *>);
vector <Border *> catBorders (vector <Border *>, vector <Border *>);


#endif
