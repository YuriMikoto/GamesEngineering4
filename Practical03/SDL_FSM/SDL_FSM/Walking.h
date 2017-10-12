#pragma once

#include "State.h"

class Walking : public State {
public:
	Walking();
	void idle(Animation* a);
	void jumping(Animation* a);
};