#include "SFML/Graphics.hpp"
#include "mainMenu.h"
#include "level.h"

int keyPress = 1;

void mainMenu::menu(sf::RenderWindow& _win) {
    sf::Text gameTitle;
    sf::Text levelOneButton;
    sf::Text levelTwoButton;
    sf::Text levelThreeButton;
    sf::Text levelFourButton;
    sf::Text exitButton;
    
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

    level level;

    //Retrieves a file to set the text as font arial 
    sf::Font font;

    //Error Handling 
    if (!font.loadFromFile("arial.ttf")) {

    }

    gameTitle.setFont(font);
    gameTitle.setString("Maze Game");
    gameTitle.setPosition(250, 50);
    
    levelOneButton.setFont(font);
    levelOneButton.setString("Level One");
    levelOneButton.setPosition(50, 100);

    levelTwoButton.setFont(font);
    levelTwoButton.setString("Level Two");
    levelTwoButton.setPosition(50, 200);

    levelThreeButton.setFont(font);
    levelThreeButton.setString("Level Three"); 
    levelThreeButton.setPosition(50, 300);

    levelFourButton.setFont(font);
    levelFourButton.setString("Level Four");
    levelFourButton.setPosition(50, 400);
    
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setPosition(50, 500);

    isLevelOneButtonSelected = true;
    isLevelTwoButtonSelected = false;
    isLevelThreeButtonSelected = false;
    isLevelFourButtonSelected = false;
    isExitButtonSelected = false;

    isLevelOneButtonPressed = false;
    isLevelTwoButtonPressed = false;
    isLevelThreeButtonPressed = false;
    isLevelFourButtonPressed = false;
    isExitButtonPressed = false;


    while (_win.isOpen()) {
        sf::Event event;
        while (_win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _win.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
               
                case sf::Keyboard::Up:
                {
                    if (keyPress > 1) {
                        keyPress--;
                    }

                    if (keyPress == 1) {
                        isLevelOneButtonSelected = true;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 2) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = true;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 3) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = true;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 4) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = true;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 5) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = true;
                    }

                    

                    break;
                }
                
                case sf::Keyboard::Down:
                {

                    if (keyPress < 5) {
                        keyPress++;
                    }
                    if (keyPress == 1) {
                        isLevelOneButtonSelected = true;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 2) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = true;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 3) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = true;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 4) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = true;
                        isExitButtonSelected = false;
                    }
                    else if (keyPress == 5) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isLevelFourButtonSelected = false;
                        isExitButtonSelected = true;
                    }

                    
                    break;
                }
                case sf::Keyboard::Return:
                {
                    isLevelOneButtonPressed = false;
                    isLevelTwoButtonPressed = false;
                    isLevelThreeButtonPressed = false;
                    isExitButtonPressed = false;

                    if (isLevelOneButtonSelected)
                    {
                        isLevelOneButtonPressed = true;
                    }
                    else if (isLevelTwoButtonSelected)
                    {
                        isLevelTwoButtonPressed = true;

                    } else if (isLevelThreeButtonSelected)
                    {
                        isLevelThreeButtonPressed = true;
                    }
                    else if (isLevelFourButtonSelected) {
                        isLevelFourButtonPressed = true;
                    }
                    else
                    {
                        isExitButtonPressed = true;
                    }

                    break;
                }
                default:
                {
                    isLevelOneButtonSelected = true;
                    isLevelTwoButtonSelected = false;
                    isLevelThreeButtonSelected = false;
                    isLevelFourButtonSelected = false;
                    isExitButtonSelected = false;
                    break;
                }
                }

                if (isLevelOneButtonSelected)
                {
                    levelOneButton.setFillColor(sf::Color::Black);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                }
                else if (isLevelTwoButtonSelected)
                {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::Black);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                }
                else if (isLevelThreeButtonSelected) {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::Black);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                }
                else if (isLevelFourButtonSelected) {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::Black);
                    exitButton.setFillColor(sf::Color::White);
                }
                else {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::Black);
                }

                if (isLevelOneButtonPressed)
                {
                    isLevelOneButtonPressed = false;
                    level.levelDesign(_win, 1);

                } else if (isLevelTwoButtonPressed)
                {
                    isLevelTwoButtonPressed = false;
                    level.levelDesign(_win, 2);

                } else if (isLevelThreeButtonPressed)
                {
                    isLevelThreeButtonPressed = false;
                    level.levelDesign(_win, 3);

                } 
                else if (isLevelFourButtonPressed) {
                    isLevelFourButtonPressed = false;
                    level.levelDesign(_win, 4);
                }
                else if (isExitButtonPressed)
                {
                    _win.close();
                }
            }

            _win.clear(sf::Color::Blue);
            _win.draw(gameTitle);
            _win.draw(levelOneButton);
            _win.draw(levelTwoButton);
            _win.draw(levelThreeButton);
            _win.draw(levelFourButton);
            _win.draw(exitButton);
            _win.display();
        }
    }
}