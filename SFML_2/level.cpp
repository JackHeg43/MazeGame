#include <SFML/Graphics.hpp>
#include "level.h"
#include "mainMenu.h"

const float  PI_F = 3.14159265358979f;

int orderedSet[15 * 15];
int frameCount = 0;
int moveTimer = 225;
int pathPos = 0;

bool updatePath = true;
int path[100];
int pathSize = 0;

sf::Vector2i playerCord = sf::Vector2i(13, 13);
sf::Vector2i enemyCord = sf::Vector2i(4, 4);

sf::Texture player_texture;

sf::RectangleShape enemy = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
sf::RectangleShape conButton = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
sf::Vector2i coinCord;

mainMenu menu;





void level::levelPicker(int value, int gameMap[], sf::RectangleShape displayRects[], sf::Vector2i coinCord) {
    //Sets each boxes properties

    int levelOne[] = {26, 27, 28, 41, 56, 61, 71, 76, 91, 95, 99, 111, 112, 113, 159, 160, 161, 168, 172, 176, 183, 184, 187, 191, 192, 193, 197, 198, 199, 200, 202};
    int levelTwo[] = { 26, 27, 28, 41, 56, 61, 71, 76, 91, 95, 99, 111, 112, 113, 159, 160, 161, 168, 172, 176, 183, 184, 187, 191, 192, 193, 197, 198, 199, 200, 202 };
    int levelThree[] = {16, 17, 18, 26, 27, 28, 31, 32, 42, 43, 46, 58, 61, 62, 63, 64, 65, 68, 69, 70, 71, 72, 73, 106, 109, 110, 111, 112, 113, 114, 115, 118, 151, 152, 153, 156, 157, 158, 159, 162, 163};
    int levelFour[] = { 18, 25, 37, 40, 48, 52, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 96, 97, 98, 99, 100, 101, 102, 103, 109, 110, 121, 122, 124, 139, 141, 142, 143, 144, 145, 146, 157, 172, 181, 186, 187, 190, 191, 192, 193, 196, 197, 198, 199, 200, 201, 202};


    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            displayRects[i + j * 15].setPosition(i * 40.0f, j * 40.0f);
            displayRects[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
            displayRects[i + j * 15].setOutlineThickness(1.f);
            displayRects[i + j * 15].setOutlineColor(sf::Color(0, 0, 0));

            //Sets box obstacles
            if (value == 1)
            {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y) && !(i == coinCord.x && j == coinCord.y)) {
                    if (i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                    else {
                        for (int l = 0; l < sizeof(levelOne)/sizeof(int); l++) {
                            int o = levelOne[l];
                            gameMap[o] = 1;
                            displayRects[o].setFillColor(sf::Color(60, 65, 50));
                        }
                    }
                }
            }
            if (value == 2)
            {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y) && !(i == coinCord.x && j == coinCord.y)) {
                    if (i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }
                else {
                    for (int l = 0; l < sizeof(levelTwo) / sizeof(int); l++) {
                        int o = levelTwo[l];
                        gameMap[o] = 1;
                        displayRects[o].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }

            if (value == 3)
            {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y) && !(i == coinCord.x && j == coinCord.y)) {
                    if (i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                    else {
                        for (int l = 0; l < sizeof(levelThree) / sizeof(int); l++) {
                            int o = levelThree[l];
                            gameMap[o] = 1;
                            displayRects[o].setFillColor(sf::Color(60, 65, 50));
                        }
                    }
                }
                
                
            }

            if (value == 4)
            {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y) && !(i == coinCord.x && j == coinCord.y)) {
                    if (i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }
                else {
                    for (int l = 0; l < sizeof(levelFour) / sizeof(int); l++) {
                        int o = levelFour[l];
                        gameMap[o] = 1;
                        displayRects[o].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }

            /*else if (level1unlock == false && level2unlock == false && level3unlock == false && level4unlock == false)
            {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y) && !(i == coinCord.x && j == coinCord.y)) {
                    if (std::rand() / (float)RAND_MAX < 0.20f || i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }*/
        }

    }
}


