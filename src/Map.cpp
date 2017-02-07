#include "Map.h"

////////////////////////////////////
//////////  Constructors  //////////
////////////////////////////////////

// Default
Map::Map() {
	countries.reserve(0);
	borders.reserve(0);
}

// Accepting vectors
Map::Map(vector <Country *> cv, vector <Border *> bv) {
	countries.reserve(cv.size());
	borders.reserve(cv.size());
	countries = cv;
	borders = bv;
	Notify();
}

// Accepting another Map
Map::Map(const Map &M) {
	addCountries(M.countries);
	addBorders(M.borders);
	Notify();
}

//////////////////////////////////////////
//////////  Constructors (END)  //////////
//////////////////////////////////////////


/////////////////////////////////////
//////////  Get Functions  //////////
/////////////////////////////////////

// These functions purposly return copies. This makes sense.

vector <Country> Map::getCountries() {
	int n = countries.size();

	vector <Country> countriesCopy;
	countriesCopy.reserve(n);

	for (int i = 0; i < n; i++) {
		countriesCopy.push_back(*countries[i]);
	}

	return countriesCopy; 
}
vector <Border> Map::getBorders() {
	int n = borders.size();

	vector <Border> bordersCopy;
	bordersCopy.reserve(n);

	for (int i = 0; i < n; i++) {
		bordersCopy.push_back(*borders[i]);
	}

	return bordersCopy; 
}

// Gets the bordering countries of a country c.
vector <Country> Map::getAdjacentCountries(Country c) {
	vector <Country> adjacentCountries;
	int n = borders.size();

	// Given a country c
	// For each edge in the graph G:
	// Check if one of the nodes in the edge has the same name as c.
	// If it does, return the OTHER node (i.e the one c is connecting to)

	for (int i = 0; i < n; i++) {
		if ( borders[i]->getDestination() == c)
			adjacentCountries.push_back( borders[i]->getOrigin() );
		else if ( borders[i]->getOrigin() == c )
			adjacentCountries.push_back( borders[i]->getDestination() );
		else
			continue;	
	}
	return adjacentCountries;
}

///////////////////////////////////////////
//////////  Get Functions (END)  //////////
///////////////////////////////////////////


////////////////////////////////////
//////////  Mutators  //////////////
////////////////////////////////////

void Map::setOwner (Country c, Player o) {
	int i = findPosition(c, countries);
	if (i == -1) {
		cout << "ERROR: Country was not found!";
	}
	else
		countries[i]->setOwner(o);
	Notify();
}

void Map::addSoldiers (Country c, int n) {
	int i = findPosition(c, countries);
	if (i == -1) {
		cout << "ERROR: Country was not found!";
	}
	countries[i]->addSoldiers(n);
	Notify();
}

void Map::removeSoldiers (Country c, int n) {
	int i = findPosition(c, countries);
	if (i == -1) {
		cout << "ERROR: Country was not found!";
	}
	countries[i]->removeSoldiers(n);
	Notify();
}

// Checks if countries exists before adding them.
void Map::addCountries (vector <Country *> cv) {
	countries = catCountries(cv, countries);
	Notify();
}

// Checks if borders exists before adding them.
void Map::addBorders (vector <Border *> bv) {
	borders = catBorders(bv,borders);
	Notify();
}

// If you want to add just one country.
void Map::addCountries(Country *c) {
	if (exists(*c, countries))	
		return;
	else
		countries.push_back(c);
	Notify();
}

void Map::addBorders(Border *b) {
	if (exists(*b, borders))	
		return;
	else
		borders.push_back(b);
	Notify();
}

void Map::addSubgraph (const Map & G) {
	addCountries(G.countries);
	addBorders(G.borders);
	Notify();
}

Map Map::operator+ (const Map & M) const {
	vector <Country *> newCountries = catCountries(countries, M.countries);
	vector <Border *> newBorders = catBorders(borders, M.borders);
	return Map(newCountries,newBorders);
}

//////////////////////////////////////////
//////////  Mutators (END)  //////////////
//////////////////////////////////////////

////////////////////////////////////
/////////  Print Funtions  /////////
////////////////////////////////////

void Map::printCountries() {
	int n = countries.size();
	for (int i = 0; i < n; i++) {
		countries[i]->print();
		cout << endl;
	}
}

void Map::printBorders() {
	int n = borders.size();
	for (int i = 0; i < n; i++) {
		borders[i]->print();
		cout << " ";
	}
	cout << endl;
}

// Just prints countries with their borders.
void Map::printSimple() {
	int  n, m;
	n = countries.size();
	
	for (int i = 0; i < n; i++)
	{
		vector <Country> adjacent = getAdjacentCountries(*countries[i]);
		m = adjacent.size();
		cout << countries[i]->getName() << ": ";
		for (int j = 0; j < m-1; j++)
		{
			cout << adjacent[j].getName() << ", ";
		}
		cout << adjacent[m-1].getName() << endl;
	}
}

