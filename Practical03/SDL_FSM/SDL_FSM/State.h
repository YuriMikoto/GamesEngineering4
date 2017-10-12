#pragma once

#include <iostream>

#include "Animation.h"

class State {
public:
	virtual void idle(Animation* a) {
		std::cout << "Still Idling" << std::endl;
	}

	virtual void walking(Animation* a) {
		std::cout << "Still Walking" << std::endl;
	}

	virtual void jumping(Animation* a) {
		std::cout << "Still in the air" << std::endl;
	}
};

