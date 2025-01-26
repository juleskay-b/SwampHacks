#include <iostream>
#include <SFML/Graphics.hpp>
#include "pet.h"
#include "player.h"
#include "math.h"
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
                        window.close();
                        return 1;
                    }
                }else if (event.key.code == sf::Keyboard::Backspace) {
                    if (input.length() > 0) {
                        input.pop_back();
                    }
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if (isalpha(event.text.unicode) && input.size() < 10) {
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

void gameWindow(sf::RenderWindow& window, sf::Font titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
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
    line1.setCharacterSize(30);
    setText(line1, (width/2), 144);

    sf::RectangleShape updateButton(sf::Vector2f(64,64));
    updateButton.setPosition(400-32,300-32);
}

int main() {

    Math math;

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
        gameWindow(window, titleFont, bodyFont, width, height, newPlayer, newPlayer.getPet());
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