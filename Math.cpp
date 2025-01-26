//
// Created by Hector on 1/25/2025.
//

#include "Math.h"


Math::Math() {
    points = 4;
}

int Math::additionProblem(player& player) {
    int points = 4;
    int a = rand() % 100;
    int b = rand() % 100;
    int answer = a + b;
    int input;
    cout << a << " + " << b << " = ";
    cin >> input;
    if (input == answer) {
        player.answerQuestion(points);
        cout << "Correct! " << points << " points!" << endl;
        return points;
    }

    points--;

    while (input != answer && points > 0) {
        cout << "Incorrect. Try again." << endl;
        cout << a << " + " << b << " = ";
        cin >> input;
        if (input == answer) {
            player.answerQuestion(points);
            cout << "Correct! " << points << " points!" << endl;
            return points;
        }
        --points;
    }

    player.answerQuestion(points);
    cout << "Sorry! Out of tries!" << endl;
    return 0;
}

int Math::subtractionProblem(player& player) {
    int points = 4;
    int a = rand() % 100;
    int b = rand() % 100;
    while (a==b || a < b) {
        a = rand() %100;
        b = rand()%100;
    }
    int answer = a - b;
    int input;
    cout << a << " - " << b << " = ";
    cin >> input;
    if (input == answer) {
        player.answerQuestion(points);
        cout << "Correct! " << points << " points!" << endl;
        return points;
    }

    points--;

    while (input != answer && points > 0) {
        cout << "Incorrect. Try again." << endl;
        cout << a << " - " << b << " = ";
        cin >> input;
        if (input == answer) {
            player.answerQuestion(points);
            cout << "Correct! " << points << " points!" << endl;
            return points;
        }
        --points;
    }

    player.answerQuestion(points);
    cout << "Sorry! Out of tries!" << endl;
    return 0;

}


int Math::multiplicationProblem(player& player) {
    int points = 4;
    int a = rand() % 10;
    int b = rand() % 10;
    int answer = a * b;
    int input;
    cout << a << " x " << b << " = ";
    cin >> input;
    if (input == answer) {
        cout << "Correct! " << points << " points!" << endl;
        player.answerQuestion(points);
        return points;
    }

    points--;

    while (input != answer && points > 0) {
        cout << "Incorrect. Try again." << endl;
        cout << a << " x " << b << " = ";
        cin >> input;
        if (input == answer) {
            player.answerQuestion(points);
            cout << "Correct! " << points << " points!" << endl;
            return points;
        }
        --points;
    }

    player.answerQuestion(points);
    cout << "Sorry! Out of tries!" << endl;
    return 0;

}
