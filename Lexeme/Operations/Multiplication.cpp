//
// Created by Дарья on 09.12.2020.
//

#include <cmath>
#include "Multiplication.h"

Multiplication::Multiplication() : BinaryOperation("*", 1) {};
double Multiplication::process(std::vector<double> args) const {
    return args[0] * args[1];
}