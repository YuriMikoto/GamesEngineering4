#include "InputHandler.h"
#include <iostream>

void InputHandler::handleInput(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == 49) {//1 key - X Button
			//buttonX_->execute(); //These were used before implementing the MacroCommand. They will directly execute the player's action.
			mc->add(buttonX_);
		}
		else if (e.key.keysym.sym == 50) {//2 key - Y Button
			//buttonY_->execute();
			mc->add(buttonY_);
		}
		else if (e.key.keysym.sym == 51) {//3 key - A Button
			//buttonA_->execute();
			mc->add(buttonA_);
		}
		else if (e.key.keysym.sym == 52) {//4 key - B Button
			//buttonB_->execute();
			mc->add(buttonB_);
		}
		else if (e.key.keysym.sym == 8) {//Backspace key - Undo
			mc->undo();
		}
		else if (e.key.keysym.sym == 13) {//Enter key - Redo
			mc->redo();
		}
		mc->execute();
	}

}

void InputHandler::assignButtons(Command* x, Command* y, Command* a, Command* b) {
	buttonX_ = x;
	buttonY_ = y;
	buttonA_ = a;
	buttonB_ = b;

	mc = new MacroCommand();
}