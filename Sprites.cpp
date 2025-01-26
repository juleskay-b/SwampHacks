//
// Created by Jules on 1/25/2025.
//

#include "Sprites.h"

Sprites::Sprites() {}

void Sprites::loadButtons() {
    statsButton.loadFromFile("files/stats.png");
    buttons.push_back(statsButton);

    easyButton.loadFromFile("files/easy.png");
    buttons.push_back(easyButton);

    medButton.loadFromFile("files/medium.png");
    buttons.push_back(medButton);

    hardButton.loadFromFile("files/hard.png");
    buttons.push_back(hardButton);
}

void Sprites::loadPetTextures() {
    happyPet.loadFromFile("files/happy.png");
    petTextures.push_back(happyPet);

    neutralPet.loadFromFile("files/neutral.png");
    petTextures.push_back(neutralPet);

    sadPet.loadFromFile("files/sad.png");
    petTextures.push_back(sadPet);

    celebrationPet.loadFromFile("files/happy.png");
    petTextures.push_back(celebrationPet);

    upsetPet.loadFromFile("files/angry.png");
    petTextures.push_back(upsetPet);
}

void Sprites::loadBackgrounds() {
    startBack.loadFromFile("files/startBack.png");
    backgrounds.push_back(startBack);

    gameBack.loadFromFile("files/gameBack.png");
    backgrounds.push_back(gameBack);
}


vector<sf::Texture> &Sprites::getPetTextures() {
    return petTextures;
}

vector<sf::Texture> &Sprites::getButtons() {
    return buttons;
}

vector<sf::Texture> &Sprites::getBackgrounds() {
    return backgrounds;
}

