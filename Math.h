//
// Created by Hector on 1/25/2025.
//

#ifndef SCRAP_MATH_H
#define SCRAP_MATH_H

#include "pet.h"
#include "player.h"
#include <random>


class Math {
    int points;
public:
    Math();
    int additionProblem(player& player);
    int subtractionProblem(player& player);
    int multiplicationProblem(player& player);
};


#endif //SCRAP_MATH_H
