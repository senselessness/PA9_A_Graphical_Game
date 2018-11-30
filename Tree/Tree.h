#include "Seed.h"
class Tree : public sf::RectangleShape
{
public:
	Tree();
	~Tree();
	void setStartLocation(sf::Vector2f& newLocation);
	void setStartLocation(double x, double y);
	sf::Vector2f& getStartLocation();
	double getHeight();
	void setHeight(double newInitHeight);
	double getWidth();
	void setWidth(double newInitWidth);
	int getIterations();
	void setIterations(int newNumberOfIterations);
	double getRAngle();
	void setRAngle(double newRightAngle);
	double getLAngle();
	void setLAngle(double newLeftAngle);
	void Render(sf::RenderWindow& window);
	void drawTree(int iteration, const sf::Vector2f& rootPosition, double rootRotation, sf::RenderWindow& window);
	double getScalingV();
	void setScalingV(double newScalingFactor);
	void setColorST(const sf::Color& c);
	sf::Color& getColorST();
	void setColorCI(const sf::Color& c);
	sf::Color& getColorCI();
private:
	sf::Color STColor;
	sf::Vector2f StartingPoint;
	sf::Color CIColor;
	int OccuranceV;
	double LAngle;
	double RAngle;
	double STHeight;
	double STWidth;
	double TRScale;
};