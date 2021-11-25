#include "SFML/Graphics.hpp"
#include "mainMenu.h"
#include "level.h"

void mainMenu::menu(sf::RenderWindow& _win) {
    sf::Text gameTitle;
    sf::Text levelOneButton;
    sf::Text levelTwoButton;
    sf::Text levelThreeButton;
    sf::Text exitButton;
    
    bool isLevelOneButtonSelected;
    bool isLevelOneButtonPressed; 
     
    bool isLevelTwoButtonSelected;
    bool isLevelTwoButtonPressed;

    bool isLevelThreeButtonSelected;
    bool isLevelThreeButtonPressed;
    
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
    gameTitle.setPosition(300, 50);
    
    levelOneButton.setFont(font);
    levelOneButton.setString("Level One");
    levelOneButton.setPosition(300, 100);

    levelTwoButton.setFont(font);
    levelTwoButton.setString("Level Two");
    levelTwoButton.setPosition(300, 200);

    levelThreeButton.setFont(font);
    levelThreeButton.setString("Level Three"); 
    levelThreeButton.setPosition(300, 300);
    
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setPosition(300, 400);

    isLevelOneButtonSelected = true;
    isLevelTwoButtonSelected = false;
    isLevelThreeButtonSelected = false;
    isExitButtonSelected = false;

    isLevelOneButtonPressed = false;
    isLevelTwoButtonPressed = false;
    isLevelThreeButtonPressed = false;
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
                    if (!isLevelOneButtonSelected)
                    {
                        isLevelOneButtonSelected = true;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    else if (!isLevelTwoButtonSelected) {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = true;
                        isLevelThreeButtonSelected = false;
                        isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!isExitButtonSelected)
                    {
                        isLevelOneButtonSelected = false;
                        isLevelTwoButtonSelected = false;
                        isLevelThreeButtonSelected = false;
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
                    else
                    {
                        isExitButtonPressed = true;
                    }

                    break;
                }
                default:
                {
                    break;
                }
                }

                if (isLevelOneButtonSelected)
                {
                    levelOneButton.setFillColor(sf::Color::Black);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                }
                else if (isLevelTwoButtonSelected)
                {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::Black);
                    levelThreeButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                }
                else if (isLevelThreeButtonSelected) {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::Black);
                    exitButton.setFillColor(sf::Color::White);
                }
                else {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::Black);
                }

                if (isLevelOneButtonPressed)
                {
                    isLevelOneButtonPressed = true;
                    level.levelDesign(_win);

                } else if (isLevelTwoButtonPressed)
                {
                    isLevelTwoButtonPressed = true;
                    level.levelDesign(_win);

                } else if (isLevelThreeButtonPressed)
                {
                    isLevelThreeButtonPressed = true;
                    level.levelDesign(_win);

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
            _win.draw(exitButton);
            _win.display();
        }
    }
}