#include "SFML/Graphics.hpp"
#include "mainMenu.h"
#include "level.h"

void mainMenu::menu(sf::RenderWindow& _win) {
    sf::Text gameTitle;
    sf::Text playButton;
    sf::Text exitButton;

    bool isPlayButtonSelected;
    bool isPlayButtonPressed;

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

    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setPosition(300, 200);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setPosition(300, 400);

    isPlayButtonSelected = true;
    isExitButtonSelected = false;
    isPlayButtonPressed = false;
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
                    if (!isPlayButtonSelected)
                    {
                        isPlayButtonSelected = true;
                        isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!isExitButtonSelected)
                    {
                        isPlayButtonSelected = false;
                        isExitButtonSelected = true;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    isPlayButtonPressed = false;
                    isExitButtonPressed = false;

                    if (isPlayButtonSelected)
                    {
                        isPlayButtonPressed = true;
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

                if (isPlayButtonSelected)
                {
                    playButton.setFillColor(sf::Color::Black);
                    exitButton.setFillColor(sf::Color::White);
                }
                else
                {
                    exitButton.setFillColor(sf::Color::Black);
                    playButton.setFillColor(sf::Color::White);
                }

                if (isPlayButtonPressed)
                {
                    isPlayButtonPressed = true;
                    level.levelDesign(_win);

                }
                else if (isExitButtonPressed)
                {
                    _win.close();
                }
            }

            if (isPlayButtonPressed == false) {
                _win.clear(sf::Color::Blue);
            }
            else {
                _win.clear(sf::Color::White);
            }
            _win.clear(sf::Color::Blue);
            _win.draw(gameTitle);
            _win.draw(playButton);
            _win.draw(exitButton);
            _win.display();
        }
    }
}