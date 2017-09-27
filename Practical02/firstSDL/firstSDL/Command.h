#pragma once
#include "Player.h"

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command() {}

	Player p1;
};

class JumpCommand : public Command {
public:
	virtual void execute() {
		p1.jump();
	}
};

class FireCommand : public Command {
public:
	virtual void execute() {
		p1.fire();
	}
};

class SwitchCommand : public Command {
public:
	virtual void execute() {
		p1.switchWeapons();
	}
};

class EvadeCommand : public Command {
public:
	virtual void execute() {
		p1.dodgeRoll();
	}
};