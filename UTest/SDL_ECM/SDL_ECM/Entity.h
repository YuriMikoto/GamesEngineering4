#pragma once
#include "Component.h"
#include <vector>
#include <algorithm>

class Entity {
public:
	Entity(int idno) { id = idno; };
	void addComponent(Component c) { components.push_back(c); }
	void removeComponent(Component c) {//Causes an error.
		std::vector<Component>::iterator position = components.end();
		//position = std::find(components.begin(), components.end(), c);
		if (position != components.end()) {
			components.erase(position);
		}
	};
	std::vector<Component> getComponents() { 
		return components;
	}
	int getID() {
		return id;
	}
private:
	int id;
	std::vector<Component> components;
};