int level::levelDesign(sf::RenderWindow& _win, int value) {

    sf::Vector2i playerCord = sf::Vector2i(13, 13);
    sf::Vector2i enemyCord = sf::Vector2i(4, 4);
    sf::Vector2i coinCord = sf::Vector2i(13, 4);

    switch (value) {
    case 1: 
        coinCord = sf::Vector2i(13, 4);
        break;
    case 2:
        coinCord = sf::Vector2i(13, 4);
        break;
    case 3:
        coinCord = sf::Vector2i(7, 1);
        break;
    case 4:
        coinCord = sf::Vector2i(1,2);
        break;
    }
    

    sf::Texture player_texture;

    sf::RectangleShape enemy = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    sf::RectangleShape coin = sf::RectangleShape(sf::Vector2f(40.f, 40.f));


    //creates players in game

    player_texture.loadFromFile("arrow_up.png");
    sf::Sprite playerSprite;
    playerSprite.setTexture(player_texture);
    playerSprite.setPosition(playerCord.x * 40.f, playerCord.y * 40.f);


    enemy.setPosition(enemyCord.x * 40.f, enemyCord.y * 40.f);
    enemy.setFillColor(sf::Color::Red);
    enemy.setOutlineThickness(1.f);
    enemy.setOutlineColor(sf::Color(0, 0, 0));

    coin.setPosition(coinCord.x * 40.f, coinCord.y * 40.f);
    coin.setFillColor(sf::Color::Yellow);
    coin.setOutlineThickness(1.f);
    coin.setOutlineColor(sf::Color(0, 0, 0));

    //Size of map
    
    int gameMap[225];
    sf::RectangleShape displayRects[225];
    


    levelPicker(value, gameMap, displayRects, coinCord);
    
    

    sf::Vector2f NormalisedVectorToMouse;

#pragma region MainMenu

    while (_win.isOpen())
    {
#pragma region ~ Check for a close level1 event ~
        sf::Event event;                                                // Windows is event driven - this code closes the level1 properly

        while (_win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {

                _win.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    if (gameMap[playerCord.x + (playerCord.y - 1) * 15] != 1) playerCord.y -= 1;
                    player_texture.loadFromFile("arrow_up.png");
                    break;
                case sf::Keyboard::Down:
                    if (gameMap[playerCord.x + (playerCord.y + 1) * 15] != 1) playerCord.y += 1;
                    break;
                case sf::Keyboard::Right:
                    if (gameMap[(playerCord.x + 1) + playerCord.y * 15] != 1) playerCord.x += 1;
                    break;
                case sf::Keyboard::Left:
                    if (gameMap[(playerCord.x - 1) + playerCord.y * 15] != 1) playerCord.x -= 1;
                    player_texture.loadFromFile("arrow_left.png");
                    break;
                }
            }
            updatePath = true;
            pathSize = 0;
            pathPos = 0;
            playerSprite.setPosition(playerCord.x * 40.f, playerCord.y * 40.f);
        }

        //code which creates the enemyCord AI pathing
        //if (updatePath == true) {
        //    int counter = 0;

        //    int fullSet[2000];
        //    int fullSetSize = 0;

        //    int openSet[100];
        //    int openSetSize = 2;
        //    openSet[0] = playerCord.x + playerCord.y * 15;
        //    openSet[1] = counter;

        //    int currentIndex = playerCord.x + playerCord.y * 15;

        //    while (currentIndex != enemyCord.x + enemyCord.y * 15) {
        //        currentIndex = openSet[0];
        //        counter = openSet[1] + 1;
        //        int neighbors[4];

        //        neighbors[0] = currentIndex - 1;
        //        neighbors[1] = currentIndex + 1;
        //        neighbors[2] = currentIndex - 15;
        //        neighbors[3] = currentIndex + 15;

        //        for (int i = 0; i < 8; i += 2) {
        //            bool alreadyExists = false;

        //            for (int j = 0; j < fullSetSize; j += 2) {
        //                if (neighbors[i / 2] == fullSet[j]) {
        //                    alreadyExists = true;
        //                    break;
        //                }
        //            }

        //            if (alreadyExists == false) {
        //                if (gameMap[neighbors[i / 2]] != 1) {
        //                    fullSet[fullSetSize] = neighbors[i / 2];
        //                    fullSet[fullSetSize + 1] = counter;
        //                    fullSetSize += 2;

        //                    openSet[openSetSize] = neighbors[i / 2];
        //                    openSet[openSetSize + 1] = counter;
        //                    openSetSize += 2;
        //                }
        //                else {
        //                    fullSet[fullSetSize] = neighbors[i / 2];
        //                    fullSet[fullSetSize + 1] = 100000;
        //                    fullSetSize += 2;
        //                }
        //            }
        //        }

        //        for (int i = 0; i < openSetSize; i++) {
        //            openSet[i] = openSet[i + 2];
        //        }

        //        openSetSize -= 2;
        //    }

        //    for (int i = 0; i < 15 * 15; i++) {
        //        orderedSet[i] = 100000;
        //    }

        //    for (int i = 0; i < fullSetSize; i += 2) {
        //        orderedSet[fullSet[i]] = fullSet[i + 1];
        //    }

        //    orderedSet[playerCord.x + playerCord.y * 15] = 0;

        //    int pathIndex = enemyCord.x + enemyCord.y * 15;

        //    while (pathIndex != playerCord.x + playerCord.y * 15) {
        //        int neighbors[4];

        //        neighbors[0] = pathIndex - 1;
        //        neighbors[1] = pathIndex + 1;
        //        neighbors[2] = pathIndex - 15;
        //        neighbors[3] = pathIndex + 15;

        //        int lowest[2]{ 0, 100000 };
        //        for (int i = 0; i < 4; i++) {
        //            if (orderedSet[neighbors[i]] < lowest[1]) {
        //                lowest[0] = i;
        //                lowest[1] = orderedSet[neighbors[i]];
        //            }
        //        }

        //        pathIndex = neighbors[lowest[0]];

        //        path[pathSize] = pathIndex;

        //        pathSize += 1;
        //    }

        //    updatePath = false;
        //}
        ////code to set the movement speed of the enemy
        //if (frameCount % moveTimer == 0) {
        //    enemyCord.x = path[pathPos] % 15;
        //    enemyCord.y = std::floor(path[pathPos] / 15);
        //    enemy.setPosition(enemyCord.x * 40.f, enemyCord.y * 40.f);
        //    pathPos += 1;

        //    if (moveTimer >= 250) {
        //        moveTimer = 1000 - std::floor(frameCount / 1000) * 4;
        //    }
        //}

        //code to reset/continue blue button (currently resets green player) in level 1
        switch (event.type)
        {

        case sf::Event::MouseMoved:
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (conButton.getGlobalBounds().contains(mousePosF))
            {
                conButton.setFillColor(sf::Color(250, 20, 20));
            }
            else
            {
                conButton.setFillColor(sf::Color::Blue);
            }
        }
        break;

        case sf::Event::MouseButtonPressed:
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (conButton.getGlobalBounds().contains(mousePosF))
            {
                _win.clear();
                _win.draw(playerSprite);
            }
        }

        break;
        }

        frameCount += 1;
        _win.clear(sf::Color::White);
         
        for (int i = 0; i < 15 * 15; i++) {
            _win.draw(displayRects[i]); 
        }

#pragma region draws level to window
        _win.draw(playerSprite);
        //_win.draw(enemy);
        _win.draw(coin);
        _win.display();
#pragma endregion

#pragma region coin collected code 

        //when player touches coin continue to next level
        if (playerCord == coinCord)
        {
            _win.clear();
            _win.display();
            return 1; 
            
            

            //menu.menu(_win);

        }

#pragma endregion      

        //allow events to occur when player makes contact with another object e.g coins, enemies

        if (playerCord == enemyCord) {
            _win.clear(); 
            playerCord = sf::Vector2i(13, 13);
            playerSprite.setPosition(playerCord.x * 40.f, playerCord.y * 40.f); 
            //menu.menu(_win);
        }
    }
    return 0;
}