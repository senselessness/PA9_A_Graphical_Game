#include "Tree.h"
Tree::Tree()
{
	ScalingV = 0;
	RAngle = 0;
	LAngle = 0;
	Width = 0; 
	Length = 0;
	NumberLoop = 0;
}
Tree::~Tree()
{

}
void Tree::setHeight(double newHeight)
{
	Length = newHeight;
}
void Tree::setWidth(double newWidth)
{
	Width = newWidth;
}
void Tree::setScalingVariable(double newScalar)
{
	ScalingV = newScalar;
}
void Tree::setRAngle(double newRight)
{
	RAngle = newRight;
}
void Tree::setLAngle(double newLeft)
{
	LAngle = newLeft;
}
void Tree::setColorFLower(sf::Color Flower)
{
	FlowerColor = Flower;
}
void Tree::setColorStem(sf::Color Stem)
{
	STColor = Stem;
}
double Tree::getHeight()
{
	return Length;
}
double Tree::getWidth()
{
	return Width;
}
sf::Color Tree::GetFlowerColor()
{
	return FlowerColor;
}
sf::Color Tree::GetStemColor()
{
	return STColor;
}
double Tree::GetScalingVariable()
{
	return ScalingV;
}
double Tree::GetRAngle()
{
	return RAngle;
}
double Tree::GetLAngle()
{
	return LAngle;
}
sf::Vector2f Tree::GetStartPoint()
{
	return StartPoint;
}
void Tree::setStartLocation(sf::Vector2f & newLocation)
{
	StartPoint = sf::Vector2f(newLocation);
}
void Tree::setStartLocation(double x, double y)
{
	StartPoint = sf::Vector2f(x, y);
}
void Tree::setLoop(int AOccured)
{
	NumberLoop = AOccured;
}
int Tree::getLoop()
{
	return NumberLoop;
}
void Tree::setHealth(int Healthlvl, int index)
{
	HealthTrack[index] = Healthlvl;
}
int Tree::getHealth(int index)
{
	return HealthTrack[index-1];
}
void Tree::RunTreeBuild()
{
	runIt();
}
void Tree::runIt()
{
		int i = 1;
	sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
	while (window.isOpen())
	{
		sf::Clock clock;
		sf::Time time = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}
		}
				//Base it off of getLoop() for Array of Health to get a more symmetrical answer.
				setHealth(rand() % 3 + 1, i);
				setLoop(i);
				Render(window);
		//window.display();
		//system("pause");
		i++;
	}
}
void Tree::drawTree(int iteration, const sf::Vector2f& rootPosition, double rootRotation, sf::RenderWindow& window, bool BROL)
{
	Test T =  Test();
	//Store in vector then clear at the end. No risk to others?
	int Health = 0;
	Health = getHealth(iteration);
	//cout << Health << endl;
	//Health = T.TestHEandUN();
	if (iteration == getLoop() /*|| function = false*/)
	{
	// 10 times simulation over and flowers blossom
	//if true then done
	//if false then still growing
		GrowFlowers(rootPosition, window);
		return;
	}
	///x = function of health
	//1 healthy
	//2 neutral
	//3 unhealthy
	if (Health == 1)
	{
		///Function Generate Healthy Values
		//setLAngle(25 + (std::rand() % (35 - 25 + 1)));
		//setRAngle(35 + (std::rand() % (45 - 35 + 1)));
		//setWidth(15 + (std::rand() % (20 - 15 + 1)));
		//setHeight(100 + (std::rand() % (120 - 100 + 1)));
		sf::Color Green = sf::Color(70, 190, 63);
		setColorStem(Green);
		sf::Color Purple = sf::Color(240, 0, 240);
		setColorFLower(Purple);
		setScalingVariable(0.9);

	}
	else if (Health == 2)
	{
		return;
	}
	else
	{
		///Function for unhealthy values;
		setLAngle(10 + ( std::rand() % ( 20 - 10 + 1 )));
		setRAngle(35 + (std::rand() % (35 - 25 + 1)));
		setWidth(10 + (std::rand() % (15 - 10 + 1)));
		setHeight(70 + (std::rand() % (80 - 70 + 1)));
		sf::Color Yellow = sf::Color(100, 115, 50);
		setColorStem(Yellow);
		sf::Color Brown = sf::Color(48, 48, 37);
		setColorFLower(Brown);
		setScalingVariable(0.8);
	}
	//Two formulas. Procedural and direct generation.
	//He will run time.
	double scalingFactor = pow(ScalingV, iteration);
	sf::RectangleShape rect = sf::RectangleShape();
	//Call function to set new position.

	double width = getWidth()*scalingFactor;
	double height = getHeight()*scalingFactor;
	//double width = T.TestWidth()*scalingFactor;
	//double height = T.TestHeight()*scalingFactor;
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
	drawTree(iteration+1,sf::Vector2f(x, y), rootRotation + LAngle, window, true);
	drawTree(iteration+1,sf::Vector2f(x, y), rootRotation - RAngle, window, false);

}
void Tree::Render(sf::RenderWindow& window)
{
	if (getLoop() < 10)
	{
	setWidth(15);
	setHeight(100);
	setHealth(1, 0);
	sf::Color Green = sf::Color(70, 190, 63);
	setColorStem(Green);
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(Width, Length));
	rect.setFillColor(STColor);
	rect.setPosition(StartPoint);
	rect.setRotation(180);
	double x = StartPoint.x - std::sin((180 * 3.14) / 180) *Length;
	double y = StartPoint.y + std::cos((180 * 3.14) / 180) *Length;
	window.draw(rect);
	drawTree(1 ,sf::Vector2f(x, y), 180 - LAngle, window, true);
	drawTree(1 ,sf::Vector2f(x, y), 180 + RAngle, window, false);
	cout << "Render" << endl;
	window.display();
	system("pause");
	if (getLoop() != 9)
	{
	window.clear();
	}
	}
}
void Tree::GrowFlowers(const sf::Vector2f& rootPosition, sf::RenderWindow& window)
{
	double scalingFactor = pow(ScalingV, getLoop());
	sf::CircleShape circle = sf::CircleShape(Width*scalingFactor*1.1);
	//sf::Color ScaleColorC = sf::Color(CIColor.r * scalingFactor, STColor.g * scalingFactor, STColor.b * scalingFactor);
	circle.setFillColor(FlowerColor);
	circle.setPosition(sf::Vector2f(rootPosition.x - circle.getRadius(), rootPosition.y - circle.getRadius()));
	window.draw(circle);
}
//Rand generator for healthy and unhealthy variable ie angle height width and color;
