//
// Created by Hector on 1/25/2025.
//

#ifndef SCRAP_MATH_H
#define SCRAP_MATH_H

#include "pet.h"
#include <random>


class Math {
private:
    int num1;
    int num2;
    string operation;
    int result;
public:
    Math();
    void RandomOperation() noexcept;

};


#endif //SCRAP_MATH_H
