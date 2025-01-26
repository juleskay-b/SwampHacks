#include <iostream>
#include <SFML/Graphics.hpp>
#include "pet.h"
#include "player.h"
#include "math.h"
#include "Sprites.h"
#include "authentification.h"

using namespace std;

//set text stuff, fun :)
void setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

//tells the player when the pet was created, aka when the game was started - eventually will reset every time the pet dies
void drawDOB(sf::RenderWindow& window, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
    //not done yet, needs to be formatted and drawn
    sf::Text dobTitle;
    dobTitle.setFont(titleFont);
    dobTitle.setString(pet.getName() + " was born on " + player.getDate());
}

void drawInput(sf::RenderWindow& window, sf::Text& userInput, string& userName, float width, float height, sf::Font& font) {
    userInput.setFont(font);
    userInput.setCharacterSize(36);
    userInput.setStyle(sf::Text::Bold);
    userInput.setFillColor(sf::Color::White);

    setText(userInput, (width / 2), (height / 2) - 45);
    window.clear();
    window.draw(userInput);
    window.display();
}

// int startWindow(sf::RenderWindow& window, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
//     sf::Text title;
//     title.setFont(titleFont);
//     title.setString("- Mathfriend -");
//     title.setStyle(sf::Text::Bold);
//     title.setCharacterSize(48);
//     setText(title, (width/2), 64);
//
//     sf::Text welcomeMessage;
//     welcomeMessage.setFont(bodyFont);
//     welcomeMessage.setString("Enter a name for your new pet: ");
//     welcomeMessage.setCharacterSize(30);
//     setText(welcomeMessage,width/2, 144);
//
//
//
//
//
//     //add functionality to display stats like hunger, points, questions answered right/wrong/retried
//
//     window.display();
//
//     sf::RectangleShape updateButton(sf::Vector2f(64,64));
//     updateButton.setPosition(400-32,300-32);
//
//
//
//     bool lock_click = false;
//
//     int hourCounter = 0;
//
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.clear();
//                 window.close();
//                 return 0;
//             }
//
//             if (event.type == sf::Event::MouseButtonPressed) {
//                 if (event.mouseButton.button == sf::Mouse::Left && lock_click != true) {
//                     lock_click = true;
//                 }
//                 if (event.mouseButton.button == sf::Mouse::Right && lock_click!= true) {
//                     lock_click = true;
//                 }
//             }
//             if (event.type == sf::Event::MouseButtonReleased) {
//                 if (event.mouseButton.button == sf::Mouse::Left) {
//                     sf::Vector2i pos = sf::Mouse::getPosition(window);
//                     if (pos.x >= (400-32) || pos.x <= (400 + 32)) {
//                         if (pos.y >= (300-32) || pos.y <= (300+32)) {
//                             pet.Print();
//                             player.printStats();
//                         }
//                     }
//                 }
//             }
//
//
//         }
//
//         if (player.getTime().getTotalSeconds() > hourCounter) {
//             pet.dec();
//             hourCounter++;
//             cout << "Dec" << endl;
//         }
//
//         window.clear();  // Clear previous frame
//         window.draw(welcomeMessage);
//         window.draw(title);
//         window.draw(updateButton);
//         window.display();  // Display the new frame
//     }
//
//     return 0;
// }

int startWindow(sf::RenderWindow& window, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
    sf::Text title;
    title.setFont(titleFont);
    title.setString("- Mathfriend -");
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(48);
    setText(title, (width/2), 64);

    sf::Text welcomeMessage;
    welcomeMessage.setFont(bodyFont);
    welcomeMessage.setString("Enter a name for your new pet: ");
    welcomeMessage.setCharacterSize(30);
    setText(welcomeMessage,width/2, 144);

    string input;

    sf::Text petName;

    drawInput(window, petName, input, width, height, bodyFont);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (input.length() > 0) {
                        pet.rename(input);
                        window.clear();
                        return 1;
                    }
                }else if (event.key.code == sf::Keyboard::Backspace) {
                    if (input.length() > 0) {
                        input.pop_back();
                    }
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if ((isalpha(event.text.unicode) || isspace(event.text.unicode)) && input.size() < 16) {
                    input += static_cast<char>(event.text.unicode);
                }
            }
        }

        petName.setString(input + "|");
        setText(petName, width / 2, 216);

        window.clear();
        window.draw(welcomeMessage);
        window.draw(title);
        window.draw(petName);
        window.display();
    }
}

