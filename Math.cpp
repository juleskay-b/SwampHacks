//
// Created by Hector on 1/25/2025.
//

#include "Math.h"


Math::Math() {

}

void Math::RandomOperation() noexcept {
    int operationIndex = rand() % 3;
    switch(operationIndex) {
        case 0:
            operation = "+";
            result = num1 + num2;
            break;
        case 1:
            operation = "-";
            result = num1 - num2;
            break;
        case 2:
            operation = "*";
            result = num1*num2;
            break;
    }
}

#include "Math.h"
