#include "Animation.h"
#include "Idle.h"
#include "Walking.h"
#include "Jumping.h"

Animation::Animation() {
	current = new Idle();
}

void Animation::setCurrent(State* s) {
	current = s;
}

void Animation::idle() {
	current->idle(this);
}

void Animation::walking() {
	current->walking(this);
}

void Animation::jumping() {
	current->jumping(this);
}