#pragma once

#include "State.h"

class Idle : public State {
public:
	Idle();
	void walking(Animation* a);
	void jumping(Animation* a);
};