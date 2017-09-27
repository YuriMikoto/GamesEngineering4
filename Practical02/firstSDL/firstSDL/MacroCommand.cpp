#include "MacroCommand.h"

MacroCommand::MacroCommand() {
	commands = new std::list<Command*>;
	undone = new std::list<Command*>;
}

void MacroCommand::execute() {//Executes all commands in order.
	for (std::list<Command*>::iterator itr = commands->begin(); itr != commands->end(); ++itr) {
		Command *c = *itr;
		c->execute();
	}
}

void MacroCommand::add(Command *c) {//Adds a new command to the queue, but empties the "undone" list to prevent use of the Redo function.
	commands->push_back(c);
}

void MacroCommand::undo() {//Removes the last command performed and saves it in a different list.
	if (commands->size() > 0) {
		undone->push_back(commands->back());
		commands->pop_back();
	}
}

void MacroCommand::redo() {//Places the last undone command back onto the performed commands.
	if (undone->size() > 0) {
		add(undone->back());
		undone->pop_back();
	}
}