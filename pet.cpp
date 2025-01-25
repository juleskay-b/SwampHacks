//
// Created by Jules on 1/25/2025.
//
#include "pet.h"

Pet::Pet(string name, int health) {
    this->name = "Gojo";
    this->health = 75;
    this->points = 100;
}

string Pet::Status(int health) {
    string condition;
    if (health >= 50 || health <= 75) {
        condition == "Excellent";
    } else if (health >= 25 && health <= 49) {
        condition == "Normal";
    } else if (health <= 25) {
        condition == "Bad";
    } else {
        condition == "Dead :-:";
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

#include "pet.h"

Pet::Pet() {
    name = "Gojo";
    health = 75;
    points = 100;
}

Pet::Pet(string name, int health) {
    this->name = name;
    this->health = health;
    this->points = 100;
}

string Pet::Status(int health) {
    string condition;
    if (health >= 50 || health <= 75) {
        condition == "Excellent";
    } else if (health >= 25 && health <= 49) {
        condition == "Normal";
    } else if (health <= 25) {
        condition == "Bad";
    } else {
        condition == "Dead :-:";
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

#include "pet.h"