// Prints each country (with continent name, owner, number of soldiers)
// as well as it's borders
void Map::printDetailed() {
	int  n, m;
	n = countries.size();
	vector <Country> adjacent;
	for (int i = 0; i < n; i++) {
		adjacent.reserve(5);
		adjacent = getAdjacentCountries(*countries[i]);
		m = adjacent.size();
		countries[i]->print();
		cout << "Borders: ";
		for (int j = 0; j < m-1; j++) {
			cout << adjacent[j].getName() << ", ";
		}
		cout << adjacent[m-1].getName() << endl;
		cout << "###########\n\n";
		adjacent.clear();
	}
}

void Map::printAdjacencyMatrix() {
	int  n, m;
	n = countries.size();
	vector <Country> adjacent;
	
	//Find longest Name of Country (for formatting)
	int lengthOfBox = 0;
	int currentLength;
	for (int i = 0; i < n; i++) {
		currentLength = countries[i]->getName().length();
		if (currentLength > lengthOfBox)
			lengthOfBox = currentLength;
	}
	// This is for formatting. It makes sure everything is alligned properly
	if (lengthOfBox%2==0)
		lengthOfBox++;

	cout << setw(lengthOfBox) << "";
	cout << "║";

	// Print Column names of Adjaceny Matrix
	for (int i = 0; i < n; i++) {

		cout << left << setw(lengthOfBox) << countries[i]->getName() << "|";
	}
	cout << endl;

	// Divider type 1. First row in the Adjaceny Matrix
	string divider1((n+1)*lengthOfBox + n + 1,'=');
	
	cout << divider1 << endl;
	// Divider type 2. Each row in the Adjaceny Matrix
	string cellDivider(lengthOfBox,'-');
	string divider2 = cellDivider + "║";

	for (int i = 0; i < n ; i++) {
		divider2 = divider2 + cellDivider + "|";
	}
	
	// Divider type 3. Last row in the Adjaceny Matrix.
	string divider3((n+1)*lengthOfBox + n + 1,'-');

	for (int i = 0; i < n; i++) {
		
		// Print row name
		cout << left << setw(lengthOfBox) << countries[i]->getName() << "║";
		adjacent = getAdjacentCountries(*countries[i]);
		m = adjacent.size();
		
		// This loops prints the values of the Adjaceny Matrix.
		// Check if the country in column j connects to the country in row i
		for (int j = 0; j < n; j++) {
			bool isAdjacent = exists(*countries[j],adjacent);
			// If there is a connection
			if (isAdjacent) {
				cout << setw(lengthOfBox/2 +1) << internal << "1";
				cout << setw(lengthOfBox/2 +1) << "|";
			}
			// If not, set a blank box of appropriate size
			else {
				cout << setw(lengthOfBox) << "";
				cout << "|";
			}
		}

		adjacent.clear();
		cout << endl;
		// If it is NOT the last row, use normal divider
		if (i!=(n-1))		
			cout << divider2 << endl;
		// If it is the last row, use a special divider
		else 
			cout << divider3 << endl;
	}

	cout << endl;
}

//////////////////////////////////////////
/////////  Print Funtions (END)  /////////
//////////////////////////////////////////

/////////////////////////////////////
/////////  Helper Funtions  /////////
/////////////////////////////////////

// Finds the position of a country c, in a countries vector.
int findPosition (Country c, vector <Country *> countries) {
	int n = countries.size();
	for (int i = 0; i < n; i++) {
		if (*countries[i] == c)
			return i;		
	}
	return -1;
}

// Checks if an element already exists in the vector
template <typename T> 
bool exists (T element, vector <T> v ) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (v[i] == element)
			return true;		
	}
	return false;
}
template <typename T> 
// Same thing but for a vector of pointers
bool exists (T element, vector <T*> v ) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (*v[i] == element)
			return true;		
	}
	return false;
}

// Cats current Country vector, with input vector,
// making sure no duplicates are added.
vector <Country *> catCountries (vector <Country *> cv1, vector <Country *> cv2) {
	vector <Country *> temp;
	int n = cv2.size();

	// For every element in cv2, check if it already exists in the vector cv1
	for (int i = 0; i < n; i++) {	
		if(exists(*cv2[i], cv1))
			continue;
		else
			temp.push_back(cv2[i]);
	}

	// Reserve memory for new countries
	cv1.reserve(cv1.size() + temp.size());
	
	// Append vector
	cv1.insert(cv1.end(), temp.begin(), temp.end());

	return cv1;
}

// Cats current Border vector, with input vector,
// making sure no duplicates are added.
vector <Border *> catBorders (vector <Border *> bv1, vector <Border *> bv2) {
	vector <Border *> temp;
	int n = bv2.size();

	// For every element in bv2, check if it already exists in the vector bv1
	for (int i = 0; i < n; i++) {
		if(exists(*bv2[i], bv1))
			continue;
		else
			temp.push_back(bv2[i]);
	}

	// Reserve memory for new borders
	bv1.reserve(bv1.size() + temp.size());
	
	// Append vectors
	bv1.insert(bv1.end(), temp.begin(), temp.end());

	return bv1;
}


///////////////////////////////////////////
/////////  Helper Funtions (END)  /////////
///////////////////////////////////////////





