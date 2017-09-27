#pragma once
#include "Command.h"
#include <list>

class MacroCommand : public Command {
public:
	MacroCommand();
	virtual void add(Command*);
	virtual void undo();
	virtual void redo();
	virtual void execute();
private:
	std::list<Command*>* commands; //List of commands to be performed via the execute() function.
	std::list<Command*>* undone; //List of commands removed from the list via Undo; can be added back with a Redo input.
};