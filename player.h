//
// Created by Jules on 1/25/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>
#include <iostream>
#include <ctime>
#include "pet.h"
using namespace std;

struct Time {
    chrono::steady_clock::time_point start;
    chrono::system_clock::time_point startDate;
    struct tm datetime;
public:
    Time();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getTotalSeconds();
    int getDate();
    void resetTime();
};

class player {
    string name;
    Time startTime;
    int questionsCorrect;
    int questionsWrong;
    int totalPointsEarned;
    Pet myPet;

public:
    player() : myPet("Gojo"){
        name = "Player";
        startTime = Time();
        questionsCorrect = 0;
        questionsWrong = 0;
        totalPointsEarned = 0;
    };

    void printStats();
    Time getTime();
    string getDate();
    string getName();
    int getQR();
    int getQW();
    int getTotalPoints();

    void answerQuestion(int points);
    Pet& getPet();
    void rename(string newName);
};



#endif //PLAYER_H
