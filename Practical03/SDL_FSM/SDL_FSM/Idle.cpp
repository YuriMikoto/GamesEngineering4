#include "Idle.h"
#include "Walking.h"
#include "Jumping.h"

Idle::Idle() {

}

void Idle::walking(Animation* a) {
	std::cout << "Start walking." << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Idle::jumping(Animation* a) {
	std::cout << "Jump!" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}