#pragma once
#include "Test.h"
class Tree : public sf::RectangleShape
{
public:
	Tree();
	~Tree();
	void setStartLocation(sf::Vector2f & newLocation);
	void setStartLocation(double x, double y);
	void setHeight(double newHeight);
	void setWidth(double newWidth);
	void setScalingVariable(double newScalar);
	void setRAngle(double newRight);
	void setLAngle(double newLeft);
	void setColorFLower(sf::Color Flower);
	void setColorStem(sf::Color Stem);
	void setLoop(int AOccured);
	void setHealth(int Healthlvl, int index);
	int getHealth(int index);
	int getLoop();
	double getHeight();
	double getWidth();
	sf::Color GetFlowerColor();
	sf::Color GetStemColor();
	double GetScalingVariable();
	double GetRAngle();
	double GetLAngle();
	sf::Vector2f GetStartPoint();
	void RunTreeBuild();
	void Render(sf::RenderWindow& window);
protected:
	void runIt();
	void drawTree(int iteration, const sf::Vector2f& rootPosition, double rootRotation, sf::RenderWindow& window, bool BROL);
	void GrowFlowers(const sf::Vector2f& rootPosition, sf::RenderWindow& window);
private:
	sf::Color STColor;
	sf::Color FlowerColor;
	double ScalingV;
	double RAngle;
	double LAngle;
	double Width;
	double Length;
	sf::Vector2f StartPoint;
	int NumberLoop;
	int HealthTrack[9];

};