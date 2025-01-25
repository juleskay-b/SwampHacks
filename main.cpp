#include <iostream>
#include <SFML/Graphics.hpp>
#include "pet.h"
#include "player.h"
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

int statsWindow(sf::RenderWindow& window, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
    sf::Text statsTitle;
    statsTitle.setFont(titleFont);
    statsTitle.setString("IT'S ALIVEEEEEE!");
    statsTitle.setStyle(sf::Text::Bold);
    statsTitle.setCharacterSize(40);
    setText(statsTitle, (width/2), (height/2)-150);

    //add functionality to display stats like hunger, points, questions answered right/wrong/retried

    window.display();

    sf::RectangleShape updateButton(sf::Vector2f(64,64));
    updateButton.setPosition(400-32,300-32);

    //

    bool lock_click = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left && lock_click != true) {
                    lock_click = true;
                }
                if (event.mouseButton.button == sf::Mouse::Right && lock_click!= true) {
                    lock_click = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    if (pos.x >= (400-32) || pos.x <= (400 + 32)) {
                        if (pos.y >= (300-32) || pos.y <= (300+32)) {
                            pet.Print();
                            player.printTimePlayed();
                        }
                    }
                }
            }


        }
        window.draw(statsTitle);
        window.draw(updateButton);
        window.display();
    }

    return 0;
}

int main() {
    int width = 800;
    int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Player Statistics");

    Pet newPet;

    player newPlayer;
    newPlayer.printTimePlayed();

    sf::Font titleFont;
    titleFont.loadFromFile("files/happySchool.ttf");

    sf::Font bodyFont;
    bodyFont.loadFromFile("files/BebasNeue-Regular.ttf");

    statsWindow(window, titleFont, bodyFont, width, height, newPlayer, newPet);











    return 0;
}