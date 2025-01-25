//
// Created by Jules on 1/25/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>
#include <iostream>
using namespace std;

struct Time {
    chrono::steady_clock::time_point start;
public:
    Time();
    int getHours();
};

class player {
    Time startTime;
public:
    player();
    void printTimePlayed();
};



#endif //PLAYER_H
