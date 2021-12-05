#pragma once
#include <SFML/Graphics.hpp>

class level {
private:
	int orderedSet[15 * 15];
	int frameCount = 0;
	int moveTimer = 225;
	int pathPos = 0;

	bool updatePath = true;
	int path[100];
	int pathSize = 0;

	int score = 0;

	//Declare player and enemy 
	sf::Vector2i playerCord;
	sf::Vector2i enemyCord;

	//Sets up enemy
	sf::RectangleShape enemy = sf::RectangleShape(sf::Vector2f(40.f, 40.f));

public:
	void levelPicker(int value, int gameMap[], sf::RectangleShape displayRects[], sf::RectangleShape coins[]);
	void levelPlayer(int value, int gameMap[]);
	int levelDesign(sf::RenderWindow& _win, int value); 
};