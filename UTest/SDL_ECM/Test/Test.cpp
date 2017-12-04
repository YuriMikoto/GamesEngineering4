#include <assert.h>
#include <HealthComponent.h>
#include <Entity.h>
//Include file? 

int main()
{
	Entity player(0);
	HealthComponent playerHC;
	player.addComponent(playerHC);

	assert(playerHC.getHealth() == 100); //Works. Health is 100 by default.
	playerHC.setHealth(95);
	assert(playerHC.getHealth() == 100); //Doesn't work this time. Health has been changed.
}