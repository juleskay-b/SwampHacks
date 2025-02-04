//
// Created by Jules on 1/25/2025.
//

#ifndef PET_H
#define PET_H

using namespace std;
#include <iostream>
#include <string>


class Pet {
    string name;
    int health = 75;
    int points;
public:

    //Constructor and Parameterized Constructor
    Pet();

    Pet(string name);

    //Other Functions
    string Status(int health);
    void Print();

    //Getters
    string getName();
    int getHealth();
    int getStatus();

    void rename(string newName);
    void dec();
    void inc(int points);
    void resetHealth();
};



#endif //PET_H