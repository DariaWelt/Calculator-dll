//
// Created by Дарья on 11.12.2020.
//

#include "SinusOperation.h"
#include <cmath>

double SinusOperation::process(std::vector<double> args) const {
    return sin(args[0]);
}

SinusOperation::SinusOperation()  : UnaryOperation("sin", 1){};
