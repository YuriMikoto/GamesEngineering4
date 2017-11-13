#pragma once
#include "Component.h"

class PositionComponent : public Component {
public:
	PositionComponent() : xPos(0), yPos(0) {}
	//Data only.
	float getXPosition() { return xPos; }
	float getYPosition() { return yPos; }
	void setXPosition(float position) { this->xPos = position; }
	void setYPosition(float position) { this->yPos = position; }
private:
	float xPos;
	float yPos;
};