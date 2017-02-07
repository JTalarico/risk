#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "Observer.h"
#include "Map.h"
#include "Country.h"

using namespace std;

class MapView : public Observer {
public:
	MapView();
	MapView(Map*);
	~MapView();

	void Update();
	void display();
private:
	Map *_subject;
};

#endif
