#ifndef OBSERVER_H
#define OBSERVER_H

using namespace std;

// Using code shown in class.
class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};

#endif
