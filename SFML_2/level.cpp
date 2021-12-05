#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "level.h"
#include "mainMenu.h"
#include <string>

void level::levelPicker(int value, int gameMap[], sf::RectangleShape displayRects[], sf::RectangleShape coins[]) {
    
    //Sets each levels design
    int levelOne[] = {26, 27, 28, 41, 56, 61, 71, 76, 91, 95, 99, 111, 112, 113, 159, 160, 161, 168, 172, 176, 183, 184, 187, 191, 192, 193, 197, 198, 199, 200, 202};
    int levelTwo[] = { 26, 27, 28, 41, 56, 61, 71, 76, 91, 95, 99, 111, 112, 113, 159, 160, 161, 168, 172, 176, 183, 184, 187, 191, 192, 193, 197, 198, 199, 200, 202 };
    int levelThree[] = {16, 17, 18, 26, 27, 28, 31, 32, 42, 43, 46, 58, 61, 62, 63, 64, 65, 68, 69, 70, 71, 72, 73, 106, 109, 110, 111, 112, 113, 114, 115, 118, 151, 152, 153, 156, 157, 158, 159, 162, 163};
    int levelFour[] = { 18, 25, 37, 40, 48, 52, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 96, 97, 98, 99, 100, 101, 102, 103, 109, 110, 121, 122, 124, 139, 141, 142, 143, 144, 145, 146, 157, 172, 181, 186, 187, 190, 191, 192, 193, 196, 197, 198, 199, 200, 201, 202};

    //Positions for coins for each level
    int coinlevel1[] = { 66, 73, 174 };
    int coinlevel2[] = {17, 37, 58, 66, 174};
    int coinlevel3[] = { 22, 76, 88, 136, 148 ,188};
    int coinlevel4[] = {32};

    //Sets each boxes properties
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            displayRects[i + j * 15].setPosition(i * 40.0f, j * 40.0f);
            displayRects[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
            displayRects[i + j * 15].setOutlineThickness(1.f);
            displayRects[i + j * 15].setOutlineColor(sf::Color(0, 0, 0));
            

            //Sets box obstacles for each level
            if (value == 1)
            {   
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y)) {
                    //Sets border for each level
                    if (i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                    //Sets obstacles and coins
                    else {
                        for (int l = 0; l < sizeof(levelOne)/sizeof(int); l++) {
                            int o = levelOne[l];
                            gameMap[o] = 1;
                            displayRects[o].setFillColor(sf::Color(60, 65, 50));

                        }
                        for (int l = 0; l < sizeof(coinlevel1) / sizeof(int); l++) {                           
                            int o = coinlevel1[l];                      
                            gameMap[o] = 2;
                            displayRects[o].setFillColor(sf::Color::Yellow);
                        }
                    }                    
                }
            }
            if (value == 2)
            {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y)) {
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
                    for (int l = 0; l < sizeof(coinlevel2) / sizeof(int); l++) {
                        int o = coinlevel2[l];
                        gameMap[o] = 2;
                        displayRects[o].setFillColor(sf::Color::Yellow);
                    }
                }

            }

            if (value == 3) {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y)) {
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
                        for (int l = 0; l < sizeof(coinlevel3) / sizeof(int); l++) {
                            int o = coinlevel3[l];
                            gameMap[o] = 2;
                            displayRects[o].setFillColor(sf::Color::Yellow);
                        }
                    }
                }                 
            }

            if (value == 4) {
                if (!(i == playerCord.x && j == playerCord.y) && !(i == enemyCord.x && j == enemyCord.y)) {
                    if (i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                    else {
                        for (int l = 0; l < sizeof(levelFour) / sizeof(int); l++) {
                            int o = levelFour[l];
                            gameMap[o] = 1;
                            displayRects[o].setFillColor(sf::Color(60, 65, 50));
                        }
                        for (int l = 0; l < sizeof(coinlevel4) / sizeof(int); l++) {
                            int o = coinlevel4[l];
                            gameMap[o] = 2;
                            displayRects[o].setFillColor(sf::Color::Yellow);
                        }
                    }
                }               
            }
        }
    }
}

