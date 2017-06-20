#pragma once
#include <vector>
#include <algorithm>

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject {
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer* o) { this->observers.push_back(o); }
	void notify() {
		for (auto s : observers)
			s->update();
	}
};