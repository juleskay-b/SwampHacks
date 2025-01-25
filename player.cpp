//
// Created by Jules on 1/25/2025.
//

#include "player.h"

Time::Time() {
    start = chrono::steady_clock::now();
}

int Time::getHours() {
    chrono::steady_clock::time_point thisTime = chrono::steady_clock::now();
    chrono::duration<int> time_span = chrono::duration_cast<chrono::duration<int>>(thisTime - start);
    int totalSeconds = time_span.count();
    int totalHours = totalSeconds / 3600;
    return totalHours;
}


player::player() {

}

void player::printTimePlayed() {
    cout << "You have been playing for " << startTime.getHours() << " hours!" << endl;
}
