//
// Created by Дарья on 11.12.2020.
//

#include "Subtraction.h"

Subtraction::Subtraction(): BinaryOperation("-", 2) {}

double Subtraction::process(std::vector<double> args) const {
    return args[1] - args[0];
}
