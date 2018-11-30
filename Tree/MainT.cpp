#include "MainT.h"
MainTree::MainTree()
{

}
MainTree::~MainTree()
{

}
void MainTree::RunApp()
{
	Choice();
}
void MainTree::Choice()
{
	int y = 0, x = 0;

	while (y == 0)
	{
		cin >> x;
		//Thanks StackOverFlow
		if (!cin) // or if(cin.fail())
		{
			// user didn't input a number
			// reset failbit
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//skip bad input
		}
		switch (x)
		{
		case 1:
			//Healthy
			TreeFrame();
			break;
		case 2:
			//Exit
			y = 1;
			break;
		default:
			break;
		}
	}
}
void MainTree::TreeFrame()
{
	int i = 0, x = 0;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
	while (window.isOpen())
	{
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
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					i++;
					std::cout << i << std::endl;
				}
			}
				Tree T = Tree();
				T.setStartLocation(500, 550);
				T.setLAngle(15);
				T.setRAngle(25);
				T.setIterations(i);
				T.setWidth(15);
				T.setHeight(75);
				sf::Color Green = sf::Color(70, 190, 63);
				T.setColorST(Green);
				sf::Color Purple = sf::Color(240, 0, 240);
				T.setColorCI(Purple);
				T.setScalingV(0.90);
				T.Render(window);
				window.display();
		}
		}
}