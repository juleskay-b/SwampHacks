//
// Created by Jules on 1/25/2025.
//

#ifndef Textures_H
#define Textures_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Sprites {
    sf::Texture happyPet;
    sf::Texture neutralPet;
    sf::Texture sadPet;
    sf::Texture celebrationPet;
    sf::Texture upsetPet;
    vector<sf::Texture> petTextures;

    sf::Texture statsButton;
    sf::Texture easyButton;
    sf::Texture medButton;
    sf::Texture hardButton;
    vector<sf::Texture> buttons;

    sf::Texture startBack;
    sf::Texture gameBack;
    vector<sf::Texture> backgrounds;

public:
    Sprites();

    void loadPetTextures();
    void loadButtons();
    void loadBackgrounds();

    vector<sf::Texture>& getPetTextures();
    vector<sf::Texture>& getButtons();
    vector<sf::Texture>& getBackgrounds();
};



#endif //Textures_H
