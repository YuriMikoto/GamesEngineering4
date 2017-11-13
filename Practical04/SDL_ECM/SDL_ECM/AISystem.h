#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>

class AISystem {
public:
	void addEntity(Entity e) { entities.push_back(e); };
	void update() {
		std::cout << "AISystem Update" << std::endl;
		//Loop through entities and update.
		for (int i = 0; i < entities.size(); i++) {
			std::cout << "Updating Entity #" << entities[i].getID() << std::endl;
		}
	}
private:
	std::vector<Entity> entities;
};