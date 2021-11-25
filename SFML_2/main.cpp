/*
* An SFML application using a vector list to store point data - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* Set up your own VS2019 project https://www.youtube.com/watch?v=lFzpkvrscs4
*/

#include <iostream>  
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp> 
#include <cmath>
#include "cells.h"
#include "mainMenu.h"
#include "level.h"
// define render level1 size constants
#define winWidth 600
#define winHeight 600
const float  PI_F = 3.14159265358979f;

//sf::RenderWindow mainMenu(sf::VideoMode(winWidth, winHeight), "main menu");
sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Level");

#pragma endregion

int main()
{
    /*  ====
        Menu
        ====
    */   


#pragma region MainMenu
    //mainMenu.draw(conButton);
    //mainMenu.display();
    //while (mainMenu.isOpen())
    //{
    //    sf::Event event;
    //    while (mainMenu.pollEvent(event))
    //    {
    //        #pragma region code of selecting level 1
    //        //code to reset/continue blue button (currently resets green player) in level 1
    //        switch (event.type)
    //        {
    //        case sf::Event::MouseMoved:
    //        {
    //            sf::Vector2i mousePos = sf::Mouse::getPosition(mainMenu);
    //            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    //            if (conButton.getGlobalBounds().contains(mousePosF))
    //            {
    //                conButton.setFillColor(sf::Color(250, 20, 20));
    //            }
    //            else
    //            {
    //                conButton.setFillColor(sf::Color::Blue);
    //            }
    //        }
    //        break;
    //
    //        case sf::Event::MouseButtonPressed:
    //        {
    //            //sf::Vector2i mousePos = sf::Mouse::getPosition(mainMenu);
    //            //sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    //            //if (conButton.getGlobalBounds().contains(mousePosF))
    //            //{
    //            //    mainMenu.setVisible(false);
    //            //    level1.setVisible(true);
    //            //    level1.clear(sf::Color::White);
    //                for (int i = 0; i < 15 * 15; i++) {
    //                    level1.draw(displayRects[i]);
    //                }
    //                level1.display();
    //            //}
    //            level1.setVisible(true);
    //        
    //        }
    //
    //        break;
    //        }
    //        #pragma endregion
    //
    //    }
    //}
    mainMenu menu;
    level level;

    while (window.isOpen()) {
        menu.menu(window);
    }




return 0;
}
