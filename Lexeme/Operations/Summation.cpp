//
// Created by Дарья on 09.12.2020.
//

#include <cmath>
#include "Summation.h"
Summation::Summation(): BinaryOperation("+", 2) {}
double Summation::process(std::vector<double> args) const {
    return args[0] + args[1];
}