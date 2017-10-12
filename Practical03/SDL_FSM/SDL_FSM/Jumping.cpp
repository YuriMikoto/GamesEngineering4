#include "Idle.h"
#include "Walking.h"
#include "Jumping.h"

Jumping::Jumping() {

}

void Jumping::idle(Animation* a) {
	std::cout << "Landing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Jumping::walking(Animation* a) {
	std::cout << "Land running." << std::endl;
	a->setCurrent(new Walking());
	delete this;
}