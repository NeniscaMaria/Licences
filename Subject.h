#pragma once
#include <vector>
class Observer;
class Subject {
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer*);
	void notify();
};