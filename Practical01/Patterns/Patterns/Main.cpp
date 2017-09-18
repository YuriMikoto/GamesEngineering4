#include <iostream>

using namespace std;

/// <summary>
/// Uncomment the following section for: Abstract Factory pattern.
/// </summary>

/*#include <vector>

class Character {
public:
	Character() {}
	virtual ~Character() {}
	virtual void draw() = 0;
};

class Player : public Character {
public:
	void draw() {
		cout << "Draw Player" << endl;
	}
};
class Boss : public Character {
public:
	void draw() {
		cout << "Draw Boss" << endl;
	}
};

class Factory {
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateBoss() = 0;
};

class CharacterFactory : Factory {
public:
	Character* CreatePlayer() {
		return new Player;
	}
	Character* CreateBoss() {
		return new Boss;
	}
};

int main() {
	CharacterFactory* factory = new CharacterFactory;
	vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateBoss());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	system("PAUSE");
}*/

/// <summary>
/// Uncomment the following section for: Handle Class pattern.
/// </summary>

/*class Character {
public:
	Character() {}
	void Print() {
		cout << "Printing Character" << endl;
	}
};

class HandleToCharacter {
public:
	HandleToCharacter() : character(new Character()) {

	}
	Character* operator->() {//Overloads the "->" operator.
		return character;
	}
private:
	Character* character;
};

int main() {
	HandleToCharacter handle; //Creates a character and a handle to that character simultaneously.
	handle->Print(); //Overloaded operator causes this to return the character and call its Print function.

	system("PAUSE");
}*/

/// <summary>
/// Uncomment the following section for: Proxy Object pattern. 
/// Uses Graphic.h & Graphic.cpp; GraphicProxy.h & GraphicProxy.cpp; IGraphic.h.
/// </summary>

/*#include "GraphicProxy.h"

int main() {
	GraphicProxy proxy;
	proxy.Draw();

	system("PAUSE");
}*/