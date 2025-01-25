#include <iostream>
#include <SFML/Graphics.hpp>
#include "pet.h"
#include "player.h"
#include "authentification.h"

using namespace std;

void setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

int statsWindow(sf::RenderWindow& window, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player) {
    sf::Text statsTitle;
    statsTitle.setFont(titleFont);
    statsTitle.setString("Player!");
    statsTitle.setStyle(sf::Text::Bold);
    statsTitle.setCharacterSize(24);
    setText(statsTitle, (width/2), (height/2)-150);

    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }
        }
        window.draw(statsTitle);
        window.display();
    }

    return 0;
}

int main() {
    int width = 800;
    int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Player Statistics");


    player newPlayer;
    newPlayer.printTimePlayed();

    sf::Font titleFont;
    titleFont.loadFromFile("files/happySchool.ttf");

    sf::Font bodyFont;
    bodyFont.loadFromFile("files/BebasNeue-Regular.ttf");

    statsWindow(window, titleFont, bodyFont, width, height, newPlayer);











    return 0;
}