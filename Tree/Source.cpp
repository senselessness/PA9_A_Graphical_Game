#include "MainT.h"
int main(void)
{
	Tree Run = Tree();
	Test T = Test();
	int Xcoor = 500, Ycoor = 650;
	//Xcoor = T.TestX;
	//Ycoor = T.TestY;
	//Run.setLoop(T.TestStep());
	Run.setStartLocation(Xcoor, Ycoor);
	Run.RunTreeBuild();
	return 0;
}