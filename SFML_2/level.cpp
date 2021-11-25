#include <SFML/Graphics.hpp>
#include "level.h"
#include "mainMenu.h"


const float  PI_F = 3.14159265358979f;

sf::Vector2i player1 = sf::Vector2i(13, 13);
sf::Vector2i player2 = sf::Vector2i(4, 4);

sf::Texture player_texture;


sf::RectangleShape enemy = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
sf::RectangleShape conButton = sf::RectangleShape(sf::Vector2f(40.f, 40.f));

mainMenu menu;


bool level1unlock = false;
bool level2unlock = true;
bool level3unlock = false;
bool level4unlock = false;


void level::levelDesign(sf::RenderWindow& _win) {
    conButton.setFillColor(sf::Color::Blue);

    //creates players in game

    sf::Texture player_texture;
    sf::Vector2i player = sf::Vector2i(13, 13);
    player_texture.loadFromFile("arrow_up.png");
    sf::Sprite playerSprite;
    playerSprite.setTexture(player_texture);
    playerSprite.setPosition(player.x * 40.f, player.y * 40.f);
    enemy.setPosition(player2.x * 40.f, player2.y * 40.f);
    enemy.setFillColor(sf::Color::Red);

    //Size of map
    int gameMap[15 * 15];
    sf::RectangleShape displayRects[15 * 15];


    //Sets each boxes properties
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            displayRects[i + j * 15].setPosition(i * 40.0f, j * 40.0f);
            displayRects[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
            displayRects[i + j * 15].setOutlineThickness(1.f);
            displayRects[i + j * 15].setOutlineColor(sf::Color(0, 0, 0));

            //Sets box obstacles
            if (level1unlock == true)
            {
                if (!(i == player1.x && j == player1.y) && !(i == player2.x && j == player2.y)) {
                    if (std::rand() / (float)RAND_MAX < 0.10f || i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(30, 30, 10));
                    }
                }
            }
            if (level2unlock == true)
            {
                if (!(i == player1.x && j == player1.y) && !(i == player2.x && j == player2.y)) {
                    if (std::rand() / (float)RAND_MAX < 0.15f || i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }

            if (level3unlock == true)
            {
                if (!(i == player1.x && j == player1.y) && !(i == player2.x && j == player2.y)) {
                    if (std::rand() / (float)RAND_MAX < 0.19f || i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }

            if (level4unlock == true)
            {
                if (!(i == player1.x && j == player1.y) && !(i == player2.x && j == player2.y)) {
                    if (std::rand() / (float)RAND_MAX < 0.21f || i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }

            else if (level1unlock == false && level2unlock == false && level3unlock == false && level4unlock == false)
            {
                if (!(i == player1.x && j == player1.y) && !(i == player2.x && j == player2.y)) {
                    if (std::rand() / (float)RAND_MAX < 0.20f || i == 0 || j == 0 || i == 14 || j == 14) {
                        gameMap[i + j * 15] = 1;
                        displayRects[i + j * 15].setFillColor(sf::Color(60, 65, 50));
                    }
                }

            }
        }

    }


    sf::Vector2f NormalisedVectorToMouse;


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
                    if (gameMap[player1.x + (player1.y - 1) * 15] != 1) player1.y -= 1;
                    player_texture.loadFromFile("arrow_up.png");
                    break;
                case sf::Keyboard::Down:
                    if (gameMap[player1.x + (player1.y + 1) * 15] != 1) player1.y += 1;
                    break;
                case sf::Keyboard::Right:
                    if (gameMap[(player1.x + 1) + player1.y * 15] != 1) player1.x += 1;
                    break;
                case sf::Keyboard::Left:
                    if (gameMap[(player1.x - 1) + player1.y * 15] != 1) player1.x -= 1;
                    player_texture.loadFromFile("arrow_left.png");
                    break;
                }
            }
            playerSprite.setPosition(player1.x * 40.f, player1.y * 40.f);
        }

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

#pragma endregion

        _win.clear(sf::Color::White);
        for (int i = 0; i < 15 * 15; i++) {
            _win.draw(displayRects[i]);
        }

        _win.draw(playerSprite);
        _win.draw(enemy);
        _win.draw(conButton);
        _win.display();

        //allow events to occur when player makes contact with another object e.g coins, enemies

        if (player1 == player2) {
            _win.clear();
            player1 = sf::Vector2i(13, 13);
            playerSprite.setPosition(player1.x * 40.f, player1.y * 40.f); 
            menu.menu(_win);
        }
    }
}