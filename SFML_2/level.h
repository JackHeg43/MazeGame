#pragma once
#include <SFML/Graphics.hpp>

class level {
private:


public:
	void levelPicker(int value, int gameMap[], sf::RectangleShape displayRects[], sf::Vector2i CoinCord);
	int levelDesign(sf::RenderWindow& _win, int value); 
};