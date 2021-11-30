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
    
    mainMenu menu;
    level level;

    while (window.isOpen()) {

        menu.menu(window);
    }




return 0;
}
