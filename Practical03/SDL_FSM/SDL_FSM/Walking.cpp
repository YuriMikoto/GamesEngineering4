#include "Idle.h"
#include "Walking.h"
#include "Jumping.h"

Walking::Walking() {

}

void Walking::idle(Animation* a) {
	std::cout << "Stopping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::jumping(Animation* a) {
	std::cout << "Running Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}