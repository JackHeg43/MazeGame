#pragma once
#include <SFML/Graphics.hpp>

class mainMenu {
private:
	//Used to navigate menu
	int keyPress = 1;

	//Used to display a star when a level is completed
	int pass1 = 0;
	int pass2 = 0;
	int pass3 = 0;
	int pass4 = 0;

	//keeps star even if user fails level
	int starFinal1 = 0;
	int starFinal2 = 0;
	int starFinal3 = 0;
	int starFinal4 = 0;

	//Retrieves a file to set the text
	sf::Font font;

	//Text and sprites for Main Menu
	sf::Text gameTitle;
	sf::Text levelOneButton;
	sf::Text levelTwoButton;
	sf::Text levelThreeButton;
	sf::Text levelFourButton;
	sf::Text exitButton;

	sf::Sprite star1; 
	sf::Sprite star2; 
	sf::Sprite star3; 
	sf::Sprite star4; 

	//Sets up menu buttons
	bool isLevelOneButtonSelected;
	bool isLevelOneButtonPressed;

	bool isLevelTwoButtonSelected;
	bool isLevelTwoButtonPressed;

	bool isLevelThreeButtonSelected;
	bool isLevelThreeButtonPressed;

	bool isLevelFourButtonSelected;
	bool isLevelFourButtonPressed;

	bool isExitButtonSelected;
	bool isExitButtonPressed;

public:
    void menuDesign();
	void menu(sf::RenderWindow& _win);
};
