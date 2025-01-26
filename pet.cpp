//
// Created by Jules on 1/25/2025.
//
#include "pet.h"

Pet::Pet() {
    name = "Gojo";
    health = 75;
    points = 100;
}

Pet::Pet(string name) {
    this->name = name;
    health = 75;
    points = 100;
}

string Pet::Status(int health) {
    string condition;
    if (health >= 50 || health <= 75) {
        condition = "Excellent";
    } else if (health >= 25 && health <= 49) {
        condition = "Normal";
    } else if (health <= 25) {
        condition = "Bad";
    } else {
        condition = "Dead :-:";
    }
    return condition;
}

void Pet::Print() {
    cout << "The Tomodachi's name is " << name << "!" << endl;
    cout << "Health: " << health << endl;
}

string Pet::getName() {
    return name;
}

int Pet::getHealth() {
    return health;
}

void Pet::rename(string newName) {
    name=newName;
}


void Pet::dec() {
    health--;
}

void Pet::inc(int points) {
    health+=points;
}

void Pet::resetHealth() {
    health = 75;
}