int gameWindow(sf::RenderWindow& window, sf::Font titleFont, sf::Font& bodyFont, Sprites& textures, int& width, int& height, player& player, Pet& pet) {
    int sidebar_left = 676;
    int sidebar_right = 740;
    int sidebar_top = 64;

    sf::Text title;
    title.setFont(titleFont);
    title.setString("- Mathfriend -");
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(48);
    setText(title, (width/2), 64);

    sf::Text line1;
    line1.setFont(bodyFont);
    line1.setString("Take care of " + pet.getName() + " by solving math questions!\n"
                                                      "Try an easy, medium, or hard problem!");
    line1.setStyle(sf::Text::Italic);
    line1.setCharacterSize(24);
    setText(line1, (width/2), 144);

    sf::Sprite petSprite;
    petSprite.setTexture(textures.getPetTextures().at(0));
    petSprite.setOrigin(width/2, height/2);
    petSprite.setScale(.5,.5);
    petSprite.setPosition(width/2,350);

    sf::Sprite statsButton;
    statsButton.setTexture(textures.getButtons().at(0));
    statsButton.setPosition(sidebar_left,sidebar_top);
    statsButton.setScale(2,2);

    sf::Sprite easyButton;
    easyButton.setTexture(textures.getButtons().at(1));
    easyButton.setPosition(sidebar_left, sidebar_top+124);
    easyButton.setScale(2,2);

    sf::Sprite medButton;
    medButton.setTexture(textures.getButtons().at(2));
    medButton.setPosition(sidebar_left,sidebar_top+248);
    medButton.setScale(2,2);

    sf::Sprite hardButton;
    hardButton.setTexture(textures.getButtons().at(3));
    hardButton.setPosition(sidebar_left,sidebar_top+372);
    hardButton.setScale(2,2);

    bool question_open = false;
    bool lock_click = false;



    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }

            if (!question_open){
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left && lock_click != true) {
                        lock_click = true;
                    }
                    if (event.mouseButton.button == sf::Mouse::Right && lock_click!= true) {
                        lock_click = true;
                    }
                }

                if (event.type == sf::Event::MouseButtonReleased) {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    //Sidebar buttons
                    if (pos.x < sidebar_right && pos.x > sidebar_left) {
                        if (pos.y > sidebar_top && pos.y < sidebar_top+64) {
                            cout << "Stats" << endl;
                        }
                        if (pos.y > sidebar_top + 124 && pos.y < sidebar_top+188) {
                            cout << "Easy" << endl;
                        }
                        if (pos.y > sidebar_top + 248 & pos.y < sidebar_top + 312) {
                            cout << "Medium" << endl;
                        }
                        if (pos.y > sidebar_top + 372 & pos.y < sidebar_top + 436) {
                            cout << "Hard" << endl;
                        }
                    }
                }
            }

        }

        if (pet.getHealth() )

        window.clear();
        window.draw(title);
        window.draw(line1);
        window.draw(petSprite);
        window.draw(statsButton);
        window.draw(easyButton);
        window.draw(medButton);
        window.draw(hardButton);
        window.display();
    }
}

int main() {

    Math math;

    Sprites textures;
    textures.loadButtons();
    textures.loadPetTextures();

    player newPlayer;
    newPlayer.printStats();

    int width = 800;
    int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Mathfriend");

    sf::Font titleFont;
    titleFont.loadFromFile("files/happySchool.ttf");

    sf::Font bodyFont;
    bodyFont.loadFromFile("files/BebasNeue-Regular.ttf");

    int gameStart = startWindow(window, titleFont, bodyFont, width, height, newPlayer, newPlayer.getPet());

    if (gameStart == 1) {
        gameWindow(window, titleFont, bodyFont, textures, width, height, newPlayer, newPlayer.getPet());
    }

    int choice = -1;

    while (choice != 0) {
        cout << "Select a math operation: " << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Print Player Stats" << endl;
        cout << "5. Print " << newPlayer.getPet().getName() << "'s Stats" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << math.additionProblem(newPlayer) << " points!" << endl;
            break;
            case 2:
                cout << math.subtractionProblem(newPlayer) << " points!" << endl;
            break;
            case 3:
                cout << math.multiplicationProblem(newPlayer) << " points!" << endl;
            break;
            case 4:
                newPlayer.printStats();
            break;
            case 5:
                newPlayer.getPet().Print();
            break;
        }
    }












    return 0;
}