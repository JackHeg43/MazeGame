#include <iostream>  
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp> 
#include <cmath>
#include "mainMenu.h"
#include "level.h"
#include <SFML/Audio.hpp>

// define render level size constants
#define winWidth 600
#define winHeight 600

sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Level");
#pragma endregion 

int main()
{
#pragma region MainMenu
    //Plays Music upon start up
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("backgroundmusic.wav")) {
       
    }
    sf::Sound intro;
    intro.setBuffer(buffer);
    intro.setVolume(37);
    intro.play();
    
    mainMenu menu;
    
    while (window.isOpen()) {

        menu.menu(window);
    }

return 0;
}
