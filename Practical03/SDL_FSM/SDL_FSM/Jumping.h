#pragma once

#include "State.h"

class Jumping : public State {
public:
	Jumping();
	void idle(Animation* a);
	void walking(Animation* a);
};