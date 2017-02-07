#ifndef BORDER_H
#define BORDER_H

#include "Country.h"
#include <iostream>

using namespace std;

class Border {

	private:
		Country *origin;
		Country *destination;
	public:
		// Constructors
		Border();
		Border(Country *, Country *);
		// Get functions
		Country getOrigin();
		Country getDestination();
		// Other
		bool operator==(const Border &);
		void print();
};

#endif

