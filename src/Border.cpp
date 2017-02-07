#include "Border.h"

Border::Border() {

}

Border::Border(Country *cOne, Country *cTwo) {
	origin = cOne;
	destination = cTwo;
}

Country Border::getOrigin() {return *origin;}

Country Border::getDestination() {return *destination;}

// Checks if each country in border is the same.
// Since edges are two way, it checks both cases.
bool Border::operator==(const Border & B) {
	bool sameOrigin = (*origin == *B.origin) || (*origin == *B.destination);
	bool sameDestination = (*destination == *B.origin) || (*destination == *B.destination);
	
	return (sameOrigin && sameDestination);
}

void Border::print() {
	cout << "(" << origin->getName() <<":"<< origin->getOwner().getName() << ", " << destination->getName() << ":" << destination->getOwner().getName() << ")" ;
}

