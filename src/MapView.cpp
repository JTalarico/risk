#include "MapView.h"

using namespace std;

MapView::MapView() {

}

MapView::MapView(Map* m) {
	_subject = m;
	_subject->Attach(this);
}

MapView::~MapView() {
	_subject->Detach(this);
}

void MapView::Update() {
	display();
}

//Prints out useful information about the countries and continents
void MapView::display() {
	_subject->printDetailed();
	cout << "\n\n";
	_subject->printAdjacencyMatrix();
}
