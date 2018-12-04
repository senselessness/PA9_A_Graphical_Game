#include "MainT.h"
int main(void)
{
	Tree Run = Tree();
	Run.setStartLocation(500, 650);
	//Run.setLAngle(15);
	//Run.setRAngle(35);
	Run.setWidth(15);
	Run.setHeight(100);
	//Run.setLoop(10);
	//Run.setScalingVariable(0.85);
	sf::Color Green = sf::Color(70, 190, 63);
	Run.setColorStem(Green);
	Run.RunTreeBuild();
	return 0;
}