void level::levelPlayer(int value, int gameMap[]) {
    //Sets postion for player and enemy depending on level chosen
    switch (value) {
    case 1:
        enemyCord = sf::Vector2i(4, 4);
        playerCord = sf::Vector2i(13, 13);
        break;
    case 2:
        enemyCord = sf::Vector2i(4, 4);
        playerCord = sf::Vector2i(13, 13);
        break;
    case 3:
        enemyCord = sf::Vector2i(2, 13);
        playerCord = sf::Vector2i(10, 13);
        break;
    case 4:
        enemyCord = sf::Vector2i(13, 13);
        playerCord = sf::Vector2i(10, 13);
        break;
    }    

    //sets enemy properties
    enemy.setPosition(enemyCord.x * 40.f, enemyCord.y * 40.f);
    enemy.setFillColor(sf::Color::Red);
    enemy.setOutlineThickness(1.f);
    enemy.setOutlineColor(sf::Color(0, 0, 0));
}

int level::levelDesign(sf::RenderWindow& _win, int value) {

    //creates player in game
    sf::Texture player_texture; 
    sf::Sprite playerSprite;
    player_texture.loadFromFile("Left-arrow.png");
    playerSprite.setTexture(player_texture);
    playerSprite.setPosition(playerCord.x * 40.f, playerCord.y * 40.f);

    //Retrieves a file to set the text as font arial
    sf::Font font;

    //Error Handling 
    if (!font.loadFromFile("arial.ttf")) {

    }


    //Sets sound for levels 
    sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("levelmusic.wav")) {
        return -1;
    }
    sf::Sound levelMusic;
    levelMusic.setBuffer(buffer2);
    levelMusic.setVolume(30);

    sf::SoundBuffer buffer3;
    if (!buffer3.loadFromFile("coinCollect.wav")) {
        return -1;
    }
    sf::Sound coinCollect;
    coinCollect.setBuffer(buffer3);

    int gameMap[225];
    sf::RectangleShape displayRects[225];
    sf::RectangleShape coins[225];

    //Sets player's position
    levelPlayer(value, gameMap);
    //Picks level and sets level design
    levelPicker(value, gameMap, displayRects, coins);
    
    levelMusic.play();

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
                //Moves the player based on the key press (Checks for collision first). Checks coin collision, if true, adds to score
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    if (gameMap[playerCord.x + (playerCord.y - 1) * 15] != 1) playerCord.y -= 1;
                    if (gameMap[playerCord.x + (playerCord.y) * 15] == 2) {
                        gameMap[playerCord.x + (playerCord.y) * 15] = 0;
                        displayRects[playerCord.x + (playerCord.y) * 15].setFillColor(sf::Color::White);
                        coinCollect.play();
                        score++;
                    }
                    player_texture.loadFromFile("Up-arrow.png");
                    break;
                case sf::Keyboard::Down:
                    if (gameMap[playerCord.x + (playerCord.y + 1) * 15] != 1) playerCord.y += 1;
                    if (gameMap[playerCord.x + (playerCord.y) * 15] == 2) {
                        gameMap[playerCord.x + (playerCord.y) * 15] = 0;
                        displayRects[playerCord.x + (playerCord.y) * 15].setFillColor(sf::Color::White);
                        coinCollect.play();
                        score++;
                    }
                    player_texture.loadFromFile("Down-arrow.png");
                    break;
                case sf::Keyboard::Right:
                    if (gameMap[(playerCord.x + 1) + playerCord.y * 15] != 1) playerCord.x += 1;
                    if (gameMap[playerCord.x + (playerCord.y) * 15] == 2) {
                        gameMap[playerCord.x + (playerCord.y) * 15] = 0;
                        displayRects[playerCord.x + (playerCord.y) * 15].setFillColor(sf::Color::White);
                        coinCollect.play();
                        score++;
                    }
                    player_texture.loadFromFile("Right-arrow.png");
                    break;
                case sf::Keyboard::Left:
                    if (gameMap[(playerCord.x - 1) + playerCord.y * 15] != 1) playerCord.x -= 1;
                    if (gameMap[playerCord.x + (playerCord.y) * 15] == 2) {
                        gameMap[playerCord.x + (playerCord.y) * 15] = 0;
                        displayRects[playerCord.x + (playerCord.y) * 15].setFillColor(sf::Color::White);
                        coinCollect.play();
                        score++;
                    }
                    player_texture.loadFromFile("Left-arrow.png");
                    break;
                }
            }
            updatePath = true;
            pathSize = 0;
            pathPos = 0;
            //Updates players position
            playerSprite.setPosition(playerCord.x * 40.f, playerCord.y * 40.f);
        }

        //code which creates the enemyCord AI pathing
        if (updatePath == true) {
            int counter = 0;

            int fullset[2000];
            int fullsetsize = 0;

            int openset[100];
            int opensetsize = 2;
            openset[0] = playerCord.x + playerCord.y * 15;
            openset[1] = counter;

            int currentindex = playerCord.x + playerCord.y * 15;

            while (currentindex != enemyCord.x + enemyCord.y * 15) {
                currentindex = openset[0];
                counter = openset[1] + 1;
                int neighbors[4];

                neighbors[0] = currentindex - 1;
                neighbors[1] = currentindex + 1;
                neighbors[2] = currentindex - 15;
                neighbors[3] = currentindex + 15;

                for (int i = 0; i < 8; i += 2) {
                    bool alreadyexists = false;

                    for (int j = 0; j < fullsetsize; j += 2) {
                        if (neighbors[i / 2] == fullset[j]) {
                            alreadyexists = true;
                            break;
                        }
                    }

                    if (alreadyexists == false) {
                        if (gameMap[neighbors[i / 2]] != 1) {
                            fullset[fullsetsize] = neighbors[i / 2];
                            fullset[fullsetsize + 1] = counter;
                            fullsetsize += 2;

                            openset[opensetsize] = neighbors[i / 2];
                            openset[opensetsize + 1] = counter;
                            opensetsize += 2;
                        }
                        else {
                            fullset[fullsetsize] = neighbors[i / 2];
                            fullset[fullsetsize + 1] = 100000;
                            fullsetsize += 2;
                        }
                    }
                }

                for (int i = 0; i < opensetsize; i++) {
                    openset[i] = openset[i + 2];
                }

                opensetsize -= 2;
            }

            for (int i = 0; i < 15 * 15; i++) {
                orderedSet[i] = 100000;
            }

            for (int i = 0; i < fullsetsize; i += 2) {
                orderedSet[fullset[i]] = fullset[i + 1];
            }

            orderedSet[playerCord.x + playerCord.y * 15] = 0;

            int pathindex = enemyCord.x + enemyCord.y * 15;

            while (pathindex != playerCord.x + playerCord.y * 15) {
                int neighbors[4];

                neighbors[0] = pathindex - 1;
                neighbors[1] = pathindex + 1;
                neighbors[2] = pathindex - 15;
                neighbors[3] = pathindex + 15;

                int lowest[2]{ 0, 100000 };
                for (int i = 0; i < 4; i++) {
                    if (orderedSet[neighbors[i]] < lowest[1]) {
                        lowest[0] = i;
                        lowest[1] = orderedSet[neighbors[i]];
                    }
                }

                pathindex = neighbors[lowest[0]];

                path[pathSize] = pathindex;

                pathSize += 1;
            }

            updatePath = false;
        }
        //code to set the movement speed of the enemy
        if (frameCount % moveTimer == 0) {
            enemyCord.x = path[pathPos] % 15;
            enemyCord.y = std::floor(path[pathPos] / 15);
            enemy.setPosition(enemyCord.x * 40.f, enemyCord.y * 40.f);
            pathPos += 1;

            if (moveTimer >= 250) { 
                moveTimer = 1000 - std::floor(frameCount / 1000) * 4;
            }
        }

        frameCount += 1;
        _win.clear(sf::Color::White);
         

        //Draws level
        for (int i = 0; i < 15 * 15; i++) {
            _win.draw(displayRects[i]); 
        }
        //Draws coins
        for (int i = 0; i < 15 * 15; i++) {
            _win.draw(coins[i]);
        }
        
        //Draws player and enemy
#pragma region draws level to window
        _win.draw(playerSprite);
        _win.draw(enemy);
        
        _win.display();
#pragma endregion

#pragma region coin collected code 
        //returns to menu if player has collected all the coins in each level
        switch (value) {
        case 1:
            if (score == 3) {
                score = 0;
                return 1;
            }
            break;
        case 2:
            if (score == 5) {
                score = 0;
                return 2;
            }
            break;
        case 3:
            if (score == 6) {
                score = 0;
                return 3;
            }
            break;
        case 4:
            if (score == 1) {
                score = 0;
                return 4;
            }
        }
        
#pragma endregion      

        //when player hits enemy, returns to main menu
        if (playerCord == enemyCord) {
            return -1;
        }
    }
    return 0;
}