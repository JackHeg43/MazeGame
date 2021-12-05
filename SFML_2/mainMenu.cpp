#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "mainMenu.h"
#include "level.h"

//Sets text properties
void mainMenu::menuDesign() {

    //Error Handling 
    if (!font.loadFromFile("ARCADECLASSIC.ttf")) {

    }   

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
}

void mainMenu::menu(sf::RenderWindow& _win) {
    
    level level;

    menuDesign();

    //Sets up Game Title
    sf::Image gameTitle;
    if (!gameTitle.loadFromFile("gameTitle.png")) {

    }
    
    sf::Texture titleTexture;
    titleTexture.loadFromImage(gameTitle);

    sf::Sprite title;
    title.setTexture(titleTexture);
    title.setPosition(300, 325);

    //Sets up background image
    sf::Image backgroundImage;
    if (!backgroundImage.loadFromFile("backgroundImage.jpg")) {

    }

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromImage(backgroundImage);

    sf::Sprite background;
    background.setTexture(backgroundTexture);
    
    //Sets up sound 
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("button.wav")) {

    }
    sf::Sound buttonSound;
    buttonSound.setBuffer(buffer);

    sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("deathsound.wav")) {
        
    }
    sf::Sound deathSound;
    deathSound.setBuffer(buffer2);

    sf::SoundBuffer complete;
    if (!complete.loadFromFile("levelUp.wav")) {

    }
    sf::Sound levelComplete;
    levelComplete.setBuffer(complete);
    levelComplete.setVolume(50);

    //Sets up stars and positions them according to their corresponding level i.e. star1 = level1
    sf::Texture starTexture;
    starTexture.loadFromFile("star.png");

    star1.setTexture(starTexture);
    star1.setPosition(200, 105);

    star2.setTexture(starTexture);
    star2.setPosition(200, 205);

    star3.setTexture(starTexture);
    star3.setPosition(230, 305);

    star4.setTexture(starTexture);
    star4.setPosition(210, 405);

    //What button is selected
    isLevelOneButtonSelected = true;
    isLevelTwoButtonSelected = false;
    isLevelThreeButtonSelected = false;
    isLevelFourButtonSelected = false;
    isExitButtonSelected = false;

    //Checks if a button has been hit
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
                switch (event.key.code){
                case sf::Keyboard::Up:
                {
                    
                    if (keyPress > 1) {
                        keyPress--;
                    }

                    
                    break;
                }
                case sf::Keyboard::Down:{

                    if (keyPress < 5) {
                        keyPress++;
                    }
                      
                    break;
                }
                case sf::Keyboard::Return:
                {
                    isLevelOneButtonPressed = false;
                    isLevelTwoButtonPressed = false;
                    isLevelThreeButtonPressed = false;
                    isLevelFourButtonPressed = false;
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
                    else {
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

                //Selects a button depending on keyPress
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
                //Changes text color upon which text is selected
                if (isLevelOneButtonSelected)
                {
                    levelOneButton.setFillColor(sf::Color::Black);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                    buttonSound.play();
                }
                else if (isLevelTwoButtonSelected)
                {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::Black);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                    buttonSound.play();
                }
                else if (isLevelThreeButtonSelected) {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::Black);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::White);
                    buttonSound.play();
                }
                else if (isLevelFourButtonSelected) {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::Black);
                    exitButton.setFillColor(sf::Color::White);
                    buttonSound.play();
                }
                else {
                    levelOneButton.setFillColor(sf::Color::White);
                    levelTwoButton.setFillColor(sf::Color::White);
                    levelThreeButton.setFillColor(sf::Color::White);
                    levelFourButton.setFillColor(sf::Color::White);
                    exitButton.setFillColor(sf::Color::Black);
                    buttonSound.play();
                }

                //When user selects a level, resets press and directs to selected level
                if (isLevelOneButtonPressed)
                {
                    isLevelOneButtonPressed = false;
                    pass1 = level.levelDesign(_win, 1);                

                } else if (isLevelTwoButtonPressed)
                {
                    isLevelTwoButtonPressed = false;
                    pass2 = level.levelDesign(_win, 2);

                } else if (isLevelThreeButtonPressed)
                {
                    isLevelThreeButtonPressed = false;
                    pass3 = level.levelDesign(_win, 3);

                } 
                else if (isLevelFourButtonPressed) {
                    isLevelFourButtonPressed = false;
                    pass4 = level.levelDesign(_win, 4);
                }
                else if (isExitButtonPressed)
                {
                    _win.close();
                }
            }

            //Draws to window
            _win.clear(sf::Color::Blue);
            _win.draw(background);
            _win.draw(title);
            _win.draw(levelOneButton);
            _win.draw(levelTwoButton);
            _win.draw(levelThreeButton);
            _win.draw(levelFourButton);
            _win.draw(exitButton);
            
            //When user completes a level value is passed to starFinal || Plays a sound if a user dies
            if (pass1 == 1) {
                pass1 = 0;
                starFinal1 = 1;
                levelComplete.play();
            }
            else if (pass1 == -1) {
                pass1 = 0;
                deathSound.play();
            }
            if (pass2 == 2) {
                pass2 = 0;
                starFinal2 = 2;
                levelComplete.play();
            }
            else if (pass2 == -1) {
                pass2 = 0;
                deathSound.play();
            }
            if (pass3 == 3) {
                pass3 = 0;
                starFinal3 = 3; 
                levelComplete.play();
            }
            else if (pass3 == -1) {
                pass3 = 0;
                deathSound.play();
            }
            if (pass4 == 4) {
                pass4 = 0;
                starFinal4 = 4; 
                levelComplete.play();
            }
            else if (pass4 == -1) {
                pass4 = 0;
                deathSound.play();
            }

            //If a user completes a level, draws star, if user replays level and dies, star remains
            if (starFinal1 == 1) {
                _win.draw(star1);
            } 
            if (starFinal2 == 2) {
                _win.draw(star2);
            }
            if (starFinal3 == 3) {
                _win.draw(star3);
            }
            if (starFinal4 == 4) {
                _win.draw(star4);
            }
            _win.display();
        }
    }
}