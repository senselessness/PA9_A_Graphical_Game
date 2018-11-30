#include "Tree.h"
Tree::Tree()
{

}
Tree::~Tree()
{

}
void Tree::drawTree(int iteration, const sf::Vector2f& rootPosition, double rootRotation, sf::RenderWindow& window)
{
	if (OccuranceV <= 1)
	{ 
		return;
	}
	if (iteration == OccuranceV)
	{
		double scalingFactor = pow(TRScale, iteration);
		sf::CircleShape circle = sf::CircleShape(STWidth*scalingFactor*1.1);
		//sf::Color ScaleColorC = sf::Color(CIColor.r * scalingFactor, STColor.g * scalingFactor, STColor.b * scalingFactor);
		circle.setFillColor(CIColor);
		circle.setPosition(sf::Vector2f(rootPosition.x - circle.getRadius(), rootPosition.y - circle.getRadius()));
		window.draw(circle);
		return;
	}
	double scalingFactor = pow(TRScale, iteration);
	sf::RectangleShape rect = sf::RectangleShape();
	double width = STWidth*scalingFactor;
	double height =STHeight*scalingFactor;
	rect.setSize(sf::Vector2f(width, height));
	sf::Color scaledColor = sf::Color(STColor.r * scalingFactor, STColor.g * scalingFactor, STColor.b * scalingFactor);
	rect.setFillColor(scaledColor);
	sf::Color Brown = sf::Color(125, 100, 20);
	rect.setOutlineColor(Brown);
	rect.setRotation(rootRotation);
	rect.setPosition(rootPosition);
	window.draw(rect);
	// SFML angles go clockwise therefore -sin is required
	double x = rootPosition.x - std::sin((rootRotation*3.14) / 180)*height;
	double y = rootPosition.y + std::cos((rootRotation*3.14) / 180)*height;
	//  std::cout << rootPosition.x << " vs " << rootPosition.x + std::sin((rootRotation*3.1)/180)*width << std::endl;
	drawTree(iteration + 1, sf::Vector2f(x, y), rootRotation + LAngle, window);
	drawTree(iteration + 1, sf::Vector2f(x, y), rootRotation - RAngle, window);
}
void Tree::Render(sf::RenderWindow& window)
{
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(STWidth,STHeight));
	rect.setFillColor(STColor);
	rect.setPosition(StartingPoint);
	rect.setRotation(180);
	double x = StartingPoint.x - std::sin((180 * 3.14) / 180) *STHeight;
	double y = StartingPoint.y + std::cos((180 * 3.14) / 180) *STHeight;
	window.draw(rect);
	drawTree(1, sf::Vector2f(x, y), 180 - LAngle, window);
	drawTree(1, sf::Vector2f(x, y), 180 + RAngle, window);
}
sf::Vector2f& Tree::getStartLocation()
{
	return StartingPoint;
}
void Tree::setStartLocation(sf::Vector2f& newStartLocation)
{
	StartingPoint = sf::Vector2f(newStartLocation);
}
double Tree::getHeight()
{
	return STHeight;
}
void Tree::setHeight(double newInitHeight)
{
	STHeight= newInitHeight;
}
double Tree::getWidth()
{
	return STWidth;
}
void Tree::setWidth(double newInitWidth)
{
	STWidth = newInitWidth;
}
void Tree::setStartLocation(double x1, double y1)
{
	StartingPoint = sf::Vector2f(x1, y1);
}
int Tree::getIterations()
{
	return OccuranceV;
}
void Tree::setIterations(int newNumberOfIterations)
{
	OccuranceV = newNumberOfIterations;
}
double Tree::getRAngle()
{
	return RAngle;
}
void Tree::setRAngle(double newRightAngle)
{
	RAngle = newRightAngle;
}
double Tree::getLAngle()
{
	return LAngle;
}
void Tree::setLAngle(double newLeftAngle)
{
	LAngle = newLeftAngle;
}
void Tree::setColorST(const sf::Color& c)
{
	STColor = sf::Color(c);
}
sf::Color& Tree::getColorCI()
{
	return CIColor;
}
void Tree::setColorCI(const sf::Color& c)
{
	CIColor = sf::Color(c);
}
sf::Color& Tree::getColorST()
{
	return STColor;
}
double Tree::getScalingV()
{
	return TRScale;
}
void Tree::setScalingV(double newScalingFactor)
{
	TRScale = newScalingFactor;
}