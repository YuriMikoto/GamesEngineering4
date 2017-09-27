#pragma once
#include "Command.h"
#include "MacroCommand.h"
#include "SDL_events.h"

class InputHandler {
public:
	void handleInput(SDL_Event event);
	void assignButtons(Command* x, Command* y, Command* a, Command* b);
private:
	Command* buttonX_;
	Command* buttonY_;
	Command* buttonA_;
	Command* buttonB_;

	MacroCommand* mc;
};