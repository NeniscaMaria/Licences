#include "Observer.h"
#include "Subject.h"
void Subject::addObserver(Observer* o) {
	observers.push_back(o);
}
void Subject::notify() {
	for (auto obs : observers)
		obs->update();
}